//---------------------------------------------------------------------------

#include <vcl.h>
#include <list.h>
#include <filectrl.hpp>
#include <io.h>
#include <windows.h>
#include <Registry.hpp>

#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;

const int confAmount = 20;

int TForm2::getConfAmount() {
        return confAmount;
}

class Configuration {
        public:
		bool set;
                String label;
                String player;
                list<String> mods;
                String password;
                String addParameters;

                Configuration(String l, String p, list<String> &m, String pw, String aP, bool ns, bool nm) {
                        this->set = true;
                        this->label = l;
			this->player = p;
                        this->mods = m;
                        this->password = pw;
                        this->addParameters = aP;
                        if(nm) {
                                this->addParameters += " -nomap";
                        }
                        if(ns) {
                                this->addParameters += " -nosplash";
                        }
                }

		Configuration () {
			this->set = false;
		}
                TStringList* createFileEntry() {
                        TStringList *output = new TStringList;
                        output->Add("[Conf]");
                        if(!this->label.IsEmpty()) {
                                output->Add("Label = " + this->label);
                        }
                        if(!this->player.IsEmpty()) {
                                output->Add("Player = " + this->player);
                        }
                        if(!this->password.IsEmpty()) {
                                output->Add("Password = " + this->password);
                        }
                        if(this->mods.size() > 0) {
                                output->Add("Mods = " + this->createModLine());
                        }
                        if(!this->addParameters.IsEmpty()) {
                                output->Add("Parameters = " + this->addParameters);
                        }
                        output->Add("[\\Conf]");
                        return output;
                }
                String createStartLine(String ip, int port) {
                        String out = "" ;
                        out += " " + this->addParameters;
                        out += " -connect=" + ip;
                        out += " -port=" + String(port);
                        out += " \"-name=" + this->player + "\"";
                        String ml = this->createModLine();
                        if(!ml.IsEmpty()) {
                                out += " \"-mod="+ this->createModLine() +"\"";
                        }
                        return out;
                }
                String createListEntry() {
                        String out = "";
                        if(this->set) {
                                if(!this->label.Trim().IsEmpty()) {
                                        out += this->label + "  ";
                                }
                                out += this->player + "  ";
                                out += this->createModLine();
                        }
                        return out;
                }

        private:
                String createModLine () {
                        String modline = "";
                        unsigned int i = 0;
                        for (list<String>::iterator ci = this->mods.begin(); ci != this->mods.end(); ++ci) {
                                i++;
                                modline += *ci;
                                if(i < this->mods.size()) {
                                        modline += ";";
                                }
                        }
                        return modline;
                }
};

String checkBool(bool in) {
        if(in) {
                return "1";
        } else {
                return "0";
        }
}

bool checkBool2(String in) {
        if(in == "1") {
                return true;
        } else {
                return false;
        }
}


class Settings {
        public:
                bool changed;
                String exe;
                String folder;
                String player;
                int interval;
                Configuration startupConfs[confAmount];
                String file;

                Settings() {
                        this->interval = 1;
                        this->file = "OFPMonitor.ini";
                        this->changed = false;
                }

                Configuration pSgetConf(int i) {
                        return this->startupConfs[i];
                }
                void pSdeleteConf(int i) {
                        int u = i;
                        this->startupConfs[i].set = false;
                        for(int j = i + 1; j < confAmount; j++) {
                                this->startupConfs[j - 1] = (this->startupConfs[j]);


                        }
                        this->startupConfs[confAmount - 1].set = false;
                        this->changed = true;
                }
                void pSaddConf(Configuration c) {
                        for(int i = 0; i < confAmount; i++) {
                                if(!this->startupConfs[i].set) {
                                        this->startupConfs[i] = c;
                                        break;
                                }
                        }
                        this->changed = true;
                }

                void setInterval(int i) {
                        this->interval = i;
                        Form1->Timer1->Interval = i * 1000;
                        this->changed = true;
                }

                void writeToFile(list<String> &servers, list<String> &font, list<String> &window) {
                        if(this->changed) {
                                TStringList *file = new TStringList;
                                file->Add("[General]");
                                file->Add("Exe = " + this->exe);
                                file->Add("Interval = " + String(this->interval));
                                file->Add("[\\General]");
                                for(int i = 0; i < confAmount; i++) {
                                        if(this->startupConfs[i].set) {
                                                TStringList *entry = this->startupConfs[i].createFileEntry();
                                                while (entry->Count > 0) {
                                                        file->Add(entry->Strings[0]);
                                                        entry->Delete(0);
                                                }
                                                delete entry;
                                        }
                                }
                                file->Add("[Filters]");
                                file->Add("Playing = " + checkBool(Form1->CheckBox1->Checked));
                                file->Add("Waiting= " + checkBool(Form1->CheckBox2->Checked));
                                file->Add("Creating = " + checkBool(Form1->CheckBox3->Checked));
                                file->Add("Settingup = " + checkBool(Form1->CheckBox8->Checked));
                                file->Add("Briefing = " + checkBool(Form1->CheckBox4->Checked));
                                file->Add("Debriefing = " + checkBool(Form1->CheckBox5->Checked));
                                file->Add("WithPW = " + checkBool(Form1->CheckBox6->Checked));
                                file->Add("WithoutPW = " + checkBool(Form1->CheckBox7->Checked));
                                file->Add("minPlayers = " + IntToStr(Form1->UpDown1->Position));
                                file->Add("ServerName = " + Form1->Edit2->Text);
                                file->Add("MissionName = " + Form1->Edit1->Text);
                                file->Add("PlayerName = " + Form1->Edit4->Text);
                                file->Add("[\\Filters]");
                                String tmp;
                                while(font.size() > 0) {
                                        tmp = font.front();
                                        file->Add(tmp);
                                        font.pop_front();
                                }
                                while(window.size() > 0) {
                                        tmp = window.front();
                                        file->Add(tmp);
                                        window.pop_front();
                                }
                                if (servers.size() > 0) {
                                        file->Add("[Servers]");
                                        while(servers.size() > 0) {
                                                tmp = servers.front();
                                                file->Add(tmp);
                                                servers.pop_front();
                                        }
                                        file->Add("[\\Servers]");
                                }
                                file->SaveToFile(this->file);
                                delete file;
                        }
                }
};
Settings programSettings = Settings();

void TForm2::writeSettingToFile(list<String> servers, list<String> font, list<String> window) {
        programSettings.writeToFile(servers, font, window);
}

void TForm2::setSettingsChanged() {
        programSettings.changed = true;
}

String TForm2::getConfListEntry(int i) {
        return programSettings.startupConfs[i].createListEntry();
}

String TForm2::getConfStartLine(int i, String ip, int port) {
        return programSettings.startupConfs[i].createStartLine(ip, port);
}

String TForm2::getExe() {
        return programSettings.exe;
}

String TForm2::getExeFolder() {
        return programSettings.folder;
}

void updateConfList() {
        Form2->ListBox1->Clear();
        for(int i = 0; i < confAmount; i++) {
                if(programSettings.startupConfs[i].set) {
                        Form2->ListBox1->Items->AddObject(programSettings.startupConfs[i].createListEntry(), (TObject *) i);
                }
        }
        return;
}

String getValue(String in) {
        String out = "";
        String tmp = in.Trim();
        for(int i = 0; i < tmp.Length(); i++) {
                if(tmp.SubString(i,1) == "=") {
                        out = tmp.SubString(i + 1, tmp.Length() - i).Trim();
                        break;
                }
        }
        return out;
}

String getFolder(String in) {
        String out = "";
        for(int i = in.Length() - 1; i >= 0; i--) {
                if(in.SubString(i,1) == "\\") {
                        out = in.SubString(0, i + 1).Trim();
                        break;
                }
        }
        return out;
}


String GetRegistryValue(void * root, list<String> a, String key) {
        String S = "";
        TRegistry *Registry = new TRegistry(KEY_READ);
        try
        {
                Registry->RootKey = root;
                while (a.size() > 0) {
                        Registry->OpenKey(a.front(),false);
                        a.pop_front();
                }
                S = Registry->ReadString(key);
        }
        __finally {
                delete Registry;
        }
        return S;
}



TStringList* TForm2::init() {
        String exe = "";
        String interval = "";
        String folder = "";
        String player = "";
        TStringList *ipList = new TStringList();
        if(FileExists(programSettings.file)) {
                TStringList *file = new TStringList;
                file->LoadFromFile(programSettings.file);
                for(int i = 0; i < file->Count; i++) {
                        String tmp = file->Strings[i].Trim();
                        if(tmp.SubString(1,9) == "[General]") {
                                i++;
                                tmp = file->Strings[i].Trim();
                                while(tmp.SubString(1,10) != "[\\General]" && i < file->Count - 1) {
                                        if(tmp.SubString(1,3) == "Exe") {
                                                String tmp = getValue(tmp);
                                                if(FileExists(tmp)) {
                                                        exe = tmp;
                                                        folder = getFolder(exe);
                                                }
                                        } else if(tmp.SubString(1,8) == "Interval") {
                                                interval = getValue(tmp);
                                        }
                                        i++;
                                        tmp = file->Strings[i].Trim();
                                }
                        } else if(tmp.SubString(1,6) == "[Conf]") {
                                Configuration c = Configuration();
                                c.set = true;
                                i++;
                                tmp = file->Strings[i].Trim();
                                while(tmp.SubString(1,7) != "[\\Conf]" && i < file->Count - 1) {
                                        if(tmp.SubString(1,6) == "Player") {
                                                c.player = getValue(tmp);
                                        } else if(tmp.SubString(1,8) == "Password") {
                                                c.password = getValue(tmp);
                                        } else if(tmp.SubString(1,4) == "Mods") {
                                                c.mods = Form1->splitUpMessage(getValue(tmp), ";");
                                        } else if(tmp.SubString(1,10) == "Parameters") {
                                                c.addParameters = getValue(tmp);
                                        } else if(tmp.SubString(1,5) == "Label") {
                                                c.label = getValue(tmp);
                                        }
                                        i++;
                                        tmp = file->Strings[i].Trim();
                                }
                                programSettings.pSaddConf(c);
                        } else if(tmp.SubString(1,9) == "[Servers]") {
                                i++;
                                tmp = file->Strings[i].Trim();
                                while(tmp.SubString(1,10) != "[\\Servers]" && i < file->Count - 1) {
                                        if(tmp.Length() > 8) {
                                                ipList->Add(tmp.Trim());
                                        }
                                        i++;
                                        tmp = file->Strings[i].Trim();
                                }
                        } else if(tmp.SubString(1,9) == "[Filters]") {
                                i++;
                                tmp = file->Strings[i].Trim();
                                while(tmp.SubString(1,10) != "[\\Filters]" && i < file->Count - 1) {
                                        if(tmp.SubString(1,7) == "Playing") {
                                                Form1->CheckBox1->Checked = checkBool2(getValue(tmp));
                                        } else if(tmp.SubString(1,7) == "Waiting") {
                                                Form1->CheckBox2->Checked = checkBool2(getValue(tmp));
                                        } else if(tmp.SubString(1,8) == "Creating") {
                                                Form1->CheckBox3->Checked = checkBool2(getValue(tmp));
                                        } else if(tmp.SubString(1,9) == "Settingup") {
                                                Form1->CheckBox8->Checked = checkBool2(getValue(tmp));
                                        } else if(tmp.SubString(1,8) == "Briefing") {
                                                Form1->CheckBox4->Checked = checkBool2(getValue(tmp));
                                        } else if(tmp.SubString(1,10) == "Debriefing") {
                                                Form1->CheckBox5->Checked = checkBool2(getValue(tmp));
                                        } else if(tmp.SubString(1,6) == "WithPW") {
                                                Form1->CheckBox6->Checked = checkBool2(getValue(tmp));
                                        } else if(tmp.SubString(1,9) == "WithoutPW") {
                                                Form1->CheckBox7->Checked = checkBool2(getValue(tmp));
                                        } else if(tmp.SubString(1,10) == "minPlayers") {
                                                try {
                                                        int i = StrToInt(getValue(tmp));
                                                        Form1->UpDown1->Position = i;
                                                } catch (...) {}
                                        } else if(tmp.SubString(1,10) == "ServerName") {
                                                Form1->Edit2->Text = getValue(tmp);
                                        } else if(tmp.SubString(1,11) == "MissionName") {
                                                Form1->Edit1->Text = getValue(tmp);
                                        } else if(tmp.SubString(1,10) == "PlayerName") {
                                                Form1->Edit4->Text = getValue(tmp);
                                        }
                                        i++;
                                        tmp = file->Strings[i].Trim();
                                }
                        } else if(tmp.SubString(1,14) == "[FontSettings]") {
                                i++;
                                tmp = file->Strings[i].Trim();
                                int charset = 0;
                                String name = "";
                                int size = 0;
                                bool bold = false, italic = false;
                                while(tmp.SubString(1,15) != "[\\FontSettings]" && i < file->Count - 1) {
                                        if(tmp.SubString(1,4) == "Name") {
                                                name = getValue(tmp);
                                        } else if(tmp.SubString(1,7) == "Charset") {
                                                try {
                                                        charset = StrToInt(getValue(tmp));
                                                } catch (...) {}
                                        } else if(tmp.SubString(1,4) == "Size") {
                                                try {
                                                        size = StrToInt(getValue(tmp));
                                                } catch (...) {};
                                        } else if(tmp.SubString(1,4) == "Bold") {
                                                bold = checkBool2(getValue(tmp));
                                        } else if(tmp.SubString(1,6) == "Italic") {
                                                italic = checkBool2(getValue(tmp));
                                        }
                                        i++;
                                        tmp = file->Strings[i].Trim();
                                }
                                Form1->setFont(name, size, charset,bold,italic);
                        } else if(tmp.SubString(1,16) == "[WindowSettings]") {
                                i++;
                                tmp = file->Strings[i].Trim();
                                int top = 0;
                                int left = 0;
                                int width = 0;
                                int height = 0;
                                float   ratioID = 0.0f,
                                        ratioSN = 0.0f,
                                        ratioPN = 0.0f,
                                        ratioST = 0.0f,
                                        ratioIS = 0.0f,
                                        ratioMN = 0.0f,
                                        ratioPI = 0.0f,
                                        ratioPL = 0.0f,
                                        ratioSC = 0.0f,
                                        ratioDE = 0.0f,
                                        ratioTE = 0.0f;
                                while(tmp.SubString(1,17) != "[\\WindowSettings]" && i < file->Count - 1) {
                                        if(tmp.SubString(1,4) == "Left") {
                                                try {   left = StrToInt(getValue(tmp));  }catch(...) {};
                                        } else if(tmp.SubString(1,3) == "Top") {
                                                try {   top = StrToInt(getValue(tmp));  }catch(...) {};
                                        } else if(tmp.SubString(1,5) == "Width") {
                                                try {   width = StrToInt(getValue(tmp));  }catch(...) {};
                                        } else if(tmp.SubString(1,6) == "Height") {
                                                try {   height = StrToInt(getValue(tmp));  }catch(...) {};
                                        } else if(tmp.SubString(1,7) == "ratioID") {
                                                try {   ratioID = atof(getValue(tmp).c_str());  }catch(...) {};
                                        } else if(tmp.SubString(1,7) == "ratioSN") {
                                                try {   ratioSN = atof(getValue(tmp).c_str());  }catch(...) {};
                                        } else if(tmp.SubString(1,7) == "ratioPN") {
                                                try {   ratioPN = atof(getValue(tmp).c_str());  }catch(...) {};
                                        } else if(tmp.SubString(1,7) == "ratioST") {
                                                try {   ratioST = atof(getValue(tmp).c_str());  }catch(...) {};
                                        } else if(tmp.SubString(1,7) == "ratioIS") {
                                                try {   ratioIS = atof(getValue(tmp).c_str());  }catch(...) {};
                                        } else if(tmp.SubString(1,7) == "ratioMN") {
                                                try {   ratioMN = atof(getValue(tmp).c_str());  }catch(...) {};
                                        } else if(tmp.SubString(1,7) == "ratioPI") {
                                                try {   ratioPI = atof(getValue(tmp).c_str());  }catch(...) {};
                                        } else if(tmp.SubString(1,7) == "ratioPL") {
                                                try {   ratioPL = atof(getValue(tmp).c_str());  }catch(...) {};
                                        } else if(tmp.SubString(1,7) == "ratioSC") {
                                                try {   ratioSC = atof(getValue(tmp).c_str());  }catch(...) {};
                                        } else if(tmp.SubString(1,7) == "ratioDE") {
                                                try {   ratioDE = atof(getValue(tmp).c_str());  }catch(...) {};
                                        } else if(tmp.SubString(1,7) == "ratioTE") {
                                                try {   ratioTE = atof(getValue(tmp).c_str());  }catch(...) {};
                                        }
                                        i++;
                                        tmp = file->Strings[i].Trim();
                                }
                                Form1->setWindowSettings(top,left,height,width,ratioID,
                                        ratioSN,
                                        ratioPN,
                                        ratioST,
                                        ratioIS,
                                        ratioMN,
                                        ratioPI,
                                        ratioPL,
                                        ratioSC,
                                        ratioDE,
                                        ratioTE);

                        }
                }
                delete file;
        }
        if(folder.IsEmpty()) {
                list<String> a;
                a.push_back("SOFTWARE");
                        a.push_back("Codemasters");
                a.push_back("Operation Flashpoint");
                folder = GetRegistryValue(HKEY_LOCAL_MACHINE, a, "Main");
        }
        if(exe.IsEmpty() && !folder.IsEmpty()) {
                if(FileExists(folder + "\\FlashpointResistance.exe")) {
                        exe = folder + "\\FlashpointResistance.exe";
                }
        }
        list<String> b;
        b.push_back("Software");
        b.push_back("Codemasters");
        b.push_back("Operation Flashpoint");
        player = GetRegistryValue(HKEY_CURRENT_USER, b, "Player Name");
        if(!exe.IsEmpty()) {
                programSettings.exe = exe;
        }
        if(!folder.IsEmpty()) {
                programSettings.folder = folder;
        }
        if(!player.IsEmpty()) {
                programSettings.player = player;
        }
        try {
                int a = StrToInt(interval);
                programSettings.setInterval(a);
                UpDown1->Position = a;
        }catch (...) {
        }
        programSettings.changed = false;
        return ipList;
}



//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button1Click(TObject *Sender)
{
        if(!Edit1->Text.IsEmpty()) {
                OpenDialog1->InitialDir = getFolder(Edit1->Text);
        }
        OpenDialog1->Execute();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormCreate(TObject *Sender)
{
        if(!programSettings.player.IsEmpty()) {
                Edit2->Text = programSettings.player;
        }
        if(!programSettings.exe.IsEmpty()) {
                Edit1->Text = programSettings.exe;
        }
        if(programSettings.folder.IsEmpty()) {
                Button3->Enabled = false;
                GroupBox3->Enabled = false;
        } else {
        	TSearchRec daten;
                if(0 == FindFirst((programSettings.folder +"\\*").c_str(), faDirectory, daten)) {
                        try {
                                do {
                                        if(daten.Size == 0 && daten.Name != "." && daten.Name != "..") {
                                                ListBox2->Items->Add(String(daten.Name));
                                        }
                                } while(FindNext(daten) == 0);
                        }__finally
                        {
                                FindClose(daten);
                        }
                }
        }


        UpDown1->Position = programSettings.interval;
        Edit5->Text = String(UpDown1->Position);
        updateConfList();


}
//---------------------------------------------------------------------------

void __fastcall TForm2::OpenDialog1CanClose(TObject *Sender,
      bool &CanClose)
{
        if(CanClose) {
                Edit1->Text = OpenDialog1->FileName;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button7Click(TObject *Sender)
{
        for(int i = 0; i < ListBox2->Count; i++) {
                if(ListBox2->Selected[i]) {
                        ListBox3->Items->Add(ListBox2->Items->Strings[i]);
                        ListBox2->Items->Delete(i);
                        i--;
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button6Click(TObject *Sender)
{
        for(int i = 0; i < ListBox3->Count; i++) {
                if(ListBox3->Selected[i]) {
                        ListBox2->Items->Add(ListBox3->Items->Strings[i]);
                        ListBox3->Items->Delete(i);
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button8Click(TObject *Sender)
{
        for(int i = 0; i < ListBox3->Count; i++) {
                if(ListBox3->Selected[i]) {
                        if(i > 0) {
                                ListBox3->Items->Exchange(i, i - 1);
                                break;
                        }
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button9Click(TObject *Sender)
{
        for(int i = 0; i < ListBox3->Count; i++) {
                if(ListBox3->Selected[i]) {
                        if(i < ListBox3->Count - 1) {
                                ListBox3->Items->Exchange(i, i + 1);
                                break;
                        }
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button2Click(TObject *Sender)
{
        for(int i = 0; i < ListBox1->Count; i++) {
                if(ListBox1->Selected[i]) {
                        TObject *t = ListBox1->Items->Objects[i];
                        int j = (int) t;
                        programSettings.pSdeleteConf(j);
                        ListBox1->Items->Delete(i);
                }
        }
        if(ListBox1->Items->Count < confAmount) {
                Button3->Enabled = true;
        }
        updateConfList();
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Button3Click(TObject *Sender)
{
        list<String> a;
        for(int i = 0; i < ListBox3->Count; i++) {
                a.push_back(ListBox3->Items->Strings[i]);
        }
        Configuration newC = Configuration(Edit6->Text, Edit2->Text, a, Edit3->Text, Edit4->Text, CheckBox1->Checked, CheckBox2->Checked);
        String str = Edit6->Text;
        if(!str.IsEmpty()) {
                str += ":  ";
        }
        str += Edit2->Text + "  ";
        if(!Edit3->Text.IsEmpty()) {
                str += "pw: " + Edit3->Text + "  ";
        }
        unsigned int j = 0;
        for (list<String>::iterator ci = a.begin(); ci != a.end(); ++ci) {
                j++;
                String mod = *ci;
                str += String(*ci);
                if(j < a.size()) {
                        str += ";";
                }
        }
        programSettings.pSaddConf(newC);
        if(ListBox1->Items->Count >= confAmount) {
                Button3->Enabled = false;
        }
        updateConfList();
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Edit5Change(TObject *Sender)
{
        try {
                int a = StrToInt(Edit5->Text);
                if(a < UpDown1->Min) {
                        Edit5->Text = UpDown1->Position;
                } else if(a > UpDown1->Max) {
                        Edit5->Text = UpDown1->Position;
                }
        } catch (...) {
                Edit5->Text = UpDown1->Position;
        }
        programSettings.setInterval(UpDown1->Position);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::UpDown1Click(TObject *Sender, TUDBtnType Button)
{
        programSettings.setInterval(UpDown1->Position);
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Button4Click(TObject *Sender)
{
        while(ListBox3->Count > 0) {
                ListBox2->Items->Add(ListBox3->Items->Strings[0]);
                ListBox3->Items->Delete(0);
        }
        Edit3->Text = "";
        Edit4->Text = "";
        Edit6->Text = "";
        CheckBox1->Checked = true;
        CheckBox2->Checked = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
        if(!Form2->getExe().IsEmpty() && !Form2->getExeFolder().IsEmpty()) {
                Form1->PopupMenu1->Items->Items[0]->Enabled = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key == VK_ESCAPE) {
                Form2->Close();
        }
}
//---------------------------------------------------------------------------


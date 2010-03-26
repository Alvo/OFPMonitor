//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <NMUDP.hpp>
#include <Grids.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include "trayicon.h"
#include <Dialogs.hpp>
//---------------------------------------------------------------------------

class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TStringGrid *StringGrid1;
        TGroupBox *GroupBox1;
        TGroupBox *GroupBox2;
        TButton *Button3;
        TTimer *Timer1;
        TNMUDP *NMUDP1;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TCheckBox *CheckBox1;
        TCheckBox *CheckBox2;
        TCheckBox *CheckBox3;
        TCheckBox *CheckBox4;
        TCheckBox *CheckBox5;
        TEdit *Edit1;
        TLabel *Label6;
        TEdit *Edit2;
        TLabel *Label7;
        TTimer *Timer3;
        TLabel *Label8;
        TLabel *Label9;
        TLabel *Label10;
        TLabel *Label11;
        TLabel *Label12;
        TLabel *Label13;
        TCheckBox *CheckBox6;
        TCheckBox *CheckBox7;
        TLabel *Label14;
        TLabel *Label15;
        TLabel *Label19;
        TUpDown *UpDown1;
        TEdit *Edit3;
        TStringGrid *StringGrid2;
        TStatusBar *StatusBar1;
        TEdit *Edit4;
        TLabel *Label16;
        TPopupMenu *PopupMenu1;
        TMenuItem *Join1;
        TCheckBox *CheckBox8;
        TMenuItem *Mods1;
        TMenuItem *N01;
        TMenuItem *N11;
        TMenuItem *N21;
        TMenuItem *N31;
        TMenuItem *N41;
        TMenuItem *N02;
        TMenuItem *N12;
        TMenuItem *N22;
        TMenuItem *N32;
        TMenuItem *N42;
        TMenuItem *N51;
        TMenuItem *N61;
        TMenuItem *N71;
        TMenuItem *N81;
        TMenuItem *N91;
        TMenuItem *N52;
        TMenuItem *N62;
        TMenuItem *N72;
        TMenuItem *N82;
        TMenuItem *N92;
        TLabel *Label5;
        TMenuItem *Watch1;
        TLabel *Label21;
        TMainMenu *MainMenu1;
        TMenuItem *Exit1;
        TMenuItem *Settings1;
        TMenuItem *GetnewServerlist1;
        TTrayIcon *TrayIcon1;
        TFontDialog *FontDialog1;
        TMenuItem *Font1;
        void __fastcall NMUDP1DataReceived(TComponent *Sender,
          int NumberBytes, AnsiString FromIP, int Port);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall StringGrid1SelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall CheckBox1Click(TObject *Sender);
        void __fastcall CheckBox2Click(TObject *Sender);
        void __fastcall CheckBox3Click(TObject *Sender);
        void __fastcall CheckBox4Click(TObject *Sender);
        void __fastcall CheckBox5Click(TObject *Sender);
        void __fastcall NMUDP1DataSend(TObject *Sender);
        void __fastcall Timer3Timer(TObject *Sender);
        void __fastcall CheckBox6Click(TObject *Sender);
        void __fastcall CheckBox7Click(TObject *Sender);
        void __fastcall Edit1Change(TObject *Sender);
        void __fastcall StringGrid1MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall Edit3Change(TObject *Sender);
        void __fastcall UpDown1Click(TObject *Sender, TUDBtnType Button);
        void __fastcall Edit2Change(TObject *Sender);
        void __fastcall StringGrid2MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall Edit4Change(TObject *Sender);
        void __fastcall PopupMenu1Popup(TObject *Sender);
        void __fastcall ClickMyButton(TObject *Sender);
        void __fastcall ClickWatchButton(TObject *Sender);
        void __fastcall CheckBox8Click(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall StringGrid1DrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State);
        void __fastcall Settings1Click(TObject *Sender);
        void __fastcall Exit1Click(TObject *Sender);
        void __fastcall GetnewServerlist1Click(TObject *Sender);
        void __fastcall Font1Click(TObject *Sender);
        void __fastcall FontDialog1Apply(TObject *Sender, HWND Wnd);
        void __fastcall FormResize(TObject *Sender);
        void __fastcall StringGrid1ColumnMoved(TObject *Sender,
          int FromIndex, int ToIndex);
        void __fastcall StringGrid1MouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall StringGrid2MouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
private:	// User declarations
public:		// User declarations
        typedef list<String> CustomStringList;
        void TForm1::setFont(String name, int size, int charset,bool bold, bool italic);
        void TForm1::setWindowSettings(int top,int left, int height, int width, float ratioID,float ratioSN,
                                float ratioPN,float ratioST,float ratioIS,
                                float ratioMN,float ratioPI,float ratioPL,
                                float ratioSC,float ratioDE,float ratioTE);
        CustomStringList TForm1::splitUpMessage(String msg, String split);
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
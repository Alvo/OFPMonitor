TButton *guiButton[7];
TCheckBox *guiCheckBox[10];
TLabel *guiLabel[18];
TGroupBox *guiGroupBox[6];
TForm *guiForm[1];
TMenuItem *guiMenuItem[4];
TStatusPanel *guiStatusPanel[10];

class guiString {
	public:
		String identifier;
		String value;
		guiString(String i, String v) {
			this->identifier = i;
			this->value = v;
		}
};

list<guiString> guiStrings;
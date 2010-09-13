object Form1: TForm1
  Left = 254
  Top = 245
  Width = 891
  Height = 594
  HorzScrollBar.Visible = False
  VertScrollBar.Visible = False
  Color = clBtnFace
  Constraints.MinHeight = 500
  Constraints.MinWidth = 666
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  KeyPreview = True
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnCreate = FormCreate
  OnKeyDown = FormKeyDown
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 16
  object Splitter1: TSplitter
    Left = 0
    Top = 231
    Width = 883
    Height = 4
    Cursor = crVSplit
    Align = alTop
    AutoSnap = False
    Color = clBackground
    MinSize = 88
    ParentColor = False
    ResizeStyle = rsLine
    OnMoved = Splitter1Moved
  end
  object StringGrid1: TStringGrid
    Left = 0
    Top = 235
    Width = 883
    Height = 279
    Align = alClient
    BiDiMode = bdRightToLeft
    ColCount = 7
    Constraints.MinHeight = 88
    Ctl3D = True
    DefaultColWidth = 101
    DefaultRowHeight = 18
    FixedCols = 0
    RowCount = 20
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRowSizing, goColSizing, goRowSelect]
    ParentBiDiMode = False
    ParentCtl3D = False
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 0
    OnContextPopup = StringGrid1ContextPopup
    OnDrawCell = StringGrid1DrawCell
    OnMouseDown = StringGrid1MouseDown
    OnMouseUp = StringGrid1MouseUp
    OnSelectCell = StringGrid1SelectCell
    ColWidths = (
      29
      196
      53
      68
      58
      183
      41)
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 883
    Height = 231
    Align = alTop
    BevelOuter = bvNone
    Constraints.MinHeight = 231
    TabOrder = 2
    object StringGrid2: TStringGrid
      Left = 403
      Top = 0
      Width = 480
      Height = 231
      Align = alRight
      ColCount = 4
      DefaultColWidth = 50
      DefaultRowHeight = 18
      FixedCols = 0
      RowCount = 50
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected, goColSizing, goRowSelect]
      ParentFont = False
      ScrollBars = ssVertical
      TabOrder = 0
      OnMouseDown = StringGrid2MouseDown
      OnMouseUp = StringGrid2MouseUp
      ColWidths = (
        100
        38
        43
        75)
    end
    object GROUPBOX_FILTERS: TGroupBox
      Left = 1
      Top = 85
      Width = 368
      Height = 146
      Align = alCustom
      Caption = '  Filters  '
      TabOrder = 1
      object LABEL_FILTER_MISSIONNAME: TLabel
        Left = 245
        Top = 52
        Width = 86
        Height = 16
        Caption = 'Mission name:'
      end
      object LABEL_FILTER_SERVERNAME: TLabel
        Left = 245
        Top = 12
        Width = 80
        Height = 16
        Caption = 'Server name:'
      end
      object LABEL_FILTER_PASSWORD: TLabel
        Left = 152
        Top = 14
        Width = 63
        Height = 16
        Caption = 'Password:'
      end
      object LABEL_FILTER_MINIMUMPLAYERS: TLabel
        Left = 152
        Top = 72
        Width = 76
        Height = 16
        Caption = 'min. Players:'
      end
      object LABEL_FILTER_PLAYERNAME: TLabel
        Left = 245
        Top = 92
        Width = 79
        Height = 16
        Caption = 'Player name:'
      end
      object LABEL_FILTER_STATUS: TLabel
        Left = 12
        Top = 14
        Width = 40
        Height = 16
        Caption = 'Status:'
      end
      object CHECKBOX_FILTER_PLAYING: TCheckBox
        Left = 12
        Top = 96
        Width = 133
        Height = 17
        Caption = 'Playing'
        Checked = True
        State = cbChecked
        TabOrder = 4
        OnClick = CHECKBOX_FILTER_PLAYINGClick
      end
      object CHECKBOX_FILTER_WAITING: TCheckBox
        Left = 12
        Top = 48
        Width = 133
        Height = 17
        Caption = 'Waiting'
        Checked = True
        State = cbChecked
        TabOrder = 1
        OnClick = CHECKBOX_FILTER_WAITINGClick
      end
      object CHECKBOX_FILTER_CREATING: TCheckBox
        Left = 12
        Top = 32
        Width = 133
        Height = 17
        Caption = 'Creating'
        Checked = True
        State = cbChecked
        TabOrder = 0
        OnClick = CHECKBOX_FILTER_CREATINGClick
      end
      object CHECKBOX_FILTER_BRIEFING: TCheckBox
        Left = 12
        Top = 80
        Width = 133
        Height = 17
        Caption = 'Briefing'
        Checked = True
        State = cbChecked
        TabOrder = 3
        OnClick = CHECKBOX_FILTER_BRIEFINGClick
      end
      object CHECKBOX_FILTER_DEBRIEFING: TCheckBox
        Left = 12
        Top = 112
        Width = 133
        Height = 17
        Caption = 'Debriefing'
        Checked = True
        State = cbChecked
        TabOrder = 5
        OnClick = CHECKBOX_FILTER_DEBRIEFINGClick
      end
      object Edit1: TEdit
        Left = 245
        Top = 68
        Width = 116
        Height = 24
        TabOrder = 11
        OnChange = Edit1Change
      end
      object Edit2: TEdit
        Left = 245
        Top = 28
        Width = 116
        Height = 24
        TabOrder = 10
        OnChange = Edit2Change
      end
      object CHECKBOX_FILTER_WITHPASSWORD: TCheckBox
        Left = 152
        Top = 32
        Width = 73
        Height = 17
        Caption = 'With'
        TabOrder = 6
        OnClick = CHECKBOX_FILTER_WITHPASSWORDClick
      end
      object CHECKBOX_FILTER_WITHOUTPASSWORD: TCheckBox
        Left = 152
        Top = 48
        Width = 65
        Height = 17
        Caption = 'Without'
        Checked = True
        State = cbChecked
        TabOrder = 7
        OnClick = CHECKBOX_FILTER_WITHOUTPASSWORDClick
      end
      object UpDown1: TUpDown
        Left = 209
        Top = 94
        Width = 15
        Height = 24
        Associate = Edit3
        Min = 0
        Position = 0
        TabOrder = 9
        Wrap = False
        OnClick = UpDown1Click
      end
      object Edit3: TEdit
        Left = 152
        Top = 94
        Width = 57
        Height = 24
        TabOrder = 8
        Text = '0'
        OnChange = Edit3Change
      end
      object Edit4: TEdit
        Left = 245
        Top = 108
        Width = 116
        Height = 24
        TabOrder = 12
        OnChange = Edit4Change
      end
      object CHECKBOX_FILTER_SETTINGUP: TCheckBox
        Left = 12
        Top = 64
        Width = 133
        Height = 17
        Caption = 'Setting up'
        Checked = True
        State = cbChecked
        TabOrder = 2
        OnClick = CHECKBOX_FILTER_SETTINGUPClick
      end
    end
    object GROUPBOX_SERVERINFO: TGroupBox
      Left = 3
      Top = 0
      Width = 366
      Height = 84
      Caption = '  Server Info  '
      Color = clBtnFace
      ParentColor = False
      TabOrder = 2
      object LABEL_SERVERINFO_IP: TLabel
        Left = 8
        Top = 32
        Width = 15
        Height = 16
        Caption = 'IP:'
        Transparent = True
      end
      object Label2: TLabel
        Left = 40
        Top = 32
        Width = 48
        Height = 16
        Caption = '                '
        Transparent = True
      end
      object LABEL_SERVERINFO_PORT: TLabel
        Left = 144
        Top = 32
        Width = 27
        Height = 16
        Caption = 'Port:'
        Transparent = True
      end
      object Label4: TLabel
        Left = 184
        Top = 32
        Width = 24
        Height = 16
        Caption = '        '
        Transparent = True
      end
      object LABEL_SERVERINFO_PLATFORM: TLabel
        Left = 224
        Top = 32
        Width = 52
        Height = 16
        Caption = 'Platform:'
        Transparent = True
      end
      object Label9: TLabel
        Left = 312
        Top = 32
        Width = 21
        Height = 16
        Caption = '       '
        Transparent = True
      end
      object LABEL_SERVERINFO_PASSWORD: TLabel
        Left = 224
        Top = 48
        Width = 63
        Height = 16
        Caption = 'Password:'
        Transparent = True
      end
      object Label11: TLabel
        Left = 312
        Top = 48
        Width = 27
        Height = 16
        Hint = 'Ja'
        Caption = '         '
        ParentShowHint = False
        ShowHint = False
        Transparent = True
      end
      object LABEL_SERVERINFO_VERSION: TLabel
        Left = 224
        Top = 64
        Width = 49
        Height = 16
        Caption = 'Version:'
        Transparent = True
      end
      object Label13: TLabel
        Left = 312
        Top = 64
        Width = 30
        Height = 16
        Caption = '          '
        Transparent = True
      end
      object Label21: TLabel
        Left = 8
        Top = 16
        Width = 66
        Height = 16
        Caption = '                      '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        Transparent = True
      end
      object BUTTON_SERVERINFO_COPYADDRESS: TButton
        Left = 24
        Top = 54
        Width = 185
        Height = 22
        Caption = 'Copy address to clipboard'
        Enabled = False
        TabOrder = 0
        OnClick = BUTTON_SERVERINFO_COPYADDRESSClick
      end
    end
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 514
    Width = 883
    Height = 34
    Anchors = []
    BorderWidth = 1
    DragMode = dmAutomatic
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    Constraints.MinHeight = 34
    Panels = <
      item
        Text = 'Listed: '
        Width = 100
      end
      item
        Text = 'Online: '
        Width = 100
      end
      item
        Width = 90
      end
      item
        Width = 50
      end>
    ParentColor = True
    ParentShowHint = False
    ShowHint = False
    SimplePanel = False
    SizeGrip = False
    UseSystemFont = False
  end
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 448
    Top = 160
  end
  object NMUDP1: TNMUDP
    RemotePort = 0
    LocalPort = 0
    ReportLevel = 5
    OnDataReceived = NMUDP1DataReceived
    OnDataSend = NMUDP1DataSend
    Left = 480
    Top = 160
  end
  object Timer3: TTimer
    Enabled = False
    Interval = 10
    OnTimer = Timer3Timer
    Left = 416
    Top = 160
  end
  object PopupMenu1: TPopupMenu
    OnPopup = PopupMenu1Popup
    Left = 384
    Top = 160
    object MENUITEM_POPUP_JOIN: TMenuItem
      Caption = 'Join'
      Enabled = False
      object N01: TMenuItem
        Caption = '0'
      end
      object N11: TMenuItem
        Caption = '1'
      end
      object N21: TMenuItem
        Caption = '2'
      end
      object N31: TMenuItem
        Caption = '3'
      end
      object N41: TMenuItem
        Caption = '4'
      end
      object N52: TMenuItem
        Caption = '5'
      end
      object N62: TMenuItem
        Caption = '6'
      end
      object N72: TMenuItem
        Caption = '7'
      end
      object N82: TMenuItem
        Caption = '8'
      end
      object N92: TMenuItem
        Caption = '9'
      end
    end
    object MENUITEM_POPUP_AUTOJOIN: TMenuItem
      Caption = 'Auto-Join'
      Enabled = False
      object N03: TMenuItem
        Caption = '0'
      end
      object N13: TMenuItem
        Caption = '1'
      end
      object N23: TMenuItem
        Caption = '2'
      end
      object N33: TMenuItem
        Caption = '3'
      end
      object N43: TMenuItem
        Caption = '4'
      end
      object N53: TMenuItem
        Caption = '5'
      end
      object N63: TMenuItem
        Caption = '6'
      end
      object N73: TMenuItem
        Caption = '7'
      end
      object N83: TMenuItem
        Caption = '8'
      end
      object N93: TMenuItem
        Caption = '9'
      end
    end
    object MENUITEM_POPUP_AUTOJOINB: TMenuItem
      Caption = 'Auto-Join2'
      Enabled = False
      OnClick = MENUITEM_POPUP_AUTOJOINBClick
    end
    object MENUITEM_POPUP_MODS: TMenuItem
      Caption = 'Mods'
      object N02: TMenuItem
        Caption = '0'
      end
      object N12: TMenuItem
        Caption = '1'
      end
      object N22: TMenuItem
        Caption = '2'
      end
      object N32: TMenuItem
        Caption = '3'
      end
      object N42: TMenuItem
        Caption = '4'
      end
      object N51: TMenuItem
        Caption = '5'
      end
      object N61: TMenuItem
        Caption = '6'
      end
      object N71: TMenuItem
        Caption = '7'
      end
      object N81: TMenuItem
        Caption = '8'
      end
      object N91: TMenuItem
        Caption = '9'
      end
    end
    object MENUITEM_POPUP_WATCH: TMenuItem
      Caption = 'Watch'
    end
  end
  object MainMenu1: TMainMenu
    BiDiMode = bdLeftToRight
    ParentBiDiMode = False
    Left = 512
    Top = 160
    object MENUITEM_MAINMENU_EXIT: TMenuItem
      Caption = 'Exit'
      OnClick = MENUITEM_MAINMENU_EXITClick
    end
    object MENUITEM_MAINMENU_SETTINGS: TMenuItem
      Caption = 'Settings'
      OnClick = MENUITEM_MAINMENU_SETTINGSClick
    end
    object MENUITEM_MAINMENU_FONT: TMenuItem
      Caption = 'Font'
      OnClick = MENUITEM_MAINMENU_FONTClick
    end
    object MENUITEM_MAINMENU_GETNEWSERVERLIST: TMenuItem
      Caption = 'Get new Server list'
      ShortCut = 116
      OnClick = MENUITEM_MAINMENU_GETNEWSERVERLISTClick
    end
  end
  object TrayIcon1: TTrayIcon
    Visible = True
    Hide = True
    RestoreOn = imMouseDown
    PopupMenuOn = imNone
    Left = 544
    Top = 160
  end
  object FontDialog1: TFontDialog
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    MinFontSize = 8
    MaxFontSize = 20
    Options = [fdForceFontExist, fdLimitSize, fdApplyButton]
    OnApply = FontDialog1Apply
    Left = 576
    Top = 160
  end
  object SkinData1: TSkinData
    Active = False
    DisableTag = 99
    SkinControls = [xcPopupMenu, xcMenuItem, xcToolbar, xcControlbar, xcCombo, xcCheckBox, xcRadioButton, xcProgress, xcScrollbar, xcEdit, xcButton, xcBitBtn, xcSpeedButton, xcSpin, xcPanel, xcGroupBox, xcStatusBar, xcTab, xcTrackBar, xcSystemMenu, xcFastReport]
    Options = [xoPreview, xoToolbarBK, xoCaptionButtonHint]
    Skin3rd.Strings = (
      'TCategoryButtons=scrollbar'
      'TPngSpeedbutton=pngspeedbutton'
      'TPngBitBtn=pngbitbtn'
      'TVirtualStringTree=scrollbar'
      'TVirtualDrawTree=scrollbar'
      'TTBXDockablePanel=Panel'
      'TAdvPanelGroup=scrollbar'
      'TComboboxex=combobox'
      'TRxSpeedButton=speedbutton'
      'THTMLViewer=scrollbar'
      'TDBCtrlGrid=scrollbar'
      'TfrSpeedButton=speedbutton'
      'TfrTBButton=speedbutton'
      'TControlBar=Panel'
      'TTBDock=Panel'
      'TTBToolbar=Panel'
      'TImageEnMView=scrollbar'
      'TImageEnView=scrollbar'
      'TAdvMemo=scrollbar'
      'TDBAdvMemo=scrollbar'
      'TcxDBLookupComboBox=combobox'
      'TcxDBComboBox=combobox'
      'TcxDBDateEdit=combobox'
      'TcxDBImageComboBox=combobox'
      'TcxDBCalcEdit=combobox'
      'TcxDBBlobEdit=combobox'
      'TcxDBPopupEdit=combobox'
      'TcxDBFontNameComboBox=combobox'
      'TcxDBShellComboBox=combobox'
      'TRxLookupEdit=combobox'
      'TRxDBLookupCombo=combobox'
      'TRzGroup=panel'
      'TRzButton=button'
      'TRzBitbtn=bitbtn'
      'TRzMenuButton=menubtn'
      'TRzCheckGroup=CheckGroup'
      'TRzRadioGroup=Radiogroup'
      'TRzButtonEdit=Edit'
      'TRzDBRadioGroup=Radiogroup'
      'TRzDBRadioButton=Radiobutton'
      'TRzDateTimeEdit=combobox'
      'TRzColorEdit=combobox'
      'TRzDateTimePicker=combobox'
      'TRzDBDateTimeEdit=combobox'
      'TRzDbColorEdit=combobox'
      'TRzDBDateTimePicker=combobox'
      'TLMDButton=bitbtn'
      'TLMDGroupBox=Groupbox'
      'TDBCheckboxEh=Checkbox'
      'TDBCheckboxEh=Checkbox'
      'TLMDCHECKBOX=Checkbox'
      'TLMDDBCHECKBOX=Checkbox'
      'TLMDRadiobutton=Radiobutton'
      'TLMDCalculator=panel'
      'TLMDGROUPBOX=Panel'
      'TLMDSIMPLEPANEL=Panel'
      'TLMDDBCalendar=Panel'
      'TLMDButtonPanel=Panel'
      'TLMDLMDCalculator=Panel'
      'TLMDHeaderPanel=Panel'
      'TLMDTechnicalLine=Panel'
      'TLMDLMDClock=Panel'
      'TLMDTrackbar=panel'
      'TLMDListCombobox=combobox'
      'TLMDCheckListCombobox=combobox'
      'TLMDHeaderListCombobox=combobox'
      'TLMDImageCombobox=combobox'
      'TLMDColorCombobox=combobox'
      'TLMDFontCombobox=combobox'
      'TLMDFontSizeCombobox=combobox'
      'TLMDFontSizeCombobox=combobox'
      'TLMDPrinterCombobox=combobox'
      'TLMDDriveCombobox=combobox'
      'TLMDCalculatorComboBox=combobox'
      'TLMDTrackBarComboBox=combobox'
      'TLMDCalendarComboBox=combobox'
      'TLMDTreeComboBox=combobox'
      'TLMDRADIOGROUP=radiogroup'
      'TLMDCheckGroup=CheckGroup'
      'TLMDDBRADIOGROUP=radiogroup'
      'TLMDDBCheckGroup=CheckGroup'
      'TLMDCalculatorEdit=edit'
      'TLMDEDIT=Edit'
      'TLMDMASKEDIT=Edit'
      'TLMDBROWSEEDIT=Edit'
      'TLMDEXTSPINEDIT=Edit'
      'TLMDCALENDAREDIT=Edit'
      'TLMDFILEOPENEDIT=Edit'
      'TLMDFILESAVEEDIT=Edit'
      'TLMDCOLOREDIT=Edit'
      'TLMDDBEDIT=Edit'
      'TLMDDBMASKEDIT=Edit'
      'TLMDDBEXTSPINEDIT=Edit'
      'TLMDDBSPINEDIT=Edit'
      'TLMDDBEDITDBLookup=Edit'
      'TLMDEDITDBLookup=Edit'
      'TDBLookupCombobox=Combobox'
      'TWWDBCombobox=Combobox'
      'TWWDBLookupCombo=Combobox'
      'TWWDBCombobox=Combobox'
      'TWWKeyCombo=Combobox'
      'TWWTempKeyCombo=combobox'
      'TWWDBDateTimePicker=Combobox'
      'TWWRADIOGROUP=radiogroup'
      'TWWDBEDIT=Edit'
      'TcxButton=bitbtn'
      'TcxDBRadioGroup=radiogroup'
      'TcxRadioGroup=radiogroup'
      'TcxGroupbox=groupbox'
      'TOVCPICTUREFIELD=Edit'
      'TOVCDBPICTUREFIELD=Edit'
      'TOVCSLIDEREDIT=Edit'
      'TOVCDBSLIDEREDIT=Edit'
      'TOVCSIMPLEFIELD=Edit'
      'TOVCDBSIMPLEFIELD=Edit'
      'TO32DBFLEXEDIT=Edit'
      'TOVCNUMERICFIELD=Edit'
      'TOVCDBNUMERICFIELD=Edit')
    SkinFile = 'E:\suipack\skins3\Xplorer.skn'
    SkinStore = '(none)'
    SkinFormtype = sfMainform
    Version = '5.80.06.23'
    MenuUpdate = True
    MenuMerge = False
    Left = 376
    Top = 112
    SkinStream = {00000000}
  end
end

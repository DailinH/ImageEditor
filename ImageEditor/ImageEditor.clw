; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CImageEditorView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ImageEditor.h"
LastPage=0

ClassCount=10
Class1=CImageEditorApp
Class2=CImageEditorDoc
Class3=CImageEditorView
Class4=CMainFrame

ResourceCount=9
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CAboutDlg
Resource3=IDD_DIALOG5
Resource4=IDD_DIALOG4
Class6=ImageEditorColorPanel
Resource5=IDD_DIALOG1
Class7=ImageEditorNewFile
Resource6=IDD_DIALOG2
Class8=ImageEditorLineWidth
Resource7=IDD_DIALOG3
Class9=ImageEditorFlipnRotate
Resource8=IDD_ABOUTBOX (English (U.S.))
Class10=ImageEditorZoom
Resource9=IDR_MAINFRAME (English (U.S.))

[CLS:CImageEditorApp]
Type=0
HeaderFile=ImageEditor.h
ImplementationFile=ImageEditor.cpp
Filter=N

[CLS:CImageEditorDoc]
Type=0
HeaderFile=ImageEditorDoc.h
ImplementationFile=ImageEditorDoc.cpp
Filter=N

[CLS:CImageEditorView]
Type=0
HeaderFile=ImageEditorView.h
ImplementationFile=ImageEditorView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CImageEditorView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_MENUITEM32828
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=ImageEditor.cpp
ImplementationFile=ImageEditor.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
CommandCount=17
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command16=ID_HELP_FINDER
Command17=ID_APP_ABOUT

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
CommandCount=16
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
Command15=ID_CONTEXT_HELP
Command16=ID_HELP


[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=CAboutDlg
ControlCount=5
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_STATIC,static,1342308352

[TB:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_SAVE
Command3=ID_FILE_OPEN
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
Command9=ID_CONTEXT_HELP
CommandCount=9

[MNU:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT_SETUP
Command6=ID_FILE_PRINT
Command7=ID_FILE_MRU_FILE1
Command8=ID_APP_EXIT
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_REPEAT
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_EDIT_DEL
Command15=ID_MENUITEM32775
Command16=ID_EDIT_COPY_TO
Command17=ID_EDIT_PASTE_FROM
Command18=ID_Pencil
Command19=ID_Line
Command20=ID_Rectangle
Command21=ID_Filled_Rectangle
Command22=ID_Outlined_Rectangle
Command23=ID_Round_Rectangle
Command24=ID_Filled_Round_Rectangle
Command25=ID_Outlined_Round_Rectangle
Command26=ID_Ellipse
Command27=ID_Outlined_Ellipse
Command28=ID_Filled_Ellipse
Command29=ID_Gaussian_Filter
Command30=ID_MENUITEM32820
Command31=LINE_STYLE_SOLID
Command32=LINE_STYLE_DASH
Command33=LINE_STYLE_DOT
Command34=LINE_STYLE_DASHDOT
Command35=LINE_STYLE_DASHDOTDOT
Command36=ID_Select_Color
Command37=ID_IMG_ROTATE
Command38=ID_IMG_STRETCH
Command39=ID_IMG_INVERSE
Command40=ID_IMG_CLEAR
Command41=ID_IMG_Grey
Command42=ID_MENUITEM32828
Command43=ID_HELP_FINDER
Command44=ID_APP_ABOUT
CommandCount=44

[ACL:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
Command15=ID_CONTEXT_HELP
Command16=ID_HELP
CommandCount=16

[DLG:IDD_DIALOG1]
Type=1
Class=ImageEditorColorPanel
ControlCount=16
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT2,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EDIT3,edit,1350631552
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,button,1476395015
Control10=IDC_EDIT4,edit,1350631552
Control11=IDC_STATIC,static,1342308352
Control12=IDC_EDIT5,edit,1350631552
Control13=IDC_STATIC,static,1342308352
Control14=IDC_EDIT6,edit,1350631552
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,button,1476395015

[CLS:ImageEditorColorPanel]
Type=0
HeaderFile=ImageEditorColorPanel.h
ImplementationFile=ImageEditorColorPanel.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT4
VirtualFilter=dWC

[DLG:IDD_DIALOG2]
Type=1
Class=ImageEditorNewFile
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT1,edit,1350631552
Control6=IDC_EDIT2,edit,1350631552

[CLS:ImageEditorNewFile]
Type=0
HeaderFile=ImageEditorNewFile.h
ImplementationFile=ImageEditorNewFile.cpp
BaseClass=CDialog
Filter=D
LastObject=IDOK
VirtualFilter=dWC

[DLG:IDD_DIALOG3]
Type=1
Class=ImageEditorLineWidth
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,button,1342177287
Control5=IDC_SLIDER1,msctls_trackbar32,1350631448
Control6=IDC_EDIT1,edit,1476460673

[CLS:ImageEditorLineWidth]
Type=0
HeaderFile=ImageEditorLineWidth.h
ImplementationFile=ImageEditorLineWidth.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_APP_ABOUT
VirtualFilter=dWC

[DLG:IDD_DIALOG4]
Type=1
Class=ImageEditorFlipnRotate
ControlCount=9
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_RADIO1,button,1342308361
Control4=IDC_RADIO2,button,1342177289
Control5=IDC_RADIO3,button,1342177289
Control6=IDC_RADIO4,button,1342308361
Control7=IDC_RADIO5,button,1342177289
Control8=IDC_RADIO6,button,1342177289
Control9=IDC_STATIC,button,1342177287

[CLS:ImageEditorFlipnRotate]
Type=0
HeaderFile=ImageEditorFlipnRotate.h
ImplementationFile=ImageEditorFlipnRotate.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_RADIO1
VirtualFilter=dWC

[DLG:IDD_DIALOG5]
Type=1
Class=ImageEditorZoom
ControlCount=9
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT1,edit,1350631552
Control6=IDC_EDIT3,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,button,1342177287

[CLS:ImageEditorZoom]
Type=0
HeaderFile=ImageEditorZoom.h
ImplementationFile=ImageEditorZoom.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_EDIT1


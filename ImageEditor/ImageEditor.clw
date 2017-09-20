; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=ImageEditorLineWidth
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ImageEditor.h"
LastPage=0

ClassCount=8
Class1=CImageEditorApp
Class2=CImageEditorDoc
Class3=CImageEditorView
Class4=CMainFrame

ResourceCount=7
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CAboutDlg
Resource3=IDD_DIALOG2
Resource4=IDD_ABOUTBOX (English (U.S.))
Class6=ImageEditorColorPanel
Resource5=IDD_DIALOG1
Class7=ImageEditorNewFile
Resource6=IDD_DIALOG3
Class8=ImageEditorLineWidth
Resource7=IDR_MAINFRAME (English (U.S.))

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
LastObject=ID_Gaussian_Filter


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame
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
Command5=ID_APP_SCANNER_CAMERA
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_PRINT
Command9=ID_APP_EMAIL
Command10=ID_FILE_MRU_FILE1
Command11=ID_APP_EXIT
Command12=ID_EDIT_UNDO
Command13=ID_EDIT_REPEAT
Command14=ID_EDIT_CUT
Command15=ID_EDIT_COPY
Command16=ID_EDIT_PASTE
Command17=ID_EDIT_DEL
Command18=ID_MENUITEM32775
Command19=ID_EDIT_COPY_TO
Command20=ID_EDIT_PASTE_FROM
Command21=ID_Irregular_Selection
Command22=ID_Rectangle_Selection
Command23=ID_Erase
Command24=ID_Fill
Command25=ID_Magnify
Command26=ID_Pencil
Command27=ID_Line
Command28=ID_Curve
Command29=ID_Text
Command30=ID_Rectangle
Command31=ID_Filled_Rectangle
Command32=ID_Outlined_Rectangle
Command33=ID_Round_Rectangle
Command34=ID_Filled_Round_Rectangle
Command35=ID_Outlined_Round_Rectangle
Command36=ID_Ellipse
Command37=ID_Outlined_Ellipse
Command38=ID_Filled_Ellipse
Command39=ID_Gaussian_Filter
Command40=ID_MENUITEM32820
Command41=LINE_STYLE_SOLID
Command42=LINE_STYLE_DASH
Command43=LINE_STYLE_DOT
Command44=LINE_STYLE_DASHDOT
Command45=LINE_STYLE_DASHDOTDOT
Command46=ID_Select_Color
Command47=ID_IMG_ROTATE
Command48=ID_IMG_STRETCH
Command49=ID_IMG_INVERSE
Command50=ID_MENUITEM32790
Command51=ID_IMG_CLEAR
Command52=ID_IMG_OPAQUE
Command53=ID_HELP_FINDER
Command54=ID_APP_ABOUT
CommandCount=54

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
LastObject=IDC_EDIT1
VirtualFilter=dWC


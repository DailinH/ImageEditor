// ImageEditorColorPanel.cpp : implementation file
//

#include "stdafx.h"
#include "ImageEditor.h"
#include "ImageEditorColorPanel.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ImageEditorColorPanel dialog


ImageEditorColorPanel::ImageEditorColorPanel(CWnd* pParent /*=NULL*/)
	: CDialog(ImageEditorColorPanel::IDD, pParent)
{
	//{{AFX_DATA_INIT(ImageEditorColorPanel)
	m_Color_Red = _T("0");
	m_Color_Green = _T("0");
	m_Color_Blue = _T("0");
	m_BG_Color_Red = _T("");
	m_BG_Color_Green = _T("");
	m_BG_Color_Blue = _T("");
	transparent = true;
	//}}AFX_DATA_INIT
}


void ImageEditorColorPanel::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ImageEditorColorPanel)
	DDX_Text(pDX, IDC_EDIT1, m_Color_Red);
	DDX_Text(pDX, IDC_EDIT2, m_Color_Green);
	DDX_Text(pDX, IDC_EDIT3, m_Color_Blue);
	DDX_Text(pDX, IDC_EDIT4, m_BG_Color_Red);
	DDX_Text(pDX, IDC_EDIT5, m_BG_Color_Green);
	DDX_Text(pDX, IDC_EDIT6, m_BG_Color_Blue);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ImageEditorColorPanel, CDialog)
	//{{AFX_MSG_MAP(ImageEditorColorPanel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ImageEditorColorPanel message handlers

void ImageEditorColorPanel::OnOK() 
{
	
	int bg_red = atoi(m_BG_Color_Red);
	int bg_green = atoi(m_BG_Color_Green);	
	int bg_blue = atoi(m_BG_Color_Blue);	
	UpdateData(true);
	if(transparent == true){
		int bg_red2 = atoi(m_BG_Color_Red);
		int bg_green2 = atoi(m_BG_Color_Green);	
		int bg_blue2 = atoi(m_BG_Color_Blue);	
		if(bg_red2 != bg_red || bg_green2 != bg_green || bg_blue2 != bg_blue){
			transparent = false;
		}
	}
	//	ModifyColor = true;
	// MessageBox(m_Color_Red);
	// MessageBox(m_Color_Green);
	// MessageBox(m_Color_Blue);
	CDialog::OnOK();
}

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
	m_BG_Color_Red = _T("255");
	m_BG_Color_Green = _T("255");
	m_BG_Color_Blue = _T("255");
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
	
	UpdateData(true);
	CDialog::OnOK();
}

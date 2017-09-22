// ImageEditorZoom.cpp : implementation file
//

#include "stdafx.h"
#include "ImageEditor.h"
#include "ImageEditorZoom.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ImageEditorZoom dialog


ImageEditorZoom::ImageEditorZoom(CWnd* pParent /*=NULL*/)
	: CDialog(ImageEditorZoom::IDD, pParent)
{
	//{{AFX_DATA_INIT(ImageEditorZoom)
	m_Zoom_Horizontal = _T("100");
	m_Zoom_Vertical = _T("100");
	//}}AFX_DATA_INIT
}


void ImageEditorZoom::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ImageEditorZoom)
	DDX_Text(pDX, IDC_EDIT1, m_Zoom_Horizontal);
	DDX_Text(pDX, IDC_EDIT3, m_Zoom_Vertical);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ImageEditorZoom, CDialog)
	//{{AFX_MSG_MAP(ImageEditorZoom)
	ON_BN_CLICKED(IDOK, OnZoom)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ImageEditorZoom message handlers

void ImageEditorZoom::OnZoom() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CDialog::OnOK();
	
}

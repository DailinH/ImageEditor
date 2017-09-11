// ImageEditorLineWidth.cpp : implementation file
//

#include "stdafx.h"
#include "ImageEditor.h"
#include "ImageEditorLineWidth.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ImageEditorLineWidth dialog


ImageEditorLineWidth::ImageEditorLineWidth(CWnd* pParent /*=NULL*/)
	: CDialog(ImageEditorLineWidth::IDD, pParent)
{
	//{{AFX_DATA_INIT(ImageEditorLineWidth)
	m_Line_Width = _T("1");
	//}}AFX_DATA_INIT
}


void ImageEditorLineWidth::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ImageEditorLineWidth)
	DDX_Text(pDX, IDC_EDIT1, m_Line_Width);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ImageEditorLineWidth, CDialog)
	//{{AFX_MSG_MAP(ImageEditorLineWidth)
	ON_BN_CLICKED(IDOK, OnSetLineWidth)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ImageEditorLineWidth message handlers

void ImageEditorLineWidth::OnSetLineWidth() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CDialog::OnOK();	
}

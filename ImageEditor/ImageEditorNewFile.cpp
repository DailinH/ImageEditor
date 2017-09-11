// ImageEditorNewFile.cpp : implementation file
//

#include "stdafx.h"
#include "ImageEditor.h"
#include "ImageEditorNewFile.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ImageEditorNewFile dialog


ImageEditorNewFile::ImageEditorNewFile(CWnd* pParent /*=NULL*/)
	: CDialog(ImageEditorNewFile::IDD, pParent)
{
	//{{AFX_DATA_INIT(ImageEditorNewFile)
	m_New_Img_Horizontal = _T("");
	m_New_Img_Vertical = _T("");
	//}}AFX_DATA_INIT
}


void ImageEditorNewFile::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ImageEditorNewFile)
	DDX_Text(pDX, IDC_EDIT1, m_New_Img_Horizontal);
	DDX_Text(pDX, IDC_EDIT2, m_New_Img_Vertical);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ImageEditorNewFile, CDialog)
	//{{AFX_MSG_MAP(ImageEditorNewFile)
	ON_BN_CLICKED(IDOK, OnCreateNewFile)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ImageEditorNewFile message handlers

void ImageEditorNewFile::OnCreateNewFile() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CDialog::OnOK();
	
}

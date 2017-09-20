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

ImageEditorLineWidth::ImageEditorLineWidth(CWnd *pParent /*=NULL*/)
	: CDialog(ImageEditorLineWidth::IDD, pParent)
{
	//{{AFX_DATA_INIT(ImageEditorLineWidth)
	m_Line_Width = 0;
	m_Show_Width = _T("");
	//}}AFX_DATA_INIT
}

void ImageEditorLineWidth::DoDataExchange(CDataExchange *pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ImageEditorLineWidth)
	DDX_Slider(pDX, IDC_SLIDER1, m_Line_Width);
	DDX_Text(pDX, IDC_EDIT1, m_Show_Width);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(ImageEditorLineWidth, CDialog)
//{{AFX_MSG_MAP(ImageEditorLineWidth)
ON_BN_CLICKED(IDOK, OnSetLineWidth)
ON_NOTIFY(NM_OUTOFMEMORY, IDC_SLIDER1, OnWidthSlider)
ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER1, OnShowLineWidth)
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

void ImageEditorLineWidth::OnWidthSlider(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here

	*pResult = 0;
}

void ImageEditorLineWidth::OnShowLineWidth(NMHDR *pNMHDR, LRESULT *pResult)
{
	UpdateData(TRUE);
	m_Show_Width.Format("%d", m_Line_Width);
	//GetDlgItem(IDC_EDIT1)->SetWindowText("1");
	UpdateData(FALSE);

	*pResult = 0;
}

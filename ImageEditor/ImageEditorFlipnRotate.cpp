// ImageEditorFlipnRotate.cpp : implementation file
//

#include "stdafx.h"
#include "ImageEditor.h"
#include "ImageEditorFlipnRotate.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ImageEditorFlipnRotate dialog

ImageEditorFlipnRotate::ImageEditorFlipnRotate(CWnd *pParent /*=NULL*/)
	: CDialog(ImageEditorFlipnRotate::IDD, pParent)
{
	//{{AFX_DATA_INIT(ImageEditorFlipnRotate)
	m_Rotate_Type = -1;
	m_Flip_Type = -1;
	//}}AFX_DATA_INIT
}

void ImageEditorFlipnRotate::DoDataExchange(CDataExchange *pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ImageEditorFlipnRotate)
	DDX_Radio(pDX, IDC_RADIO4, m_Rotate_Type);
	DDX_Radio(pDX, IDC_RADIO1, m_Flip_Type);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(ImageEditorFlipnRotate, CDialog)
//{{AFX_MSG_MAP(ImageEditorFlipnRotate)
ON_BN_CLICKED(IDC_RADIO1, OnFlipHorizontal)
ON_BN_CLICKED(IDC_RADIO2, OnFlipVertical)
ON_BN_CLICKED(IDC_RADIO3, OnRotate)
ON_BN_CLICKED(IDC_RADIO4, OnRotate90)
ON_BN_CLICKED(IDC_RADIO5, OnRotate180)
ON_BN_CLICKED(IDC_RADIO6, OnRotate270)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ImageEditorFlipnRotate message handlers

void ImageEditorFlipnRotate::OnFlipHorizontal()
{
	// TODO: Add your control notification handler code here
	m_Flip_Type = 0;
}

void ImageEditorFlipnRotate::OnFlipVertical()
{
	// TODO: Add your control notification handler code here
	m_Flip_Type = 1;
}

void ImageEditorFlipnRotate::OnRotate()
{
	// TODO: Add your control notification handler code here
	m_Flip_Type = 2;
}

void ImageEditorFlipnRotate::OnRotate90()
{
	// TODO: Add your control notification handler code here
	m_Rotate_Type = 0;
}

void ImageEditorFlipnRotate::OnRotate180()
{
	m_Rotate_Type = 1;
	// TODO: Add your control notification handler code here
}

void ImageEditorFlipnRotate::OnRotate270()
{
	m_Rotate_Type = 2;
	// TODO: Add your control notification handler code here
}

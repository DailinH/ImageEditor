// ImageEditorFlipnRot.cpp : implementation file
//

#include "stdafx.h"
#include "ImageEditor.h"
#include "ImageEditorFlipnRot.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ImageEditorFlipnRot dialog


ImageEditorFlipnRot::ImageEditorFlipnRot(CWnd* pParent /*=NULL*/)
	: CDialog(ImageEditorFlipnRot::IDD, pParent)
{
	//{{AFX_DATA_INIT(ImageEditorFlipnRot)
	m_Flip_Type = -1;
	m_Rotate_Type = -1;
	//}}AFX_DATA_INIT
}


void ImageEditorFlipnRot::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ImageEditorFlipnRot)
	DDX_Radio(pDX, IDC_RADIO1, m_Flip_Type);
	DDX_Radio(pDX, IDC_RADIO4, m_Rotate_Type);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ImageEditorFlipnRot, CDialog)
	//{{AFX_MSG_MAP(ImageEditorFlipnRot)
	ON_BN_CLICKED(IDC_RADIO1, OnFlipH)
	ON_BN_CLICKED(IDC_RADIO2, OnFlipV)
	ON_BN_CLICKED(IDC_RADIO3, OnRotate)
	ON_BN_CLICKED(IDC_RADIO4, OnRotate90)
	ON_BN_CLICKED(IDC_RADIO5, OnRotate180)
	ON_BN_CLICKED(IDC_RADIO6, OnRotate270)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ImageEditorFlipnRot message handlers

void ImageEditorFlipnRot::OnFlipH() 
{
	// TODO: Add your control notification handler code here
m_Flip_Type = 1;	
}

void ImageEditorFlipnRot::OnFlipV() 
{
	// TODO: Add your control notification handler code here
	m_Flip_Type=2;
}

void ImageEditorFlipnRot::OnRotate() 
{
	// TODO: Add your control notification handler code here
	m_Flip_Type=3;
}

void ImageEditorFlipnRot::OnRotate90() 
{
	// TODO: Add your control notification handler code here
	m_Flip_Type=4;
}

void ImageEditorFlipnRot::OnRotate180() 
{
	// TODO: Add your control notification handler code here
	m_Flip_Type=5;
}

void ImageEditorFlipnRot::OnRotate270() 
{
	// TODO: Add your control notification handler code here
	m_Flip_Type=6;
}

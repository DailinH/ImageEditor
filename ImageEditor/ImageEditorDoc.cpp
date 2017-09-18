// ImageEditorDoc.cpp : implementation of the CImageEditorDoc class
//

#include "stdafx.h"
#include "ImageEditor.h"

#include "ImageEditorDoc.h"
#include "cv.h"
#include "highgui.h"
// using namespace cv;
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CImageEditorDoc

IMPLEMENT_DYNCREATE(CImageEditorDoc, CDocument)

BEGIN_MESSAGE_MAP(CImageEditorDoc, CDocument)
//{{AFX_MSG_MAP(CImageEditorDoc)
// NOTE - the ClassWizard will add and remove mapping macros here.
//    DO NOT EDIT what you see in these blocks of generated code!
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImageEditorDoc construction/destruction

CImageEditorDoc::CImageEditorDoc()
{
	// TODO: add one-time construction code here
	openImg = false;
	saveImg = false;
	getPathName = "";
}

CImageEditorDoc::~CImageEditorDoc()
{
}

BOOL CImageEditorDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	// m_img.
	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

BOOL CImageEditorDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	// TODO: add reinitialization code here
	if (lpszPathName != NULL)
	{
		pImg = cvLoadImage(lpszPathName, 1);
		m_img.CopyOf(pImg); //, IMAGE_CHANNELS);
		// m_img.Destroy();
	//	InvalidateRect(NULL, FALSE);

		// m_img.Load(lpszPathName, 1);
		openImg = true;
	}
	// (SDI documents will reuse this document)

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CImageEditorDoc serialization

void CImageEditorDoc::Serialize(CArchive &ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CImageEditorDoc diagnostics

#ifdef _DEBUG
void CImageEditorDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CImageEditorDoc::Dump(CDumpContext &dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CImageEditorDoc commands
// BOOL CImageEditorDoc::Save(LPCTSTR csFilename, IplImage *thisImg)
// {
// 	int bl;
// 	cvFlip(thisImg);					   //  恢复原 OpenCV 位图结构
// 	bl = cvSaveImage(csFilename, thisImg); //  图像存盘
// 	return (bl);
// }
BOOL CImageEditorDoc::DoSave(LPCTSTR lpszPathName, BOOL bReplace)
// BOOL CImageEditorDoc::onSaveDocument(LPCTSTR lpszPathName) //图像保存
{
	// MessageBox(NULL, "right!", "", MB_OK);
	// return true;
	CFileDialog dlg(false, "*.bmp", "Untitled.bmp", OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, "BMP(*.bmp)|*.bmp|PNG(*.png)|*.png|JPEG(*.jpg;*.jpeg;*.jpe;*.jfif)|*.jpg||");
	// CString strPath("");
	if (dlg.DoModal() == IDOK)
	{
		getPathName = dlg.GetPathName();
		saveImg = true;
		MessageBox(NULL, getPathName, "", MB_OK);
//		InvalidateRect(NULL, FALSE);
		return TRUE;
		// saveImg = pImg;
		// // pImg = m_img.GetImage();
		// cvFlip(saveImg);
		// cvSaveImage(dlg.GetPathName(), saveImg);
		// cvFlip(saveImg);
		// return TRUE;
		// CImageEditorDoc *pDoc = GetDocument();
		// CImage &tmpImg = pDoc->m_img;
		// pDoc->pImg = tmpImg.GetImage();
		// saveImg = pDoc->pImg;
		// cvFlip(saveImg);
		// cvSaveImage(dlg.GetPathName(), IplImg);
		// cvFlip(saveImg);
		//return TRUE;
	}
	return FALSE;
}
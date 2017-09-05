// ImageEditorDoc.cpp : implementation of the CImageEditorDoc class
//

#include "stdafx.h"
#include "ImageEditor.h"

#include "ImageEditorDoc.h"

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

}

CImageEditorDoc::~CImageEditorDoc()
{
}

BOOL CImageEditorDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CImageEditorDoc serialization

void CImageEditorDoc::Serialize(CArchive& ar)
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

void CImageEditorDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CImageEditorDoc commands

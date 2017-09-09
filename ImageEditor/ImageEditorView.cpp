// ImageEditorView.cpp : implementation of the CImageEditorView class
//

#include "stdafx.h"
#include "ImageEditor.h"

#include "ImageEditorDoc.h"
#include "ImageEditorView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CImageEditorView

IMPLEMENT_DYNCREATE(CImageEditorView, CView)

BEGIN_MESSAGE_MAP(CImageEditorView, CView)
//{{AFX_MSG_MAP(CImageEditorView)
	ON_COMMAND(ID_Pencil, OnPencil)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
// Standard printing commands
ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImageEditorView construction/destruction

CImageEditorView::CImageEditorView()
{
	m_type = 0;
//	m_Current_LBtnDn_Position_Last(0,0);
	// TODO: add construction code here
}

CImageEditorView::~CImageEditorView()
{
}

BOOL CImageEditorView::PreCreateWindow(CREATESTRUCT &cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CImageEditorView drawing

void CImageEditorView::OnDraw(CDC *pDC)
{
	CImageEditorDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if(m_type==1){
		CPoint point= pDoc->m_Current_LBtnDn_Position_Last;
		if(point.x ==0 && point.y == 0){
			point = pDoc->m_Current_LBtnDn_Position;
			pDoc->m_Current_LBtnDn_Position_Last=pDoc->m_Current_LBtnDn_Position;		
		}
		pDC->MoveTo(point);
		pDC->LineTo(pDoc->m_Current_LBtnDn_Position);
		pDoc->m_Current_LBtnDn_Position_Last=pDoc->m_Current_LBtnDn_Position;
	}

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CImageEditorView printing

BOOL CImageEditorView::OnPreparePrinting(CPrintInfo *pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CImageEditorView::OnBeginPrinting(CDC * /*pDC*/, CPrintInfo * /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CImageEditorView::OnEndPrinting(CDC * /*pDC*/, CPrintInfo * /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CImageEditorView diagnostics

#ifdef _DEBUG
void CImageEditorView::AssertValid() const
{
	CView::AssertValid();
}

void CImageEditorView::Dump(CDumpContext &dc) const
{
	CView::Dump(dc);
}

CImageEditorDoc *CImageEditorView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CImageEditorDoc)));
	return (CImageEditorDoc *)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CImageEditorView message handlers


void CImageEditorView::OnPencil() 
{
	m_type = 1;	
}

void CImageEditorView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CImageEditorDoc* pDoc = GetDocument();
	pDoc->m_Current_LBtnDn_Position=point;
	InvalidateRect(NULL,FALSE);
	CView::OnLButtonDown(nFlags, point);
}

// ImageEditorView.cpp : implementation of the CImageEditorView class
//

#include "stdafx.h"
#include "ImageEditor.h"

#include "ImageEditorDoc.h"
#include "ImageEditorView.h"
#include "ImageEditorColorPanel.h"

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
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_Select_Color, OnSelectColor)
	ON_COMMAND(ID_FILE_NEW, OnCreateNewFile)
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
	LBtnDn = false;
	ImgHeight = 500;
	ImgWidth = 500;
	
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
	///create new bitmap//////
	// CBitmap bmp;
	if (createNewFile.ResetMap == true){
		CRect rc_size;	
		GetClientRect(&rc_size);		
		if(createNewFile.m_New_Img_Horizontal && createNewFile.m_New_Img_Vertical){
			ImgHeight = (atoi(createNewFile.m_New_Img_Horizontal) < rc_size.right)?atoi(createNewFile.m_New_Img_Horizontal) : rc_size.right;
			ImgWidth = (atoi(createNewFile.m_New_Img_Vertical) < rc_size.bottom)?atoi(createNewFile.m_New_Img_Vertical) : rc_size.bottom;	
		}
		pDC->FillSolidRect(0,0,rc_size.right,rc_size.bottom,RGB(128,128,128));
		pDC->FillSolidRect(0,0,ImgWidth,ImgHeight,RGB(255,255,255));
		createNewFile.ResetMap = false;
		}
///////double buffer//////

	///////set color//////////
	int red = atoi(colorPanel.m_Color_Red);
	int green = atoi(colorPanel.m_Color_Green);	
	int blue = atoi(colorPanel.m_Color_Blue);
	int color = RGB(red,green,blue);

	///////set width//////////
	int width = 1;
	

	CPen newPen(PS_SOLID,width,color);
	
	if(m_type==1){
		CPoint point= pDoc->m_Last_Position;
		CPoint tgtPoint = pDoc->m_Current_Position;
		pDC->SelectObject(&newPen);
		if(point.x <= ImgWidth && point.y <= ImgHeight &&tgtPoint.x <= ImgWidth && tgtPoint.y <= ImgHeight ){
			pDC->MoveTo(point);			
			pDC->LineTo(tgtPoint);
		}
		pDoc->m_Last_Position=pDoc->m_Current_Position;
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
	LBtnDn = true;
	CImageEditorDoc* pDoc = GetDocument();

	pDoc->m_Last_LBtnDn_Position=point;
	pDoc->m_Last_Position = point;
	// InvalidateRect(NULL,FALSE);

	CView::OnLButtonDown(nFlags, point);
}

void CImageEditorView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	LBtnDn = false;
	CView::OnLButtonUp(nFlags, point);
}

void CImageEditorView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_type == 1){
		if(LBtnDn == true){
			CImageEditorDoc* pDoc = GetDocument();
			pDoc->m_Current_Position = point;
			InvalidateRect(NULL,FALSE);	
		}
	}
	
	CView::OnMouseMove(nFlags, point);
}

void CImageEditorView::OnSelectColor() 
{
	// TODO: Add your command handler code here
	colorPanel.DoModal();
//	CView::OnMouseMove(nFlags, point);
	
}

void CImageEditorView::OnCreateNewFile() 
{
	// TODO: Add your command handler code here
	createNewFile.DoModal();
	if(createNewFile.ResetMap==true)   
		InvalidateRect(NULL,FALSE);
	
}

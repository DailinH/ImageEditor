// ImageEditorView.cpp : implementation of the CImageEditorView class
//

#include "stdafx.h"
#include "ImageEditor.h"

#include "ImageEditorDoc.h"
#include "ImageEditorView.h"
#include "ImageEditorColorPanel.h"
#include "ImageEditorLineWidth.h"

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
	ON_COMMAND(LINE_STYLE_SOLID, OnStyleSolid)
	ON_COMMAND(LINE_STYLE_DASH, OnStyleDash)
	ON_COMMAND(LINE_STYLE_DOT, OnStyleDot)
	ON_COMMAND(LINE_STYLE_DASHDOT, OnStyleDashdot)
	ON_COMMAND(LINE_STYLE_DASHDOTDOT, OnStyleDashdotdot)
	ON_COMMAND(ID_MENUITEM32820, OnGetLineWidth)
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
	LineStyle =0;
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
	CRect rc_size;	
	GetClientRect(&rc_size);
	///////double buffer//////
	// CDC MemDC;
	// MemDC.CreateCompatibleDC(pDC);

	// CBitmap oldBitmap;
	// oldBitmap.CreateCompatibleBitmap(pDC,rc_size.Width(),rc_size.Height());

	// MemDC.SelectObject(&oldBitmap);
	// MemDC.FillSolidRect(0,0,rc_size.right,rc_size.bottom,RGB(128,128,128));
	// MemDC.FillSolidRect(0,0,ImgWidth,ImgHeight,RGB(255,255,255));

	///create new bitmap//////
	// if (createNewFile.ResetMap == true){
	// 	ImgHeight = (atoi(createNewFile.m_New_Img_Horizontal) < rc_size.right)?atoi(createNewFile.m_New_Img_Horizontal) : rc_size.right;
	// 	ImgWidth = (atoi(createNewFile.m_New_Img_Vertical) < rc_size.bottom)?atoi(createNewFile.m_New_Img_Vertical) : rc_size.bottom;	

	// 	MemDC.FillSolidRect(0,0,rc_size.right,rc_size.bottom,RGB(128,128,128));
	// 	MemDC.FillSolidRect(0,0,ImgWidth,ImgHeight,RGB(255,255,255));
	// 	createNewFile.ResetMap = false;
	// 	}
	
	if (createNewFile.ResetMap == true){
		ImgHeight = (atoi(createNewFile.m_New_Img_Horizontal) < rc_size.right)?atoi(createNewFile.m_New_Img_Horizontal) : rc_size.right;
		ImgWidth = (atoi(createNewFile.m_New_Img_Vertical) < rc_size.bottom)?atoi(createNewFile.m_New_Img_Vertical) : rc_size.bottom;	
		pDC->FillSolidRect(0,0,rc_size.right,rc_size.bottom,RGB(128,128,128));
		pDC->FillSolidRect(0,0,ImgWidth,ImgHeight,RGB(255,255,255));
		createNewFile.ResetMap = false;
		}

	///////set color//////////
	int red = atoi(colorPanel.m_Color_Red);
	int green = atoi(colorPanel.m_Color_Green);	
	int blue = atoi(colorPanel.m_Color_Blue);
	int color = RGB(red,green,blue);

	///////set width//////////
	int width = atoi(getLineWidth.m_Line_Width);
	if(width != 1)
	{
		
	}
	///////create pen/////////
	CPen newPen(LineStyle,width,color);
	if(m_type==1){
		CPoint point= pDoc->m_Last_Position;
		CPoint tgtPoint = pDoc->m_Current_Position;
		pDC->SelectObject(&newPen);
		// MemDC.SelectObject(&newPen);
		if(point.x <= ImgWidth && point.y <= ImgHeight &&tgtPoint.x <= ImgWidth && tgtPoint.y <= ImgHeight ){
			pDC->MoveTo(point);			
			pDC->LineTo(tgtPoint);
		}
		pDoc->m_Last_Position=pDoc->m_Current_Position;
	}
	newPen.DeleteObject();

	// pDC->BitBlt(rc_size.left,rc_size.top,rc_size.Width(),rc_size.Height(),&MemDC,0,0,SRCCOPY);
	// oldBitmap.DeleteObject();
	// MemDC.DeleteDC();
	return;
	
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

void CImageEditorView::OnStyleSolid() 
{
	// TODO: Add your command handler code here
	LineStyle = 0;
}

void CImageEditorView::OnStyleDash() 
{
	// TODO: Add your command handler code here
	LineStyle = 1;	
}

void CImageEditorView::OnStyleDot() 
{
	// TODO: Add your command handler code here
	LineStyle = 2;
}

void CImageEditorView::OnStyleDashdot() 
{
	// TODO: Add your command handler code here
	LineStyle = 3;	
}

void CImageEditorView::OnStyleDashdotdot() 
{
	// TODO: Add your command handler code here
	LineStyle = 4;
}

void CImageEditorView::OnGetLineWidth() 
{
	// TODO: Add your command handler code here
	getLineWidth.DoModal();
}

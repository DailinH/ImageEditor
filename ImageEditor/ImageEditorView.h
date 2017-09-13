// ImageEditorView.h : interface of the CImageEditorView class
//
//////////////////////////////////////// / ////////////////////////////////////

#if !defined(AFX_IMAGEEDITORVIEW_H__06CE64C1_5033_44B5_9189_F099CDE5A07F__INCLUDED_)
#define AFX_IMAGEEDITORVIEW_H__06CE64C1_5033_44B5_9189_F099CDE5A07F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ImageEditorColorPanel.h"
#include "ImageEditorNewFile.h"
#include "ImageEditorLineWidth.h"
class CImageEditorView : public CView
{
protected: // create from serialization only
	CImageEditorView();
	DECLARE_DYNCREATE(CImageEditorView)

// Attributes
public:
	CImageEditorDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImageEditorView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	bool LBtnDn;
	int ImgHeight;
	int ImgWidth;
	ImageEditorColorPanel colorPanel;
	ImageEditorNewFile createNewFile;
	ImageEditorLineWidth getLineWidth;
	int m_type;
/*
	brief notes:
		define m_type:
		1	pencil (default)
		2	line
		3	curve
		4	text
		5	rectangle
		6	outlined rectangle
		7	filled rectangle
		8	round rectangle
		9	outlined round rectangle
		10	filled round rectangle
		11	ellipse
		12	round ellipse
		13	filled ellipse
*/
	int LineStyle;
	virtual ~CImageEditorView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CImageEditorView)
	afx_msg void OnPencil();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnSelectColor();
	afx_msg void OnCreateNewFile();
	afx_msg void OnStyleSolid();
	afx_msg void OnStyleDash();
	afx_msg void OnStyleDot();
	afx_msg void OnStyleDashdot();
	afx_msg void OnStyleDashdotdot();
	afx_msg void OnGetLineWidth();
	afx_msg void OnCurve();
	afx_msg void OnText();
	afx_msg void OnLine();
	afx_msg void OnRectangle();
	afx_msg void OnOutlinedRectangle();
	afx_msg void OnFilledRectangle();
	afx_msg void OnRoundRectangle();
	afx_msg void OnOutlinedRoundRectangle();
	afx_msg void OnFilledRoundRectangle();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ImageEditorView.cpp
inline CImageEditorDoc* CImageEditorView::GetDocument()
   { return (CImageEditorDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGEEDITORVIEW_H__06CE64C1_5033_44B5_9189_F099CDE5A07F__INCLUDED_)

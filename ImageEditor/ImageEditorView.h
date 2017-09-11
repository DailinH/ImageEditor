// ImageEditorView.h : interface of the CImageEditorView class
//
//////////////////////////////////////// / ////////////////////////////////////

#if !defined(AFX_IMAGEEDITORVIEW_H__06CE64C1_5033_44B5_9189_F099CDE5A07F__INCLUDED_)
#define AFX_IMAGEEDITORVIEW_H__06CE64C1_5033_44B5_9189_F099CDE5A07F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ImageEditorColorPanel.h"

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
	int m_type;
	bool LBtnDn;
	ImageEditorColorPanel colorPanel;	
/*
	brief notes:
		define m_type:
		0	default
		1	pencil 
*/
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

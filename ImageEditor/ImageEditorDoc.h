// ImageEditorDoc.h : interface of the CImageEditorDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_IMAGEEDITORDOC_H__2A0650CF_4029_4E04_9971_42A1EDBE5715__INCLUDED_)
#define AFX_IMAGEEDITORDOC_H__2A0650CF_4029_4E04_9971_42A1EDBE5715__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CImageEditorDoc : public CDocument
{
protected: // create from serialization only
	CImageEditorDoc();
	DECLARE_DYNCREATE(CImageEditorDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImageEditorDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	CPoint m_Current_Position;
	CPoint m_Last_Position;
	CPoint m_Last_LBtnDn_Position;
	CBitmap Bmp_Buff;
	
	virtual ~CImageEditorDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CImageEditorDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGEEDITORDOC_H__2A0650CF_4029_4E04_9971_42A1EDBE5715__INCLUDED_)

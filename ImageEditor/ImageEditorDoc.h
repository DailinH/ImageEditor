// ImageEditorDoc.h : interface of the CImageEditorDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_IMAGEEDITORDOC_H__2A0650CF_4029_4E04_9971_42A1EDBE5715__INCLUDED_)
#define AFX_IMAGEEDITORDOC_H__2A0650CF_4029_4E04_9971_42A1EDBE5715__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "cv.h"
#include "highgui.h"

class CImageEditorDoc : public CDocument
{
protected: // create from serialization only
	CImageEditorDoc();
	DECLARE_DYNCREATE(CImageEditorDoc)

	// Attributes
public:
	CImage m_img;
	IplImage *pImg;
	BOOL newImg;
	BOOL openImg;
	BOOL saveImg;
	BOOL saveStatus;
	CString getPathName;
	// CFileDialog *dlg;
	//IplImage *saveImg;

	// Operations
public:
	// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImageEditorDoc)
public:
	virtual BOOL OnNewDocument();
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	// virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual void Serialize(CArchive &ar);
	// BOOL Save(LPCTSTR csFilename, IplImage *thisImg);
	// virtual BOOL onSaveDocument(LPCTSTR lpszPathName); //图像保存
	virtual BOOL DoSave(LPCTSTR lpszPathName, BOOL bReplace);

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
	virtual void Dump(CDumpContext &dc) const;
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

#if !defined(AFX_IMAGEEDITORNEWFILE_H__347C76EE_A996_425B_A0DA_604E9A74BEB3__INCLUDED_)
#define AFX_IMAGEEDITORNEWFILE_H__347C76EE_A996_425B_A0DA_604E9A74BEB3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ImageEditorNewFile.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ImageEditorNewFile dialog

class ImageEditorNewFile : public CDialog
{
// Construction
public:
	ImageEditorNewFile(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ImageEditorNewFile)
	enum { IDD = IDD_DIALOG2 };
	CString	m_New_Img_Horizontal;
	CString	m_New_Img_Vertical;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ImageEditorNewFile)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ImageEditorNewFile)
	afx_msg void OnCreateNewFile();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGEEDITORNEWFILE_H__347C76EE_A996_425B_A0DA_604E9A74BEB3__INCLUDED_)

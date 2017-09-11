#if !defined(AFX_IMAGEEDITORLINEWIDTH_H__B1FEDFD4_A16F_4D96_B77D_AD9308BC62D2__INCLUDED_)
#define AFX_IMAGEEDITORLINEWIDTH_H__B1FEDFD4_A16F_4D96_B77D_AD9308BC62D2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ImageEditorLineWidth.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ImageEditorLineWidth dialog

class ImageEditorLineWidth : public CDialog
{
// Construction
public:
	ImageEditorLineWidth(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ImageEditorLineWidth)
	enum { IDD = IDD_DIALOG3 };
	CString	m_Line_Width;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ImageEditorLineWidth)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ImageEditorLineWidth)
	afx_msg void OnSetLineWidth();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGEEDITORLINEWIDTH_H__B1FEDFD4_A16F_4D96_B77D_AD9308BC62D2__INCLUDED_)

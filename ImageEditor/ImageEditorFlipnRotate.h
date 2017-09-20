#if !defined(AFX_IMAGEEDITORFLIPNROTATE_H__36B9EB2D_E758_4A5F_ACC4_8482E67C749B__INCLUDED_)
#define AFX_IMAGEEDITORFLIPNROTATE_H__36B9EB2D_E758_4A5F_ACC4_8482E67C749B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ImageEditorFlipnRotate.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ImageEditorFlipnRotate dialog

class ImageEditorFlipnRotate : public CDialog
{
// Construction
public:
	ImageEditorFlipnRotate(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ImageEditorFlipnRotate)
	enum { IDD = IDD_DIALOG4 };
	int		m_Rotate_Type;
	int		m_Flip_Type;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ImageEditorFlipnRotate)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ImageEditorFlipnRotate)
	afx_msg void OnFlipHorizontal();
	afx_msg void OnFlipVertical();
	afx_msg void OnRotate();
	afx_msg void OnRotate90();
	afx_msg void OnRotate180();
	afx_msg void OnRotate270();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGEEDITORFLIPNROTATE_H__36B9EB2D_E758_4A5F_ACC4_8482E67C749B__INCLUDED_)

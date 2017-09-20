#if !defined(AFX_IMAGEEDITORFLIPNROT_H__6033BE0B_D30B_4260_9235_F33127946A80__INCLUDED_)
#define AFX_IMAGEEDITORFLIPNROT_H__6033BE0B_D30B_4260_9235_F33127946A80__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ImageEditorFlipnRot.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ImageEditorFlipnRot dialog

class ImageEditorFlipnRot : public CDialog
{
// Construction
public:
	ImageEditorFlipnRot(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ImageEditorFlipnRot)
	enum { IDD = IDD_DIALOG4 };
	int		m_Flip_Type;
	int		m_Rotate_Type;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ImageEditorFlipnRot)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ImageEditorFlipnRot)
	afx_msg void OnFlipH();
	afx_msg void OnFlipV();
	afx_msg void OnRotate();
	afx_msg void OnRotate90();
	afx_msg void OnRotate180();
	afx_msg void OnRotate270();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGEEDITORFLIPNROT_H__6033BE0B_D30B_4260_9235_F33127946A80__INCLUDED_)

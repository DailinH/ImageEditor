#if !defined(AFX_IMAGEEDITORZOOM_H__15754320_107B_4DEC_AC07_8237D71B98D5__INCLUDED_)
#define AFX_IMAGEEDITORZOOM_H__15754320_107B_4DEC_AC07_8237D71B98D5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ImageEditorZoom.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ImageEditorZoom dialog

class ImageEditorZoom : public CDialog
{
// Construction
public:
	ImageEditorZoom(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ImageEditorZoom)
	enum { IDD = IDD_DIALOG5 };
	CString	m_Zoom_Horizontal;
	CString	m_Zoom_Vertical;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ImageEditorZoom)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ImageEditorZoom)
	afx_msg void OnZoom();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGEEDITORZOOM_H__15754320_107B_4DEC_AC07_8237D71B98D5__INCLUDED_)

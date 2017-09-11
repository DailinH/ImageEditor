#if !defined(AFX_IMAGEEDITORCOLORPANEL_H__DC9650F8_2FAF_4321_86EB_FDD1BFE18127__INCLUDED_)
#define AFX_IMAGEEDITORCOLORPANEL_H__DC9650F8_2FAF_4321_86EB_FDD1BFE18127__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ImageEditorColorPanel.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ImageEditorColorPanel dialog

class ImageEditorColorPanel : public CDialog
{
// Construction
public:
	ImageEditorColorPanel(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ImageEditorColorPanel)
	enum { IDD = IDD_DIALOG1 };
	CString	m_Color_Red;
	CString	m_Color_Green;
	CString	m_Color_Blue;
//	bool ModifyColor;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ImageEditorColorPanel)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ImageEditorColorPanel)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGEEDITORCOLORPANEL_H__DC9650F8_2FAF_4321_86EB_FDD1BFE18127__INCLUDED_)

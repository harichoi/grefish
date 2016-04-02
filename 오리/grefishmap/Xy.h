#if !defined(AFX_XY_H__0BD79FA5_9078_4F75_AD12_98BC8875C188__INCLUDED_)
#define AFX_XY_H__0BD79FA5_9078_4F75_AD12_98BC8875C188__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Xy.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CXy dialog

class CXy : public CDialog
{
// Construction
public:
	CXy(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CXy)
	enum { IDD = IDD_DIALOG1 };
	int		m_x;
	int		m_y;
	int		m_z;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CXy)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CXy)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XY_H__0BD79FA5_9078_4F75_AD12_98BC8875C188__INCLUDED_)

#if !defined(AFX_DELEF_H__D139A8F4_950E_49A3_BE41_85135B1FDABC__INCLUDED_)
#define AFX_DELEF_H__D139A8F4_950E_49A3_BE41_85135B1FDABC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// delef.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// delef dialog

class delef : public CDialog
{
// Construction
public:
	delef(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(delef)
	enum { IDD = IDD_DELETEEFFECT };
	int		m_num;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(delef)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(delef)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DELEF_H__D139A8F4_950E_49A3_BE41_85135B1FDABC__INCLUDED_)

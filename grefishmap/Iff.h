#if !defined(AFX_IFF_H__95091D17_F529_44DC_808F_E092971C59B1__INCLUDED_)
#define AFX_IFF_H__95091D17_F529_44DC_808F_E092971C59B1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Iff.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CIff dialog

class CIff : public CDialog
{
// Construction
public:
	CIff(CWnd* pParent = NULL);   // standard constructor
	IFF ifmaking;
	MOTION motmaking;

// Dialog Data
	//{{AFX_DATA(CIff)
	enum { IDD = IDD_IFF };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIff)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CIff)
	afx_msg void OnButton1();
	afx_msg void OnButton4();
	afx_msg void OnButton8();
	afx_msg void OnButton12();
	afx_msg void OnButton2();
	afx_msg void OnButton6();
	afx_msg void OnButton7();
	afx_msg void OnButton3();
	afx_msg void OnButton9();
	afx_msg void OnButton5();
	afx_msg void OnButton11();
	afx_msg void OnButton10();
	afx_msg void OnButton13();
	afx_msg void OnButton14();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IFF_H__95091D17_F529_44DC_808F_E092971C59B1__INCLUDED_)

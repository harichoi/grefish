#if !defined(AFX_EXPLAIN_H__A2405FF8_F395_4C89_993D_C6703D09D603__INCLUDED_)
#define AFX_EXPLAIN_H__A2405FF8_F395_4C89_993D_C6703D09D603__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Explain.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CExplain dialog

class CExplain : public CDialog
{
// Construction
public:
	CExplain(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CExplain)
	enum { IDD = IDD_EXPLAIN };
	CString	m_1;
	CString	m_2;
	CString	m_3;
	CString	m_4;
	CString	m_5;
	CString	m_6;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExplain)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CExplain)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXPLAIN_H__A2405FF8_F395_4C89_993D_C6703D09D603__INCLUDED_)

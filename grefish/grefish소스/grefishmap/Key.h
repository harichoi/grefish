#if !defined(AFX_KEY_H__0BA09318_BF30_4342_8074_AEB10DF606CC__INCLUDED_)
#define AFX_KEY_H__0BA09318_BF30_4342_8074_AEB10DF606CC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Key.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CKey dialog

class CKey : public CDialog
{
// Construction
public:
	CKey(CWnd* pParent = NULL);   // standard constructor
	int m_key;

// Dialog Data
	//{{AFX_DATA(CKey)
	enum { IDD = IDD_KKey };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKey)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CKey)
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KEY_H__0BA09318_BF30_4342_8074_AEB10DF606CC__INCLUDED_)

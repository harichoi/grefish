#if !defined(AFX_SETT_H__C195093D_BBCE_4D07_ACFB_23A2E5339047__INCLUDED_)
#define AFX_SETT_H__C195093D_BBCE_4D07_ACFB_23A2E5339047__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Sett.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSett dialog

class CSett : public CDialog
{
// Construction
public:
	CSett(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSett)
	enum { IDD = IDD_SET };
	int		m_x;
	int		m_y;
	int		m_imgnumber;
	int		m_xsize;
	int		m_ysize;
	int		m_imgy;
	int		m_imgx;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSett)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSett)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETT_H__C195093D_BBCE_4D07_ACFB_23A2E5339047__INCLUDED_)

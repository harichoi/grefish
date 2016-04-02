// grefishmapDlg.h : header file
//

#if !defined(AFX_GREFISHMAPDLG_H__49B8091C_0D72_4D0C_B077_8F734F97CAE3__INCLUDED_)
#define AFX_GREFISHMAPDLG_H__49B8091C_0D72_4D0C_B077_8F734F97CAE3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGrefishmapDlg dialog

class CGrefishmapDlg : public CDialog
{
// Construction
public:
	CGrefishmapDlg(CWnd* pParent = NULL);	// standard constructor
	void print();
// Dialog Data
	//{{AFX_DATA(CGrefishmapDlg)
	enum { IDD = IDD_GREFISHMAP_DIALOG };
	CString	m_result;
	int		m_number;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGrefishmapDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGrefishmapDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	afx_msg void OnButton5();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnButton6();
	afx_msg void OnButton7();
	afx_msg void OnButton8();
	afx_msg void OnButton9();
	afx_msg void OnButton11();
	afx_msg void OnButton12();
	afx_msg void OnButton13();
	afx_msg void OnButton14();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnButton10();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnButton15();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GREFISHMAPDLG_H__49B8091C_0D72_4D0C_B077_8F734F97CAE3__INCLUDED_)

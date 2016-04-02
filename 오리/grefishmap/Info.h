#if !defined(AFX_INFO_H__0E811F07_9844_461E_B02F_1FE662703DDC__INCLUDED_)
#define AFX_INFO_H__0E811F07_9844_461E_B02F_1FE662703DDC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Info.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CInfo dialog

class CInfo : public CDialog
{
// Construction
public:
	CInfo(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CInfo)
	enum { IDD = IDD_INFO };
	CString	m_px;
	CString	m_aaay;
	CString	m_py;
	CString	m_pvx;
	CString	m_pvy;
	CString	m_mx;
	CString	m_my;
	CString	m_mvx;
	CString	m_mvy;
	CString	m_aaax;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInfo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CInfo)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INFO_H__0E811F07_9844_461E_B02F_1FE662703DDC__INCLUDED_)

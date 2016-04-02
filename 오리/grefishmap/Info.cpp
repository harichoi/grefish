// Info.cpp : implementation file
//

#include "stdafx.h"
#include "grefishmap.h"
#include "Info.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInfo dialog


CInfo::CInfo(CWnd* pParent /*=NULL*/)
	: CDialog(CInfo::IDD, pParent)
{
	//{{AFX_DATA_INIT(CInfo)
	m_px = _T("0");
	m_aaay = _T("0");
	m_py = _T("0");
	m_pvx = _T("0");
	m_pvy = _T("0");
	m_mx = _T("0");
	m_my = _T("0");
	m_mvx = _T("0");
	m_mvy = _T("0");
	m_aaax = _T("0");
	//}}AFX_DATA_INIT
}


void CInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CInfo)
	DDX_Text(pDX, IDC_EDIT1, m_px);
	DDX_Text(pDX, IDC_EDIT10, m_aaay);
	DDX_Text(pDX, IDC_EDIT2, m_py);
	DDX_Text(pDX, IDC_EDIT3, m_pvx);
	DDX_Text(pDX, IDC_EDIT4, m_pvy);
	DDX_Text(pDX, IDC_EDIT5, m_mx);
	DDX_Text(pDX, IDC_EDIT6, m_my);
	DDX_Text(pDX, IDC_EDIT7, m_mvx);
	DDX_Text(pDX, IDC_EDIT8, m_mvy);
	DDX_Text(pDX, IDC_EDIT9, m_aaax);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CInfo, CDialog)
	//{{AFX_MSG_MAP(CInfo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInfo message handlers

void CInfo::OnOK() 
{
	// TODO: Add extra validation here

	CDialog::OnOK();
}

// Explain.cpp : implementation file
//

#include "stdafx.h"
#include "grefishmap.h"
#include "Explain.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExplain dialog


CExplain::CExplain(CWnd* pParent /*=NULL*/)
	: CDialog(CExplain::IDD, pParent)
{
	//{{AFX_DATA_INIT(CExplain)
	m_1 = _T("");
	m_2 = _T("");
	m_3 = _T("");
	m_4 = _T("");
	m_5 = _T("");
	m_6 = _T("");
	//}}AFX_DATA_INIT
}


void CExplain::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CExplain)
	DDX_Text(pDX, IDC_EDIT1, m_1);
	DDX_Text(pDX, IDC_EDIT2, m_2);
	DDX_Text(pDX, IDC_EDIT3, m_3);
	DDX_Text(pDX, IDC_EDIT4, m_4);
	DDX_Text(pDX, IDC_EDIT5, m_5);
	DDX_Text(pDX, IDC_EDIT6, m_6);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CExplain, CDialog)
	//{{AFX_MSG_MAP(CExplain)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExplain message handlers

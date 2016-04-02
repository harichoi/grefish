// Xy.cpp : implementation file
//

#include "stdafx.h"
#include "grefishmap.h"
#include "Xy.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CXy dialog


CXy::CXy(CWnd* pParent /*=NULL*/)
	: CDialog(CXy::IDD, pParent)
{
	//{{AFX_DATA_INIT(CXy)
	m_x = 0;
	m_y = 0;
	m_z = 0;
	//}}AFX_DATA_INIT
}


void CXy::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CXy)
	DDX_Text(pDX, IDC_EDIT1, m_x);
	DDX_Text(pDX, IDC_EDIT2, m_y);
	DDX_Text(pDX, IDC_EDIT3, m_z);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CXy, CDialog)
	//{{AFX_MSG_MAP(CXy)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CXy message handlers

void CXy::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}

// delef.cpp : implementation file
//

#include "stdafx.h"
#include "grefishmap.h"
#include "delef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// delef dialog


delef::delef(CWnd* pParent /*=NULL*/)
	: CDialog(delef::IDD, pParent)
{
	//{{AFX_DATA_INIT(delef)
	m_num = 0;
	//}}AFX_DATA_INIT
}


void delef::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(delef)
	DDX_Text(pDX, IDC_EDIT1, m_num);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(delef, CDialog)
	//{{AFX_MSG_MAP(delef)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// delef message handlers

void delef::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	CDialog::OnOK();
}

// Sett.cpp : implementation file
//

#include "stdafx.h"
#include "grefishmap.h"
#include "Sett.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSett dialog


CSett::CSett(CWnd* pParent /*=NULL*/)
	: CDialog(CSett::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSett)
	m_x = 0;
	m_y = 0;
	m_imgnumber = 0;
	m_xsize = 0;
	m_ysize = 0;
	m_imgy = 0;
	m_imgx = 0;
	//}}AFX_DATA_INIT
}


void CSett::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSett)
	DDX_Text(pDX, IDC_EDIT1, m_x);
	DDX_Text(pDX, IDC_EDIT2, m_y);
	DDX_Text(pDX, IDC_EDIT4, m_imgnumber);
	DDX_Text(pDX, IDC_EDIT5, m_xsize);
	DDX_Text(pDX, IDC_EDIT6, m_ysize);
	DDX_Text(pDX, IDC_EDIT8, m_imgy);
	DDX_Text(pDX, IDC_EDIT7, m_imgx);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSett, CDialog)
	//{{AFX_MSG_MAP(CSett)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSett message handlers

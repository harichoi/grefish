// Key.cpp : implementation file
//

#include "stdafx.h"
#include "grefishmap.h"
#include "Key.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CKey dialog


CKey::CKey(CWnd* pParent /*=NULL*/)
	: CDialog(CKey::IDD, pParent)
{
	//{{AFX_DATA_INIT(CKey)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CKey::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CKey)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CKey, CDialog)
	//{{AFX_MSG_MAP(CKey)
	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKey message handlers

void CKey::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	m_key=nChar;
	EndDialog(0);
	//MessageBox("aa");
	//this->SendMessage(WM_CLO
	CDialog::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CKey::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	//m_key=nChar;
	//MessageBox("aa");
	CDialog::OnKeyUp(nChar, nRepCnt, nFlags);
}

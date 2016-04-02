// Iff.cpp : implementation file
//

#include "stdafx.h"
#include "grefishmap.h"
#include "eff.h"
#include "Iff.h"
#include "delef.h"
#include "info.h"
#include "xy.h"
#include "key.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CIff dialog


CIff::CIff(CWnd* pParent /*=NULL*/)
	: CDialog(CIff::IDD, pParent)
{
	//{{AFX_DATA_INIT(CIff)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CIff::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CIff)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CIff, CDialog)
	//{{AFX_MSG_MAP(CIff)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON8, OnButton8)
	ON_BN_CLICKED(IDC_BUTTON12, OnButton12)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton7)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON9, OnButton9)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON11, OnButton11)
	ON_BN_CLICKED(IDC_BUTTON10, OnButton10)
	ON_BN_CLICKED(IDC_BUTTON13, OnButton13)
	ON_BN_CLICKED(IDC_BUTTON14, OnButton14)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIff message handlers

void CIff::OnButton1() 
{
	// TODO: Add your control notification handler code here
	MessageBox("항상");
	ifmaking.what=0;
}

void CIff::OnButton4() 
{
	// TODO: Add your control notification handler code here
	MessageBox("동등조건");
	ifmaking.what=4;
}

void CIff::OnButton8() 
{
	// TODO: Add your control notification handler code here
	MessageBox("죽어라");
	motmaking.what=3;
}

void CIff::OnButton12() 
{
	// TODO: Add your control notification handler code here
	MessageBox("숨겨라");
	motmaking.ex=1;
	motmaking.ey=1000;
	motmaking.what=1;
}

void CIff::OnButton2() 
{
	// TODO: Add your control notification handler code here
	delef a;
	a.DoModal();
	ifmaking.what=2;
	ifmaking.effecthit=5;
	ifmaking.whichblock=a.m_num;
	MessageBox("충돌할때");
}

void CIff::OnButton6() 
{
	// TODO: Add your control notification handler code here
	CInfo a;
	a.DoModal();
	motmaking.what=1;
	motmaking.px=atof(a.m_px);
	motmaking.py=atof(a.m_py);
	motmaking.pvx=atof(a.m_pvx);
	motmaking.pvy=atof(a.m_pvy);
	motmaking.ax=atof(a.m_mx);
	motmaking.ay=atof(a.m_my);
	motmaking.avx=atof(a.m_mvx);
	motmaking.avy=atof(a.m_mvy);
	MessageBox("움직여라");
}

void CIff::OnButton7() 
{
	// TODO: Add your control notification handler code here
	CInfo a;
	a.DoModal();
	motmaking.what=1;
	motmaking.ex=atof(a.m_px);
	motmaking.ey=atof(a.m_py);
	motmaking.evx=atof(a.m_pvx);
	motmaking.evy=atof(a.m_pvy);
	motmaking.aex=atof(a.m_mx);
	motmaking.aey=atof(a.m_my);
	motmaking.aevx=atof(a.m_mvx);
	motmaking.aevy=atof(a.m_mvy);
	motmaking.aavx=atof(a.m_aaax);
	motmaking.aavy=atof(a.m_aaay);
	MessageBox("움직여라");
}

void CIff::OnButton3() 
{
	// TODO: Add your control notification handler code here
	delef a;
	a.DoModal();
	ifmaking.what=3;
	ifmaking.ff=a.m_num;
	MessageBox("신호를 받으면");
}

void CIff::OnButton9() 
{
	// TODO: Add your control notification handler code here
	delef a;
	a.DoModal();
	motmaking.what=2;
	motmaking.ff=a.m_num;
	MessageBox("신호를 보내라");
}

void CIff::OnButton5() 
{
	// TODO: Add your control notification handler code here
	
	ifmaking.what=5;
	MessageBox("이것이 캐릭터와 충돌하면");
}

void CIff::OnButton11() 
{
	// TODO: Add your control notification handler code here
	delef a;
	a.DoModal();
	motmaking.what=5;
	motmaking.ff=a.m_num;
	MessageBox("지나게 하라.");
}

void CIff::OnButton10() 
{
	// TODO: Add your control notification handler code here
	CXy xy;
	xy.DoModal();
	motmaking.what=4;
	motmaking.px=xy.m_x;
	motmaking.py=xy.m_y;
	motmaking.ff=xy.m_z;
	MessageBox("바꿔라");
}

void CIff::OnButton13() 
{
	// TODO: Add your control notification handler code here
	motmaking.what=6;
	MessageBox("방향반대");
}

void CIff::OnButton14() 
{
	// TODO: Add your control notification handler code here
	CKey a;
	a.DoModal();
	ifmaking.what=6;
	ifmaking.ff=a.m_key;
	MessageBox("키를 입력하면");
}

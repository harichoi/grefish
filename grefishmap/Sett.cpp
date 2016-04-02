// Sett.cpp : implementation file
//

#include "stdafx.h"
#include "grefishmap.h"
#include "eff.h"
#include "Sett.h"
#include "iff.h"
#include "delef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

MOTION clrmott;
IFF clrift;

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
	m_svx = 0.0;
	m_svy = 0.0;
	m_result = _T("");
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
	DDX_Text(pDX, IDC_EDIT3, m_svx);
	DDX_Text(pDX, IDC_EDIT9, m_svy);
	DDX_Text(pDX, IDC_EDIT10, m_result);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSett, CDialog)
	//{{AFX_MSG_MAP(CSett)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSett message handlers

void CSett::OnButton1() 
{
	// TODO: Add your control notification handler code here
	CIff a;
	a.ifmaking=clrift;
	a.motmaking=clrmott;
	a.DoModal();
	
	eft.ifn++;
	eft.iff[eft.ifn]=a.ifmaking;
	eft.mot[eft.ifn]=a.motmaking;
	prints();
}

void CSett::OnButton2() 
{
	// TODO: Add your control notification handler code here
	
	delef b;
	if(b.DoModal()){
		CIff a;
		a.ifmaking=eft.iff[b.m_num];
		a.motmaking=eft.mot[b.m_num];
		a.DoModal();
		
		eft.iff[b.m_num]=a.ifmaking;
		eft.mot[b.m_num]=a.motmaking;
		prints();
	}
}

void CSett::OnButton3() 
{
	// TODO: Add your control notification handler code here
	int i;
	delef a;
	if(a.DoModal()){
	
	eft.iff[a.m_num].what=0;
	eft.mot[a.m_num].what=0;
	for(i=a.m_num ; i<=eft.ifn ; i++)
	{
		eft.iff[i]=eft.iff[i+1];
		eft.mot[i]=eft.mot[i+1];
	}
	eft.ifn--;
	}
	prints();
}

void CSett::prints()
{
	char str[10000];
	UpdateData(TRUE);

	int i, j;
	for(i=1 ; i<10000 ; i++)
		str[i]=0;
	FILE *out=fopen("prints.txt","w");
	{
		fprintf(out,"[[%d번 효과]]\r\n",number);
		EFFECT temp=eft;
			
		for(j=1 ; j<=eft.ifn ; j++)
		{
			fprintf(out,"%d. ",j);
			switch(temp.iff[j].what)
			{
			case 0:
				fprintf(out,"항상,\r\n");
				break;
			case 1:
				fprintf(out,"충돌시,\r\n");
					break;
			case 2:
				fprintf(out,"이것이 %d번 블럭과 %d 방향으로 충돌했을때,\r\n",temp.iff[j].whichblock,temp.iff[j].hit);
				break;
			case 3:
				fprintf(out,"%d번 신호를 받았을때,\r\n",temp.iff[j].ff);
				break;
			case 4:
				fprintf(out,"위와 똑같은 조건으로,\r\n");
				break;
			case 5:
				fprintf(out,"캐릭터가 이것과 충돌할때,\r\n");
				break;
			case 6:
				fprintf(out,"0x%d%d키를 입력하면,\r\n",temp.iff[j].ff/16,temp.iff[j].ff%16);
				break;
			};
			switch(temp.mot[j].what)
			{
			case 1:
				fprintf(out,"캐릭터 또는 이것이 움직이게 한다\r\n");
				break;
			case 2:
				fprintf(out,"%d번 신호를 보낸다.\r\n",temp.mot[j].ff);
				break;
			case 3:
				fprintf(out,"죽는다.\r\n");
				break;
			case 4:
				fprintf(out,"(%.0lf,%.0lf)의 블럭을 %d 블럭으로 바꾼다.\r\n",temp.mot[j].px,temp.mot[j].py,temp.mot[j].ff);
				break;
			case 5:
				fprintf(out,"%d 만큼의 시간이 지난후에 이것이 실행된다.\r\n",temp.mot[j].ff);
				break;
			case 6:
				fprintf(out,"방향을 바꾼다\r\n");
			};
		}
	}
	fclose(out);
	out=fopen("prints.txt","r");
	while(!feof(out))
	{
		fread(str,sizeof(char),10000,out);
	}
	m_result.Format("%s",str);
	fclose(out);
	
	
	UpdateData(FALSE);
	/*for(i=1 ; i<1000 ; i++)
	{
		if(effect[i].
	}*/
}

void CSett::OnButton4() 
{
	// TODO: Add your control notification handler code here
	eft.exist=0;
}

BOOL CSett::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	prints();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

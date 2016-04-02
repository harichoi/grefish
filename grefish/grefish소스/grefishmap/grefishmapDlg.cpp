// grefishmapDlg.cpp : implementation file
//

#include "stdafx.h"
#include "grefishmap.h"
#include "grefishmapDlg.h"
#include "delef.h"
#include "sett.h"
#include "eff.h"
#include "iff.h"
#include "explain.h"

#define hWnd this
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


#define GRAV 2
#define GROUND 1
#define DIE 3
#define SKY 0
#define WHAT 4
#define BLOD 5
#define HIGH 6
#define FLAG 7
#define NOGRAV 9
#define DOWNUP 8
#define GASI 51
#define TREE 50
#define RANGE 5
#define BACK 52
#define CHA 53
#define BREAK 55
#define CSX 7
#define CSY 7

#define NO 999999

#define ALL 0
#define FAST 1
#define XSIZE (30*18)
#define YSIZE (30*16)
#define HIDEX 1
#define HIDEY 1000
#define MEX 9890
#define MEY 9895




CBitmap blockbit[101];
//HBITMAP blockbit[100];
double x, y;
int bx, by, gx=1, gy=1, fflag;
int dietime;
double vx, vy;
EFFECTNUMBER efn[100][100];

int allmap[1000][1000];

int lll;
int nef;
EFFECT ef[100];
EFFECT effect[1000];
int numef[100];
int keybd[256];
int bgx;
int bgy;
int bbx;
int bby;
int chooseblock;
double ggx, ggy, agx, agy;
int life=2;
MOTION clrmot;
IFF clrif;
char explain[100][100][100];
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGrefishmapDlg dialog

CGrefishmapDlg::CGrefishmapDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGrefishmapDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGrefishmapDlg)
	m_result = _T("");
	m_number = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32

	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGrefishmapDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGrefishmapDlg)
	DDX_Text(pDX, IDC_EDIT1, m_result);
	DDX_Text(pDX, IDC_EDIT2, m_number);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CGrefishmapDlg, CDialog)
	//{{AFX_MSG_MAP(CGrefishmapDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_WM_LBUTTONUP()
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton7)
	ON_BN_CLICKED(IDC_BUTTON8, OnButton8)
	ON_BN_CLICKED(IDC_BUTTON9, OnButton9)
	ON_BN_CLICKED(IDC_BUTTON11, OnButton11)
	ON_BN_CLICKED(IDC_BUTTON12, OnButton12)
	ON_BN_CLICKED(IDC_BUTTON13, OnButton13)
	ON_BN_CLICKED(IDC_BUTTON14, OnButton14)
	ON_WM_RBUTTONDOWN()
	ON_BN_CLICKED(IDC_BUTTON10, OnButton10)
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_BUTTON15, OnButton15)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGrefishmapDlg message handlers

BOOL CGrefishmapDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	SetTimer(1,50,0);
	blockbit[SKY].LoadBitmap(MAKEINTRESOURCE(IDB_SKY));
	blockbit[GROUND].LoadBitmap(MAKEINTRESOURCE(IDB_GROUND));
	blockbit[GRAV].LoadBitmap(MAKEINTRESOURCE(IDB_GRAV));
	blockbit[DIE].LoadBitmap(MAKEINTRESOURCE(IDB_DIE));
	blockbit[WHAT].LoadBitmap(MAKEINTRESOURCE(IDB_WHAT));
	blockbit[BLOD].LoadBitmap(MAKEINTRESOURCE(IDB_BLOD));
	blockbit[HIGH].LoadBitmap(MAKEINTRESOURCE(IDB_HIGH));
	blockbit[FLAG].LoadBitmap(MAKEINTRESOURCE(IDB_FLAG));
	blockbit[DOWNUP].LoadBitmap(MAKEINTRESOURCE(IDB_DOWNUP));
	blockbit[TREE].LoadBitmap(MAKEINTRESOURCE(IDB_TREE));
	blockbit[NOGRAV].LoadBitmap(MAKEINTRESOURCE(IDB_NOGRAV));
	blockbit[GASI].LoadBitmap(MAKEINTRESOURCE(IDB_GASI));
	blockbit[BACK].LoadBitmap(MAKEINTRESOURCE(IDB_BACK));
	blockbit[CHA].LoadBitmap(MAKEINTRESOURCE(IDB_CHA));
	blockbit[BREAK].LoadBitmap(MAKEINTRESOURCE(IDB_BREAK));
	
	int i, j;
	for(i=0 ; i<=900 ; i++)
		for(j=0 ; j<=900 ; j++)
		{
			if(i<=1 || j<=1 || i>=899 || j>=899)
				allmap[i][j]=1;
		}
		print();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CGrefishmapDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CGrefishmapDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
	
	ggx-=gx*30-30;
	ggy-=gy*30-30;

	int possible;
	int max;
	int i, j, k;
	char str[256];
	HBITMAP bit, *old, *old2;
	HBRUSH *old3, brush;
	HDC MemDC;
	HDC bitDC;

	CClientDC hDC(this);
	bit=CreateCompatibleBitmap(hDC,1200,1200);
	MemDC=CreateCompatibleDC(hDC);
	bitDC=CreateCompatibleDC(hDC);
	//hDC=BeginPaint(hWnd,&ps);
	old = (HBITMAP *)SelectObject(MemDC,bit);

	Rectangle(MemDC,0,0,1024,768);

	SetBkMode(MemDC,0);


	old2=(HBITMAP *)SelectObject(bitDC,blockbit[BACK]);
						BitBlt(MemDC,30,30,540,480,bitDC,0,0,SRCCOPY);
						SelectObject(bitDC,old2);
						
	//배경  출력
	//	old2=(HBITMAP *)SelectObject(bitDC,bgbit);
	//	BitBlt(MemDC,0,0,1024,768,bitDC,0,0,SRCCOPY);
	//	SelectObject(bitDC,old2);
	if(dietime==-1)
	{
		char str[256];

		sprintf(str,"남은 life : %d",life);
		TextOut(MemDC,250,220,str,strlen(str));
		sprintf(str,"다시 시작할려면 'R'");
		TextOut(MemDC,230,240,str,strlen(str));
	}
	else{/*
	for(i=1 ; i<=16 ; i++)
		for(j=1 ; j<=18 ; j++)
		{
				
						if(j*30-ggx>0 && j*30-ggx<XSIZE+30)
						if(i*30-ggy>0 && i*30-ggy<YSIZE+30)
						{
				old2=(HBITMAP *)SelectObject(bitDC,blockbit[allmap[i][j]]);
				BitBlt(MemDC,j*30-ggx,i*30-ggy,30,30,bitDC,0,0,SRCCOPY);
				SelectObject(bitDC,old2);
						}
			
		}*/
		
	//	ggx+=gx*30;
	//	ggy+=gx*30;
	for(i=-16*2 ; i<=32*2 ; i++)
		for(j=-18*2 ; j<=36*2 ; j++)
		{
			//if(1<=i && i<=16 && 1<=j && j<=18){}
			//else
			{
				if(j*30-ggx>0 && j*30-ggx<XSIZE+30)
					if(i*30-ggy>0 && i*30-ggy<YSIZE+30)
					{
						old2=(HBITMAP *)SelectObject(bitDC,blockbit[allmap[i+gy-1][j+gx-1]]);
						BitBlt(MemDC,j*30-ggx,i*30-ggy,30,30,bitDC,0,0,SRCCOPY);
						SelectObject(bitDC,old2);
					}
			}
		}
	for(i=1 ; i<=nef ; i++)
	{
		if(ef[i].ay!=HIDEY)
		{
			if(ef[i].ax>=0 && ef[i].ax<=30*18)
				if(ef[i].ay>=0 && ef[i].ay<=30*16)
				{
					Rectangle(MemDC,ef[i].ax-ef[i].xsize-RANGE,ef[i].ay-ef[i].ysize-RANGE,ef[i].ax+ef[i].xsize+RANGE,ef[i].ay+ef[i].ysize+RANGE);
					char str[256];
					sprintf(str,"%d번 효과",numef[i]);
					TextOut(MemDC,ef[i].ax-20,ef[i].ay+20,str,strlen(str));
					old2=(HBITMAP *)SelectObject(bitDC,blockbit[ef[i].imgnumber]);
					BitBlt(MemDC,ef[i].ax-ef[i].imgxsize-ggx,ef[i].ay-ef[i].imgysize-ggy,ef[i].imgxsize*2,ef[i].imgysize*2,bitDC,0,0,SRCCOPY);
					SelectObject(bitDC,old2);
				}
		}
	}
	

	//Rectangle(MemDC,bx-CSX-ggx,by-CSY-ggy,bx+CSX-ggx,by-ggy+CSY);
	/*
	SetTextColor(MemDC,RGB(150,150,255));
	TextOut(MemDC,bx-CSX-ggx,by-CSY-ggy,"●",2);
	SetTextColor(MemDC,RGB(255,255,255));
	TextOut(MemDC,bx-CSX-ggx,by-CSY-ggy,"○",2);
	SetTextColor(MemDC,RGB(0,0,255));
	TextOut(MemDC,x-CSX-ggx,y-CSY-ggy,"●",2);
	SetTextColor(MemDC,RGB(255,255,255));
	TextOut(MemDC,x-CSX-ggx,y-CSY-ggy,"○",2);*/
		old2=(HBITMAP *)SelectObject(bitDC,blockbit[CHA]);
		BitBlt(MemDC,x-CSX-ggx,y-CSY-ggy,CSX*2,CSY*2,bitDC,0,0,SRCCOPY);
		SelectObject(bitDC,old2);
	
	}
		BitBlt(hDC,0,0,30*18,30*16,MemDC,30,30,SRCCOPY);
	//BitBlt(hDC,0,0,30*19,30*17,MemDC,0,0,SRCCOPY);
	SelectObject(MemDC,old);
	::ReleaseDC((HWND)this,MemDC);
	::ReleaseDC((HWND)this,bitDC);
	::ReleaseDC((HWND)this,hDC);
	DeleteObject(bit);
	DeleteObject(old);
	DeleteObject(old2);
	DeleteObject(old3);
	DeleteObject(MemDC);
	DeleteObject(bitDC);
	DeleteObject(hDC);

	ggx+=gx*30-30;
	ggy+=gy*30-30;

}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CGrefishmapDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CGrefishmapDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	chooseblock++;
	chooseblock=chooseblock%10;
	int wwwx;
	int wwwy;
	CClientDC dc(this);
	CDC MemDC;
	MemDC.CreateCompatibleDC(&dc);
	MemDC.SelectObject(blockbit[chooseblock]);
	dc.BitBlt(30*18+30,10,30,30,&MemDC,0,0,SRCCOPY);
}

void CGrefishmapDlg::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	//ggx-=gx*30-30;
	//ggy-=gy*30-30;
	lll=0;
	allmap[int(point.y+ggy)/30+1][int(point.x+ggx)/30+1]=chooseblock;
	//	ggx+=gx*30-30;
	//ggy+=gy*30-30;
	
	OnPaint();
	CDialog::OnLButtonUp(nFlags, point);
}

void CGrefishmapDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	if(gy>10)
	gy-=16;
	OnPaint();
	print();
}

void CGrefishmapDlg::OnButton3() 
{
	// TODO: Add your control notification handler code here
	gy+=16;
	OnPaint();
	print();
}

void CGrefishmapDlg::OnButton4() 
{
	// TODO: Add your control notification handler code here
	if(gx>0)
	gx-=18;
	OnPaint();
	print();
}

void CGrefishmapDlg::OnButton5() 
{
	// TODO: Add your control notification handler code here
	gx+=18;
	OnPaint();
	print();
}

void CGrefishmapDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
agx=gx*30+30-60;
		agy=gy*30-30;
		//if(agx+gx*30<0)
		//	agx=0;
		//if(agy<0)
		//	agy=0;
	//	ggx=agx;//
	//	ggy=agy;//
		ggx=(ggx*9+agx)/10;
		ggy=(ggy*9+agy)/10;
		OnPaint();
	
	CDialog::OnTimer(nIDEvent);
}

void CGrefishmapDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	lll=1;
	allmap[int(point.y+ggy)/30+1][int(point.x+ggx)/30+1]=chooseblock;
	//	ggx+=gx*30-30;
	//ggy+=gy*30-30;
	
	OnPaint();
	
	CDialog::OnLButtonDown(nFlags, point);
}

void CGrefishmapDlg::OnButton6() 
{
	// TODO: Add your control notification handler code here
	int i;
	FILE *out=fopen("grefish.txt","wb");

	fwrite(effect,sizeof(EFFECT),1000,out);
	fwrite(efn,sizeof(EFFECTNUMBER),10000,out);
	fwrite(allmap,sizeof(int),1000000,out);
	bgx=gx;
	bgy=gy;
	bbx=x;
	bby=y;
	fwrite(&bgx,sizeof(int),1,out);
	fwrite(&bgy,sizeof(int),1,out);
	fwrite(&bbx,sizeof(int),1,out);
	fwrite(&bby,sizeof(int),1,out);
	fwrite(explain,sizeof(char),1000000,out);
	fclose(out);
	MessageBox("저장완료");
}

void CGrefishmapDlg::OnButton7() 
{
	// TODO: Add your control notification handler code here

	int i,j;
	FILE *out=fopen("grefish.txt","rb");
	fread(effect,sizeof(EFFECT),1000,out);
	fread(efn,sizeof(EFFECTNUMBER),10000,out);
	fread(allmap,sizeof(int),1000000,out);
	fread(&bgx,sizeof(int),1,out);
	fread(&bgy,sizeof(int),1,out);
	fread(&bbx,sizeof(int),1,out);
	fread(&bby,sizeof(int),1,out);
	fread(explain,sizeof(char),1000000,out);
	fclose(out);
	
	MessageBox("불러왔다.");
	print();
}
void filesave()
{
	FILE *out=fopen("grefish.txt","wb");
	fwrite(effect,sizeof(EFFECT),1000,out);
	fwrite(efn,sizeof(EFFECTNUMBER),10000,out);
	fwrite(allmap,sizeof(int),1000000,out);
	fclose(out);
}
void fileload()
{
	int i,j;
	FILE *out=fopen("grefish.txt","r");
	fread(effect,sizeof(EFFECT),1000,out);
	fread(efn,sizeof(EFFECTNUMBER),10000,out);
	fread(allmap,sizeof(int),1000000,out);
	fclose(out);
	char str[256];

}

void CGrefishmapDlg::OnButton8() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	if(effect[m_number].exist==0)
	{
		MessageBox("그런 효과번호는 없습니다.");
		return;
	}
	delef b;
	b.DoModal();
	CIff a;
	a.ifmaking=clrif;
	a.motmaking=clrmot;
	a.ifmaking=effect[m_number].iff[b.m_num];
	a.motmaking=effect[m_number].mot[b.m_num];
	a.DoModal();
	
	effect[m_number].iff[b.m_num]=a.ifmaking;
	effect[m_number].mot[b.m_num]=a.motmaking;
	m_number=0;
	print();
}
void CGrefishmapDlg::print()
{
	char str[10000];
	UpdateData(TRUE);

	int i, j;
	for(i=1 ; i<10000 ; i++)
		str[i]=0;
	FILE *out=fopen("print.txt","w");
	fprintf(out,"%s\r\n\r\n",explain[gy/16+1][gx/18+1]);
	for(i=1 ; i<=efn[gy/16+1][gx/18+1].enef ; i++)
	{
		fprintf(out,"\r\n[%d번 효과]\r\n",efn[gy/16+1][gx/18+1].eef[i]);
		EFFECT temp=effect[efn[gy/16+1][gx/18+1].eef[i]];
			
		for(j=1 ; j<=effect[efn[gy/16+1][gx/18+1].eef[i]].ifn ; j++)
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
	out=fopen("print.txt","r");
	while(!feof(out))
	{
		fread(str,sizeof(char),10000,out);
	}
	m_result.Format("%s",str);
	fclose(out);
	
	
		nef=efn[gy/16+1][gx/18+1].enef;
		for(i=1 ; i<=nef ; i++)
		{
			ef[i]=effect[efn[gy/16+1][gx/18+1].eef[i]];
			numef[i]=efn[gy/16+1][gx/18+1].eef[i];
		}
	UpdateData(FALSE);
	/*for(i=1 ; i<1000 ; i++)
	{
		if(effect[i].
	}*/
}

void CGrefishmapDlg::OnButton9() 
{
	// TODO: Add your control notification handler code here
	int i, j;
	UpdateData(TRUE);
	//효과 삭제
	for(i=1 ; i<=efn[gy/16+1][gx/18+1].enef ; i++)
		if(efn[gy/16+1][gx/18+1].eef[i]==m_number)
		{
			effect[m_number].exist=0;
			for(j=i ; j<=efn[gy/16+1][gx/18+1].enef ; j++)
			efn[gy/16+1][gx/18+1].eef[j]=efn[gy/16+1][gx/18+1].eef[j+1];
			efn[gy/16+1][gx/18+1].enef--;
	m_number=0;
			print();
	MessageBox("정상적으로 삭제 되었습니다.");
			return;
		}
	MessageBox("그런 효과번호가 없습니다.");
	m_number=0;
	print();
}

void CGrefishmapDlg::OnButton11() 
{
	// TODO: Add your control notification handler code here
	//조건 추가 
	UpdateData(TRUE);

	if(effect[m_number].exist==0)
	{
		MessageBox("그런 효과번호는 없습니다.");
		return;
	}
	CIff a;
	a.ifmaking=clrif;
	a.motmaking=clrmot;
	a.DoModal();
	
	effect[m_number].ifn++;
	effect[m_number].iff[effect[m_number].ifn]=a.ifmaking;
	effect[m_number].mot[effect[m_number].ifn]=a.motmaking;
	m_number=0;
	print();
}

void CGrefishmapDlg::OnButton12() 
{
	// TODO: Add your control notification handler code here
	//조건 삭제
	int i;
	UpdateData(TRUE);

	if(effect[m_number].exist==0)
	{
		MessageBox("그런 효과번호는 없습니다.");
		return;
	}
	delef a;
	a.DoModal();
	effect[m_number].iff[a.m_num].what=0;
	effect[m_number].mot[a.m_num].what=0;
	for(i=a.m_num ; i<=effect[m_number].ifn ; i++)
	{
		effect[m_number].iff[i]=effect[m_number].iff[i+1];
		effect[m_number].mot[i]=effect[m_number].mot[i+1];
	}
	effect[m_number].ifn--;
	m_number=0;
	
	print();
}

void CGrefishmapDlg::OnButton13() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	//효과 추가
	int i, num;
	char str[256];
	num=0;
	for(i=1 ; i<1000 ; i++)
	{
		if(effect[i].exist==0)
		{
			effect[i].exist=1;
			efn[gy/16+1][gx/18+1].enef++;
			efn[gy/16+1][gx/18+1].eef[efn[gy/16+1][gx/18+1].enef]=i;
			effect[i].ifn=0;
			num=i;
			break;
		}
	}
	CSett a;
	a.m_x=100;
	a.m_y=100;
	a.m_imgx=15;
	a.m_imgy=15;
	a.m_xsize=15;
	a.m_ysize=15;
	a.m_imgnumber=4;
	
	m_number=num;
	a.DoModal();
	effect[num].setting(a.m_x,a.m_y,a.m_imgnumber,a.m_xsize,a.m_ysize,a.m_imgx,a.m_imgy);
	
	
	print();
}

void CGrefishmapDlg::OnButton14() 
{
	// TODO: Add your control notification handler code here
	
	UpdateData(TRUE);
	//효과 설정
	CSett a;
	a.m_x=effect[m_number].ax;
	a.m_y=effect[m_number].ay;
	a.m_imgnumber=effect[m_number].imgnumber;
	a.m_xsize=effect[m_number].xsize;
	a.m_ysize=effect[m_number].ysize;
	a.m_imgx=effect[m_number].imgxsize;
	a.m_imgy=effect[m_number].imgysize;
	a.DoModal();
	effect[m_number].setting(a.m_x,a.m_y,a.m_imgnumber,a.m_xsize,a.m_ysize,a.m_imgx,a.m_imgy);
	print();
}

void EFFECT::setting(int _x,int _y,int _imgnumber,int _xsize,int _ysize,int _imgxsize,int _imgysize)
{
	ax=_x;
	ay=_y;
	imgnumber=_imgnumber;
	xsize=_xsize;
	ysize=_ysize;
	imgxsize=_imgxsize;
	imgysize=_imgysize;
}

void CGrefishmapDlg::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	x=point.x+30;
	y=point.y+30;
	CDialog::OnRButtonDown(nFlags, point);
}

void CGrefishmapDlg::OnButton10() 
{
	// TODO: Add your control notification handler code here
	CExplain a;
	a.DoModal();
	char str[256];
	sprintf(str,"%s               ",a.m_1);
	memcpy(&explain[gy/16+1][gx/18+1][0],str,15);
	sprintf(str,"%s               ",a.m_2);
	memcpy(&explain[gy/16+1][gx/18+1][15],str,15);
	sprintf(str,"%s               ",a.m_3);
	memcpy(&explain[gy/16+1][gx/18+1][30],str,15);
	sprintf(str,"%s               ",a.m_4);
	memcpy(&explain[gy/16+1][gx/18+1][45],str,15);
	sprintf(str,"%s               ",a.m_5);
	memcpy(&explain[gy/16+1][gx/18+1][60],str,15);
	sprintf(str,"%s               ",a.m_6);
	memcpy(&explain[gy/16+1][gx/18+1][75],str,15);
	print();
}

void CGrefishmapDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(lll)
	{
		allmap[int(point.y+ggy)/30+1][int(point.x+ggx)/30+1]=chooseblock;
	}
	CDialog::OnMouseMove(nFlags, point);
}

void CGrefishmapDlg::OnButton15() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	//효과 추가
	int i, num;
	char str[256];
	num=0;
	for(i=1 ; i<1000 ; i++)
	{
		if(effect[i].exist==0)
		{
			effect[i].exist=1;
			efn[gy/16+1][gx/18+1].enef++;
			efn[gy/16+1][gx/18+1].eef[efn[gy/16+1][gx/18+1].enef]=i;
			effect[i].ifn=0;
			num=i;
			break;
		}
	}
	delef a;
	a.DoModal();

	effect[num]=effect[a.m_num];
	print();
}

#include <windows.h>
#include <Stdio.h>
#include <math.h>
#include <string.h>
#include <memory.h>
#include "resource.h"
#include "ddraw.h"
#include "common.h"

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
#define RIGHT 55
#define MAIN 54
#define GASI 51
#define TREE 50
#define BREAK 56
#define RANGE 5
#define BACK 52
#define CHA 53
#define CSX 7
#define CSY 7

#define NO 999999

#define ALL 0
#define FAST 1
#define XSIZE (30*18)
#define YSIZE (30*16)
#define HIDEX 1
#define HIDEY 1000

struct EFFECTNUMBER
{
	int enef;
	int eef[100];
};
struct MOTION
{
	int what;
	//1
	
	// 고정으로 만들기
	double px;
	double py;
	double pvx;
	double pvy;
	// 추가 하기
	double ax;
	double ay;
	double avx;
	double avy;
	// effect 가 움직이기
	
	// 고정
	double ex;
	double ey;
	double evx;
	double evy;

	// 추가 하기
	double aex;
	double aey;
	double aevx;
	double aevy;
	double aavx;
	double aavy;

	int fimg;
	int cimg;
	
	//2 flag 수정
	int ff;
	
	//3 die

	//4 블록 전환

	//5 시간
	
	//6 방향반대
};
struct IFF
{
	int what;
	//what
	//0 always.
	//1 hit.
	int hit; //방향
	//2 effect 와 블럭과의 충돌
	int effecthit;
	int whichblock;
	//3 flag
	int ff;
	//4 연속
	//5 effect 와 나와 충돌
	//6 키 입력
};
struct EFFECT
{
	double ax, ay;
	double bfx, bfy;
	double evx, evy;
	double avx, avy;
	int exist;
	int efftime;
	int xsize, ysize;
	int imgnumber;
	int imgxsize;
	int imgysize;
	int ifn;
	IFF iff[20];
	MOTION mot[20];
	void setting(int _x,int _y,int _imgnumber,int _xsize,int _ysize,int _imgxsize,int _imgysize);
	void always(int number);
	void ifhit(int number,int _hit);
	void ifon(int number);
	void ifgo(int number);
	void ifflag(int number,int _fflag);
	void changeflag(int number,int _fflag);
	void effhit(int number,int _hit,int _whichblock);
	void changeimg(int number,int _img);
	void timelater(int number,int _time);
	void changeblock(int number,int _xx,int _yy,int _whichblock);
	void moveme(int number,int _px,int _py,int _pvx,int _pvy,int _mx,int _my,int _mvx,int _mvy);
	void moveeffct(int number,int _px,int _py,int _pvx,int _pvy,int _mx,int _my,int _mvx,int _mvy,double _afx,double _afy);
	void death(int number);
	void excute();
	void hide(int number);
}effect[1000];

int nef;
EFFECT ef[100];
int keybd[256];
int bgx;
int bgy;
int bbx;
int bby;
double ggx, ggy, agx, agy;
int life=3;
int map[300][200]=
{
	{1,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,0,},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
};
int allmap[1000][1000]=
{//이게 맵이거든.. 자 니가 만들어바 ㅋㅋ
/*	
*/
	{1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0, 1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},

	{1, 1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0, 1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
	{1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0, 0,0,1,1,1,0,1,1,0,1,1,0,0,0,0,2,2,1, 0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,1,9, 9,9,9,1,9,9,9,9,9,9,9,9,1,9,9,9,1,0,},
	{1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0, 0,0,0,0,1,1,1,1,0,0,1,0,0,0,0,2,2,1, 0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,0,1,9, 1,1,9,1,1,1,9,1,1,1,1,9,1,9,1,9,1,0,},
	{1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0, 0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,2,2,1, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,9, 9,1,9,9,9,1,9,9,9,9,1,9,9,9,1,9,1,0,},
	{1, 1,0,0,0,0,0,0,0,2,2,0,0,0,1,0,0,1,0, 0,0,5,1,1,0,0,0,0,0,2,2,2,0,0,1,1,1, 0,7,0,0,0,0,1,0,0,5,0,5,0,0,5,8,8,1, 9,1,1,1,9,1,1,1,1,9,1,1,1,1,1,9,1,0,},
	{1, 1,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,1,0, 0,1,1,0,0,0,2,2,0,0,2,2,2,0,0,0,0,1, 1,1,0,0,1,0,0,0,0,3,3,3,3,3,3,8,8,1, 9,9,9,1,9,1,9,9,9,9,1,9,9,9,9,9,1,0,},
	{1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0, 0,0,0,0,0,0,2,2,1,1,1,0,0,0,0,0,0,1, 0,1,0,0,0,1,3,3,1,0,0,0,0,0,0,0,0,1, 9,9,9,1,9,1,9,1,1,1,1,9,1,1,1,1,1,3,},
	{1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0, 0,0,7,0,0,0,2,2,0,0,0,0,0,0,0,0,0,1, 0,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,5,1, 9,9,7,1,9,1,9,9,9,1,9,9,1,9,9,9,9,9, 1,},
	{1, 1,0,0,0,0,0,0,2,0,0,0,0,0,1,0,0,1,0, 0,0,1,1,2,2,2,2,0,0,0,0,0,0,0,0,0,1, 0,1,0,0,0,0,0,0,1,0,0,1,1,1,1,1,1,1, 1,1,9,1,9,1,1,1,9,1,9,1,1,9,1,1,1,9, 1,},
	{1, 1,0,0,0,0,0,0,2,0,0,0,0,0,1,0,0,1,0, 0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,1, 0,1,1,0,0,7,0,0,1,0,0,0,0,0,0,0,0,4, 9,1,9,1,9,1,9,9,9,1,9,1,9,9,1,7,1,9, 1,},
	{1, 1,0,0,0,0,2,0,0,0,0,2,0,0,1,0,0,1,0, 6,0,2,2,1,1,1,1,1,0,0,0,0,0,0,0,0,1, 0,1,0,0,1,1,0,0,1,0,0,0,0,0,0,0,0,4, 9,1,9,1,9,1,9,1,9,1,9,9,9,1,1,9,1,9, 1,},
	{1, 1,0,0,2,0,2,0,0,0,0,2,0,0,0,0,0,0,0, 0,0,2,2,0,0,0,0,0,0,1,0,0,0,0,1,0,1, 0,1,0,0,0,0,5,0,1,0,0,0,0,0,0,0,0,4, 9,1,9,1,9,1,9,1,9,1,1,1,1,1,9,9,9,9, 1,},
	{1, 1,0,0,2,0,0,0,0,0,2,2,0,0,0,0,0,1,0, 0,1,2,2,0,0,0,0,0,0,0,1,0,0,1,0,1,1, 0,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,4, 9,1,9,1,9,1,9,1,9,1,9,9,9,1,9,1,1,1,},
	{1, 1,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,1,0, 0,0,0,2,2,0,0,0,0,0,1,0,0,0,0,0,0,1, 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,4, 9,1,9,1,9,1,9,1,9,1,9,1,9,9,9,1,1,1,},
	{1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0, 0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,1, 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,4, 9,9,9,1,9,9,9,1,9,1,9,1,9,9,9,9,9,1,},
	{1, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,1,1,1, 1,1,1,1,3,3,1,3,1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1,9,1,1,1,1,1,1,1,},
	
	{1, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,},
	{1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,1,6,0,0,7,0,0,0,1,},
	{1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,1,},
	{1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,},
	{1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,0,1,},
	{1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,},
	{1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,},
	{1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1,1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,},
	{1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1,9,9,9,5,5,5,5,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,},
	{1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1,9,9,9,5,5,5,5,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,},
	{1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,1,2,2,1,1,1, 1,9,9,9,5,5,5,5,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	{1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,1,2,2,9,9,9, 9,9,9,9,5,5,5,5,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	{1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,1,2,2,9,9,9, 9,9,9,9,5,5,5,5,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	{1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,1,9,9,9,9,9, 9,9,9,9,5,5,5,5,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,1,5,5,5,1,0,0,0,0,1,},
	{1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,1,9,9,9,9,9, 9,9,9,9,9,9,5,5,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,5,5,5,1,5,5,5,1,5,5,5,5,1,},
	{1, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
	
	{1, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,},
	{1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, 1,0,0,0,7,0,0,0,0,0,0,1,0,0,0,0,0,1,},
	{1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, 1,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,},
	{1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, 1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	{1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, 1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	{1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, 1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	{1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, 1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	{1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, 1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	{1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, 1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	{1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, 1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	{1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, 1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	{1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	{1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, 1,0,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	{1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	{1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	{1, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,},
};
HBITMAP blockbit[100];
double x, y;
int bx, by, gx=1, gy=1, fflag;
int dietime;
double vx, vy;
EFFECTNUMBER efn[100][100];
char explain[100][100][100];
HWND window;
LPDIRECTDRAW lpdd;

POINT pt; // 클라이언트의 화면 좌표.
RECT ClientRect; // 클라이언트 영역이 저장될 RECT 구조체.


DDSURFACEDESC ddsd;
LPDIRECTDRAWSURFACE lpddSPrimary; // Primary Surface.


LRESULT CALLBACK WndProc(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam);
void draw(HWND hWnd, int flag);
int mapmove();
int onblock(int xx,int yy,int block);
int hitblock(int xx,int yy,int block);
int hiteffect(int xx,int yy,EFFECT eft);
int oneffect(int xx,int yy,EFFECT eft);
int rhitblock(int xx,int yy,int block,int dir);
void rightdraw(HWND hWnd);
void die();
void filesave();
void fileload();
int Init(HWND m_hWnd); // 게임 초기화.
int Main();                    // 게임 메인.
int Shutdown();             // 게임 종료.
DWORD _RGB(LPDIRECTDRAWSURFACE Surf, COLORREF rgb);
int GetClientPos(); // 클라이언트 영역의 화면 위치를 얻어온다.
HWND hWnd;

int WINAPI WinMain(HINSTANCE hInst,
				   HINSTANCE hPrev,
				   LPSTR lpCmd,
				   int nShow)
{

	blockbit[SKY]=LoadBitmap(hInst,MAKEINTRESOURCE(IDB_SKY));
	blockbit[GROUND]=LoadBitmap(hInst,MAKEINTRESOURCE(IDB_GROUND));
	blockbit[GRAV]=LoadBitmap(hInst,MAKEINTRESOURCE(IDB_GRAV));
	blockbit[DIE]=LoadBitmap(hInst,MAKEINTRESOURCE(IDB_DIE));
	blockbit[WHAT]=LoadBitmap(hInst,MAKEINTRESOURCE(IDB_WHAT));
	blockbit[BLOD]=LoadBitmap(hInst,MAKEINTRESOURCE(IDB_BLOD));
	blockbit[HIGH]=LoadBitmap(hInst,MAKEINTRESOURCE(IDB_HIGH));
	blockbit[FLAG]=LoadBitmap(hInst,MAKEINTRESOURCE(IDB_FLAG));
	blockbit[DOWNUP]=LoadBitmap(hInst,MAKEINTRESOURCE(IDB_SKY));
	blockbit[TREE]=LoadBitmap(hInst,MAKEINTRESOURCE(IDB_TREE));
	blockbit[NOGRAV]=LoadBitmap(hInst,MAKEINTRESOURCE(IDB_NOGRAV));
	blockbit[GASI]=LoadBitmap(hInst,MAKEINTRESOURCE(IDB_GASI));
	//blockbit[BACK]=LoadBitmap(hInst,MAKEINTRESOURCE(IDB_BACK));
	blockbit[CHA]=LoadBitmap(hInst,MAKEINTRESOURCE(IDB_CHA));
	blockbit[MAIN]=LoadBitmap(hInst,MAKEINTRESOURCE(IDB_MAIN));
	blockbit[RIGHT]=LoadBitmap(hInst,MAKEINTRESOURCE(IDB_RIGHT));
	blockbit[BREAK]=LoadBitmap(hInst,MAKEINTRESOURCE(IDB_BREAK));

	srand(GetTickCount());
	WNDCLASS wnd;
	MSG msg;

	wnd.cbClsExtra = 0;
	wnd.cbWndExtra = 0;
	wnd.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
	wnd.hCursor = 0;//LoadCursor(hInst,MAKEINTRESOURCE(IDC_CURSOR1));
	wnd.hIcon = LoadIcon(hInst,MAKEINTRESOURCE(IDI_ICON1));
	wnd.hInstance = hInst;
	wnd.lpfnWndProc = WndProc;
	wnd.lpszClassName = "grefish";
	wnd.lpszMenuName =0;// MAKEINTRESOURCE(IDR_MENU1);
	wnd.style = 0;

	RegisterClass(&wnd);

	hWnd = CreateWindow("grefish","GREMCUS-grefish",WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,18*30+5+150,16*30+35,0,0,hInst,0);
	ShowWindow(hWnd,SW_SHOW);

	Init(hWnd);
//	selectx++;selecty++;
	while(GetMessage(&msg,0,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	Shutdown();
	return 0;
}
int visit[100];
int check;
LRESULT CALLBACK WndProc(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
	int ttype;
	int i, j, k, ax, ay, qx,qy, temp;
	int hitb;
	FILE *out;
	switch(msg)
	{
	case WM_MOVE:
		GetClientPos();
		break;
	case WM_DESTROY:
		PostQuitMessage(1);
		break;
	case WM_CREATE:
		window=hWnd;
		dietime=-1;
		x=80+30*15+30*18*0, y=80+30*18*0;
		x=80+30*18;y=80;
		gx=-17;
		vy=2;

		effect[1].setting(30*15+45,30*3+45,WHAT,15,15,15,15);
		effect[1].ifon(1);
		effect[1].changeflag(1,2);
		effect[1].ifgo(2);
		effect[1].moveeffct(2,HIDEX,HIDEY,0,0,0,0,0,0,0,0);
		
		effect[2].setting(30*16+45,30*11+45,DIE,15,15,15,15);
		effect[2].ifon(1);
		effect[2].death(1);
		effect[2].ifflag(2,2);
		effect[2].moveeffct(2,0,0,0,0,0,0,0,0,-0.05,0);
		effect[2].ifgo(3);
		effect[2].changeflag(3,5);
		effect[2].effhit(4,5,GROUND);
		effect[2].death(4);
		effect[2].ifflag(5,6);
		effect[2].moveeffct(5,0,0,NO,0,0,0,0,0,0,0.005);

		effect[3].setting(HIDEX,HIDEY,WHAT,15,15,15,15);
		effect[3].ifflag(1,5);
		effect[3].moveeffct(1,30*10+45,30*3+45,0,0,0,0,0,0,0,0);
		effect[3].ifon(2);
		effect[3].changeflag(2,6);
		effect[3].ifgo(3);
		effect[3].moveeffct(3,HIDEX,HIDEY,0,0,0,0,0,0,0,0);

		effect[4].setting(30*16+45,30*1+45,WHAT,15,15,15,15);
		effect[4].ifon(1);
		effect[4].changeflag(1,2);
		effect[4].ifgo(2);
		effect[4].hide(2);
		
		effect[5].setting(HIDEX,HIDEY,WHAT,15,15,15,15);
		effect[5].ifflag(1,2);
		effect[5].moveeffct(1,30*13+45,30*12+45,0,0,0,0,0,0,0,0);
		effect[5].ifgo(2);
		effect[5].changeflag(2,10);
		effect[5].ifgo(3);
		effect[5].changeblock(3,18,6,0);
		effect[5].ifgo(4);
		effect[5].changeblock(4,18,7,0);
		effect[5].ifgo(5);
		effect[5].changeblock(5,18,8,0);
		effect[5].ifon(6);
		effect[5].changeblock(6,18,6,1);
		effect[5].ifgo(7);
		effect[5].changeblock(7,18,7,1);
		effect[5].ifgo(8);
		effect[5].changeblock(8,18,8,1);
		effect[5].ifgo(9);
		effect[5].hide(9);

		effect[6].setting(30*6,30*15,WHAT,45,45,0,0);
		effect[6].ifon(1);
		effect[6].changeflag(1,3);
		effect[6].ifgo(2);
		effect[6].hide(2);

		effect[7].setting(HIDEX,HIDEY,3,15,15,15,15);
		effect[7].ifon(1);
		effect[7].death(1);
		effect[7].ifflag(2,3);
		effect[7].moveeffct(2,30*6,30*17,0,0,0,0,0,0,0,-1.5);
		effect[7].effhit(3,4,GROUND);
		effect[7].moveeffct(3,30*4.5,30*12,0,NO,0,0,0,0,0,1.5);
		effect[7].ifgo(4);
		effect[7].changeblock(4,8,16,HIGH);
		effect[7].ifgo(5);
		effect[7].changeblock(5,3,11,GROUND);
		effect[7].ifgo(6);
		effect[7].changeblock(6,4,11,GROUND);
		effect[7].ifflag(7,30);
		effect[7].moveeffct(7,30*7+15,30*7,0,0,0,0,0,0,0,-1.5);

		effect[8].setting(30*7+15,30*5,WHAT,30,30,0,0);
		effect[8].ifon(1);
		effect[8].changeblock(1,6,5,1);
		effect[8].ifgo(2);
		effect[8].changeblock(2,7,5,0);
		effect[8].ifgo(3);
		effect[8].changeblock(3,8,5,1);
		effect[8].ifgo(4);
		effect[8].moveeffct(4,30*7+15,30*7,0,0,0,0,0,0,0,-1.5);
		effect[8].ifgo(5);
		effect[8].changeflag(5,30);
		effect[8].ifgo(6);
		effect[8].hide(6);

		
		effect[9].setting(30*14,30*14,WHAT,50,90,0,0);
		effect[9].ifon(1);
		effect[9].changeflag(1,91);
		effect[9].ifgo(2);
		effect[9].changeblock(2,18,15,0);
		effect[9].ifgo(3);
		effect[9].changeblock(3,18,14,0);
		effect[9].ifgo(4);
		effect[9].changeblock(4,18,13,0);
		effect[9].ifgo(5);
		effect[9].changeblock(5,18,12,0);
		effect[9].ifgo(6);
		effect[9].changeblock(6,18,11,0);
		effect[9].ifgo(7);
		effect[9].changeblock(7,18,10,0);
		effect[9].ifgo(8);
		effect[9].hide(8);

		effect[10].setting(HIDEX,HIDEY,TREE,100,13,100,13);
		effect[10].ifflag(1,91);
		effect[10].moveeffct(1,30*16,30*10,0,0,0,0,0,0,0,1);
		effect[10].ifon(2);
		effect[10].death(2);

		effect[11].setting(HIDEX,HIDEY,TREE,100,13,100,13);
		effect[11].ifflag(1,91);
		effect[11].moveeffct(1,30*5-20,30*5,0,NO,0,0,0,0,0,0.5);
		effect[11].ifon(2);
		effect[11].death(2);
		
		effect[12].setting(30*6,30*14,WHAT,50,100,0,0);
		effect[12].ifon(1);
		effect[12].changeflag(1,91);
		effect[12].ifgo(2);
		effect[12].hide(2);

		
		effect[13].setting(30*11.5,30*14,WHAT,30,100,0,0);
		effect[13].ifon(1);
		effect[13].changeflag(1,100);
		effect[13].ifgo(2);
		effect[13].hide(2);

		
		effect[14].setting(HIDEX,HIDEY,GASI,25,25,25,25);
		effect[14].ifflag(1,100);
		effect[14].moveeffct(1,30*11.5,30*16,0,NO,0,0,0,0,0,-1);
		effect[14].ifon(2);
		effect[14].death(2);

		
		effect[15].setting(30*16,30*14,WHAT,15,15,15,15);
		effect[15].ifon(1);
		effect[15].changeblock(1,2,1,3);
		effect[15].ifgo(2);
		effect[15].hide(2);
		effect[15].ifon(3);
		effect[15].changeblock(3,2,1,3);
		effect[15].ifon(4);
		effect[15].changeblock(4,4,1,3);
		effect[15].ifon(5);
		effect[15].changeblock(5,6,1,3);
		effect[15].ifon(6);
		effect[15].changeblock(6,8,1,3);
		effect[15].ifon(7);
		effect[15].changeblock(7,10,1,3);
		effect[15].ifon(8);
		effect[15].changeblock(8,12,1,3);
		effect[15].ifon(9);
		effect[15].changeblock(9,14,1,3);
		effect[15].ifon(10);
		effect[15].changeblock(10,16,1,3);
		effect[15].ifon(11);
		effect[15].changeblock(11,13,6,2);
		effect[15].ifon(12);
		effect[15].changeblock(12,13,8,2);
		effect[15].ifon(13);
		effect[15].changeblock(13,13,10,2);
		effect[15].ifon(14);
		effect[15].changeblock(14,13,12,2);
		effect[15].ifon(15);
		effect[15].changeblock(15,13,14,2);

		effect[16].setting(30*13,30*12.5,WHAT,20,20,0,0);
		effect[16].ifon(1);
		effect[16].changeflag(1,35);
		effect[16].ifgo(2);
		effect[16].hide(2);
		
		effect[17].setting(HIDEX,HIDEY,GROUND,12,4,12,4);//총알
		effect[17].ifon(1);
		effect[17].death(1);
		effect[17].ifflag(2,35);
		effect[17].moveeffct(2,30*8,30*11,0,0,0,0,0,0,1.0,0);
		effect[17].ifgo(3);
		effect[17].changeflag(3,36);

		effect[18].setting(HIDEX,HIDEY,GROUND,12,4,12,4);//총알
		effect[18].ifon(1);
		effect[18].death(1);
		effect[18].ifflag(2,36);
		effect[18].moveeffct(2,30*8,30*10.3,0,0,0,0,0,0,1.2,0);
		effect[18].ifgo(3);
		effect[18].changeflag(3,37);
		
		
		effect[19].setting(HIDEX,HIDEY,GROUND,12,4,12,4);//총알
		effect[19].ifon(1);
		effect[19].death(1);
		effect[19].ifflag(2,37);
		effect[19].moveeffct(2,30*8,30*9.7,0,0,0,0,0,0,1.4,0);

		
		effect[20].setting(30*4,30*7,WHAT,50,50,0,0);
		effect[20].ifon(1);
		effect[20].moveme(1,0,0,0,0,0,0,0,-3);

		effect[21].setting(30*8,30*8,TREE,100,13,100,13);
		effect[21].ifon(1);
		effect[21].death(1);
		effect[21].ifflag(2,0);
		effect[21].changeflag(2,5);
		effect[21].ifgo(3);
		effect[21].moveeffct(3,0,0,0,8,0,0,0,0,0,0);
		effect[21].ifflag(4,1);
		effect[21].changeflag(4,5);
		effect[21].ifgo(5);
		effect[21].moveeffct(5,0,0,0,-8,0,0,0,0,0,0);
		effect[21].effhit(6,3,GROUND);
		effect[21].changeflag(6,1);
		effect[21].effhit(7,4,GROUND);
		effect[21].changeflag(7,0);

		for(i=1 ; i<=21 ; i++)
			effect[i].exist=1;


		efn[1][1].enef=3;
		efn[1][1].eef[1]=1;
		efn[1][1].eef[2]=2;
		efn[1][1].eef[3]=3;

		efn[1][2].enef=2;
		efn[1][2].eef[1]=4;
		efn[1][2].eef[2]=5;

		efn[1][3].enef=5;
		efn[1][3].eef[1]=6;
		efn[1][3].eef[2]=7;
		efn[1][3].eef[3]=8;
		efn[1][3].eef[4]=9;
		efn[1][3].eef[5]=10;

		efn[2][4].enef=4;
		efn[2][4].eef[1]=11;
		efn[2][4].eef[2]=12;
		efn[2][4].eef[3]=13;
		efn[2][4].eef[4]=14;

		
		efn[2][3].enef=6;
		efn[2][3].eef[1]=15;
		efn[2][3].eef[2]=16;
		efn[2][3].eef[3]=17;
		efn[2][3].eef[4]=18;
		efn[2][3].eef[5]=19;
		efn[2][3].eef[6]=20;

		efn[2][2].enef=1;
		efn[2][2].eef[1]=21;

		bgx=gx;
		bgy=gy;
		bbx=x;
		bby=y;
		fileload();
		break;
	case WM_TIMER:
		/////////화면조절///////
		//ggy+=gy*30;
		agx=gx*30-30+x-30*9;
		agy=gy*30-30;
		if(agx+gx*30<0)
			agx=0;
		if(agy<0)
			agy=0;
		ggx=(ggx*19+agx)/20;
		ggy=(ggy*19+agy)/20;
		//ggy-=gy*30;
		////////////////////////
		/*if(keybd['A'])
		{
			keybd['A']=0;
			filesave();
		}
		if(keybd['S'])
		{
			keybd['S']=0;
			fileload();
		}*/
		if(keybd['R'] || keybd[VK_SPACE])
		{
			//새시작
			keybd['R']=0;
			keybd[VK_SPACE]=0;
			if(life==3)
			{
				dietime=0;
				break;
			}
			x=bbx+30*18, y=bby;
			gx=bgx-18;
			gy=bgy;
			vx=0;
			vy=2;
			fflag=0;
			mapmove();
			dietime=0;
		}
		if(dietime!=0)
		{
			if(dietime!=-1)
				dietime--;
			if(dietime==1)
				dietime=-1;
			draw(hWnd,ALL);
			break;
		}
		//키보드//
		/*
		if(vx>3)
			vx=3;
		if(vx<-3)
			vx=-3;
		*/
		if(keybd[VK_RIGHT] && vx<=2.7)
			vx+=0.3;
		if(keybd[VK_LEFT] && vx>=-2.7)
			vx-=0.3;
		if(keybd[VK_UP])
		{
			
			if(onblock(x,y,NOGRAV))
				vy=-4;
			else if(onblock(x,y+10,GROUND))	
				vy=-8;
		}
		if(keybd[VK_DOWN])
		{
			if(onblock(x,y,NOGRAV))	
				vy=4;
			else if(onblock(x,y-10,GROUND))	
				vy=8;
		}
		if(onblock(x,y+10,GROUND))
		{
			vx*=0.95;
			if(vx>0 && vx<=0.2)
				vx=0;
			if(vx<0 && vx>=-0.2)
				vx=0;
				
		}
		//////////
		//중력과 이동//
		if(!onblock(x,y,NOGRAV))
		{
			if(!onblock(x,y+10,GROUND))
				vy+=0.25;
			else if(vy>0)
				vy=0;
		}
		else
		{
			if(onblock(x,y+10,GROUND) && vy>0)
				vy=0;
			if(onblock(x,y-10,GROUND) && vy<0)
				vy=0;
		}
		vy=vy*0.985;
		bx=x;
		by=y;
		y+=vy;
		x+=vx;
		int xx, yy;
		xx=x,yy=y;
		////////
		// 블럭 반사 //
		/*if(onblock(xx,yy,BLOD))
		{
			map[yy/30][xx/30]=0;
			vy=-9;
		}*/
		
		hitb=hitblock(xx,yy,BLOD);
		//if(hitb==1)
		if(rhitblock(xx,yy,BLOD,1))
		{
			x=bx-RANGE-vx;
			vx=-vx;
		}
		if(rhitblock(xx,yy,BLOD,2))
		{
			x=bx+RANGE-vx;
			vx=-vx;
		}
		if(hitb==1 || hitb==2)
		{
		//	vx=-vx;
			//x=bx/30*30+(hitb-1)*30;
	//		x=(x+bx)/2;
		}
		if(hitb==3 || hitb==4)
		{
			
			if(hitb==3)
				map[(yy+10)/30][xx/30]=0;
			if(vy>0)
				vy=-8;
			else
				vy=-vy;
			y=by/30*30+(4-hitb)*30;
			y=(y+by)/2;
		}
		hitb=hitblock(xx,yy,HIGH);
		if(hitb==1 || hitb==2)
		{
			vx=-vx;
			//x=bx/30*30+(hitb-1)*30;
			x=(x+bx)/2;
		}
		else if(hitb==3 || hitb==4)
		{
			if(vy>0)
				vy=-11;
			else
				vy=-vy;
			y=by/30*30+(4-hitb)*30;
			y=(y+by)/2;
		}
		else if(onblock(xx,yy,HIGH))
		{
			vy=-11;
		}
		if(onblock(xx,yy,GRAV))
		{
			vy-=1.2;
		}
		if(onblock(xx,yy,FLAG))
		{
			map[yy/30][xx/30]=0;
			bbx=xx;
			bby=yy;
			bgx=gx;
			bgy=gy;
		}
		hitb=hitblock(xx,yy,GROUND);
		//if(hitb==1)
		if(rhitblock(xx,yy,GROUND,1))
		{
			x=bx-RANGE-vx;
			vx=-vx;
		}
		if(rhitblock(xx,yy,GROUND,2))
		{
			x=bx+RANGE-vx;
			vx=-vx;
		}
		if(hitb==1 || hitb==2)
		{
		//	vx=-vx;
			//x=bx/30*30+(hitb-1)*30;
	//		x=(x+bx)/2;
		}
		if(hitb==3 || hitb==4)
		{
			if(vy>0)
				vy=0;
			else
				vy=-vy;
			y=by/30*30+(4-hitb)*30;
			y=(y+by)/2;
		}
		if(rhitblock(xx,yy,DOWNUP,4))
		{
			
			if(onblock(xx,yy-10,DOWNUP)){
				map[(yy-10)/30][xx/30]=GROUND;
				vy=-vy;
				y=by/30*30;
				y=(y+by)/2;
			}
		}
		
		if(onblock(xx,yy,DIE))
			die();
		for(i=1 ; i<=nef ; i++)
			ef[i].excute();
		///////////////
		if(mapmove())
			draw(hWnd,ALL);
		else
			draw(hWnd,ALL);
		break;
	case WM_KEYDOWN:
		keybd[wParam]=1;
		break;
	case WM_KEYUP:
		keybd[wParam]=0;
		break;
	case WM_LBUTTONDOWN:
		qy=HIWORD(lParam);
		qx=LOWORD(lParam)-30*18;
		if(qx>24 && qy>289 && qx<129 && qy<328)
		{
			
			out=fopen("where.txt","wb");
			fwrite(&bgx,sizeof(int),1,out);
			fwrite(&bgy,sizeof(int),1,out);
			fwrite(&bbx,sizeof(int),1,out);
			fwrite(&bby,sizeof(int),1,out);
			MessageBox(hWnd,"저장완료","저장",0);
			fclose(out);
		}
		
		if(qx>24 && qy>354 && qx<129 && qy<396)
		{
			out=fopen("where.txt","rb");
			if(out){
			fread(&bgx,sizeof(int),1,out);
			fread(&bgy,sizeof(int),1,out);
			fread(&bbx,sizeof(int),1,out);
			fread(&bby,sizeof(int),1,out);
			gx=bgx-18;
			gy=bgy;
			x=bbx+30*18;
			y=bby;
			mapmove();
			
			MessageBox(hWnd,"불러오기 완료","불러오기",0);
			fclose(out);
			}
			else
			{
				MessageBox(hWnd,"부를 거 없음.","불러오기",0);
			}
		}
		break;
	case WM_COMMAND:
		
		break;
	case WM_PAINT:
		SetTimer(hWnd,0,20,0);
		draw(hWnd,ALL);
		rightdraw(hWnd);
		break;
	};
	return DefWindowProc(hWnd,msg,wParam,lParam);
}

void draw(HWND hWnd, int flag)
{
	ggx-=gx*30-30;
	ggy-=gy*30-30;

	int possible;
	int max;
	int i, j, k;
	char str[256];
	HBITMAP bit, *old, *old2;
	HBRUSH *old3, brush;
	HDC hDC;
	HDC MemDC;
	HDC bitDC;

	
    lpddSPrimary->GetDC(&hDC);
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
		if(life!=3){
		char str[256];

		sprintf(str,"life : %d",life);
		TextOut(MemDC,270,240,str,strlen(str));
		}
		else
		{
			char str[256];
			old2=(HBITMAP *)SelectObject(bitDC,blockbit[MAIN]);
			BitBlt(MemDC,30,30,540,480,bitDC,0,0,SRCCOPY);
			SelectObject(bitDC,old2);
		}
	}
	else{
	for(i=1 ; i<=16 ; i++)
		for(j=1 ; j<=18 ; j++)
		{
			if(flag==FAST)
			{
				if(y>=i*30-60 && y<=i*30+30+60)
					if(x>=j*30-60 && x<=j*30+30+60)
					{
						if(j*30-ggx>0 && j*30-ggx<XSIZE+30)
						if(i*30-ggy>0 && i*30-ggy<YSIZE+30)
						{
						old2=(HBITMAP *)SelectObject(bitDC,blockbit[map[i][j]]);
						BitBlt(MemDC,j*30-ggx,i*30-ggy,30,30,bitDC,0,0,SRCCOPY);
						SelectObject(bitDC,old2);
						}
					}
			}
			else
			{
				
						if(j*30-ggx>0 && j*30-ggx<XSIZE+30)
						if(i*30-ggy>0 && i*30-ggy<YSIZE+30)
						{
				old2=(HBITMAP *)SelectObject(bitDC,blockbit[map[i][j]]);
				BitBlt(MemDC,j*30-ggx,i*30-ggy,30,30,bitDC,0,0,SRCCOPY);
				SelectObject(bitDC,old2);
						}
			}
		}
		
	//	ggx+=gx*30;
	//	ggy+=gx*30;
	for(i=-16 ; i<=32 ; i++)
		for(j=-18 ; j<=36 ; j++)
		{
			if(1<=i && i<=16 && 1<=j && j<=18){}
			else
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
	if(flag==FAST)
		BitBlt(hDC,pt.x+x-60,pt.y+y-60,120,120,MemDC,x-60,y-60,SRCCOPY);
	if(flag==ALL)
		BitBlt(hDC,pt.x,pt.y,30*18,30*16,MemDC,30,30,SRCCOPY);
	//BitBlt(hDC,0,0,30*19,30*17,MemDC,0,0,SRCCOPY);
	SelectObject(MemDC,old);
	ReleaseDC(hWnd,MemDC);
	ReleaseDC(hWnd,bitDC);
	ReleaseDC(hWnd,hDC);
	DeleteObject(bit);
	DeleteObject(old);
	DeleteObject(old2);
	DeleteObject(old3);
	DeleteObject(MemDC);
	DeleteObject(bitDC);
    lpddSPrimary->ReleaseDC(hDC);

	ggx+=gx*30-30;
	ggy+=gy*30-30;

}

int mapmove()
{
	int i, j, flag;
	flag=0;
	if(x<30)
	{
		x+=XSIZE;
		gx-=18;
		flag=1;
	}
	else if(x>XSIZE+30)
	{
		x-=XSIZE;
		gx+=18;
		flag=1;
	}
	if(y<30)
	{
		y+=YSIZE;
		gy-=16;
		flag=1;
	}
	else if(y>YSIZE+30)
	{
		y-=YSIZE;
		gy+=16;
		flag=1;
	}
	if(flag)
	{
		for(i=gy ; i<=gy+18 ; i++)
			for(j=gx ; j<=gx+20 ; j++)
			{
				map[i-gy][j-gx]=allmap[i-1][j-1];
			}
		nef=efn[gy/16+1][gx/18+1].enef;
		for(i=1 ; i<=nef ; i++)
			ef[i]=effect[efn[gy/16+1][gx/18+1].eef[i]];
		rightdraw(window);
	}
	return flag;
}

int rhitblock(int xx,int yy,int block,int dir)
{
	if(yy>30*21 || xx<0 || xx>30*21 || yy<0)
		return 0;
	int flag=0;
	int r=RANGE;
	if(map[yy/30][(bx+CSX)/30]!=block && map[yy/30][(xx+CSX)/30]==block && bx<xx)
	{
		if(dir==1)
			return 1;
	}
	if(map[yy/30][(bx-CSX)/30]!=block && map[yy/30][(xx-CSX)/30]==block && bx>xx)
	{
		if(dir==2)
			return 1;
	}
	if(map[(yy-r)/30][(bx+CSX)/30]!=block && map[(yy-r)/30][(xx+CSX)/30]==block && bx<xx)
	{
		if(dir==1)
			return 1;
	}
	if(map[(yy-r)/30][(bx-CSX)/30]!=block && map[(yy-r)/30][(xx-CSX)/30]==block && bx>xx)
	{
		if(dir==2)
			return 1;
	}
	if(map[(yy+r)/30][(bx+CSX)/30]!=block && map[(yy+r)/30][(xx+CSX)/30]==block && bx<xx)
	{
		if(dir==1)
			return 1;
	}
	if(map[(yy+r)/30][(bx-CSX)/30]!=block && map[(yy+r)/30][(xx-CSX)/30]==block && bx>xx)
	{
		if(dir==2)
			return 1;
	}

	if(map[(by-CSY)/30][xx/30]!=block && map[(yy-CSY)/30][xx/30]==block && by>yy)
	{
		if(dir==4)
			return 1;
	}
	if(map[(by+CSY)/30][xx/30]!=block && map[(yy+CSY)/30][xx/30]==block  && by<yy)
	{
		if(dir==3)
			return 1;
	}
	if(map[(by-CSY)/30][(xx-r)/30]!=block && map[(yy-CSY)/30][(xx-r)/30]==block && by>yy)
	{
		if(dir==4)
			return 1;
	}
	if(map[(by+CSY)/30][(xx-r)/30]!=block && map[(yy+CSY)/30][(xx-r)/30]==block && by<yy)
	{
		if(dir==3)
			return 1;
	}
	if(map[(by-CSY)/30][(xx+r)/30]!=block && map[(yy-CSY)/30][(xx+r)/30]==block && by>yy)
	{
		if(dir==4)
			return 1;
	}
	if(map[(by+CSY)/30][(xx+r)/30]!=block && map[(yy+CSY)/30][(xx+r)/30]==block)
	{
		if(dir==3)
			return 1;
	}
	return 0;
}
int hitblock(int xx,int yy,int block)
{
	if(yy>30*21 || xx<0 || xx>30*21 || yy<0)
		return 0;
	int r=RANGE;
	if(map[yy/30][(bx+CSX)/30]!=block && map[yy/30][(xx+CSX)/30]==block && bx<xx)
	{
		return 1;
	}
	if(map[yy/30][(bx-CSX)/30]!=block && map[yy/30][(xx-CSX)/30]==block && bx>xx)
	{
		return 2;
	}
	if(map[(yy-r)/30][(bx+CSX)/30]!=block && map[(yy-r)/30][(xx+CSX)/30]==block && bx<xx)
	{
		return 1;
	}
	if(map[(yy-r)/30][(bx-CSX)/30]!=block && map[(yy-r)/30][(xx-CSX)/30]==block && bx>xx)
	{
		return 2;
	}
	if(map[(yy+r)/30][(bx+CSX)/30]!=block && map[(yy+r)/30][(xx+CSX)/30]==block && bx<xx)
	{
		return 1;
	}
	if(map[(yy+r)/30][(bx-CSX)/30]!=block && map[(yy+r)/30][(xx-CSX)/30]==block && bx>xx)
	{
		return 2;
	}

	if(map[(by-CSY)/30][xx/30]!=block && map[(yy-CSY)/30][xx/30]==block && by>yy)
	{
		return 4;
	}
	if(map[(by+CSY)/30][xx/30]!=block && map[(yy+CSY)/30][xx/30]==block  && by<yy)
	{
		return 3;
	}
	if(map[(by-CSY)/30][(xx-r)/30]!=block && map[(yy-CSY)/30][(xx-r)/30]==block && by>yy)
	{
		return 4;
	}
	if(map[(by+CSY)/30][(xx-r)/30]!=block && map[(yy+CSY)/30][(xx-r)/30]==block && by<yy)
	{
		return 3;
	}
	if(map[(by-CSY)/30][(xx+r)/30]!=block && map[(yy-CSY)/30][(xx+r)/30]==block && by>yy)
	{
		return 4;
	}
	if(map[(by+CSY)/30][(xx+r)/30]!=block && map[(yy+CSY)/30][(xx+r)/30]==block)
	{
		return 3;
	}
	return 0;
}

int hiteffect(int xx,int yy,EFFECT eft)
{
	
	if(yy>30*21 || xx<0 || xx>30*21 || yy<0)
		return 0;
	int r=RANGE;
	if(bx+r<eft.ax-eft.xsize && xx+r>eft.ax-eft.xsize) //왼쪽에서 오른쪽
	{
		if(yy>eft.ay-eft.ysize-r && yy<eft.ay+eft.ysize+r)
			return 1;
	}
	
	if(bx-r>eft.ax+eft.xsize && xx-r<eft.ax+eft.xsize) //오른쪽에서 왼쪽
	{
		if(yy>eft.ay-eft.ysize-r && yy<eft.ay+eft.ysize+r)
			return 2;
	}
	if(by+r<eft.ay-eft.ysize && yy+r>eft.ay-eft.ysize)//위에서 아래
	{
		if(xx>eft.ax-eft.xsize-r && xx<eft.ax+eft.xsize+r)
			return 3;
	}
	if(by-r>eft.ay+eft.ysize && yy-r<eft.ay+eft.ysize)//아래에서 위
	{
		if(xx>eft.ax-eft.xsize-r && xx<eft.ax+eft.xsize+r)
			return 4;
	}
	return 0;
}

int oneffect(int xx,int yy,EFFECT eft)
{
	int r=RANGE;
	if(xx>eft.ax-eft.xsize-r && xx<eft.ax+eft.xsize+r){
		if(yy>eft.ay-eft.ysize-r && yy<eft.ay+eft.ysize+r)
			return 1;
	}
	return 0;
}
int onblock(int xx,int yy,int block)
{
	if(yy>30*21 || xx<0 || xx>30*21 || yy<0)
		return 0;
	if(map[yy/30][xx/30]==block)
		return 1;
	return 0;
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


void EFFECT::ifhit(int number,int _hit)
{
	if(ifn<number)
	{
		ifn=number;
	}
	iff[number].what=1;
	iff[number].hit=_hit;
}
void EFFECT::effhit(int number,int _hit,int _whichblock)
{
	if(ifn<number)
	{
		ifn=number;
	}
	iff[number].what=2;
	iff[number].effecthit=_hit;
	iff[number].whichblock=_whichblock;
}
void EFFECT::always(int number)
{
	if(ifn<number)
	{
		ifn=number;
	}
	iff[number].what=0;
}
void EFFECT::moveme(int number,int _px,int _py,int _pvx,int _pvy,int _mx,int _my,int _mvx,int _mvy)
{
	mot[number].ex=mot[number].ey=mot[number].evx=mot[number].evy=0;
	mot[number].px=_px;
	mot[number].py=_py;
	mot[number].pvx=_pvx;
	mot[number].pvy=_pvy;
	mot[number].ax=_mx;
	mot[number].ay=_my;
	mot[number].avx=_mvx;
	mot[number].avy=_mvy;
	mot[number].what=1;
}
void EFFECT::moveeffct(int number,int _px,int _py,int _pvx,int _pvy,int _mx,int _my,int _mvx,int _mvy,double _afx,double _afy)
{
	mot[number].px=mot[number].py=mot[number].pvx=mot[number].pvy=0;
	mot[number].ex=_px;
	mot[number].ey=_py;
	mot[number].evx=_pvx;
	mot[number].evy=_pvy;
	mot[number].aex=_mx;
	mot[number].aey=_my;
	mot[number].aevx=_mvx;
	mot[number].aevy=_mvy;
	mot[number].what=1;
	mot[number].aavx=_afx;
	mot[number].aavy=_afy;
}
void EFFECT::excute()
{
	int i, flag;
	if(efftime>0)
	{
		efftime--;
		return;
	}
	if(ay==HIDEY && ax==HIDEX){}
	else
	{
		bfx=ax;
		bfy=ay;
		ax+=evx;
		ay+=evy;
		evx+=avx;
		evy+=avy;
	}
	EFFECT ttt;
	ttt.ax=ax;
	ttt.ay=ay;
	ttt.evx=evx;
	ttt.evy=evy;
	ttt.xsize=xsize;
	ttt.ysize=ysize;
	flag=0;
	for(i=1 ; i<=ifn ; i++)
	{
		////////////조건부
		if(iff[i].what!=4)
			flag=0;
		if(iff[i].what==0)
		{
			flag=1;
		}
		else if(iff[i].what==1)
		{
			//hit
			if(iff[i].hit==hiteffect(x,y,ttt))
			{
				flag=1;
			}
		}
		else if(iff[i].what==2)
		{
			//effecthit
			if(iff[i].effecthit==5 && onblock(ttt.ax,ttt.ay,iff[i].whichblock))
				flag=1;
			if(iff[i].effecthit!=5)
			{
				double tempx,tempy;
				tempx=bx;
				tempy=by;
				bx=bfx;
				by=bfy;
				if(rhitblock(ttt.ax,ttt.ay,iff[i].whichblock,iff[i].effecthit))
					flag=1;
				bx=tempx;
				by=tempy;
			}
		}
		else if(iff[i].what==3)
		{
			//flag
			if(fflag==iff[i].ff)
			{
				flag=1;
				fflag=0;
			}
		}
		else if(iff[i].what==5)
		{
			//effecthit
			if(oneffect(x,y,ttt))
				flag=1;
		}
		else if(iff[i].what==6)
		{
			if(keybd[iff[i].ff]==1)
				flag=1;
		}
		
		if(ttt.ay==HIDEY && ttt.ax==HIDEX && iff[i].what!=4 && iff[i].what!=3)
			continue;

	//////실행부
		if(flag==1)
		{
			
			//결과물 표시
			if(mot[i].what==1)
			{
				double _px=mot[i].px;
				double _py=mot[i].py;
				double _pvx=mot[i].pvx;
				double _pvy=mot[i].pvy;
				double _mx=mot[i].ax;
				double _my=mot[i].ay;
				double _mvx=mot[i].avx;
				double _mvy=mot[i].avy;
				
				if(_px!=0)
					x=_px;
				if(_py!=0)
					y=_py;
				if(_pvx!=0)
					vx=_pvx;
				if(_pvy!=0)
					vy=_pvy;
				if(_px==NO)x=0;
				if(_py==NO)y=0;
				if(_pvx==NO)vx=0;
				if(_pvy==NO)vy=0;
				x+=_mx;
				y+=_my;
				vx+=_mvx;
				vy+=_mvy;

				_px=mot[i].ex;
				_py=mot[i].ey;
				_pvx=mot[i].evx;
				_pvy=mot[i].evy;
				_mx=mot[i].aex;
				_my=mot[i].aey;
				_mvx=mot[i].aevx;
				_mvy=mot[i].aevy;

				if(_px!=0)
					ax=_px;
				if(_py!=0)
					ay=_py;
				if(_pvx!=0)
					evx=_pvx;
				if(_pvy!=0)
					evy=_pvy;
				if(_px==NO)ax=0;
				if(_py==NO)ay=0;
				if(_pvx==NO)evx=0;
				if(_pvy==NO)evy=0;
				
				ax+=_mx;
				ay+=_my;
				evx+=_mvx;
				evy+=_mvy;
				if(mot[i].aavx!=0)
				avx=mot[i].aavx;
				
				if(mot[i].aavy!=0)
				avy=mot[i].aavy;
				if(mot[i].fimg==1)
					imgnumber=mot[i].cimg;
			}
			else if(mot[i].what==2)
			{
				fflag=mot[i].ff;
			}
			else if(mot[i].what==3)
			{
				die();
			}
			else if(mot[i].what==4)
			{
				map[int(mot[i].py)][int(mot[i].px)]=mot[i].ff;
			}
			else if(mot[i].what==5)
			{
				efftime=mot[i].ff;
			}
			else if(mot[i].what==6)
			{
				evx*=-1;
				evy*=-1;
				avx*=-1;
				avy*=-1;
			}
		}
	}
}

void EFFECT::ifon(int number)
{
	if(ifn<number)
		ifn=number;
	iff[number].what=5;
}

void EFFECT::changeimg(int number,int _img)
{
	mot[number].ex=mot[number].ey=mot[number].evx=mot[number].evy=0;
	mot[number].px=mot[number].py=mot[number].pvx=mot[number].pvy=0;
	mot[number].fimg=1;
	mot[number].cimg=_img;
	mot[number].what=1;
}


void EFFECT::ifflag(int number,int _fflag)
{
	if(ifn<number)
		ifn=number;
	iff[number].what=3;
	iff[number].ff=_fflag;
}

void EFFECT::changeflag(int number,int _fflag)
{
	mot[number].what=2;
	mot[number].ff=_fflag;
}

void die()
{
	life--;
	dietime=20;
}

void EFFECT::death(int number)
{
	mot[number].what=3;
}

void EFFECT::ifgo(int number)
{
	if(ifn<number)
		ifn=number;
	iff[number].what=4;
}

void EFFECT::hide(int number)
{
	moveeffct(number,HIDEX,HIDEY,0,0,0,0,0,0,0,0);
}

void EFFECT::changeblock(int number,int _xx,int _yy,int _whichblock)
{
	mot[number].what=4;
	mot[number].px=_xx;
	mot[number].py=_yy;
	mot[number].ff=_whichblock;
}

void EFFECT::timelater(int number,int _time)
{
	mot[number].what=5;
	mot[number].ff=_time;
}

void filesave()
{
	FILE *out=fopen("grefish.txt","wb");
	fwrite(effect,sizeof(EFFECT),1000,out);
	fwrite(efn,sizeof(EFFECTNUMBER),10000,out);
	fwrite(allmap,sizeof(int),1000000,out);
	fwrite(&bgx,sizeof(int),1,out);
	fwrite(&bgy,sizeof(int),1,out);
	fwrite(&bbx,sizeof(int),1,out);
	fwrite(&bby,sizeof(int),1,out);
	fwrite(explain,sizeof(char),1000000,out);
	fclose(out);
}
void fileload()
{
	int i,j;
	FILE *out=fopen("grefish.txt","rb");
	if(out){
		fread(effect,sizeof(EFFECT),1000,out);
		fread(efn,sizeof(EFFECTNUMBER),10000,out);
		fread(allmap,sizeof(int),1000000,out);
		fread(&bgx,sizeof(int),1,out);
		fread(&bgy,sizeof(int),1,out);
		fread(&bbx,sizeof(int),1,out);
		fread(&bby,sizeof(int),1,out);
		fread(explain,sizeof(char),1000000,out);
		gx=bgx-18;
		gy=bgy;
		x=bbx+30*18;
		y=bby;
		fclose(out);
	}
}


void rightdraw(HWND hWnd)
{
	
	int possible;
	int max;
	int i, j, k;
	char str[256];
	HBITMAP bit, *old, *old2;
	HBRUSH *old3, brush;
	HDC hDC;
	HDC bitDC;

    lpddSPrimary->GetDC(&hDC);
	bitDC=CreateCompatibleDC(hDC);
	//hDC=BeginPaint(hWnd,&ps);

	old2=(HBITMAP *)SelectObject(bitDC,blockbit[RIGHT]);
	BitBlt(hDC,30*18+pt.x,pt.y,150,480,bitDC,0,0,SRCCOPY);
	SelectObject(bitDC,old2);
	TextOut(hDC,30*18+13+pt.x,30*2+18+pt.y,explain[gy/16+1][gx/18+1],15);
	TextOut(hDC,30*18+13+pt.x,30*2+38+pt.y,&explain[gy/16+1][gx/18+1][15],15);
	TextOut(hDC,30*18+13+pt.x,30*2+58+pt.y,&explain[gy/16+1][gx/18+1][30],15);
	TextOut(hDC,30*18+13+pt.x,30*2+78+pt.y,&explain[gy/16+1][gx/18+1][45],15);
	TextOut(hDC,30*18+13+pt.x,30*2+98+pt.y,&explain[gy/16+1][gx/18+1][60],15);
	TextOut(hDC,30*18+13+pt.x,30*2+118+pt.y,&explain[gy/16+1][gx/18+1][75],15);
//	SelectObject(MemDC,old);
	//ReleaseDC(hWnd,MemDC);
	ReleaseDC(hWnd,bitDC);
	ReleaseDC(hWnd,hDC);
	DeleteObject(bit);
	DeleteObject(old);
	DeleteObject(old2);
	DeleteObject(old3);
	//DeleteObject(MemDC);
	DeleteObject(bitDC);
	
    lpddSPrimary->ReleaseDC(hDC);
}


int GetClientPos()
{
    pt.x = 0;
    pt.y = 0;

    ClientToScreen(hWnd, &pt); // 클라이언트 영역의 화면 좌표를 구해온다. 
    GetClientRect(hWnd, &ClientRect); // 클라이언트 렉트를 구한다.
    
    return 0;
}
int Init(HWND m_hWnd)
{
	DDCOLORKEY ddColorKey;
    hWnd = m_hWnd;

    if( FAILED(DirectDrawCreate(NULL, &lpdd, NULL)) )
        return ERR;
    if( FAILED(lpdd->SetCooperativeLevel(hWnd, DDSCL_NORMAL)) )
        return ERR;

    // 프라이머리 서페이스 생성.
    memset(&ddsd, 0, sizeof(ddsd));
    ddsd.dwSize = sizeof(ddsd);
    ddsd.dwFlags = DDSD_CAPS;
    ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE;
    
    if( FAILED(lpdd->CreateSurface(&ddsd, &lpddSPrimary, NULL)) )
        return ERR;
    ddColorKey.dwColorSpaceHighValue = _RGB(lpddSPrimary, RGB(255, 0, 255));
    ddColorKey.dwColorSpaceLowValue = _RGB(lpddSPrimary, RGB(255, 0, 255));
	lpddSPrimary->SetColorKey(DDCKEY_SRCBLT, &ddColorKey);
  //  lstrcpy(str, "메롱");

    // 문자열의 초기 좌표 설정.
//    Text.X = 0;
  //  Text.Y = 0;
    //PreText.X = 1;
   // PreText.Y = 1;
    
    GetClientPos(); // 클라이언트의 화면상 위치를 구한다.

    return 0;
}

int Shutdown()
{
    SAFERELEASE( lpddSPrimary );
    SAFERELEASE( lpdd );

    return 0;
}

DWORD _RGB(LPDIRECTDRAWSURFACE Surf, COLORREF rgb)
{
    COLORREF                PreColor; // 이전에 찍혀있던 색상코드 백업용.
    HDC                          hdc;
    DWORD                      dw = CLR_INVALID;
    DDSURFACEDESC     ddsd;

    Surf->GetDC(&hdc);
    PreColor = GetPixel(hdc, 0, 0);     // 원래의 색상을 기억해 둔다.
    SetPixel(hdc, 0, 0, rgb);              // (0, 0)에 투명색으로 지정한 픽셀을 찍어준다.
    Surf->ReleaseDC(hdc);

    // 우리가 원하는 색을 구할때까지,
    // 서페이스의 내용이 고정되어있도록 서페이스에 Lock을 걸어 둔다.
    ddsd.dwSize = sizeof(ddsd);

    if( SUCCEEDED(Surf->Lock(NULL, &ddsd, 0, NULL)) )
    {
        dw = *(DWORD*)ddsd.lpSurface; // 서페이스의 실제 메모리의 주소값을 얻어온다.

        Surf->Unlock(NULL);
    }

    Surf->GetDC(&hdc);
    SetPixel(hdc, 0, 0, PreColor); // (0, 0)의 색을 원래 색으로 되돌려준다.
    Surf->ReleaseDC(hdc);

    return dw;
}

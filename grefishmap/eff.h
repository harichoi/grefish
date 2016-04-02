
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
};


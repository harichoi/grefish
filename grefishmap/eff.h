
struct EFFECTNUMBER
{
	int enef;
	int eef[100];
};
struct MOTION
{
	int what;
	//1

	// �������� �����
	double px;
	double py;
	double pvx;
	double pvy;
	// �߰� �ϱ�
	double ax;
	double ay;
	double avx;
	double avy;
	// effect �� �����̱�
	
	// ����
	double ex;
	double ey;
	double evx;
	double evy;

	// �߰� �ϱ�
	double aex;
	double aey;
	double aevx;
	double aevy;
	double aavx;
	double aavy;

	int fimg;
	int cimg;
	
	//2 flag ����
	int ff;
	
	//3 die

	//4 ��� ��ȯ

	//5 �ð�
};
struct IFF
{
	int what;
	//what
	//0 always.
	//1 hit.
	int hit; //����
	//2 effect �� ������ �浹
	int effecthit;
	int whichblock;
	//3 flag
	int ff;
	//4 ����
	//5 effect �� ���� �浹
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


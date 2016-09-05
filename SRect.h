#ifndef FSRECT_H
#define FSRECT_H

struct SRect{
	short int x1; //left-up conner position
	short int y1;
	short int x2; //right-bottom conner position
	short int y2;
	SRect() :x1(0), y1(0), x2(100), y2(100){}
	SRect(short int a1, short  int b1, short  int a2, short  int b2) :x1(a1), y1(b1), x2(a2), y2(b2){}
	inline void setLeft(short int x, short  int y) //set left-up conner
	{
		x1 = x; y1 = y;
	}
	inline void setRight(short int x, short  int y) //set right-bottom
	{
		x2 = x; y2 = y;
	}
	inline bool check() //��������Ƿ���Ͼ���
	{
		return x1 >= 0 && y1 >= 0 && x2 > 0 && y2 > 0 && x1 < x2 && y1 < y2;
	}
	inline SRect getClip(SRect& rt){ //rt��this�У��õ����Ծ��ε�����
		SRect res = rt;
		if (check() && rt.check()){
			res.x1 = x1 + rt.x1;
			res.y1 = y1 + rt.y1;
			res.x2 = x1 + rt.x2;
			res.y2 = y1 + rt.y2;
		}
		return res;
	}
	inline SRect& operator-=(short val) //���ο���С
	{
		x1 += val;
		y1 += val;
		x2 -= val;
		y2 -= val;
		if (!check()) { //��С��ͷ�����һ����
			x2 = x1;
			y2 = y1;
		}
		return *this;
	}
	inline bool isContains(short x,short y) //�����Ƿ������ؾ�����
	{
		return x >= x1 && x <= x2 && y >= y1 && y <= y2;
	}
	inline SRect& operator|=(const SRect& rt){ //ȡ����rt�Ļ������ľ���
		if (x1 > rt.x1) x1 = rt.x1;
		if (y1 > rt.y1) y1 = rt.y1;
		if (x2 < rt.x2) x2 = rt.x2;
		if (y2 < rt.y2) y2 = rt.y2;
		return *this;
	}
	inline short getWidth()
	{
		if (x2 >= x1)
			return x2 - x1;
		else return 0;
	}
	inline short getHeight()
	{
		if (y2 >= y1)
				return y2 - y1;
		else return 0;
	}
};
#endif
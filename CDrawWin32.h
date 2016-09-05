#ifndef CDRAWWIN32_H
#define CDRAWWIN32_H
#include<windows.h>
#include "IDrawInterface.h"
/*windows的绘图接口类，继承IDrawInterface*/
class CDrawWin32:public IDrawInterface{
public:
	CDrawWin32(){
		beginCount = 0;
		memHdc = NULL;
	}
	void setHDC(HDC hd){	canvasHdc = hd; }
	void setCanvas(short int x1, short int y1, short int x2, short int y2){ canvasRect = SRect(x1,y1,x2,y2); }
	void beginDraw(SRect& rt);
	void drawDotRect(SRect& rt, COLORVAL color); //绘制四条虚线的矩形
	void drawPolyLine(SPoint * points, int n, COLORVAL  color); //画一条折线，首尾相连,points是点的数组,n是点的数目
	void drawText(const char* text, int x, int y, COLORVAL color); //画文字
	void fillRect(SRect& rt, COLORVAL backColor, COLORVAL foreColor); //填充矩形,背景色是边框，前景色是填充色
	//virtual WORD FG_OSDrawInterface::GetTextHeight(const char *  	Text)[pure virtual]
	short  getTextHeight(const char *	Text); //得到文本高度
	//virtual WORD FG_OSDrawInterface::GetTextWidth(const char *  	Text)[pure virtual]
	short  getTextWidth(const char *	Text);  //得到文本宽度
	void line(int x1, int y1, int x2, int y2, COLORVAL color); //画一条直线
	void drawBitmap(const char*, int, int); //画位图
	void endDraw();
	~CDrawWin32(){
		if (memHdc)
			DeleteObject(memHdc);
	}
private:
	//HDC hdc;  //区域的hdc
	//HRGN hClip; //当前所画区域
	HBITMAP hBitmap;
	HDC canvasHdc;//画布的HDC
	HDC memHdc;	//临时hdc
	int beginCount;	//调用beginDraw()的次数
	HPEN pen; //画笔
	HBRUSH brush; //画刷
	SRect ivalidRect;	//重画的区域，复制到canvasHdc中
};

#endif
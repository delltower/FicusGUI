#ifndef CDRAWX11_H
#define CDRAWX11_H
#include<string>
#include "IDrawInterface.h"
/*X11的绘图接口类，继承IDrawInterface*/
class CDrawX11{
public:
	CDrawX11(){}
	 
	  void beginDraw(SRect&);	//开始画图，提供画图的矩形
	  void endDraw(); //结束画图，回收资源
	  void fillRect(SRect&, COLORVAL foreColor, COLORVAL backgroundColor);//填充矩形，提供前景色，背景色
	//画直线，提供起点和终点，坐标是相对于画布的，使用时加上所在矩形的起点
	  void line(int, int, int, int, COLORVAL);
	//画文字,提供内容和位置，文字颜色
	  void drawText(char*, int, int, COLORVAL);
	//得到文本的宽度
	  short getTextWidth(char*);
	//得到文本的高度
	  short getTextHeight(char*);
	//画位图
	  void drawBitmap(char*, int, int);
	//画折线,提供点的数组，点的个数，颜色
	  void drawPolyLine(SPoint*, int, COLORVAL);
	//画虚线矩形，提供矩形大小坐标和颜色
	virtual void drawDotRect(SRect&, COLORVAL);
private:
	std::string str;
};
#endif
#ifndef IDRAWINTERFACE_H
#define IDRAWINTERFACE_H
#include"SRect.h"
#include"FCommon.h"
#include"SPoint.h"
/*绘图接口，虚基类*/
class IDrawInterface
{
public:
	IDrawInterface(){}
	~IDrawInterface(){}
	virtual void beginDraw(SRect&) = 0;	//开始画图，提供画图的矩形
	virtual void endDraw() = 0; //结束画图，回收资源
	virtual void fillRect(SRect&, COLORVAL foreColor, COLORVAL backgroundColor) = 0;//填充矩形，提供前景色，背景色
	//画直线，提供起点和终点，坐标是相对于画布的，使用时加上所在矩形的起点
	virtual void line(int, int, int, int, COLORVAL) = 0;
	//画文字,提供内容和位置，文字颜色
	virtual void drawText(const char*, int, int, COLORVAL) = 0;
	//得到文本的宽度
	virtual short  getTextWidth(const char*) = 0;
	//得到文本的高度
	virtual short  getTextHeight(const char*) = 0;
	//画位图
	virtual void drawBitmap(const char*, int, int) = 0;
	//画折线,提供点的数组，点的个数，颜色
	virtual void drawPolyLine(SPoint*, int, COLORVAL) = 0;
	//画虚线矩形，提供矩形大小坐标和颜色
	virtual void drawDotRect(SRect&, COLORVAL) = 0;

protected:
	SRect canvasRect;//	画布

};

#endif // !IDRAWINTERFACE_H

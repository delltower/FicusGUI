#include "CDrawX11.h"

//开始画图，提供画图的矩形
void CDrawX11::beginDraw(SRect&)	{}
//结束画图，回收资源
void CDrawX11::endDraw() {}
//填充矩形，提供前景色，背景色
void CDrawX11::fillRect(SRect&, COLORVAL foreColor, COLORVAL backgroundColor){}
//画直线，提供起点和终点，坐标是相对于画布的，使用时加上所在矩形的起点
void CDrawX11::line(int, int, int, int, COLORVAL){}
//画文字,提供内容和位置，文字颜色
void CDrawX11::drawText(char*, int, int, COLORVAL){}
//得到文本的宽度
short  CDrawX11::getTextWidth(char*){ return 0; }
//得到文本的高度
short  CDrawX11::getTextHeight(char*){ return 0; }
//画位图
void CDrawX11::drawBitmap(char*, int, int){}
//画折线,提供点的数组，点的个数，颜色
void CDrawX11::drawPolyLine(SPoint*, int, COLORVAL){}
//画虚线矩形，提供矩形大小坐标和颜色
void CDrawX11::drawDotRect(SRect&, COLORVAL){}

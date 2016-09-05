#include<windows.h>
#include "CDrawWin32.h"
/*windows的绘图接口类，继承IDrawInterface*/
void CDrawWin32::beginDraw(SRect& rt){
	 //没有处理位图
	 //根据rt与画布的位置产生新的区域，在区域内作图,作图的参数是相对于某个窗口的坐标，窗口位置是传入的rt参数
	 //rt = canvasRect.getClip(rt);
	 //hClip = CreateRectRgn(rt.x1, rt.y1, rt.x2, rt.y2);
	// SelectObject(canvasHdc, hClip);

	if (!beginCount){
		if (!memHdc){
			memHdc = CreateCompatibleDC(canvasHdc);  //新建的内存环境只有1像素的宽和高，必须增大它
			hBitmap = CreateCompatibleBitmap(canvasHdc, SCREEN_WIDTH, SCREEN_HEIGHT);  
			SelectObject(memHdc, hBitmap);
			//SelectObject(canvasHdc,memHdc);
		}
		ivalidRect = rt;
	}
	else{
		ivalidRect |= rt;   //更大的区域
	}
	beginCount++;
}
void CDrawWin32::drawDotRect(SRect& rt, COLORVAL color) //绘制四条虚线的矩形
{
	if (memHdc){
		//创建画笔，并选入设备环境
		pen = (HPEN)SelectObject(memHdc, CreatePen(PS_DOT, 1, color));

		MoveToEx(memHdc, rt.x1, rt.y1, NULL); //顺时针开始画
		LineTo(memHdc, rt.x2, rt.y1);  //第一条
		LineTo(memHdc, rt.x2, rt.y2);	//第二条
		LineTo(memHdc, rt.x1, rt.y2);  //第三条
		LineTo(memHdc, rt.x1, rt.y1);  //第四条

		//删除新画笔，恢复原画笔
		DeleteObject(SelectObject(memHdc, pen));
	}
}
void CDrawWin32::drawPolyLine(SPoint * points, int n, COLORVAL  color) //画一条折线，首尾相连,points是点的数组,n是点的数目
{
	if (memHdc && points && n > 1){
		//创建画笔，并选入设备环境
		pen = (HPEN)SelectObject(memHdc, CreatePen(PS_SOLID, 1, color));
		//转化为win32的point
		POINT* winPoints = (POINT*)malloc(sizeof(POINT)*n);
		for (int i = 0; i < n; i++){
			winPoints[i].x = points[i].x;
			winPoints[i].y = points[i].y;
		}
		//画折线
		Polyline(memHdc, winPoints, n);
		//删除新画笔，恢复原画笔
		DeleteObject(SelectObject(memHdc, pen));
	}
}
void CDrawWin32::drawText(const char* text, int x, int y, COLORVAL color) //画文字
{
	if (memHdc && text){
		SetTextColor(memHdc, color);
		SetBkMode(memHdc, TRANSPARENT);
		TextOut(memHdc, x, y, TEXT(text), strlen(text));
	}
}
void CDrawWin32::fillRect(SRect& rt, COLORVAL backColor, COLORVAL foreColor) //填充矩形,前景色是边框，背景色是填充色
{
	if (memHdc && rt.check())	{
		//创建画笔，并选入设备环境
		pen = (HPEN)SelectObject(memHdc, CreatePen(PS_SOLID, 1, foreColor));
		//创建画刷，并选入设备环境
		brush = (HBRUSH)SelectObject(memHdc, CreateSolidBrush(backColor));

		Rectangle(memHdc, rt.x1, rt.y1, rt.x2, rt.y2);

		//删除新画笔，恢复原画笔
		DeleteObject(SelectObject(memHdc, pen));
		//删除临时画刷，恢复原画刷
		DeleteObject(SelectObject(memHdc, brush));
	}
}
short  CDrawWin32::getTextHeight(const char *	Text) //得到文本高度
{
	//文字未处理
	if (memHdc)
	{
		SIZE size;
		GetTextExtentPoint(memHdc, Text, strlen(Text), &size);
		return (WORD)size.cy;
	}
	else
		return 0;
}
short  CDrawWin32::getTextWidth(const char *	Text){ //得到文本宽度

	//文字未处理
	if (memHdc)
	{
		SIZE size;
		GetTextExtentPoint(memHdc, Text, strlen(Text), &size);
		return (WORD)size.cx;
	}
	else
		return 0;
}
void CDrawWin32::line(int x1, int y1, int x2, int y2, COLORVAL color) //画一条直线
{
	if (memHdc && x1 >= 0 && y1 >= 0 && x2 >= 0 && y2 >= 0){
		//创建画笔，并选入设备环境
		pen = (HPEN)SelectObject(memHdc, CreatePen(PS_SOLID, 1, color));

		MoveToEx(memHdc, x1, y1, NULL);
		LineTo(memHdc, x2, y2);

		//删除新画笔，恢复原画笔
		DeleteObject(SelectObject(memHdc, pen));
	}
}
//画位图,提供位图名字和画图的坐标
void CDrawWin32::drawBitmap(const char* name, int x, int y){
	if (memHdc){
		HDC hdcMem = CreateCompatibleDC(canvasHdc);
		BITMAP info;
		HBITMAP bitmap = (HBITMAP)LoadImage(NULL, name, IMAGE_BITMAP, 0, 0,
			LR_DEFAULTSIZE | LR_LOADFROMFILE);
		GetObject(bitmap,sizeof(BITMAP),&info);
		SelectObject(hdcMem, bitmap);
		BitBlt(memHdc, x, y, info.bmWidth, info.bmHeight, hdcMem, 0, 0, SRCCOPY);  //暂时放入临时区

		DeleteObject(hdcMem);
		DeleteObject(bitmap);
	}
} 
void CDrawWin32::endDraw()
{
	--beginCount;
	if (!beginCount){
		BitBlt(canvasHdc, ivalidRect.x1, ivalidRect.y1, ivalidRect.x2 - ivalidRect.x1 + 1, ivalidRect.y2 - ivalidRect.y1 + 1,
			memHdc, ivalidRect.x1, ivalidRect.y1, SRCCOPY);
	}
}
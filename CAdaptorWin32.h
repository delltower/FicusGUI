#ifndef CFSADAPTORWIN32_H
#define CFSADAPTORWIN32_H
#include<windows.h>
#include "CDrawWin32.h"
#include "CAdaptor.h"

class CAdaptorWin32 :public CAdaptor{
public:
	////画图
	//void beginDraw(SRect&);	//开始画图，提供画图的矩形
	//void endDraw(); //结束画图，回收资源
	//void fillRect(SRect&, COLORVAL foreColor, COLORVAL backgroundColor);//填充矩形，提供前景色，背景色
	////画直线，提供起点和终点，坐标是相对于画布的，使用时加上所在矩形的起点
	//void line(int, int, int, int, COLORVAL);
	////画文字,提供内容和位置，文字颜色
	//void drawText(const char*, int, int, COLORVAL);
	////得到文本的宽度
	//int getTextWidth(const char*);
	////得到文本的高度
	//int getTextHeight(const char*);
	//画位图
	void drawBitmap(const char*, int, int);  // 重写基类函数
	////画折线,提供点的数组，点的个数，颜色
	//void drawPolyLine(SPoint*, int, COLORVAL);
	////画虚线矩形，提供矩形大小坐标和颜色
	//void drawDotRect(SRect&, COLORVAL);

	//设置win32的句柄
	void setWin32Handle(HINSTANCE hInstance, HINSTANCE preHinstance, int iCmdShow){
		handle = hInstance;
		preHandle = preHinstance;
		showStyle = iCmdShow;
	}
	//设置bmp图形目录
	void setBmpPath(const char* path){
		unsigned i = 0, size = strlen(path);
		for (i = 0; i < size; i++) 
			bitmapPath[i] = path[i];
	}
	//IObserver* setObserver(IObserver*,MSGTYPE);//注册观察者,返回上次的观察者
	//void sendMsg(SMsg&); //发送消息
	void processMessage(SMsg&);  //处理消息

	////激活区域
	//void activateRect(short x1, short y1, short x2,short y2)
	//{
	//	RECT rt;
	//	rt.left = x1;
	//	rt.top = y1;
	//	rt.right = x2;
	//	rt.bottom = y2;
	//	InvalidateRect(h, &rt, TRUE);
	//}
public:
	void initInstance();//初始化程序
	void executeInstance();//执行程序
	void exitInstance();//退出程序
	static LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam); //windows程序消息处理函数
private:
	HINSTANCE  handle;	//windows程序句柄
	HINSTANCE  preHandle;	//父程序的程序句柄
	int showStyle; //windows程序的初始化方式
	//static HWND h;
	char bitmapPath[MAX_PATHNAME + 1]; //最大路径长度
	//static IDrawInterface* pDraw;
};

#endif
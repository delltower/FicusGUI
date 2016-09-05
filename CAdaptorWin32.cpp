#include<windows.h>
#include "CAdaptorWin32.h"
#include "CLabel.h"
#include "CButton.h"
#include "CRadioButton.h"
#include "CCheckBox.h"
#include "CGroup.h"
#include "CEdit.h"
//HWND CAdaptorWin32::h = NULL;
////开始画图，提供画图的矩形
//void CAdaptorWin32::beginDraw(SRect& rt){
//	if (pDraw)
//		pDraw->beginDraw(rt);
//}
////结束画图，回收资源
//void CAdaptorWin32::endDraw()
//{
//	if (pDraw)
//		pDraw->endDraw();
//}
////填充矩形，提供前景色，背景色
//void CAdaptorWin32::fillRect(SRect& rt, COLORVAL foreColor, COLORVAL backgroundColor)
//{
//	if (pDraw)
//		pDraw->fillRect(rt, foreColor, backgroundColor);
//}
////画直线，提供起点和终点，坐标是相对于画布的，使用时加上所在矩形的起点
//void CAdaptorWin32::line(int x1, int y1, int x2, int y2, COLORVAL color)
//{
//	if (pDraw)
//		pDraw->line(x1, y1, x2, y2, color);
//}
////画文字,提供内容和位置，文字颜色
//void CAdaptorWin32::drawText(const char* text, int x, int y, COLORVAL color)
//{
//	if (pDraw && text)
//		pDraw->drawText(text, x, y, color);
//}
////得到文本的宽度
//int CAdaptorWin32::getTextWidth(const char* text){
//	if (pDraw && text)
//		return pDraw->getTextWidth(text);
//	else return 0;
//}
////得到文本的高度
//int CAdaptorWin32::getTextHeight(const char* text)
//{
//	if (pDraw && text)
//		return pDraw->getTextHeight(text);
//	else return 0;
//}
//画位图,提供位图名字和开始画的坐标
void CAdaptorWin32::drawBitmap(const char* name, int x, int y){
	if (pDraw && name && x >= 0 && y >= 0){
		char pathName[MAX_PATHNAME + 1];
		unsigned i = 0,size = strlen(bitmapPath);
		while (i < size && i <= MAX_PATHNAME){
			pathName[i] = bitmapPath[i];
			i++;
		}
		pathName[i++] = '\\';
		unsigned j = 0;
		size = strlen(name);
		while (j < size){
			pathName[i + j] = name[j];
			j++;
		}
		pathName[i + j] = '\0';
		pDraw->drawBitmap(pathName, x, y);
	}
}
////画折线,提供点的数组，点的个数，颜色
//void CAdaptorWin32::drawPolyLine(SPoint* points, int n, COLORVAL color)
//{
//	if (pDraw)
//		pDraw->drawPolyLine(points, n, color);
//}
////画虚线矩形，提供矩形大小坐标和颜色
//void CAdaptorWin32::drawDotRect(SRect& rt, COLORVAL color)
//{
//	if (pDraw)
//		pDraw->drawDotRect(rt, color);
//}
//初始化程序
void CAdaptorWin32::initInstance()
{
	static TCHAR szAppName[] = TEXT("clover");
	HWND hwnd;
	WNDCLASS wndClass;

	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	//wndClass.style = WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX& ~WS_THICKFRAME; //固定长和宽
	wndClass.lpfnWndProc = CAdaptorWin32::WndProc;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hInstance = handle;
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hCursor = LoadCursor(NULL, IDI_APPLICATION);
	wndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndClass.lpszMenuName = NULL;
	wndClass.lpszClassName = szAppName;

	if (!RegisterClass(&wndClass)){
		MessageBox(NULL, TEXT("This program requiers Windows NT!"), szAppName, MB_ICONERROR);
		//return 0;
	}

	hwnd = CreateWindow(szAppName, //window class name
		TEXT("The Hello Program"), //window caption
		WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX& ~WS_THICKFRAME, //window style 长度和宽度不可以改变，不能最大化
		//WS_OVERLAPPEDWINDOW, // window style  默认风格
		CW_USEDEFAULT, // initial x position
		CW_USEDEFAULT, // initial y position
		SCREEN_WIDTH,//CW_USEDEFAULT, // initial x size
		SCREEN_HEIGHT,//CW_USEDEFAULT, // initial y size
		NULL, // parent window handle
		NULL, // window menu handle
		handle, // program instance handle
		NULL); // creation parameters

	//发送启动消息
	SMsg msg(STARTUP_MSG, NULL);
	sendMsg(msg);
	//定时器设置
	SetTimer(hwnd, 1, 500, NULL);
	ShowWindow(hwnd,showStyle);
	UpdateWindow(hwnd);

}
//执行程序
void CAdaptorWin32::executeInstance()
{
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}
//退出程序
void CAdaptorWin32::exitInstance()
{

}
//处理消息
void CAdaptorWin32::processMessage(SMsg& msg)
{

}
//windows程序消息处理函数
LRESULT CALLBACK CAdaptorWin32::WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	//SRect rt1(20, 20, 40, 40), rt2(10, 10, 300, 300);
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rt;
	//SMsg msg;
	//CLabel* pLabel = new CLabel("first label", SRect(20, 20, 100, 100));
	////CButton* pButton = new CButton("first button", SRect(50, 50, 100, 100));
	//CRadioButton* pRadioButton = new CRadioButton("first radio button", SRect(50, 50, 100, 100));
	//CCheckBox* pCheckBox = new CCheckBox("first radio button", SRect(50, 50, 100, 100));
	//CGroup* pGroup = new CGroup("first group", SRect(50, 50, 200, 200));
	//CEdit* pEdit = new CEdit(SRect(50, 50, 70, 70),30);

	switch (message)
	{
	/*case WM_CREATE:
		msg = SMsg(STARTUP_MSG, NULL);
		sendMsg(msg);
		return 0;*/
	case WM_PAINT:{
			hdc = BeginPaint(hwnd, &ps);
			GetClientRect(hwnd, &rt);
			pDraw = new CDrawWin32();
			((CDrawWin32*)pDraw)->setHDC(hdc);
			((CDrawWin32*)pDraw)->setCanvas((short)rt.left, (short)rt.top, (short)rt.right, (short)rt.bottom);
			/*pDraw->beginDraw(SRect(rt.left,rt.top,rt.right,rt.bottom));
			pDraw->line(0,0,50,50,COLOR_WHITE);
			pDraw->endDraw();*/
			SMsg msg(DRAW_MSG, NULL);
			sendMsg(msg);
			//((CAdaptorWin32 *)CAdaptor::getAdaptor())->beginDraw(rt2);
			//pDraw->fillRect(rt2, COLOR_GRAY, COLOR_GRAY);
			////pRadioButton->onDraw((CAdaptorWin32 *)CAdaptor::getAdaptor());
			////pCheckBox->onDraw((CAdaptorWin32 *)CAdaptor::getAdaptor());
			////pGroup->onDraw((CAdaptorWin32 *)CAdaptor::getAdaptor());
			//pEdit->onDraw((CAdaptorWin32 *)CAdaptor::getAdaptor());
			////pLabel->setBgColor(COLOR_GRAY);
			////pLabel->onDraw(pDraw);
			//((CAdaptorWin32 *)CAdaptor::getAdaptor())->endDraw();
			////DrawText(hdc, "hello world", -1, &rt, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
			//
			EndPaint(hwnd, &ps);
			//_CrtDumpMemoryLeaks();
			return 0;
		}
	case WM_LBUTTONDOWN:{ //鼠标按下
		hdc = GetDC(hwnd);
		((CDrawWin32*)pDraw)->setHDC(hdc);
		short x = LOWORD(lParam);
		short y = HIWORD(lParam);
		SMsg msg(MOUSEDOWN_MSG,NULL);
		msg.x = x;
		msg.y = y;
		sendMsg(msg);
		ReleaseDC(hwnd, hdc);
		return 0;
	}
	case WM_KEYDOWN:{
		hdc = GetDC(hwnd);
		((CDrawWin32*)pDraw)->setHDC(hdc);
		SMsg msg(KEY_MSG,NULL);
		if ((wParam >= '0' && wParam <= '9') || (wParam >= 'A' && wParam <= 'Z') || (wParam >= 'a' && wParam <= 'z')){
			msg.keyData = wParam;
			sendMsg(msg);
		}
		else {
			switch (wParam){
			case VK_DELETE:
				msg.keyData = FVK_DELETE;
				break;
			case VK_BACK:
				msg.keyData = FVK_BACK;
				break;
			case VK_LEFT:
				msg.keyData = FVK_LEFT;
					break;
			case VK_RIGHT:
				msg.keyData = FVK_RIGHT;
				break;
			default:
				break;
			}
			sendMsg(msg);
		}
		
		ReleaseDC(hwnd, hdc);
		return 0;
	}
	case WM_LBUTTONUP:{ //鼠标安起
		hdc = GetDC(hwnd);
		((CDrawWin32*)pDraw)->setHDC(hdc);
		short x = LOWORD(lParam);
		short y = HIWORD(lParam);
		SMsg msg(MOUSEUP_MSG, NULL);
		msg.x = x;
		msg.y = y;
		sendMsg(msg);
		ReleaseDC(hwnd, hdc);
		return 0;
	}
	case WM_TIMER:{  //定时器消息
		hdc = GetDC(hwnd);
		((CDrawWin32*)pDraw)->setHDC(hdc);
		SMsg msg(TIMER_MSG, NULL);
		sendMsg(msg);
		ReleaseDC(hwnd, hdc);
		return 0;
	}
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}
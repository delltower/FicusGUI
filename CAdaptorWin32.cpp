#include<windows.h>
#include "CAdaptorWin32.h"
#include "CLabel.h"
#include "CButton.h"
#include "CRadioButton.h"
#include "CCheckBox.h"
#include "CGroup.h"
#include "CEdit.h"
//HWND CAdaptorWin32::h = NULL;
////��ʼ��ͼ���ṩ��ͼ�ľ���
//void CAdaptorWin32::beginDraw(SRect& rt){
//	if (pDraw)
//		pDraw->beginDraw(rt);
//}
////������ͼ��������Դ
//void CAdaptorWin32::endDraw()
//{
//	if (pDraw)
//		pDraw->endDraw();
//}
////�����Σ��ṩǰ��ɫ������ɫ
//void CAdaptorWin32::fillRect(SRect& rt, COLORVAL foreColor, COLORVAL backgroundColor)
//{
//	if (pDraw)
//		pDraw->fillRect(rt, foreColor, backgroundColor);
//}
////��ֱ�ߣ��ṩ�����յ㣬����������ڻ����ģ�ʹ��ʱ�������ھ��ε����
//void CAdaptorWin32::line(int x1, int y1, int x2, int y2, COLORVAL color)
//{
//	if (pDraw)
//		pDraw->line(x1, y1, x2, y2, color);
//}
////������,�ṩ���ݺ�λ�ã�������ɫ
//void CAdaptorWin32::drawText(const char* text, int x, int y, COLORVAL color)
//{
//	if (pDraw && text)
//		pDraw->drawText(text, x, y, color);
//}
////�õ��ı��Ŀ��
//int CAdaptorWin32::getTextWidth(const char* text){
//	if (pDraw && text)
//		return pDraw->getTextWidth(text);
//	else return 0;
//}
////�õ��ı��ĸ߶�
//int CAdaptorWin32::getTextHeight(const char* text)
//{
//	if (pDraw && text)
//		return pDraw->getTextHeight(text);
//	else return 0;
//}
//��λͼ,�ṩλͼ���ֺͿ�ʼ��������
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
////������,�ṩ������飬��ĸ�������ɫ
//void CAdaptorWin32::drawPolyLine(SPoint* points, int n, COLORVAL color)
//{
//	if (pDraw)
//		pDraw->drawPolyLine(points, n, color);
//}
////�����߾��Σ��ṩ���δ�С�������ɫ
//void CAdaptorWin32::drawDotRect(SRect& rt, COLORVAL color)
//{
//	if (pDraw)
//		pDraw->drawDotRect(rt, color);
//}
//��ʼ������
void CAdaptorWin32::initInstance()
{
	static TCHAR szAppName[] = TEXT("clover");
	HWND hwnd;
	WNDCLASS wndClass;

	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	//wndClass.style = WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX& ~WS_THICKFRAME; //�̶����Ϳ�
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
		WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX& ~WS_THICKFRAME, //window style ���ȺͿ�Ȳ����Ըı䣬�������
		//WS_OVERLAPPEDWINDOW, // window style  Ĭ�Ϸ��
		CW_USEDEFAULT, // initial x position
		CW_USEDEFAULT, // initial y position
		SCREEN_WIDTH,//CW_USEDEFAULT, // initial x size
		SCREEN_HEIGHT,//CW_USEDEFAULT, // initial y size
		NULL, // parent window handle
		NULL, // window menu handle
		handle, // program instance handle
		NULL); // creation parameters

	//����������Ϣ
	SMsg msg(STARTUP_MSG, NULL);
	sendMsg(msg);
	//��ʱ������
	SetTimer(hwnd, 1, 500, NULL);
	ShowWindow(hwnd,showStyle);
	UpdateWindow(hwnd);

}
//ִ�г���
void CAdaptorWin32::executeInstance()
{
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}
//�˳�����
void CAdaptorWin32::exitInstance()
{

}
//������Ϣ
void CAdaptorWin32::processMessage(SMsg& msg)
{

}
//windows������Ϣ������
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
	case WM_LBUTTONDOWN:{ //��갴��
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
	case WM_LBUTTONUP:{ //��갲��
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
	case WM_TIMER:{  //��ʱ����Ϣ
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
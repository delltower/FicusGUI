#ifndef CFSADAPTORWIN32_H
#define CFSADAPTORWIN32_H
#include<windows.h>
#include "CDrawWin32.h"
#include "CAdaptor.h"

class CAdaptorWin32 :public CAdaptor{
public:
	////��ͼ
	//void beginDraw(SRect&);	//��ʼ��ͼ���ṩ��ͼ�ľ���
	//void endDraw(); //������ͼ��������Դ
	//void fillRect(SRect&, COLORVAL foreColor, COLORVAL backgroundColor);//�����Σ��ṩǰ��ɫ������ɫ
	////��ֱ�ߣ��ṩ�����յ㣬����������ڻ����ģ�ʹ��ʱ�������ھ��ε����
	//void line(int, int, int, int, COLORVAL);
	////������,�ṩ���ݺ�λ�ã�������ɫ
	//void drawText(const char*, int, int, COLORVAL);
	////�õ��ı��Ŀ��
	//int getTextWidth(const char*);
	////�õ��ı��ĸ߶�
	//int getTextHeight(const char*);
	//��λͼ
	void drawBitmap(const char*, int, int);  // ��д���ຯ��
	////������,�ṩ������飬��ĸ�������ɫ
	//void drawPolyLine(SPoint*, int, COLORVAL);
	////�����߾��Σ��ṩ���δ�С�������ɫ
	//void drawDotRect(SRect&, COLORVAL);

	//����win32�ľ��
	void setWin32Handle(HINSTANCE hInstance, HINSTANCE preHinstance, int iCmdShow){
		handle = hInstance;
		preHandle = preHinstance;
		showStyle = iCmdShow;
	}
	//����bmpͼ��Ŀ¼
	void setBmpPath(const char* path){
		unsigned i = 0, size = strlen(path);
		for (i = 0; i < size; i++) 
			bitmapPath[i] = path[i];
	}
	//IObserver* setObserver(IObserver*,MSGTYPE);//ע��۲���,�����ϴεĹ۲���
	//void sendMsg(SMsg&); //������Ϣ
	void processMessage(SMsg&);  //������Ϣ

	////��������
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
	void initInstance();//��ʼ������
	void executeInstance();//ִ�г���
	void exitInstance();//�˳�����
	static LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam); //windows������Ϣ������
private:
	HINSTANCE  handle;	//windows������
	HINSTANCE  preHandle;	//������ĳ�����
	int showStyle; //windows����ĳ�ʼ����ʽ
	//static HWND h;
	char bitmapPath[MAX_PATHNAME + 1]; //���·������
	//static IDrawInterface* pDraw;
};

#endif
#ifndef CDRAWWIN32_H
#define CDRAWWIN32_H
#include<windows.h>
#include "IDrawInterface.h"
/*windows�Ļ�ͼ�ӿ��࣬�̳�IDrawInterface*/
class CDrawWin32:public IDrawInterface{
public:
	CDrawWin32(){
		beginCount = 0;
		memHdc = NULL;
	}
	void setHDC(HDC hd){	canvasHdc = hd; }
	void setCanvas(short int x1, short int y1, short int x2, short int y2){ canvasRect = SRect(x1,y1,x2,y2); }
	void beginDraw(SRect& rt);
	void drawDotRect(SRect& rt, COLORVAL color); //�����������ߵľ���
	void drawPolyLine(SPoint * points, int n, COLORVAL  color); //��һ�����ߣ���β����,points�ǵ������,n�ǵ����Ŀ
	void drawText(const char* text, int x, int y, COLORVAL color); //������
	void fillRect(SRect& rt, COLORVAL backColor, COLORVAL foreColor); //������,����ɫ�Ǳ߿�ǰ��ɫ�����ɫ
	//virtual WORD FG_OSDrawInterface::GetTextHeight(const char *  	Text)[pure virtual]
	short  getTextHeight(const char *	Text); //�õ��ı��߶�
	//virtual WORD FG_OSDrawInterface::GetTextWidth(const char *  	Text)[pure virtual]
	short  getTextWidth(const char *	Text);  //�õ��ı����
	void line(int x1, int y1, int x2, int y2, COLORVAL color); //��һ��ֱ��
	void drawBitmap(const char*, int, int); //��λͼ
	void endDraw();
	~CDrawWin32(){
		if (memHdc)
			DeleteObject(memHdc);
	}
private:
	//HDC hdc;  //�����hdc
	//HRGN hClip; //��ǰ��������
	HBITMAP hBitmap;
	HDC canvasHdc;//������HDC
	HDC memHdc;	//��ʱhdc
	int beginCount;	//����beginDraw()�Ĵ���
	HPEN pen; //����
	HBRUSH brush; //��ˢ
	SRect ivalidRect;	//�ػ������򣬸��Ƶ�canvasHdc��
};

#endif
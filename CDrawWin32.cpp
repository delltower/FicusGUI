#include<windows.h>
#include "CDrawWin32.h"
/*windows�Ļ�ͼ�ӿ��࣬�̳�IDrawInterface*/
void CDrawWin32::beginDraw(SRect& rt){
	 //û�д���λͼ
	 //����rt�뻭����λ�ò����µ���������������ͼ,��ͼ�Ĳ����������ĳ�����ڵ����꣬����λ���Ǵ����rt����
	 //rt = canvasRect.getClip(rt);
	 //hClip = CreateRectRgn(rt.x1, rt.y1, rt.x2, rt.y2);
	// SelectObject(canvasHdc, hClip);

	if (!beginCount){
		if (!memHdc){
			memHdc = CreateCompatibleDC(canvasHdc);  //�½����ڴ滷��ֻ��1���صĿ�͸ߣ�����������
			hBitmap = CreateCompatibleBitmap(canvasHdc, SCREEN_WIDTH, SCREEN_HEIGHT);  
			SelectObject(memHdc, hBitmap);
			//SelectObject(canvasHdc,memHdc);
		}
		ivalidRect = rt;
	}
	else{
		ivalidRect |= rt;   //���������
	}
	beginCount++;
}
void CDrawWin32::drawDotRect(SRect& rt, COLORVAL color) //�����������ߵľ���
{
	if (memHdc){
		//�������ʣ���ѡ���豸����
		pen = (HPEN)SelectObject(memHdc, CreatePen(PS_DOT, 1, color));

		MoveToEx(memHdc, rt.x1, rt.y1, NULL); //˳ʱ�뿪ʼ��
		LineTo(memHdc, rt.x2, rt.y1);  //��һ��
		LineTo(memHdc, rt.x2, rt.y2);	//�ڶ���
		LineTo(memHdc, rt.x1, rt.y2);  //������
		LineTo(memHdc, rt.x1, rt.y1);  //������

		//ɾ���»��ʣ��ָ�ԭ����
		DeleteObject(SelectObject(memHdc, pen));
	}
}
void CDrawWin32::drawPolyLine(SPoint * points, int n, COLORVAL  color) //��һ�����ߣ���β����,points�ǵ������,n�ǵ����Ŀ
{
	if (memHdc && points && n > 1){
		//�������ʣ���ѡ���豸����
		pen = (HPEN)SelectObject(memHdc, CreatePen(PS_SOLID, 1, color));
		//ת��Ϊwin32��point
		POINT* winPoints = (POINT*)malloc(sizeof(POINT)*n);
		for (int i = 0; i < n; i++){
			winPoints[i].x = points[i].x;
			winPoints[i].y = points[i].y;
		}
		//������
		Polyline(memHdc, winPoints, n);
		//ɾ���»��ʣ��ָ�ԭ����
		DeleteObject(SelectObject(memHdc, pen));
	}
}
void CDrawWin32::drawText(const char* text, int x, int y, COLORVAL color) //������
{
	if (memHdc && text){
		SetTextColor(memHdc, color);
		SetBkMode(memHdc, TRANSPARENT);
		TextOut(memHdc, x, y, TEXT(text), strlen(text));
	}
}
void CDrawWin32::fillRect(SRect& rt, COLORVAL backColor, COLORVAL foreColor) //������,ǰ��ɫ�Ǳ߿򣬱���ɫ�����ɫ
{
	if (memHdc && rt.check())	{
		//�������ʣ���ѡ���豸����
		pen = (HPEN)SelectObject(memHdc, CreatePen(PS_SOLID, 1, foreColor));
		//������ˢ����ѡ���豸����
		brush = (HBRUSH)SelectObject(memHdc, CreateSolidBrush(backColor));

		Rectangle(memHdc, rt.x1, rt.y1, rt.x2, rt.y2);

		//ɾ���»��ʣ��ָ�ԭ����
		DeleteObject(SelectObject(memHdc, pen));
		//ɾ����ʱ��ˢ���ָ�ԭ��ˢ
		DeleteObject(SelectObject(memHdc, brush));
	}
}
short  CDrawWin32::getTextHeight(const char *	Text) //�õ��ı��߶�
{
	//����δ����
	if (memHdc)
	{
		SIZE size;
		GetTextExtentPoint(memHdc, Text, strlen(Text), &size);
		return (WORD)size.cy;
	}
	else
		return 0;
}
short  CDrawWin32::getTextWidth(const char *	Text){ //�õ��ı����

	//����δ����
	if (memHdc)
	{
		SIZE size;
		GetTextExtentPoint(memHdc, Text, strlen(Text), &size);
		return (WORD)size.cx;
	}
	else
		return 0;
}
void CDrawWin32::line(int x1, int y1, int x2, int y2, COLORVAL color) //��һ��ֱ��
{
	if (memHdc && x1 >= 0 && y1 >= 0 && x2 >= 0 && y2 >= 0){
		//�������ʣ���ѡ���豸����
		pen = (HPEN)SelectObject(memHdc, CreatePen(PS_SOLID, 1, color));

		MoveToEx(memHdc, x1, y1, NULL);
		LineTo(memHdc, x2, y2);

		//ɾ���»��ʣ��ָ�ԭ����
		DeleteObject(SelectObject(memHdc, pen));
	}
}
//��λͼ,�ṩλͼ���ֺͻ�ͼ������
void CDrawWin32::drawBitmap(const char* name, int x, int y){
	if (memHdc){
		HDC hdcMem = CreateCompatibleDC(canvasHdc);
		BITMAP info;
		HBITMAP bitmap = (HBITMAP)LoadImage(NULL, name, IMAGE_BITMAP, 0, 0,
			LR_DEFAULTSIZE | LR_LOADFROMFILE);
		GetObject(bitmap,sizeof(BITMAP),&info);
		SelectObject(hdcMem, bitmap);
		BitBlt(memHdc, x, y, info.bmWidth, info.bmHeight, hdcMem, 0, 0, SRCCOPY);  //��ʱ������ʱ��

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
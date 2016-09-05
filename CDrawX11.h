#ifndef CDRAWX11_H
#define CDRAWX11_H
#include<string>
#include "IDrawInterface.h"
/*X11�Ļ�ͼ�ӿ��࣬�̳�IDrawInterface*/
class CDrawX11{
public:
	CDrawX11(){}
	 
	  void beginDraw(SRect&);	//��ʼ��ͼ���ṩ��ͼ�ľ���
	  void endDraw(); //������ͼ��������Դ
	  void fillRect(SRect&, COLORVAL foreColor, COLORVAL backgroundColor);//�����Σ��ṩǰ��ɫ������ɫ
	//��ֱ�ߣ��ṩ�����յ㣬����������ڻ����ģ�ʹ��ʱ�������ھ��ε����
	  void line(int, int, int, int, COLORVAL);
	//������,�ṩ���ݺ�λ�ã�������ɫ
	  void drawText(char*, int, int, COLORVAL);
	//�õ��ı��Ŀ��
	  short getTextWidth(char*);
	//�õ��ı��ĸ߶�
	  short getTextHeight(char*);
	//��λͼ
	  void drawBitmap(char*, int, int);
	//������,�ṩ������飬��ĸ�������ɫ
	  void drawPolyLine(SPoint*, int, COLORVAL);
	//�����߾��Σ��ṩ���δ�С�������ɫ
	virtual void drawDotRect(SRect&, COLORVAL);
private:
	std::string str;
};
#endif
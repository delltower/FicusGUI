#include "CDrawX11.h"

//��ʼ��ͼ���ṩ��ͼ�ľ���
void CDrawX11::beginDraw(SRect&)	{}
//������ͼ��������Դ
void CDrawX11::endDraw() {}
//�����Σ��ṩǰ��ɫ������ɫ
void CDrawX11::fillRect(SRect&, COLORVAL foreColor, COLORVAL backgroundColor){}
//��ֱ�ߣ��ṩ�����յ㣬����������ڻ����ģ�ʹ��ʱ�������ھ��ε����
void CDrawX11::line(int, int, int, int, COLORVAL){}
//������,�ṩ���ݺ�λ�ã�������ɫ
void CDrawX11::drawText(char*, int, int, COLORVAL){}
//�õ��ı��Ŀ��
short  CDrawX11::getTextWidth(char*){ return 0; }
//�õ��ı��ĸ߶�
short  CDrawX11::getTextHeight(char*){ return 0; }
//��λͼ
void CDrawX11::drawBitmap(char*, int, int){}
//������,�ṩ������飬��ĸ�������ɫ
void CDrawX11::drawPolyLine(SPoint*, int, COLORVAL){}
//�����߾��Σ��ṩ���δ�С�������ɫ
void CDrawX11::drawDotRect(SRect&, COLORVAL){}

#ifndef IDRAWINTERFACE_H
#define IDRAWINTERFACE_H
#include"SRect.h"
#include"FCommon.h"
#include"SPoint.h"
/*��ͼ�ӿڣ������*/
class IDrawInterface
{
public:
	IDrawInterface(){}
	~IDrawInterface(){}
	virtual void beginDraw(SRect&) = 0;	//��ʼ��ͼ���ṩ��ͼ�ľ���
	virtual void endDraw() = 0; //������ͼ��������Դ
	virtual void fillRect(SRect&, COLORVAL foreColor, COLORVAL backgroundColor) = 0;//�����Σ��ṩǰ��ɫ������ɫ
	//��ֱ�ߣ��ṩ�����յ㣬����������ڻ����ģ�ʹ��ʱ�������ھ��ε����
	virtual void line(int, int, int, int, COLORVAL) = 0;
	//������,�ṩ���ݺ�λ�ã�������ɫ
	virtual void drawText(const char*, int, int, COLORVAL) = 0;
	//�õ��ı��Ŀ��
	virtual short  getTextWidth(const char*) = 0;
	//�õ��ı��ĸ߶�
	virtual short  getTextHeight(const char*) = 0;
	//��λͼ
	virtual void drawBitmap(const char*, int, int) = 0;
	//������,�ṩ������飬��ĸ�������ɫ
	virtual void drawPolyLine(SPoint*, int, COLORVAL) = 0;
	//�����߾��Σ��ṩ���δ�С�������ɫ
	virtual void drawDotRect(SRect&, COLORVAL) = 0;

protected:
	SRect canvasRect;//	����

};

#endif // !IDRAWINTERFACE_H

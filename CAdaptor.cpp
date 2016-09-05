#include "CAdaptor.h"
#include "CAdaptorWin32.h"
#include "CObject.h"
#include "CTimerManger.h"

CAdaptor* CAdaptor::pAdaptor = NULL;
IDrawInterface* CAdaptor::pDraw = NULL;
IObserver* CAdaptor::allObserver[MAX_MSGNUM];
CTimerManger* CAdaptor::timerManger = NULL;

CAdaptor* CAdaptor::getAdaptor()
{
	if (pAdaptor == NULL)
		pAdaptor = new CAdaptorWin32();
	return	pAdaptor;
}
void CAdaptor::run()
{
	initInstance();
	executeInstance();
	exitInstance();
}

//FG_OSMsgObserver* SetMsgObserver(word type, FG_OSMsgObserver* const pObserver); ע��ϵͳ��Ϣ�Ĺ۲���
//void SendMsg(FG_Message* pMsg); //����ϵͳ��Ϣ��ע��Ĺ۲���
//��ʼ��ͼ���ṩ��ͼ�ľ���
void CAdaptor::beginDraw(SRect& rt)	
{
	if (pDraw)
		pDraw->beginDraw(rt);
}
//������ͼ��������Դ
void CAdaptor::endDraw()
{
	if (pDraw)
		pDraw->endDraw();

}
//�����Σ��ṩǰ��ɫ������ɫ
void CAdaptor::fillRect(SRect& rt, COLORVAL foreColor, COLORVAL backgroundColor)
{
	if (pDraw)
		pDraw->fillRect(rt, foreColor,backgroundColor);
}
//��ֱ�ߣ��ṩ�����յ㣬����������ڻ����ģ�ʹ��ʱ�������ھ��ε����
void CAdaptor::line(int x1, int y1, int x2, int y2, COLORVAL color)
{
	if (pDraw)
		pDraw->line(x1, y1, x2, y2, color);
}
////������,�ṩ���ݺ�λ�ã�������ɫ
void CAdaptor::drawText(const char* text, int x, int y, COLORVAL color)
{
	if (pDraw)
		pDraw->drawText(text,x,y,color);
}
////�õ��ı��Ŀ��
int CAdaptor::getTextWidth(const char* text)
{
	if (pDraw)
		return pDraw->getTextWidth(text);
	else return 0;
}
////�õ��ı��ĸ߶�
int CAdaptor::getTextHeight(const char* text)
{
	if (pDraw)
		return pDraw->getTextHeight(text);
	else return 0;
}
////��λͼ
void CAdaptor::drawBitmap(const char* name, int x, int y)
{
	if (pDraw){

		pDraw->drawBitmap(name, x, y);
	}
		
}
////������,�ṩ������飬��ĸ�������ɫ
void CAdaptor::drawPolyLine(SPoint* points, int n, COLORVAL color)
{
	if (pDraw)
		pDraw->drawPolyLine(points,n,color);
}
////�����߾��Σ��ṩ���δ�С�������ɫ
void CAdaptor::drawDotRect(SRect& rt, COLORVAL color)
{
	if (pDraw)
		pDraw->drawDotRect(rt,color);
}

//ע��۲���,�����ϴεĹ۲���
IObserver* CAdaptor::setObserver(IObserver* observer, MSGTYPE type)
{
	IObserver* temp = allObserver[type];
	allObserver[type] = observer;
	return temp;
}
//������Ϣ
void CAdaptor::sendMsg(SMsg& msg)
{
	if (allObserver[msg.type])
		allObserver[msg.type]->processMessage(msg);
}
//ע�ᶨʱ��
bool CAdaptor::registerTimer(CObject* obj, unsigned int i)
{
	if (!timerManger)
		timerManger = CTimerManger::getTimerManger();
	if (obj){
		timerManger->addTimer(obj, i);
		return true;
	}
	else return true;
}
//ֹͣ��ʱ��
bool CAdaptor::stopTimer(CObject* obj)
{
	if (timerManger && obj){
		timerManger->delTimer(obj);
		return false;
	}
	else return false;
}

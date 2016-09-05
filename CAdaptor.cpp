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

//FG_OSMsgObserver* SetMsgObserver(word type, FG_OSMsgObserver* const pObserver); 注册系统消息的观察者
//void SendMsg(FG_Message* pMsg); //发送系统消息给注册的观察者
//开始画图，提供画图的矩形
void CAdaptor::beginDraw(SRect& rt)	
{
	if (pDraw)
		pDraw->beginDraw(rt);
}
//结束画图，回收资源
void CAdaptor::endDraw()
{
	if (pDraw)
		pDraw->endDraw();

}
//填充矩形，提供前景色，背景色
void CAdaptor::fillRect(SRect& rt, COLORVAL foreColor, COLORVAL backgroundColor)
{
	if (pDraw)
		pDraw->fillRect(rt, foreColor,backgroundColor);
}
//画直线，提供起点和终点，坐标是相对于画布的，使用时加上所在矩形的起点
void CAdaptor::line(int x1, int y1, int x2, int y2, COLORVAL color)
{
	if (pDraw)
		pDraw->line(x1, y1, x2, y2, color);
}
////画文字,提供内容和位置，文字颜色
void CAdaptor::drawText(const char* text, int x, int y, COLORVAL color)
{
	if (pDraw)
		pDraw->drawText(text,x,y,color);
}
////得到文本的宽度
int CAdaptor::getTextWidth(const char* text)
{
	if (pDraw)
		return pDraw->getTextWidth(text);
	else return 0;
}
////得到文本的高度
int CAdaptor::getTextHeight(const char* text)
{
	if (pDraw)
		return pDraw->getTextHeight(text);
	else return 0;
}
////画位图
void CAdaptor::drawBitmap(const char* name, int x, int y)
{
	if (pDraw){

		pDraw->drawBitmap(name, x, y);
	}
		
}
////画折线,提供点的数组，点的个数，颜色
void CAdaptor::drawPolyLine(SPoint* points, int n, COLORVAL color)
{
	if (pDraw)
		pDraw->drawPolyLine(points,n,color);
}
////画虚线矩形，提供矩形大小坐标和颜色
void CAdaptor::drawDotRect(SRect& rt, COLORVAL color)
{
	if (pDraw)
		pDraw->drawDotRect(rt,color);
}

//注册观察者,返回上次的观察者
IObserver* CAdaptor::setObserver(IObserver* observer, MSGTYPE type)
{
	IObserver* temp = allObserver[type];
	allObserver[type] = observer;
	return temp;
}
//发送消息
void CAdaptor::sendMsg(SMsg& msg)
{
	if (allObserver[msg.type])
		allObserver[msg.type]->processMessage(msg);
}
//注册定时器
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
//停止定时器
bool CAdaptor::stopTimer(CObject* obj)
{
	if (timerManger && obj){
		timerManger->delTimer(obj);
		return false;
	}
	else return false;
}

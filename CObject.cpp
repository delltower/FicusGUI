#include "CObject.h"
//处理消息的虚函数
void CObject::msgProc(SMsg& msg){
	switch (msg.type){
	case DRAW_MSG:  //发送给所有部件，使其重画
		onDraw(CAdaptor::getAdaptor());
		break;
	case MOUSEDOWN_MSG:
		onMouseDown(SPoint(msg.x, msg.y));
		break;
	case MOUSEUP_MSG:
		onMouseUp(SPoint(msg.x, msg.y));
		break;
	case DRAW_REQUEST_MSG:
		onDrawRequest(msg.id);
		break;
	case TIMER_MSG:
		onTimer();
		break;
	case NOTIFY_MSG:
		onNotify(msg.notice);
		break;
	case KEY_MSG:
		onKey(msg);
		break;
	}
}

//处理重画消息
  void CObject::onDraw(CAdaptor* pAda)
{
	drawBorder(pAda, borderStyle);
}
//处理键盘消息
  void CObject::onKey(SMsg& pMsg)
{

}
//处理鼠标消息
  void CObject::onMouseDown(SPoint& p){}
//处理鼠标消息
  void CObject::onMouseUp(SPoint& p){}
//处理请求重画消息
  void CObject::onDrawRequest(short idFlag)
{
}
//处理焦点切换消息
void CObject::onFocus(SMsg* pMsg)
{

}
//处理通知
  void CObject::onNotify(SNotice& notice)
{

}
//处理定时器消息
  void CObject::onTimer(){}
//发送重画消息给父窗口
void CObject::requestDraw(){
	SMsg msg(DRAW_REQUEST_MSG, NULL);
	msg.id = getId();
	parent->msgProc(msg);

}
void CObject::drawBorder(CAdaptor* pAda, BORDERSTYLE style)
{
	if (pAda){
		pAda->beginDraw(rect);
		SRect rt = rect;
		SPoint p[3];

		switch (style){
		case EMBOSSING_BORDER: //凸起边框
			rt -= 2;
			p[0].x = rt.x1 - 1;
			p[0].y = rt.y2 + 1;
			p[1].x = rt.x1 - 1;
			p[1].y = rt.y1 - 1;
			p[2].x = rt.x2 + 1;
			p[2].y = rt.y1 - 1;

			pAda->drawPolyLine(p, 3, COLOR_WHITE);//白色部分
			p[1].x = rt.x2 + 1;
			p[1].y = rt.y2 + 1;
			pAda->drawPolyLine(p, 3, COLOR_BLACK); //黑色部分
			pAda->fillRect(rt, bgColor, bgColor);
			break;
		case SUNKEN_BORDER: //下沉边框
			rt -= 2;
			p[0].x = rt.x1 - 1;
			p[0].y = rt.y2 + 1;
			p[1].x = rt.x1 - 1;
			p[1].y = rt.y1 - 1;
			p[2].x = rt.x2 + 1;
			p[2].y = rt.y1 - 1;

			pAda->drawPolyLine(p, 3, COLOR_BLACK);//白色部分
			p[1].x = rt.x2 + 1;
			p[1].y = rt.y2 + 1;
			pAda->drawPolyLine(p, 3, COLOR_WHITE); //黑色部分
			pAda->fillRect(rt, bgColor, bgColor);
			break;
		case THIN_BORDER: //细线边框
			pAda->fillRect(rt, bgColor, COLOR_WHITE);
			break;
		case NONE_BORDER: //无边框
			pAda->fillRect(rt, bgColor, bgColor);
			break;
		default:
			break;
		}
		pAda->endDraw();
	}
}
//发送通知消息给父窗口
void CObject::notifyParent(SMsg& msg){
	if (msg.type == NOTIFY_MSG)
		getParent()->msgProc(msg);
}
//处理焦点切换消息  为啥不是虚函数
void CObject::onFocus(SMsg& msg)
{}

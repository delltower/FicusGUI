#include "CObject.h"
//������Ϣ���麯��
void CObject::msgProc(SMsg& msg){
	switch (msg.type){
	case DRAW_MSG:  //���͸����в�����ʹ���ػ�
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

//�����ػ���Ϣ
  void CObject::onDraw(CAdaptor* pAda)
{
	drawBorder(pAda, borderStyle);
}
//���������Ϣ
  void CObject::onKey(SMsg& pMsg)
{

}
//���������Ϣ
  void CObject::onMouseDown(SPoint& p){}
//���������Ϣ
  void CObject::onMouseUp(SPoint& p){}
//���������ػ���Ϣ
  void CObject::onDrawRequest(short idFlag)
{
}
//�������л���Ϣ
void CObject::onFocus(SMsg* pMsg)
{

}
//����֪ͨ
  void CObject::onNotify(SNotice& notice)
{

}
//����ʱ����Ϣ
  void CObject::onTimer(){}
//�����ػ���Ϣ��������
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
		case EMBOSSING_BORDER: //͹��߿�
			rt -= 2;
			p[0].x = rt.x1 - 1;
			p[0].y = rt.y2 + 1;
			p[1].x = rt.x1 - 1;
			p[1].y = rt.y1 - 1;
			p[2].x = rt.x2 + 1;
			p[2].y = rt.y1 - 1;

			pAda->drawPolyLine(p, 3, COLOR_WHITE);//��ɫ����
			p[1].x = rt.x2 + 1;
			p[1].y = rt.y2 + 1;
			pAda->drawPolyLine(p, 3, COLOR_BLACK); //��ɫ����
			pAda->fillRect(rt, bgColor, bgColor);
			break;
		case SUNKEN_BORDER: //�³��߿�
			rt -= 2;
			p[0].x = rt.x1 - 1;
			p[0].y = rt.y2 + 1;
			p[1].x = rt.x1 - 1;
			p[1].y = rt.y1 - 1;
			p[2].x = rt.x2 + 1;
			p[2].y = rt.y1 - 1;

			pAda->drawPolyLine(p, 3, COLOR_BLACK);//��ɫ����
			p[1].x = rt.x2 + 1;
			p[1].y = rt.y2 + 1;
			pAda->drawPolyLine(p, 3, COLOR_WHITE); //��ɫ����
			pAda->fillRect(rt, bgColor, bgColor);
			break;
		case THIN_BORDER: //ϸ�߱߿�
			pAda->fillRect(rt, bgColor, COLOR_WHITE);
			break;
		case NONE_BORDER: //�ޱ߿�
			pAda->fillRect(rt, bgColor, bgColor);
			break;
		default:
			break;
		}
		pAda->endDraw();
	}
}
//����֪ͨ��Ϣ��������
void CObject::notifyParent(SMsg& msg){
	if (msg.type == NOTIFY_MSG)
		getParent()->msgProc(msg);
}
//�������л���Ϣ  Ϊɶ�����麯��
void CObject::onFocus(SMsg& msg)
{}

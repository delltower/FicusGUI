#include "CScreen.h"
CScreen* CScreen::pScreen = NULL;
//��ȡ��Ļ
CScreen* CScreen::getScreen(){
	if (pScreen) return pScreen;
	else
		pScreen = new CScreen(SRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
	return pScreen;
}
//ɾ����Ļ
void CScreen::deleteScreen(){

}
//��Ӵ���
bool CScreen::addWindow(CWindow* pWindow){
	if (addItem(pWindow)){
		SDNode* p = objectList.last();

		if (objectList.length() > 1){
			p = p->pre;
			p->data->setFocus(false);

			//if (((CWindow*)(p->data))->checkStatus()){  //���ڱ�����ȡ�����㣬���ڱ���
			//	//sendNotice(p->data->getId(), 3);
			//}
		}

		//sendNotice(pWindow->getId(), 4);	//�õ�����
		pWindow->setFocus(true);
		pWindow->setParent(this);
		focusItem = pWindow;			//�����ӵĴ��ڼ���
		focusItem->requestDraw();//	�´������»�
		return true;
	}
	return false;
}
//ɾ������
bool CScreen::removeWindow(CWindow* pWindow){
	if (removeItem(pWindow)){
		pWindow->setParent(NULL);
		//������õĶ�ʱ��
		CAdaptor* pAda = CAdaptor::getAdaptor();
		SDNode* p = pWindow->first();
		while (p){
			pAda->stopTimer(p->data);
			p = p->next;
		}
		CObject::onDraw(CAdaptor::getAdaptor());
		SDNode* last = objectList.last();
		if (last){
			last->data->setFocus(true);
			SMsg msg(DRAW_MSG, NULL);
			sendMsgAll(msg);
		}
	}
	return false;
}
//����ϵͳ��Ϣ
void CScreen::processMessage(SMsg& msg){
	SDNode* p = objectList.last();
	switch (msg.type)
	{
	case DRAW_MSG:
		sendMsgAll(msg);
		break;
	default:
		if (p)
			p->data->msgProc(msg);
		break;
	}
}
//���ڷ��͵�Ҫ���ػ���Ϣ�Ĵ�����
void CScreen::onDrawRequest(short idFlag)
{
	changeFocus(getWindowById(idFlag));
	if (focusItem){
		isDone = false;
		focusItem->onDraw(CAdaptor::getAdaptor());
	}
	isDone = true;
}
CWindow* CScreen::getWindowById(short idFlag){
	CObject* p = getItemById(idFlag);
	if (p)
		return (CWindow*)p;
	else return NULL;
}
//�����ػ������Ķ�ʱ����Ϣ�Ĵ�����
void CScreen::onDrawTimer()
{

}

void CScreen::drawAllWindow(SMsg& msg){
	SDNode* p = objectList.first();
	while (p){
		p->data->msgProc(msg);
		p = p->next;
	}
}
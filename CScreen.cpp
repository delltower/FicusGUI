#include "CScreen.h"
CScreen* CScreen::pScreen = NULL;
//获取屏幕
CScreen* CScreen::getScreen(){
	if (pScreen) return pScreen;
	else
		pScreen = new CScreen(SRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));
	return pScreen;
}
//删除屏幕
void CScreen::deleteScreen(){

}
//添加窗口
bool CScreen::addWindow(CWindow* pWindow){
	if (addItem(pWindow)){
		SDNode* p = objectList.last();

		if (objectList.length() > 1){
			p = p->pre;
			p->data->setFocus(false);

			//if (((CWindow*)(p->data))->checkStatus()){  //正在遍历，取消焦点，不在遍历
			//	//sendNotice(p->data->getId(), 3);
			//}
		}

		//sendNotice(pWindow->getId(), 4);	//得到焦点
		pWindow->setFocus(true);
		pWindow->setParent(this);
		focusItem = pWindow;			//最后添加的窗口激活
		focusItem->requestDraw();//	新窗口重新画
		return true;
	}
	return false;
}
//删除窗口
bool CScreen::removeWindow(CWindow* pWindow){
	if (removeItem(pWindow)){
		pWindow->setParent(NULL);
		//清除设置的定时器
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
//接收系统消息
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
//窗口发送的要求重画消息的处理函数
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
//减少重画次数的定时器消息的处理函数
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
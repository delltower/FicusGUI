#include "CContainer.h"

bool CContainer::addItem(CObject* p)//添加子窗口元素
{
	if (p){
		objectList.append(p);
		return true;
	}
	else return false;
}
CObject* CContainer::getItemById(SWORD id) //通过id得到元素
{
	SDNode* p = objectList.first();
	while (p){
		if (p->data->getId() == id)
			return p->data;
		p = p->next;
	}
	return NULL;
}
bool CContainer::removeItem(CObject* p)//删除一个子窗口元素
{
	if (p){
		return  objectList.delItem(p);
	}
	else return false;
}
bool CContainer::removeAllItem()	//删除所有元素
{
	if (objectList.isEmpty()) return false;
	else {
		objectList.clear();
		return true;
	}
}
void CContainer::sendMsgAll(SMsg& msg){
	SDNode* p = objectList.first();
	while (p){
		isDone = false;
		p->data->msgProc(msg);
		p = p->next;
	}
	isDone = true;
}
//向控件发送通知
void CContainer::sendNotice(SWORD id, short int type)
{
	SMsg msg(NOTIFY_MSG, NULL);
	SNotice notice(id, type);
	msg.notice = notice;
	CObject* p = getItemById(id);
	if (p)
		p->msgProc(msg);
}
//改变焦点控件
void CContainer::changeFocus(CObject* p)
{
	p->setFocus();
	if (focusItem && focusItem->getId() != p->getId())
		focusItem->setFocus(false);
	focusItem = p;
}
SDNode* CContainer::first(){
	return objectList.first();
}
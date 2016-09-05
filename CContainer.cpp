#include "CContainer.h"

bool CContainer::addItem(CObject* p)//����Ӵ���Ԫ��
{
	if (p){
		objectList.append(p);
		return true;
	}
	else return false;
}
CObject* CContainer::getItemById(SWORD id) //ͨ��id�õ�Ԫ��
{
	SDNode* p = objectList.first();
	while (p){
		if (p->data->getId() == id)
			return p->data;
		p = p->next;
	}
	return NULL;
}
bool CContainer::removeItem(CObject* p)//ɾ��һ���Ӵ���Ԫ��
{
	if (p){
		return  objectList.delItem(p);
	}
	else return false;
}
bool CContainer::removeAllItem()	//ɾ������Ԫ��
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
//��ؼ�����֪ͨ
void CContainer::sendNotice(SWORD id, short int type)
{
	SMsg msg(NOTIFY_MSG, NULL);
	SNotice notice(id, type);
	msg.notice = notice;
	CObject* p = getItemById(id);
	if (p)
		p->msgProc(msg);
}
//�ı佹��ؼ�
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
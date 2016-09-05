#include "CWindow.h"

//������ӿؼ�
bool CWindow::addWidget(CWidget* pWidget)
{
	if (addItem(pWidget)){
		pWidget->setParent(this);
		return true;
	}
	return false;
}
//����ɾ���ؼ�
bool CWindow::removeWidget(CWidget* pWidget)
{
	if (removeItem(pWidget)){
		pWidget->setParent(NULL);
		return true;
	}
	else return false;
}
//���ش��ڵĿͻ�������
  void CWindow::getClientRect(SRect& rt)
{
	short y = CAdaptor::getAdaptor()->getTextHeight(title);
	rt = rect;
	rt -= 2;//	border
	rt.y1 -= y; //title height
}
//ͨ��id�õ�Ԫ��
  CWidget* CWindow::getWidgetById(SWORD id)
{
	CObject* p = getItemById(id);
	if (p)
		return (CWidget*)p;
	else
		return NULL;
}

  SDNode* CWindow::first()
{
	SDNode* p = CContainer::first();
	if (p)
		return p;
	else return NULL;
}
  //�����ػ���Ϣ
  void CWindow::onDraw(CAdaptor* pAda)
  {
	  pAda->beginDraw(rect);

	  CObject::onDraw(pAda);  //���߿�
	  //������
	  SRect rt;
	  CObject::getClientRect(rt); //�õ��������ھ���
	  rt.y2 = rt.y1 + pAda->getTextHeight(title); //������
	  pAda->fillRect(rt, COLOR_BLUE, COLOR_BLUE);
	  pAda->drawText(title, rt.x1, rt.y1, COLOR_WHITE);
	  //�������
	  SDNode* p = objectList.first();
	  while (p){
		  isDone = false;
		  p->data->onDraw(pAda);
		  p = p->next;
	  }
	  isDone = true;
	  pAda->endDraw();
  }
  //���������Ϣ
  void CWindow::onKey(SMsg& msg)
  {
	  if (focusItem){
		  focusItem->msgProc(msg);
	  }
  }
  //�����������
  void CWindow::onMouseUp(SPoint& point){
	  SDNode* p = objectList.first();
	  while (p){
		  isDone = false;
		  if (p->data->isContains(point)) {
			  changeFocus(p->data);
			  p->data->onMouseUp(point);
		  }
		  p = p->next;
	  }
	  isDone = true;
  }
  //������갴��
  void CWindow::onMouseDown(SPoint& point){
	  SDNode* p = objectList.first();
	  while (p){
		  isDone = false;
		  if (p->data->isContains(point)){
			  changeFocus(p->data);
			  p->data->onMouseDown(point);
		  }
		  p = p->next;
	  }
	  isDone = true;
  }
  //���������ػ���Ϣ
  void CWindow::onDrawRequest(short idFlag)
  {
	  changeFocus(getWidgetById(idFlag));
	  if (isFocus() && focusItem){
		  isDone = false;
		  focusItem->onDraw(CAdaptor::getAdaptor());
	  }
	  isDone = true;
  }
  //�������л���Ϣ
  void CWindow::onFocus(SMsg* pMsg)
  {

  }
  //����֪ͨ
  void CWindow::onNotify(SNotice& notice)
  {

  }
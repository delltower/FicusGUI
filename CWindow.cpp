#include "CWindow.h"

//窗口添加控件
bool CWindow::addWidget(CWidget* pWidget)
{
	if (addItem(pWidget)){
		pWidget->setParent(this);
		return true;
	}
	return false;
}
//窗口删除控件
bool CWindow::removeWidget(CWidget* pWidget)
{
	if (removeItem(pWidget)){
		pWidget->setParent(NULL);
		return true;
	}
	else return false;
}
//返回窗口的客户区矩形
  void CWindow::getClientRect(SRect& rt)
{
	short y = CAdaptor::getAdaptor()->getTextHeight(title);
	rt = rect;
	rt -= 2;//	border
	rt.y1 -= y; //title height
}
//通过id得到元素
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
  //处理重画消息
  void CWindow::onDraw(CAdaptor* pAda)
  {
	  pAda->beginDraw(rect);

	  CObject::onDraw(pAda);  //画边框
	  //画标题
	  SRect rt;
	  CObject::getClientRect(rt); //得到整个窗口矩形
	  rt.y2 = rt.y1 + pAda->getTextHeight(title); //画标题
	  pAda->fillRect(rt, COLOR_BLUE, COLOR_BLUE);
	  pAda->drawText(title, rt.x1, rt.y1, COLOR_WHITE);
	  //所有组件
	  SDNode* p = objectList.first();
	  while (p){
		  isDone = false;
		  p->data->onDraw(pAda);
		  p = p->next;
	  }
	  isDone = true;
	  pAda->endDraw();
  }
  //处理键盘消息
  void CWindow::onKey(SMsg& msg)
  {
	  if (focusItem){
		  focusItem->msgProc(msg);
	  }
  }
  //处理鼠标跳起
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
  //处理鼠标按下
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
  //处理请求重画消息
  void CWindow::onDrawRequest(short idFlag)
  {
	  changeFocus(getWidgetById(idFlag));
	  if (isFocus() && focusItem){
		  isDone = false;
		  focusItem->onDraw(CAdaptor::getAdaptor());
	  }
	  isDone = true;
  }
  //处理焦点切换消息
  void CWindow::onFocus(SMsg* pMsg)
  {

  }
  //处理通知
  void CWindow::onNotify(SNotice& notice)
  {

  }
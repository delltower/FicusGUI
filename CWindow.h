#ifndef CWINDOW_H
#define CWINDOW_H
#include "CWidget.h"
#include "CContainer.h"
#include "IObserver.h"

class CWindow :public CContainer{
public:
	CWindow(const SWORD id = 0, BORDERSTYLE style = NONE_BORDER) :CContainer(id,style){
		char text[] = "no title";
		unsigned i = 0, size = strlen(text);
		title = new char[size + 1];
		for (i = 0; i < size; i++) title[i] = text[i];
		title[size] = '\0';

		focusWidget = NULL;
	}
	CWindow(const SRect& rt, const char* t, const SWORD id = 0, BORDERSTYLE style = NONE_BORDER) :CContainer(rt,id,style){
		unsigned i = 0, size = 0;
		const	char* p = t;
		if (title){
			size = strlen(t);
		}
		else {
			char text[] = "no title";
			size = strlen(text);
			p = text;
		}
		title = new char[size + 1];
		for (i = 0; i < size; i++) title[i] = p[i];
		title[size] = '\0';
	}
	//窗口添加控件
	bool addWidget(CWidget* pWidget);
	//窗口删除控件
	bool removeWidget(CWidget* pWidget);
	//返回窗口的客户区矩形
	virtual void getClientRect(SRect& rt);
	//通过id得到元素
	CWidget* getWidgetById(SWORD id);
	SDNode* first();
	 
protected:
	
	//处理重画消息
	void onDraw(CAdaptor* pAda);
	//处理键盘消息
	void onKey(SMsg& msg);
	//处理鼠标跳起
	void onMouseUp(SPoint& point);
	//处理鼠标按下
	void onMouseDown(SPoint& point);
	//处理请求重画消息
	void onDrawRequest(short idFlag);
	//处理焦点切换消息
	void onFocus(SMsg* pMsg);
	//处理通知
	void onNotify(SNotice& notice);
private:
	char* title;//窗口标题
	CWidget* focusWidget;//当前有焦点的控件指针
};
#endif
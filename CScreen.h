#ifndef CSCREEN_H
#define CSCREEN_H
#include "CContainer.h"
#include "CWindow.h"
#include "IObserver.h"

class CScreen:public CContainer ,IObserver{
public:
	//获取屏幕
	static CScreen* getScreen();
	//删除屏幕
	static void deleteScreen();
	//添加窗口
	bool addWindow(CWindow* pWindow);
	//删除窗口
	bool removeWindow(CWindow* pWindow);
	//接收系统消息
	void processMessage(SMsg& msg);

protected:
	CScreen(const SRect& rt) :CContainer(rt){
		setBgColor(COLOR_BLACK);
		CAdaptor::getAdaptor()->setObserver(this, DRAW_MSG);
		//CAdaptor::getAdaptor()->setObserver(this, MOUSE_MSG);
		CAdaptor::getAdaptor()->setObserver(this, MOUSEUP_MSG);
		CAdaptor::getAdaptor()->setObserver(this, MOUSEDOWN_MSG);
		CAdaptor::getAdaptor()->setObserver(this, KEY_MSG);

	}
	~CScreen(){}
	void onDrawRequest(short idFlag); 	//窗口发送的要求重画消息的处理函数
	CWindow* getWindowById(short idFlag); //得到窗口
	void onDrawTimer(); //减少重画次数的定时器消息的处理函数
 	void drawAllWindow(SMsg& msg); //重画所有窗口

private:
	static CScreen* pScreen;	//系统唯一存在的屏幕实例
};

#endif
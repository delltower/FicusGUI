#ifndef CAPP_H
#define CAPP_H
#include "FCommon.h"
#include "CAdaptor.h"
#include "CScreen.h"
#include "IObserver.h"
#include "CMainWindow.h"
#include "CTimerManger.h"
 
class CApp:public IObserver{
public:	
	CApp(){
		CAdaptor::getAdaptor(); //step1:create the adaptor
		CAdaptor::getAdaptor()->setObserver(this, STARTUP_MSG); //step2:register the observer	
	}
	void processMessage(SMsg& msg){   //step3: return from adaptor
		switch (msg.type){
		case STARTUP_MSG:
			CScreen::getScreen();  //step4:create the screen
			CAdaptor::getAdaptor()->setObserver(CTimerManger::getTimerManger(), TIMER_MSG);  //定时器注册消息
			initInstance();
			break;
		default:break;
		}
	}
	virtual void initInstance() = 0; //继承类实现
};

#endif
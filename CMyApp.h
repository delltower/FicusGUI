#ifndef CMYAPP_H
#define CMYAPP_H
#include "CApp.h"

class CMyApp :public CApp{
public:
	CMyApp(){}
	//�����麯��
	void initInstance()
	{
		CScreen::getScreen()->addWindow(new CMainWindow(0));

	}

};
#endif 
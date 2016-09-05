#ifndef CSCREEN_H
#define CSCREEN_H
#include "CContainer.h"
#include "CWindow.h"
#include "IObserver.h"

class CScreen:public CContainer ,IObserver{
public:
	//��ȡ��Ļ
	static CScreen* getScreen();
	//ɾ����Ļ
	static void deleteScreen();
	//��Ӵ���
	bool addWindow(CWindow* pWindow);
	//ɾ������
	bool removeWindow(CWindow* pWindow);
	//����ϵͳ��Ϣ
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
	void onDrawRequest(short idFlag); 	//���ڷ��͵�Ҫ���ػ���Ϣ�Ĵ�����
	CWindow* getWindowById(short idFlag); //�õ�����
	void onDrawTimer(); //�����ػ������Ķ�ʱ����Ϣ�Ĵ�����
 	void drawAllWindow(SMsg& msg); //�ػ����д���

private:
	static CScreen* pScreen;	//ϵͳΨһ���ڵ���Ļʵ��
};

#endif
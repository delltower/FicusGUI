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
	//������ӿؼ�
	bool addWidget(CWidget* pWidget);
	//����ɾ���ؼ�
	bool removeWidget(CWidget* pWidget);
	//���ش��ڵĿͻ�������
	virtual void getClientRect(SRect& rt);
	//ͨ��id�õ�Ԫ��
	CWidget* getWidgetById(SWORD id);
	SDNode* first();
	 
protected:
	
	//�����ػ���Ϣ
	void onDraw(CAdaptor* pAda);
	//���������Ϣ
	void onKey(SMsg& msg);
	//�����������
	void onMouseUp(SPoint& point);
	//������갴��
	void onMouseDown(SPoint& point);
	//���������ػ���Ϣ
	void onDrawRequest(short idFlag);
	//�������л���Ϣ
	void onFocus(SMsg* pMsg);
	//����֪ͨ
	void onNotify(SNotice& notice);
private:
	char* title;//���ڱ���
	CWidget* focusWidget;//��ǰ�н���Ŀؼ�ָ��
};
#endif
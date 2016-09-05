#ifndef CWIDGET_H
#define CWIDGET_H
#include<iostream>
#include "CObject.h"
#include "CAdaptor.h"

class CWidget:public CObject{
public:
	CWidget(const SWORD id = 0, BORDERSTYLE style = NONE_BORDER) :CObject(id, style),title("No Title"){		
		char text[] = "no title";
		unsigned i = 0, size = strlen(text);
		title = new char[size + 1];
		for (i = 0; i < size; i++) title[i] = text[i];
		title[size] = '\0';
	}
	CWidget(const char * t, const SRect& rt, const SWORD id = 0, BORDERSTYLE style = NONE_BORDER) :CWidget(id, style){
		unsigned i = 0, size = 0;
		const	char* p = t;
		if (t){
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
		rect = rt;
	}
	~CWidget(){}
	//�ؼ����ı�
	char* getText();
	//���ÿؼ����ı�
	void setText(const char* text);
	//����ı����ھ�������
	SRect getRect();
	//�ı�����
	short textLength();
	//���ƽ���򣬵õ�����ʱ��Χ�����߿�
	void drawTextFocus(CAdaptor* pAda, const SWORD X, const SWORD y);

protected:
	char*  title;	//�ؼ��ı�
};
#endif
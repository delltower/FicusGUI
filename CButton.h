#ifndef CBUTTON_H
#define CBUTTON_H
#include<iostream>
#include "CWidget.h"
#include "CAdaptor.h"
#include "IDrawInterface.h"
#include "IObserver.h"

class CButton :public CWidget{
public:
	CButton(){}
	CButton(const char   * text,const SRect& rt, const SWORD id = 0) :CWidget(text, rt, id, EMBOSSING_BORDER){	}

protected:
	//�����Ϣ,����
	void onMouseUp(SPoint& point);
	//�����Ϣ������
	void onMouseDown(SPoint& point);
	//��ť�Ķ�ʱ��Ϣ
	void onTimer();
	
	//�ػ��Լ�
	void onDraw(CAdaptor* pAda);
private:
};
#endif
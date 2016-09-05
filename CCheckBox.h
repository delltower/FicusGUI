#ifndef CCHECKBOX_H
#define CCHECKBOX_H
#include<iostream>
#include "CWidget.h"
#include "CAdaptor.h"
#include "IDrawInterface.h"

class CCheckBox :public CWidget{
public:
	CCheckBox(const char* text,const SRect& rt,const SWORD id  = 0) :CWidget(text, rt,id){
		isCheck = false;
	}

	//�����Ƿ�ѡ��
	void setCheck(bool checkFlag = true);
protected:	
	//�����
	void onMouseDown(SPoint& point);
	//�ػ��Լ�
	void onDraw(CAdaptor* pAda);
	
private:
	bool isCheck; //�Ƿ�ѡ��

};
#endif
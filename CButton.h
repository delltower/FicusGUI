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
	//鼠标消息,弹起
	void onMouseUp(SPoint& point);
	//鼠标消息，按下
	void onMouseDown(SPoint& point);
	//按钮的定时信息
	void onTimer();
	
	//重画自己
	void onDraw(CAdaptor* pAda);
private:
};
#endif
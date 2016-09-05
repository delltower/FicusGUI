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

	//设置是否选中
	void setCheck(bool checkFlag = true);
protected:	
	//鼠标点击
	void onMouseDown(SPoint& point);
	//重画自己
	void onDraw(CAdaptor* pAda);
	
private:
	bool isCheck; //是否被选中

};
#endif
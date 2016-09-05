#ifndef CLABEL_H
#define CLABEL_H
#include<iostream>
#include "CWidget.h"
#include "CAdaptor.h"
#include "IDrawInterface.h"

class CLabel :public CWidget{
public:
	CLabel(){}
	CLabel(const char* text,const SRect& rt,const SWORD id = 0,BORDERSTYLE style = NONE_BORDER):CWidget(text,rt,id,style){
		align = LEFT_ALIGN;
	}
	void onDraw(CAdaptor* pAda);
	//设置对齐方式
	void setAlign(TEXTALIGN style){ align = style; }
	//can not get focus 
	void setFocus(bool flag = false){
		focus = false;
	}
private:
	TEXTALIGN align; //文字对齐方式，默认左对齐
};
#endif
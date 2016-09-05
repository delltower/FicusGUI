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
	//控件的文本
	char* getText();
	//设置控件的文本
	void setText(const char* text);
	//获得文本所在矩形区域
	SRect getRect();
	//文本长度
	short textLength();
	//绘制焦点框，得到焦点时周围有虚线框
	void drawTextFocus(CAdaptor* pAda, const SWORD X, const SWORD y);

protected:
	char*  title;	//控件文本
};
#endif
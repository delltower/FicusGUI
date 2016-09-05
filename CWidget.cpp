#include "CWidget.h"

//控件的文本
char* CWidget::getText(){ return title; }
//设置控件的文本
void CWidget::setText(const char* text){
	if (text){
		if (title) delete[] title;

		unsigned i = 0, size = strlen(text);
		title = new char[size + 1];
		for (i = 0; i < size; i++) title[i] = text[i];
		title[size] = '\0';
	}

}
//获得文本所在矩形区域
SRect CWidget::getRect(){
	return rect;
}
//文本长度
short CWidget::textLength(){
	return CAdaptor::getAdaptor()->getTextWidth(title);
}
//绘制焦点框，得到焦点时周围有虚线框
void CWidget::drawTextFocus(CAdaptor* pAda, const SWORD X, const SWORD y)
{

}
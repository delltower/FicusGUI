#include "CWidget.h"

//�ؼ����ı�
char* CWidget::getText(){ return title; }
//���ÿؼ����ı�
void CWidget::setText(const char* text){
	if (text){
		if (title) delete[] title;

		unsigned i = 0, size = strlen(text);
		title = new char[size + 1];
		for (i = 0; i < size; i++) title[i] = text[i];
		title[size] = '\0';
	}

}
//����ı����ھ�������
SRect CWidget::getRect(){
	return rect;
}
//�ı�����
short CWidget::textLength(){
	return CAdaptor::getAdaptor()->getTextWidth(title);
}
//���ƽ���򣬵õ�����ʱ��Χ�����߿�
void CWidget::drawTextFocus(CAdaptor* pAda, const SWORD X, const SWORD y)
{

}
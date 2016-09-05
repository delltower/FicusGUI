#ifndef CRADIOBUTTON_H
#define CRADIOBUTTON_H
#include<iostream>
#include "CWidget.h"
#include "CAdaptor.h"

class CRadioButton :public CWidget{
public:
	CRadioButton(const char* text, const SRect& rt, CRadioButton* preRadio, const SWORD id = 0) :CWidget(text, rt, id){
		isCheck = false;
		if (preRadio)	//����ѭ������
		{
			this->nextRadio = preRadio->nextRadio;
			preRadio->nextRadio = this;
		}
		else nextRadio = this;
	}
	//�����
	void onMouseDown(SPoint& point)
	{
		isCheck = !isCheck;
		//Ҫ���ػ�
		requestDraw();
		if (isCheck){
			CRadioButton* p = this->nextRadio;
			while (p != this){
				if (p->getCheck()){
					p->setCheck(false);
					p->requestDraw();
				}
				p = p->nextRadio;
			}
		}
	}
	void onDraw(CAdaptor* pAda)
	{
		if (pAda){
			pAda->beginDraw(rect);
			CWidget::onDraw(pAda);
			if (isCheck)
				pAda->drawBitmap("Radio_EC.bmp",rect.x1,rect.y1);
			else
				pAda->drawBitmap("Radio_ENC.bmp", rect.x1, rect.y1);
			pAda->drawText(title, rect.x1 + 14, rect.y1, foreColor);
			pAda->endDraw();
		}	
	}
	//����ѡ��
	void setCheck(bool checkFlag = true){ isCheck = checkFlag; }
	//�õ�״̬
	bool getCheck()
	{
		return isCheck;
	}
private:
	bool isCheck; //�Ƿ�ѡ��
	CRadioButton* nextRadio;
};
#endif
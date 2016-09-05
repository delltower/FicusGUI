#ifndef CRADIOBUTTON_H
#define CRADIOBUTTON_H
#include<iostream>
#include "CWidget.h"
#include "CAdaptor.h"

class CRadioButton :public CWidget{
public:
	CRadioButton(const char* text, const SRect& rt, CRadioButton* preRadio, const SWORD id = 0) :CWidget(text, rt, id){
		isCheck = false;
		if (preRadio)	//构成循环链表
		{
			this->nextRadio = preRadio->nextRadio;
			preRadio->nextRadio = this;
		}
		else nextRadio = this;
	}
	//鼠标点击
	void onMouseDown(SPoint& point)
	{
		isCheck = !isCheck;
		//要求重画
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
	//设置选中
	void setCheck(bool checkFlag = true){ isCheck = checkFlag; }
	//得到状态
	bool getCheck()
	{
		return isCheck;
	}
private:
	bool isCheck; //是否被选中
	CRadioButton* nextRadio;
};
#endif
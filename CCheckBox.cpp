#include "CCheckBox.h"

//�����Ƿ�ѡ��
void CCheckBox::setCheck(bool checkFlag){
	isCheck = checkFlag;
}
//�����
void CCheckBox::onMouseDown(SPoint& point)
{
	isCheck = !isCheck;
	//Ҫ���ػ�
	requestDraw();
}
//�ػ��Լ�
void CCheckBox::onDraw(CAdaptor* pAda)
{
	if (pAda){
		pAda->beginDraw(rect);
		CWidget::onDraw(pAda);
		if (isCheck)  //ѡ��
			pAda->drawBitmap("Check_EC.bmp", rect.x1, rect.y1);
		else
			pAda->drawBitmap("Check_ENC.bmp", rect.x1, rect.y1);
		pAda->drawText(title, rect.x1 + 14, rect.y1, foreColor);
		pAda->endDraw();
	}
}
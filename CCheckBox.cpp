#include "CCheckBox.h"

//设置是否选中
void CCheckBox::setCheck(bool checkFlag){
	isCheck = checkFlag;
}
//鼠标点击
void CCheckBox::onMouseDown(SPoint& point)
{
	isCheck = !isCheck;
	//要求重画
	requestDraw();
}
//重画自己
void CCheckBox::onDraw(CAdaptor* pAda)
{
	if (pAda){
		pAda->beginDraw(rect);
		CWidget::onDraw(pAda);
		if (isCheck)  //选中
			pAda->drawBitmap("Check_EC.bmp", rect.x1, rect.y1);
		else
			pAda->drawBitmap("Check_ENC.bmp", rect.x1, rect.y1);
		pAda->drawText(title, rect.x1 + 14, rect.y1, foreColor);
		pAda->endDraw();
	}
}
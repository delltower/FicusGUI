#include "CBitmap.h"

//不能设置焦点的类
void CBitmap::setFocus(bool flag){
	focus = false;
}
//得到运行信息
bool CBitmap::isRun(){
	return status == 1;
}
//增加动画的图像
void CBitmap::addBitmap(const char* text)
{
	if (text && size < 100){
		unsigned i = 0, size1 = strlen(text);
		allBitmap[size] = new char[size1 + 1];
		for (i = 0; i < size1; i++)
			allBitmap[size][i] = text[i];
		allBitmap[size][size1] = '\0';

		size++;
	}
}

//覆盖onDraw,重画自己
void CBitmap::onDraw(CAdaptor* pAda)
{
	if (pAda){
		pAda->beginDraw(rect);
		CWidget::onDraw(pAda);
		if (allBitmap[curIndex])
			pAda->drawBitmap(allBitmap[curIndex], rect.x1, rect.y1);

		pAda->endDraw();
	}
}
//覆盖onTimer,定时器到点
void CBitmap::onTimer()
{
	if (status == 1){
		curIndex = (curIndex + 1) % size;
		//onDraw(CAdaptor::getAdaptor());
		requestDraw();
		status = 1;
	}
}
//覆盖onNotify,处理收到的通知
void CBitmap::onNotify(SNotice& notice){
	if (notice.type == 1)  //停止动画
		status = 0;
	else if (notice.type == 2) //开始动画
		status = 1;
}
#include "CButton.h"

//鼠标消息,弹起
void CButton::onMouseUp(SPoint& point)
{
	if (borderStyle != EMBOSSING_BORDER)
	{
		setBorderStyle(EMBOSSING_BORDER);
		//要求重画
		requestDraw();
		//取消定时
		CAdaptor::stopTimer(this);
		//通知父窗口,发生点击事件，代表按钮经历了按下和弹起
		SMsg msg2(NOTIFY_MSG, NULL);
		msg2.notice = SNotice(getId(), 0);
		notifyParent(msg2);
	}
}
//鼠标消息，按下
void CButton::onMouseDown(SPoint& point)
{
	if (borderStyle != SUNKEN_BORDER)
	{
		setBorderStyle(SUNKEN_BORDER);
		//要求重画
		requestDraw();
		//设置按钮保持按下状态的最长时间，超过后恢复原样
		CAdaptor::registerTimer(this, 1000); //2000ms
	}
}
//按钮的定时信息
void CButton::onTimer()
{
	if (borderStyle == SUNKEN_BORDER){
		setBorderStyle(EMBOSSING_BORDER);
		//要求重画
		requestDraw();
		//取消定时
		CAdaptor::stopTimer(this);
		//通知父窗口,发生点击事件，代表按钮经历了按下和弹起
		SMsg msg2(NOTIFY_MSG, NULL);
		msg2.notice = SNotice(getId(), 0);
		notifyParent(msg2);
	}
}

//重画自己
void CButton::onDraw(CAdaptor* pAda)
{
	if (pAda){
		pAda->beginDraw(rect);
		CWidget::onDraw(pAda);
		if (title)
			pAda->drawText(title, rect.x1 + 2, rect.y1 + 2, foreColor);

		pAda->endDraw();
	}
}
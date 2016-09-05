#include "CButton.h"

//�����Ϣ,����
void CButton::onMouseUp(SPoint& point)
{
	if (borderStyle != EMBOSSING_BORDER)
	{
		setBorderStyle(EMBOSSING_BORDER);
		//Ҫ���ػ�
		requestDraw();
		//ȡ����ʱ
		CAdaptor::stopTimer(this);
		//֪ͨ������,��������¼�������ť�����˰��º͵���
		SMsg msg2(NOTIFY_MSG, NULL);
		msg2.notice = SNotice(getId(), 0);
		notifyParent(msg2);
	}
}
//�����Ϣ������
void CButton::onMouseDown(SPoint& point)
{
	if (borderStyle != SUNKEN_BORDER)
	{
		setBorderStyle(SUNKEN_BORDER);
		//Ҫ���ػ�
		requestDraw();
		//���ð�ť���ְ���״̬���ʱ�䣬������ָ�ԭ��
		CAdaptor::registerTimer(this, 1000); //2000ms
	}
}
//��ť�Ķ�ʱ��Ϣ
void CButton::onTimer()
{
	if (borderStyle == SUNKEN_BORDER){
		setBorderStyle(EMBOSSING_BORDER);
		//Ҫ���ػ�
		requestDraw();
		//ȡ����ʱ
		CAdaptor::stopTimer(this);
		//֪ͨ������,��������¼�������ť�����˰��º͵���
		SMsg msg2(NOTIFY_MSG, NULL);
		msg2.notice = SNotice(getId(), 0);
		notifyParent(msg2);
	}
}

//�ػ��Լ�
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
#include "CBitmap.h"

//�������ý������
void CBitmap::setFocus(bool flag){
	focus = false;
}
//�õ�������Ϣ
bool CBitmap::isRun(){
	return status == 1;
}
//���Ӷ�����ͼ��
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

//����onDraw,�ػ��Լ�
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
//����onTimer,��ʱ������
void CBitmap::onTimer()
{
	if (status == 1){
		curIndex = (curIndex + 1) % size;
		//onDraw(CAdaptor::getAdaptor());
		requestDraw();
		status = 1;
	}
}
//����onNotify,�����յ���֪ͨ
void CBitmap::onNotify(SNotice& notice){
	if (notice.type == 1)  //ֹͣ����
		status = 0;
	else if (notice.type == 2) //��ʼ����
		status = 1;
}
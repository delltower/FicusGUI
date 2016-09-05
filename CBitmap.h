#ifndef CBITMAP_H
#define CBITMAP_H
#include<iostream>
#include "CWidget.h"
#include "CAdaptor.h"
#include "IDrawInterface.h"
#include "IObserver.h"

class CBitmap :public CWidget{
public:
	//text��λͼ����
	CBitmap(const char* text,const SRect& rt,const SWORD id= 0,BORDERSTYLE style = NONE_BORDER) :CWidget(text, rt,id,style){
		for (int i = 0; i < 100; i++){
			allBitmap[i] = NULL;
		}
		if (text){
			allBitmap[curIndex] = title;
			size = 1;
		}
		else size = 0;
		curIndex = 0;
		status = 0;
	}
	
	//�������ý������
	void setFocus(bool flag = false);
	//�õ�������Ϣ
	bool isRun(); 
	//���Ӷ�����ͼ��
	void addBitmap(const char* text);
protected:
	//����onDraw,�ػ��Լ�
	void onDraw(CAdaptor* pAda);
	//����onTimer,��ʱ������
	void onTimer();
	//����onNotify,�����յ���֪ͨ
	void onNotify(SNotice& notice);
private:
	char* allBitmap[100]; //���е�bitmap
	int size;	//	bitmap������
	int curIndex;	//��ǰ��bitmap
	int status;//��ǰ��״̬��0��������1�����Ѿ�����
};
#endif
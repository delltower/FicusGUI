#ifndef CEDIT_H
#define CEDIT_H
#include<iostream>
#include "CLabel.h"
#include "CAdaptor.h"

class CEdit :public CLabel{
public:
	CEdit(const SRect& rt, short maxLen, const SWORD id = 0, BORDERSTYLE style = SUNKEN_BORDER) :CLabel(NULL, rt,id,style){
		limit = maxLen;
		cursorPos = 0;
		isCursor = false;
		isText = true;
		setBgColor(COLOR_WHITE);
		setForeColor(COLOR_BLACK);

		if (title)
			delete[] title;
		title = new char[30];	//�ַ��Ļ���
		for (int i = 0; i < 30; i++)
			title[i] = '\0';
	}
	//��������ַ���
	void setLimit(short len)
	{
		limit = len;
	}
	void setCursorPos(short pos)
	{
		cursorPos = pos;
	}
	void setCursor(bool flag = true){
		isCursor = flag;
	}
	//set focus,override the label's setFocus
	void setFocus(bool flag = true){ focus = flag; }
	//�õ�����ַ���
	short getLimit(){ return limit; }
	short getCursorPos(){ return cursorPos; }
	bool getCursorFlag(){ return isCursor; }

	
	void onDraw(CAdaptor* pAda);
	//���������
	void onMouseDown(SPoint& point);
	//�����ʱ��
	void onTimer();
	//���������Ϣ
	void onKey(SMsg& msg);
	
private:
	//�������
	void insertChar(){}
	//ɾ�����ǰһ���ַ�
	void deleteChar(){}
private:
	short limit;//����ַ���
	short cursorPos;	//��굱ǰλ��,ֵΪ�����ַ���index
	bool isCursor;	//�Ƿ���ʾ���
	bool isText; //�Ƿ���ʾ����
};
#endif
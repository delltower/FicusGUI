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
		title = new char[30];	//字符的缓存
		for (int i = 0; i < 30; i++)
			title[i] = '\0';
	}
	//设置最大字符数
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
	//得到最大字符数
	short getLimit(){ return limit; }
	short getCursorPos(){ return cursorPos; }
	bool getCursorFlag(){ return isCursor; }

	
	void onDraw(CAdaptor* pAda);
	//处理鼠标点击
	void onMouseDown(SPoint& point);
	//处理计时器
	void onTimer();
	//处理键盘消息
	void onKey(SMsg& msg);
	
private:
	//光标后插入
	void insertChar(){}
	//删除光标前一个字符
	void deleteChar(){}
private:
	short limit;//最大字符数
	short cursorPos;	//光标当前位置,值为后面字符的index
	bool isCursor;	//是否显示光标
	bool isText; //是否显示字体
};
#endif
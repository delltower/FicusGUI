#ifndef CBITMAP_H
#define CBITMAP_H
#include<iostream>
#include "CWidget.h"
#include "CAdaptor.h"
#include "IDrawInterface.h"
#include "IObserver.h"

class CBitmap :public CWidget{
public:
	//text是位图名称
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
	
	//不能设置焦点的类
	void setFocus(bool flag = false);
	//得到运行信息
	bool isRun(); 
	//增加动画的图像
	void addBitmap(const char* text);
protected:
	//覆盖onDraw,重画自己
	void onDraw(CAdaptor* pAda);
	//覆盖onTimer,定时器到点
	void onTimer();
	//覆盖onNotify,处理收到的通知
	void onNotify(SNotice& notice);
private:
	char* allBitmap[100]; //所有的bitmap
	int size;	//	bitmap的数量
	int curIndex;	//当前的bitmap
	int status;//当前的状态，0代表不动，1代表已经启动
};
#endif
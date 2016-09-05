#ifndef  COBJECT_H
#define  COBJECT_H
#include<stdlib.h>
#include "FCommon.h"
#include "CAdaptor.h"

//所有类的基类
class CObject{
public:
	//id,style
	CObject(const SWORD id = 0, const BORDERSTYLE style = NONE_BORDER){
		foreColor = COLOR_BLACK;
		bgColor = COLOR_GRAY;
		parent = NULL;
		this->id = id;
		borderStyle = style;
		//ifCanFocus = true;
	}
	//区域,id,style
	CObject(const SRect& rt, const SWORD id = 0, const BORDERSTYLE style = NONE_BORDER) :CObject(id, style){
		rect = rt;
	}
	virtual ~CObject(){}  //为啥虚函数
	//set function
	 void setForeColor(COLORVAL color) //设置前景色
	{
		foreColor = color;
	}
	 void setBgColor(COLORVAL color) //设置背景色
	{
		bgColor = color;
	}
	 void setRect(SRect& rt) //改变所在矩形大小
	{
		rect = rt;
	}
	 void setBorderStyle(BORDERSTYLE style) //设置边框风格
	{
		borderStyle = style;
	}
	 void setId(const WORD id) //设置id，为啥id可以随便设置
	{
		this->id = id;
	}
	 void setParent(CObject* item) //设置父元素
	{
		if (item)
			parent = item;
	//	else parent = NULL;
	}
	 void setFocus(bool flag = true) //设置焦点
	{
		focus = flag;
	}
	//get function
	 COLORVAL getForeColor() //得到前景色
	{
		return foreColor;
	}
	 COLORVAL getBgColor() //得到背景色
	{
		return bgColor;
	}
	 virtual void getClientRect(SRect& rt) //得到客户区矩形，不同的组件不同的结果
	{
		rt = rect;
	}
	 BORDERSTYLE getBorderStyle() //得到边框风格
	{
		return borderStyle;
	}
	 WORD getId() //得到id
	{
		return id;
	}
	 CObject* getParent() //得到父元素
	{
		return parent;
	}
	 bool isFocus() //是否为焦点
	{
		return focus;
	}
	 bool message(SMsg& msg) //消息分发函数
	{
		return true;
	}
	 bool isContains(const SPoint& p) //判断像素是否在本元素
	{
		return rect.isContains(p.x, p.y);
	}
	
	//process function
	 virtual void msgProc(SMsg& msg);  //处理消息的虚函数
	 virtual void onDraw(CAdaptor* pAda); ////处理重画消息
	 virtual void onKey(SMsg& pMsg); //处理键盘消息
	 virtual void onMouseDown(SPoint& p);//处理鼠标消息
	 virtual void onMouseUp(SPoint& p); //处理鼠标消息
	 virtual void onDrawRequest(short idFlag);	//处理请求重画消息
	 void onFocus(SMsg* pMsg);	//处理焦点切换消息
	 virtual void onNotify(SNotice& notice);//处理通知
	 virtual void onTimer();//处理定时器消息
	 void requestDraw();//发送重画消息给父窗口
	
protected:
	 void drawBorder(CAdaptor* pAda, BORDERSTYLE style);	//根据矩形大小和风格绘制边框
	 void notifyParent(SMsg& msg);//发送通知消息给父窗口
	 void onFocus(SMsg& msg); //处理焦点切换消息  为啥不是虚函数
protected:
	COLORVAL foreColor;	//前景色
	COLORVAL bgColor;	//背景色
	SRect rect;	//元素所在区域
	BORDERSTYLE borderStyle;	//边框风格
	SWORD id;	//元素的id
	CObject* parent;	//父窗口元素
	bool focus;	//是否为焦点

};
#endif
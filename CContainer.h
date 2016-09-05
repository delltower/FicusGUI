#ifndef CCONTAINER_H
#define CCONTAINER_H
#include "CObject.h"
#include "SDList.h"

class CContainer:public CObject{
public:	
	CContainer(const SWORD id = 0, BORDERSTYLE style = NONE_BORDER):CObject(id,style),objectList(){
		isDone = true;
	}
	CContainer(const SRect& rt,const SWORD id = 0,BORDERSTYLE style = NONE_BORDER):CObject(rt,id,style),objectList(){	
		isDone = true;
	}
	~CContainer(){}
	//是否正在遍历,ture表示正遍历
	bool checkStatus()
	{
		return !isDone;
	}
protected:   //只能供派生类使用  
	bool addItem(CObject* p);//添加子窗口元素
	CObject* getItemById(SWORD id); //通过id得到元素
	bool removeItem(CObject* p);//删除一个子窗口元素
	bool removeAllItem();	//删除所有元素
	void sendMsgAll(SMsg& msg); //向所有子控件发送消息
	void sendNotice(SWORD id, short int type); //向控件发送通知
	void changeFocus(CObject* p); //改变焦点控件
	SDNode* first();  //获得第一个子控件
		 
protected:
	CObject* focusItem;//得到焦点的组件或者窗口	
	bool isDone;	//是否正在遍历，true表示完成遍历或者没有遍历
	SDList objectList;
};
#endif
#ifndef CADAPTOR_H
#define CADAPTOR_H
#include<windows.h>
#include "IDrawInterface.h"
#include "IObserver.h"
class CTimerManger;
class CObject;

class CAdaptor:public IObserver{  
public: //用户可以执行下列函数
	void run();	//运行
	static CAdaptor* getAdaptor();	//返回各自的平台的adaptor
	//FG_OSMsgObserver* SetMsgObserver(word type, FG_OSMsgObserver* const pObserver); 注册系统消息的观察者
	//void SendMsg(FG_Message* pMsg); //发送系统消息给注册的观察者
	virtual void beginDraw(SRect&);	//开始画图，提供画图的矩形
	virtual void endDraw() ; //结束画图，回收资源
	virtual void fillRect(SRect&, COLORVAL foreColor, COLORVAL backgroundColor);//填充矩形，提供前景色，背景色
	//画直线，提供起点和终点，坐标是相对于画布的，使用时加上所在矩形的起点
	virtual void line(int, int, int, int, COLORVAL);
	//画文字,提供内容和位置，文字颜色
	virtual void drawText(const char*, int, int, COLORVAL);
	//得到文本的宽度
	virtual int getTextWidth(const char*);
	//得到文本的高度
	virtual int getTextHeight(const char*);
	//画位图
	virtual void drawBitmap(const char*, int, int);
	//画折线,提供点的数组，点的个数，颜色
	virtual void drawPolyLine(SPoint*, int, COLORVAL);
	//画虚线矩形，提供矩形大小坐标和颜色
	virtual void drawDotRect(SRect&, COLORVAL);
	
	//消息
	IObserver* setObserver(IObserver*,MSGTYPE);//注册观察者,返回上次的观察者
	static void sendMsg(SMsg&); //发送消息
	//注册定时器
	static bool registerTimer(CObject*, unsigned int);
	//停止定时器
	static bool stopTimer(CObject* obj);

	//消息
	//virtual IObserver* setObserver(MSGTYPE) = 0;//注册观察者,返回上次的观察者
	//virtual void sendMsg(SMsg&) = 0; //发送消息
	//virtual void processMessage(SMsg&) = 0;  //处理消息
	~CAdaptor(){}
protected: //这些函数在子类是protected属性，用户不需要调用这些函数
	CAdaptor(){};//防止派生类的对象调用此函数
	virtual void initInstance() = 0;	//程序初始化
	virtual void executeInstance() = 0; //程序执行
	virtual void exitInstance() = 0;//程序退出，回收资源
protected: //静态的成员要在运行之前初始化，程序中只有这一个adaptor可以获得操作系统的接口
	//FG_OSMsgObserver* m_ppObserver[FG_MAX_SYS_MSG]; 记录所有的系统消息的观察者的数组
	static IDrawInterface* pDraw;	//获得能画图的接口
	static CAdaptor* pAdaptor;	//获得操作系统的适配器
	static IObserver* allObserver[MAX_MSGNUM]; //所有消息的观察者的指针
	static CTimerManger* timerManger;
};

#endif
/*使用示例
FG_Win32Adaptor * pAdp = (FG_Win32Adaptor *)FG_GetAdaptor(); //获得操作系统的adaptor
pAdp->SetBmpPath(Name, length); //设置位图路径

pAdp->SetInst(hInstance);  //windows下设置句柄
pAdp->SetPrevInst(hPrevInstance); //windows下设置句柄
pAdp->SetCmdShow(nCmdShow); //windows下设置句柄
pAdp->Run(); //程序运行，程序的动作在windows的wndProc函数中设定
*/
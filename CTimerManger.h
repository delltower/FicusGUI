#ifndef CTIMERMANGER_H
#define CTIMERMANGER_H
#include "CObject.h"
#include "IObserver.h"

struct STimer{
	CObject* pTarget;		//定时器的使用者
	unsigned int interval;  //定时间隔
	unsigned long spare;//剩余时间
	STimer() :pTarget(NULL), interval(0), spare(0){}
	STimer(CObject* p, unsigned int i) :pTarget(p), interval(i), spare(i){}
};

class CTimerManger :public IObserver{
public:

	static CTimerManger* getTimerManger(){
		if (!timerManger){
			timerManger = new CTimerManger();
		}
		return timerManger;
	}
	//遍历计时器
	void tick();
	//增加计时器
	void addTimer(CObject* t, unsigned int i);
	//停止计时器
	void delTimer(CObject* p);
	//事件处理
	void processMessage(SMsg& msg);
	static CTimerManger* timerManger;
private:
	CTimerManger(){
		for (int i = 0; i < 5; i++)
			allTimer[i] = STimer();
		size = 0;
	}
private:

	STimer allTimer[5];	//所有的定时器
	int size;//	定时器的个数
};

#endif
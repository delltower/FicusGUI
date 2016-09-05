#include "CTimerManger.h"

CTimerManger* CTimerManger::timerManger = NULL;
void CTimerManger::tick(){ //遍历计时器
	int i = 0;
	for (i = 0; i < size; i++){
		if (allTimer[i].spare <= 500) //倒计时结束
		{
			SMsg msg(TIMER_MSG, NULL);
			allTimer[i].pTarget->msgProc(msg);
		}
		else allTimer[i].spare -= 500;  //减少倒计时
	}
}
void CTimerManger::addTimer(CObject* t, unsigned int i){
	if (size < 5 && t){
		allTimer[size] = STimer(t, i);
		size++;
	}
}
//停止计时器
void CTimerManger::delTimer(CObject* p){
	if (p && size > 0){
		int i = 0;
		for (; i < size; i++){
			if (allTimer[i].pTarget == p)
				break;
		}
		if (i < size){
			size--;
			for (; i < size; i++)
				allTimer[i] = allTimer[i + 1];
		}
	}
}
void CTimerManger::processMessage(SMsg& msg)
{
	if (msg.type == TIMER_MSG){
		tick();
	}
}
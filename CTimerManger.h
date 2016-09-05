#ifndef CTIMERMANGER_H
#define CTIMERMANGER_H
#include "CObject.h"
#include "IObserver.h"

struct STimer{
	CObject* pTarget;		//��ʱ����ʹ����
	unsigned int interval;  //��ʱ���
	unsigned long spare;//ʣ��ʱ��
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
	//������ʱ��
	void tick();
	//���Ӽ�ʱ��
	void addTimer(CObject* t, unsigned int i);
	//ֹͣ��ʱ��
	void delTimer(CObject* p);
	//�¼�����
	void processMessage(SMsg& msg);
	static CTimerManger* timerManger;
private:
	CTimerManger(){
		for (int i = 0; i < 5; i++)
			allTimer[i] = STimer();
		size = 0;
	}
private:

	STimer allTimer[5];	//���еĶ�ʱ��
	int size;//	��ʱ���ĸ���
};

#endif
#ifndef IOBSERVER_H
#define IOBSERVER_H
#include "SMsg.h"

class IObserver{
public:
	
	~IObserver(){}
	virtual void processMessage(SMsg& msg)  = 0;  //������Ϣ

protected:
	IObserver() {}
};
#endif
#ifndef SMSG_H
#define SMSG_H
#include "FCommon.h"
struct SNotice{
	SWORD id;	//组件id
	short int type; //通知类型,0代表click事件,1代表停止,2代表开始,3取消焦点，4，得到焦点
	SNotice(SWORD i = 0, short int t = 0) :id(i), type(t){}
};
struct SMsg{
	MSGTYPE type; //消息类型
	char* data;//消息内容
	SNotice notice;
	short id;
	short x;
	short y;
	SWORD keyData;
	SMsg(){ type = EMPTY_MSG; data = NULL; }//空消息
	SMsg(MSGTYPE t, const char* d = NULL):SMsg(){
		type = t;
		if (d){
			unsigned i = 0, size = strlen(d);
			data = new char[size + 1];
			for (i = 0; i < size; i++) data[i] = d[i];
			data[size] = '\0';
		}
	}
	SMsg(const SMsg& other){ //拷贝复制函数
		type = other.type;
		if (other.data){
			unsigned i = 0, size = strlen(other.data);
			data = new char[size + 1];
			for (i = 0; i < size; i++) data[i] = other.data[i];
			data[size] = '\0';
		}
		else data = NULL;
	}
	~SMsg(){
		if (data)
			delete[] data;
	}
};
#endif
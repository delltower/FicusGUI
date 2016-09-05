#ifndef SMSG_H
#define SMSG_H
#include "FCommon.h"
struct SNotice{
	SWORD id;	//���id
	short int type; //֪ͨ����,0����click�¼�,1����ֹͣ,2����ʼ,3ȡ�����㣬4���õ�����
	SNotice(SWORD i = 0, short int t = 0) :id(i), type(t){}
};
struct SMsg{
	MSGTYPE type; //��Ϣ����
	char* data;//��Ϣ����
	SNotice notice;
	short id;
	short x;
	short y;
	SWORD keyData;
	SMsg(){ type = EMPTY_MSG; data = NULL; }//����Ϣ
	SMsg(MSGTYPE t, const char* d = NULL):SMsg(){
		type = t;
		if (d){
			unsigned i = 0, size = strlen(d);
			data = new char[size + 1];
			for (i = 0; i < size; i++) data[i] = d[i];
			data[size] = '\0';
		}
	}
	SMsg(const SMsg& other){ //�������ƺ���
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
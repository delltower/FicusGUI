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
	//�Ƿ����ڱ���,ture��ʾ������
	bool checkStatus()
	{
		return !isDone;
	}
protected:   //ֻ�ܹ�������ʹ��  
	bool addItem(CObject* p);//����Ӵ���Ԫ��
	CObject* getItemById(SWORD id); //ͨ��id�õ�Ԫ��
	bool removeItem(CObject* p);//ɾ��һ���Ӵ���Ԫ��
	bool removeAllItem();	//ɾ������Ԫ��
	void sendMsgAll(SMsg& msg); //�������ӿؼ�������Ϣ
	void sendNotice(SWORD id, short int type); //��ؼ�����֪ͨ
	void changeFocus(CObject* p); //�ı佹��ؼ�
	SDNode* first();  //��õ�һ���ӿؼ�
		 
protected:
	CObject* focusItem;//�õ������������ߴ���	
	bool isDone;	//�Ƿ����ڱ�����true��ʾ��ɱ�������û�б���
	SDList objectList;
};
#endif
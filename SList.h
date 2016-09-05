#ifndef SLIST_H
#define SLIST_H
#include "CObject.h"
#include<stdlib.h>

struct SNode{
	CObject* data;
	SNode* next;
	SNode(CObject* d = NULL){
		data = d;
		next = NULL;
	}
};
class SList{
public:
	SList(){
		head = new SNode();
		tail = NULL;
		head->next = tail;
		num = 0;
	}
	bool insFirst(CObject* data){ //ͷ��������Ԫ��
		if (data){
			SNode* p = new SNode(data);
			p->next = head->next;
			head->next = p;

			if (!tail) tail = p;
			num++;
			return true;
		}
		else return false;
	}
	CObject* delFirst(){ //ɾ����һ����㣬������
		if (head->next) {
			num--;
			return head->next->data;
		}
		else return NULL;
	}
	void append(CObject* data){ //ĩβ���Ԫ��
		if (!data) return;
		if (tail){
			tail->next = new SNode(data);
			num++;
		}
		else{
			head->next = new SNode(data);
			tail = head->next;
			num = 1;
		}
	}
	CObject*  remove(){ //�Ƴ����һ��Ԫ�أ�������
		if (tail){
			SNode* p = head;
			while (p->next != tail){
				p = p->next;
			}
			p->next = NULL;
			CObject* res = tail->data;
			tail = p;
			return res;
		}
		else return NULL;
	}
	void clear(){ //�������Ԫ��
		SNode* p = head,*temp = NULL;
		while (p->next){
			temp = p->next;
			p->next = p->next->next;
			delete temp;
		}
		tail = NULL;
		head->next = NULL;
		num = 0;
	}
	int lengh(){ //Ԫ�ظ���
		return num;
	}

	SNode* find(CObject* data){ //�ҵ�Ԫ��
		SNode* p = head;
		while (p->next){
			if (p->next->data == data) return p->next;
		}
		return NULL;
	}
	SNode* findPre(CObject* data){ //�ҵ�Ԫ��֮ǰ��Ԫ��,�ҵ�ͷ��㷵�ؿ�
		SNode* res = findPreInner(data);
		if (!res || res == head) return NULL;
		else return res;
	}
	bool isEmpty(){ //�Ƿ�Ϊ��
		return false;
	}
protected:
	SNode* findPreInner(CObject* data){ //�ҵ�Ԫ��֮ǰ��Ԫ��,�ڲ�ʹ��
		if (!data) return NULL;
		SNode* p = head;
		while (p->next){
			if (p->next->data == data) return p;
		}
		return NULL;
	}
private:
	SNode* head;   //ͷ��㣬��װԪ��
	SNode* tail;	//���һ��Ԫ��
	int num;	//Ԫ�ظ���

};
#endif
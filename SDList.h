#ifndef SDLIST_H
#define SDLIST_H
#include "CObject.h"
#include<stdlib.h>
#include<stdio.h>

struct SDNode{ //���ĸ���û��д��������������ָ��ͬһ�������ڴ�
	CObject* data;
	SDNode* next;
	SDNode* pre;
	SDNode(CObject* d = NULL){
		data = d;
		next = NULL;
		pre = NULL;
	}
};
class SDList{  //����ĸ���û��д,��Ӧ��дһ��������������
public:
	SDList(){
		head = new SDNode();
		tail = NULL;
		head->next = tail;
		num = 0;
	}
	SDNode* first(){
		if (head->next) return head->next;
		else return NULL;
	}
	SDNode* last(){
		if (tail) return tail;
		else return NULL;
	}
	void append(CObject* data){ //ĩβ���Ԫ��
		if (data){
			SDNode* p = new SDNode(data);
			if (!tail){
				p->pre = head;
				head->next = p;
				tail = p;
			}
			else {
				p->pre = tail;
				tail->next = p;
				tail = p;
			}
			num++;
		}
	}
	SDNode* remove(){ //�Ƴ����һ��Ԫ��
		if (tail){
			SDNode * res = tail;
			tail = tail->pre;
			tail->next = NULL;

			res->pre = NULL;
			num--;
			return res;
		}
		else return NULL;
	}
	void clear(){ //�������Ԫ��
		SDNode* p = head,*temp = NULL;
		while (p->next){
			temp = p->next;
			p->next = p->next->next;
			delete temp;
		}
		tail = NULL;
		head->next = tail;
		num = 0;
	}
	SDNode* find(CObject* data){ //�ҵ�Ԫ��
		SDNode* p = head;
		while (p->next){
			if (p->next->data == data) return p->next;
			p = p->next;
		}
		return NULL;
	}
	bool delItem(CObject* data){ //ɾ��ĳԪ��
		SDNode* p = find(data);
		if (p){
			p->pre->next = p->next;
			if (p != tail) p->next->pre = p->pre;
			else tail = p->pre;
			delete p;
			return true;
		}
		else return NULL;
	}
	bool isEmpty(){ //�Ƿ�Ϊ��
		return tail == NULL;
	}
	int length(){ //����Ԫ�ظ���
		return num;
	}
	~SDList(){
		if (head)
			delete head;
	}

private:
	SDNode* head; //ͷ���,��װԪ��
	SDNode* tail; //β���

	int num;	//Ԫ�ظ���

};
#endif
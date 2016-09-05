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
	bool insFirst(CObject* data){ //头部插入新元素
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
	CObject* delFirst(){ //删除第一个结点，并返回
		if (head->next) {
			num--;
			return head->next->data;
		}
		else return NULL;
	}
	void append(CObject* data){ //末尾添加元素
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
	CObject*  remove(){ //移除最后一个元素，并返回
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
	void clear(){ //清空所有元素
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
	int lengh(){ //元素个数
		return num;
	}

	SNode* find(CObject* data){ //找到元素
		SNode* p = head;
		while (p->next){
			if (p->next->data == data) return p->next;
		}
		return NULL;
	}
	SNode* findPre(CObject* data){ //找到元素之前的元素,找到头结点返回空
		SNode* res = findPreInner(data);
		if (!res || res == head) return NULL;
		else return res;
	}
	bool isEmpty(){ //是否为空
		return false;
	}
protected:
	SNode* findPreInner(CObject* data){ //找到元素之前的元素,内部使用
		if (!data) return NULL;
		SNode* p = head;
		while (p->next){
			if (p->next->data == data) return p;
		}
		return NULL;
	}
private:
	SNode* head;   //头结点，不装元素
	SNode* tail;	//最后一个元素
	int num;	//元素个数

};
#endif
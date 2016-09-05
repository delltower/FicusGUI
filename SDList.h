#ifndef SDLIST_H
#define SDLIST_H
#include "CObject.h"
#include<stdlib.h>
#include<stdio.h>

struct SDNode{ //结点的复制没有写，两个结点的数据指向同一个数据内存
	CObject* data;
	SDNode* next;
	SDNode* pre;
	SDNode(CObject* d = NULL){
		data = d;
		next = NULL;
		pre = NULL;
	}
};
class SDList{  //链表的复制没有写,还应该写一个迭代器来遍历
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
	void append(CObject* data){ //末尾添加元素
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
	SDNode* remove(){ //移除最后一个元素
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
	void clear(){ //清空所有元素
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
	SDNode* find(CObject* data){ //找到元素
		SDNode* p = head;
		while (p->next){
			if (p->next->data == data) return p->next;
			p = p->next;
		}
		return NULL;
	}
	bool delItem(CObject* data){ //删除某元素
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
	bool isEmpty(){ //是否为空
		return tail == NULL;
	}
	int length(){ //返回元素个数
		return num;
	}
	~SDList(){
		if (head)
			delete head;
	}

private:
	SDNode* head; //头结点,不装元素
	SDNode* tail; //尾结点

	int num;	//元素个数

};
#endif
#include"LinkedList1.h"
#include<iostream>
#include"Star.h"
//void initLinkedList1(LinkedList1& ll1) {
//	
//	 ll1.p_next= NULL;
//}
//LinkedList1::LinkedList1() {
//date = new Star();
//p_next = NULL;
//	}LinkedList1::LinkedList1() {}
LinkedList1::LinkedList1() {
	date = new int();
	p_next = NULL;
		}
using namespace std;
bool addLinkedList1(LinkedList1& ll1, LinkedListHead& llh, int i) {
	if (i <= 0) { cout << "添加失败\n"; return false; }
	if (i == 1) {
		addHeadLinkedList1(ll1, llh);  return true;
	}
	int j = 2;
	LinkedList1* p;
	p = llh.p_next;
	while (p) {
		if (j == i) {
			/*if ((*(p)).p_next == NULL) {
				(*(p)).p_next = ll1.p_next; ll1.p_next = NULL; return true;
			}*/
			LinkedList1* tp = p; ll1.p_next = p->p_next;//先把插入的节点指针指向插入后的下一个节点
			tp->p_next = &ll1; //再把前一个节点的指针指向插入的节点
			cout << "添加成功\n";
			return true;
		}		
		else if (j < i) {
			if ((*(p)).p_next == NULL) {
				cout << "添加失败\n"; return false;
			}
			p = (*(p)).p_next; j++;
		}
	}cout << "添加失败\n";
	return false;
}

void addHeadLinkedList1(LinkedList1& ll1, LinkedListHead& llh) {
	if (llh.p_next==NULL) {
		llh.p_next = &ll1; 
	}
	else {
		
		ll1.p_next = llh.p_next; llh.p_next = &ll1;
	}cout << "添加成功\n";
}

void addEndLinkedList1(LinkedList1& ll1, LinkedListHead& llh) {
	if (llh.p_next == NULL) { llh.p_next = &ll1; ll1.p_next = NULL; cout << "添加失败\n"; return; }
	LinkedList1* p=llh.p_next;
	while (p) {
		if ((*(p)).p_next==NULL) {
			(*(p)).p_next = ll1.p_next; ll1.p_next = NULL; break;
		}
		p = (*(p)).p_next;
	}cout << "添加成功\n";
}

bool subLinkedList1(LinkedListHead& llh,size_t i) {
	if (llh.p_next == NULL || i <= 0) { cout << "删除失败\n"; return false; }
	size_t j = 2;
	LinkedList1* p ;
	p = llh.p_next;
	while (p) {
		if (j==i) {
			LinkedList1* tp= (*(p)).p_next;
			(*(p)).p_next = ((*(p)).p_next)->p_next;
			 delete (*(tp)).date; delete tp; cout << "移除成功\n"; return true;
		}
		else if (i==1) {
			llh.p_next = p->p_next; delete (*(p)).date; delete p; cout << "移除成功\n"; return true;
		}
		else if (j<i) {
			if ((*(p)).p_next == NULL) {
				cout << "删除失败\n"; return false;
			}
			p = (*(p)).p_next; j++;
		}
	}cout << "删除失败\n";
	return false;
}

bool deleteLinkedList1(LinkedListHead& llh) {
	if (llh.p_next == NULL) { cout << "删除失败\n"; return false; }
	//size_t j = 2;
	LinkedList1* p;
	p = llh.p_next;
	while (p) {
		LinkedList1* tp = p;
		p = p->p_next;
		delete (*(tp)).date; delete tp;
	}llh.p_next = NULL; cout << "删除成功\n"; return true;
}
//按值查找
LinkedList1** findLinkedList1(LinkedListHead& llh, int i) {
	if (llh.p_next == NULL) { cout << "查找失败\n"; return NULL; }
	LinkedList1* p; LinkedList1** pArr= new LinkedList1*[FIND_COUNT](); int count = 0;
	p = llh.p_next;
	while (p) {
		if (*(p->date) == i) {			
			cout << "查找成功\t所在节点地址为" << p << endl; pArr[count] = p; count++;
			p = p->p_next;
			continue;
		}
		else {
			p = p->p_next;
		}
	}if (pArr) {
		return pArr;
	}
	else {
		cout << "查找失败\n"; return NULL;
	}
}

void printfLinkedList1(LinkedListHead& llh) {
	if (llh.p_next == NULL) { cout << "输出失败\n"; return; }
	LinkedList1* p;
	p = llh.p_next;
	while (p) {
		cout << *(p->date) << "\t";		
			p = p->p_next;		
	}cout << "输出成功\n";
}



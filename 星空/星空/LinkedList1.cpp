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
	if (i <= 0) { cout << "���ʧ��\n"; return false; }
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
			LinkedList1* tp = p; ll1.p_next = p->p_next;//�ȰѲ���Ľڵ�ָ��ָ���������һ���ڵ�
			tp->p_next = &ll1; //�ٰ�ǰһ���ڵ��ָ��ָ�����Ľڵ�
			cout << "��ӳɹ�\n";
			return true;
		}		
		else if (j < i) {
			if ((*(p)).p_next == NULL) {
				cout << "���ʧ��\n"; return false;
			}
			p = (*(p)).p_next; j++;
		}
	}cout << "���ʧ��\n";
	return false;
}

void addHeadLinkedList1(LinkedList1& ll1, LinkedListHead& llh) {
	if (llh.p_next==NULL) {
		llh.p_next = &ll1; 
	}
	else {
		
		ll1.p_next = llh.p_next; llh.p_next = &ll1;
	}cout << "��ӳɹ�\n";
}

void addEndLinkedList1(LinkedList1& ll1, LinkedListHead& llh) {
	if (llh.p_next == NULL) { llh.p_next = &ll1; ll1.p_next = NULL; cout << "���ʧ��\n"; return; }
	LinkedList1* p=llh.p_next;
	while (p) {
		if ((*(p)).p_next==NULL) {
			(*(p)).p_next = ll1.p_next; ll1.p_next = NULL; break;
		}
		p = (*(p)).p_next;
	}cout << "��ӳɹ�\n";
}

bool subLinkedList1(LinkedListHead& llh,size_t i) {
	if (llh.p_next == NULL || i <= 0) { cout << "ɾ��ʧ��\n"; return false; }
	size_t j = 2;
	LinkedList1* p ;
	p = llh.p_next;
	while (p) {
		if (j==i) {
			LinkedList1* tp= (*(p)).p_next;
			(*(p)).p_next = ((*(p)).p_next)->p_next;
			 delete (*(tp)).date; delete tp; cout << "�Ƴ��ɹ�\n"; return true;
		}
		else if (i==1) {
			llh.p_next = p->p_next; delete (*(p)).date; delete p; cout << "�Ƴ��ɹ�\n"; return true;
		}
		else if (j<i) {
			if ((*(p)).p_next == NULL) {
				cout << "ɾ��ʧ��\n"; return false;
			}
			p = (*(p)).p_next; j++;
		}
	}cout << "ɾ��ʧ��\n";
	return false;
}

bool deleteLinkedList1(LinkedListHead& llh) {
	if (llh.p_next == NULL) { cout << "ɾ��ʧ��\n"; return false; }
	//size_t j = 2;
	LinkedList1* p;
	p = llh.p_next;
	while (p) {
		LinkedList1* tp = p;
		p = p->p_next;
		delete (*(tp)).date; delete tp;
	}llh.p_next = NULL; cout << "ɾ���ɹ�\n"; return true;
}
//��ֵ����
LinkedList1** findLinkedList1(LinkedListHead& llh, int i) {
	if (llh.p_next == NULL) { cout << "����ʧ��\n"; return NULL; }
	LinkedList1* p; LinkedList1** pArr= new LinkedList1*[FIND_COUNT](); int count = 0;
	p = llh.p_next;
	while (p) {
		if (*(p->date) == i) {			
			cout << "���ҳɹ�\t���ڽڵ��ַΪ" << p << endl; pArr[count] = p; count++;
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
		cout << "����ʧ��\n"; return NULL;
	}
}

void printfLinkedList1(LinkedListHead& llh) {
	if (llh.p_next == NULL) { cout << "���ʧ��\n"; return; }
	LinkedList1* p;
	p = llh.p_next;
	while (p) {
		cout << *(p->date) << "\t";		
			p = p->p_next;		
	}cout << "����ɹ�\n";
}



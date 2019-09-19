#include"LoopLinkedList.h"
#include<iostream>
#include"Star.h"
//using namespace std;
LoopLinkedList::LoopLinkedList() {
	date = new Star();
	p_next = nullptr;
}
inline void initLoopLinkedList(LoopLinkedList* ll1, LoopLinkedListHead& lllh);
bool addLoopLinkedList(LoopLinkedList& ll1, LoopLinkedListHead& llh, int i) {
	if (i <= 0) { cout << "���ʧ��\n"; return false; }
	if (i == 1) {
		addHeadLoopLinkedList(ll1, llh);  return true;
	}
	int j = 2;
	LoopLinkedList* p;
	p = llh.p_next;
	while (p != &llh) {
		if (j == i) {
			LoopLinkedList* tp = p; ll1.p_next = p->p_next;//�ȰѲ���Ľڵ�ָ��ָ���������һ���ڵ�
			initLoopLinkedList((p->p_next), llh);
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

void addHeadLoopLinkedList(LoopLinkedList& ll1, LoopLinkedListHead& lllh) {
	if (lllh.p_next == &lllh|| lllh.p_next == nullptr) {
		lllh.p_next = &ll1; 
		ll1.p_next = &lllh;//β��ͷ
	}
	else {
		ll1.p_next = lllh.p_next; initLoopLinkedList(lllh.p_next,lllh);
		lllh.p_next = &ll1;

	}cout << "��ӳɹ�\n";
}

void addEndLoopLinkedList(LoopLinkedList& ll1, LoopLinkedListHead& llh, LoopLinkedListHead& lllh) {
	if (lllh.p_next == NULL|| lllh.p_next == &lllh) { llh.p_next = &ll1; ll1.p_next = &lllh; cout << "��ӳɹ���ͷ�ڵ��ַ"<<&lllh<<"β�ڵ�ָ��"<<ll1.p_next<<endl; return; }
	LoopLinkedListHead* p = &llh;
	while (1) {
		if (p->p_next == &lllh|| p->p_next == nullptr) {
			p->p_next = &ll1;  initLoopLinkedList((&ll1), lllh); break;
		}
		else {
			p = p->p_next;
		}
	}cout << "��ӳɹ�\n";
}

LoopLinkedList* subLoopLinkedList(LoopLinkedListHead& llh, size_t i, LoopLinkedListHead& lllh) {//lllh��ͷ�ڵ㣬llhδ������ͷ�ڵ�
	if (llh.p_next == NULL || i <= 0|| llh.p_next == &lllh) { cout << "�Ƴ�ʧ��\n"; return NULL; }
	size_t j = 1;
	LoopLinkedList* p = llh.p_next;	
	while ((p) != &lllh||p!=nullptr) {		
		 if (i == 1) {
			if (p) {
				LoopLinkedList* tp = p->p_next;
				llh.p_next = p->p_next; delete p->date; delete p; cout << "�Ƴ��ɹ�\n"; return tp;
			}
			/*else {
				llh.p_next = &llh; delete (*(p)).date; delete p; cout << "�Ƴ��ɹ�\n"; return &llh;
			}*/
		}else if (j == i) {
			LoopLinkedList* tp = (*(p)).p_next;
			//(*(p)).p_next = tp;
			delete p->date; delete p; cout << "�Ƴ��ɹ�\n"; return tp;
		}
		else if (j < i) {
			if ((*(p)).p_next == NULL) {
				cout << "�Ƴ�ʧ��\n"; return NULL;
			}
			p = (*(p)).p_next; j++;
		}
	}cout << "�Ƴ�ʧ��\n";
	return nullptr;
}

bool deleteLoopLinkedList(LoopLinkedListHead& lllh) {
	if (lllh.p_next == NULL|| lllh.p_next == &lllh) { cout << "û��Ԫ��ɾ��ʧ��,���ͷ�ڵ��ڶ����������\n"; return false; }
	//size_t j = 2;
	LoopLinkedList* p;
	p = lllh.p_next;
	while (p !=&lllh) {
		LoopLinkedList* tp = p;
		p = p->p_next;
		delete (*(tp)).date; delete tp;
	}lllh.p_next = &lllh; cout << "ɾ���ɹ�\n"; return true;
}

LoopLinkedList** findLoopLinkedList(LoopLinkedListHead& lllh, int i) {
	if (lllh.p_next == NULL) { cout << "����ʧ��\n"; return NULL; }
	LoopLinkedList* p; LoopLinkedList** pArr = new LoopLinkedList * [FIND_COUNT](); int count = 0;
	p = lllh.p_next;
	while (p !=&lllh) {
		if ((p->date)->x == i) {
			cout << "���ҳɹ�\t���ڽڵ��ַΪ" << p << endl; pArr[count] = p; count++;
			p = p->p_next;
			//continue;
		}
		else {
			p = p->p_next;
		}
	}if (pArr) {
		return pArr;
	}
	else {
		cout << "����ʧ��\n"; return nullptr;
	}	
}

void printfLoopLinkedList(LoopLinkedListHead& lllh) {
	if (lllh.p_next == NULL) { cout << "���ʧ��\n"; return; }
	LoopLinkedList* p;
	p = lllh.p_next;
	while (p !=&lllh) {
		cout << (p->date)->x << "\t";
		p = p->p_next;
	}cout << "����ɹ�\n";
}

inline void initLoopLinkedList(LoopLinkedList* ll1, LoopLinkedListHead& lllh) {
	if (ll1->p_next==nullptr) {
		ll1->p_next = &lllh;
	}
}

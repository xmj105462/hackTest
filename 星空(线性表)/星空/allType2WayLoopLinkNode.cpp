#include"AllType2WayLoopLinkNode.h"
#include"Star.h"
#include"Int.h"
#include<iostream>
using namespace std;
inline void initAllType2WayLLN(AllType2WayLLN* ll1, AllType2WayH& lllh);
bool addAllType2WayLLN(AllType2WayLLN& ll1, AllType2WayH& llh, int i) {
	if (i <= 0) { cout << "���ʧ��\n"; return false; }
	if (i == 1) {
		addHeadAllType2WayLLN(ll1, llh);  return true;
	}
	int j = 2;
	AllType2WayLLN* p = llh.p_next;
	while (p != &llh) {
		if (j == i) {
			if ((*(p)).p_next == nullptr || p->p_next == &llh) {
				ll1.p_front = p; p->p_next = &ll1;
				initAllType2WayLLN((p->p_next), llh);
			}
			else {
				ll1.p_front = p; ll1.p_next = p->p_next;
				//if(p->p_next->p_next == nullptr || p->p_next->p_next == &llh){ initAllType2WayLLN((p->p_next), llh); }
				p->p_next->p_front = &ll1; p->p_next = &ll1;
			}
			cout << "��ӳɹ�\n";
			return true;
		}
		else if (j < i) {
			if ((*(p)).p_next == nullptr || p->p_next == &llh) {
				cout << "���ʧ��\n"; return false;
			}
			p = (*(p)).p_next; j++;
		}
	}cout << "���ʧ��\n";
	return false;
}

void addHeadAllType2WayLLN(AllType2WayLLN& ll1, AllType2WayH& lllh) {
	if (lllh.p_next == &lllh || lllh.p_next == nullptr) {
		lllh.p_next = &ll1; ll1.p_front = &lllh;
		ll1.p_next = &lllh;//β��ͷ
		lllh.p_front = &ll1;
	}
	else {
		ll1.p_next = lllh.p_next; lllh.p_next->p_front = &ll1; ll1.p_front = &lllh;
		initAllType2WayLLN(lllh.p_next, lllh);
		lllh.p_next = &ll1;

	}cout << "��ӳɹ�\n";
}

void addEndAllType2WayLLN(AllType2WayLLN& ll1, AllType2WayH& llh, AllType2WayH& lllh) {
	if (lllh.p_next == NULL || lllh.p_next == &lllh) {
		ll1.p_front = &llh;
		llh.p_next = &ll1;
		initAllType2WayLLN((&ll1), lllh);
		cout << "��ӳɹ���ͷ�ڵ��ַ" << &lllh << "β�ڵ�ָ��" << ll1.p_next << endl;
		return;
	}
	AllType2WayH* p = &llh;
	while (1) {
		if (p->p_next == &lllh || p->p_next == nullptr) {
			p->p_next = &ll1;  ll1.p_front = p;
			initAllType2WayLLN((&ll1), lllh); break;
		}
		else {
			p = p->p_next;
		}
	}cout << "��ӳɹ�\n";
}

AllType2WayLLN* subAllType2WayLLN(AllType2WayH& llh, size_t i, AllType2WayH& lllh) {
	if (llh.p_next == NULL || i <= 0 || llh.p_next == &lllh) { cout << "�Ƴ�ʧ��\n"; return NULL; }
	size_t j = 2;
	AllType2WayLLN* p = llh.p_next;
	while ((p) != &lllh || p != nullptr) {
		if (i == 1) {
			if (p) {
				AllType2WayLLN* tp = p->p_next;
				llh.p_next = p->p_next; tp->p_front = &llh;
				  cout << "�Ƴ��ɹ�\n"; return tp;
			}
		}
		else if (j == i) {
			if (p->p_next == nullptr || p->p_next == &lllh) { cout << "�Ƴ�ʧ��\n"; return NULL; }
			AllType2WayLLN* tp = (*(p)).p_next->p_next;
			AllType2WayLLN* tp1 = (*(p)).p_next;
			p->p_next = tp; tp->p_front = p;
			   cout << "�Ƴ��ɹ�\n"; return tp;
		}
		else if (j < i) {
			if ((*(p)).p_next == NULL || (*(p)).p_next == &lllh) {
				cout << "�Ƴ�ʧ��\n"; return NULL;
			}
			p = (*(p)).p_next; j++;
		}
	}cout << "�Ƴ�ʧ��\n";
	return nullptr;
}

//bool deleteAllType2WayLLN(AllType2WayH& llh) {
//	if (llh.p_next == NULL || llh.p_next == &llh) { cout << "û��Ԫ��ɾ��ʧ��,���ͷ�ڵ��ڶ����������\n"; return false; }
//	//size_t j = 2;
//	AllType2WayLLN* p;
//	p = llh.p_next;
//	while (p != &llh) {
//		AllType2WayLLN* tp = p;
//		p = p->p_next;
//		 delete tp;
//	}llh.p_next = &llh; cout << "ɾ���ɹ�\n"; return true;
//}

AllType2WayLLN** findAllType2WayLLN(AllType2WayH& llh, int i) {
	if (llh.p_next == NULL || llh.p_next == &llh) { cout << "����ʧ��\n"; return NULL; }
	AllType2WayLLN* p; AllType2WayLLN** pArr = new AllType2WayLLN * [FIND_COUNT](); int count = 0;
	p = llh.p_next;
	while (p != &llh) {
		////if (*(p->date) == i) {
		//	cout << "���ҳɹ�\t���ڽڵ��ַΪ" << p << endl; pArr[count] = p; count++;
		//	p = p->p_next;
		////}
		//else {
		//	p = p->p_next;
		//}
	}if (pArr) {
		return pArr;
	}
	else {
		cout << "����ʧ��\n"; return nullptr;
	}
	
}

void printfAllType2WayLLN(AllType2WayH& llh) {
	if (llh.p_next == NULL || llh.p_next == &llh) { cout << "���ʧ��\n"; return; }
	AllType2WayLLN* p;
	p = llh.p_next;
	while (p != &llh) {
		cout << *((int*)(((int)p)-4)) << "\t";
		p = p->p_next;
	}cout << "��������ɹ�\n";
	p = llh.p_front;
	while (p != &llh) {
		cout << *((int*)(((int)p) - 4)) << "\t";
		p = p->p_front;
	}cout << "��������ɹ�\n";
}
inline void initAllType2WayLLN(AllType2WayLLN* ll1, AllType2WayH& llh) {
	if (ll1->p_next == nullptr) {
		ll1->p_next = &llh;
		llh.p_front = ll1;
	}
}

AllType2WayLLN::AllType2WayLLN() {
	p_front = nullptr;
	p_next = nullptr;
}

#include"TwoWayLoopLinkNode.h"
#include<iostream>
TwoWayLoopLinkNode::TwoWayLoopLinkNode() {//双向循环链表
	date = new int();
	p_front = nullptr;
	p_next = nullptr;
}
using namespace std;
inline void initTwoWayLoopLinkNode(TwoWayLoopLinkNode* ll1, TwoWayLoopLinkHead& lllh);
bool addTwoWayLoopLinkNode(TwoWayLoopLinkNode& ll1, TwoWayLoopLinkHead& llh, int i) {
	if (i <= 0) { cout << "添加失败\n"; return false; }
	if (i == 1) {
		addHeadTwoWayLoopLinkNode(ll1, llh);  return true;
	}
	int j = 2;
	TwoWayLoopLinkNode* p = llh.p_next;
	while (p != &llh) {
		if (j == i) {
			if ((*(p)).p_next == nullptr || p->p_next == &llh) {
				ll1.p_front = p; p->p_next = &ll1;
				initTwoWayLoopLinkNode((p->p_next), llh);
			}
			else {
				ll1.p_front = p; ll1.p_next = p->p_next;
				//if(p->p_next->p_next == nullptr || p->p_next->p_next == &llh){ initTwoWayLoopLinkNode((p->p_next), llh); }
				p->p_next->p_front = &ll1; p->p_next = &ll1;
			}
			cout << "添加成功\n";
			return true;
		}
		else if (j < i) {
			if ((*(p)).p_next == nullptr||p->p_next==&llh) {
				cout << "添加失败\n"; return false;
			}
			p = (*(p)).p_next; j++;
		}
	}cout << "添加失败\n";
	return false;
}

void addHeadTwoWayLoopLinkNode(TwoWayLoopLinkNode& ll1, TwoWayLoopLinkHead& lllh) {
	if (lllh.p_next == &lllh || lllh.p_next == nullptr) {
		lllh.p_next = &ll1; ll1.p_front = &lllh;
		ll1.p_next = &lllh;//尾连头
		lllh.p_front = &ll1;
	}
	else {
		ll1.p_next = lllh.p_next; lllh.p_next->p_front = &ll1; ll1.p_front = &lllh;
		initTwoWayLoopLinkNode(lllh.p_next, lllh);
		lllh.p_next = &ll1;

	}cout << "添加成功\n";
}

void addEndTwoWayLoopLinkNode(TwoWayLoopLinkNode& ll1, TwoWayLoopLinkHead& llh, TwoWayLoopLinkHead& lllh) {
	if (lllh.p_next == NULL || lllh.p_next == &lllh) {
		ll1.p_front = &llh;
		llh.p_next = &ll1;
	initTwoWayLoopLinkNode((&ll1), lllh);
	cout << "添加成功真头节点地址" << &lllh << "尾节点指向" << ll1.p_next << endl; 
	return; }
	TwoWayLoopLinkHead* p = &llh;
	while (1) {
		if (p->p_next == &lllh || p->p_next == nullptr) {
			p->p_next = &ll1;  ll1.p_front = p;
			initTwoWayLoopLinkNode((&ll1), lllh); break;
		}
		else {
			p = p->p_next;
		}
	}cout << "添加成功\n";
}

TwoWayLoopLinkNode* subTwoWayLoopLinkNode(TwoWayLoopLinkHead& llh, size_t i, TwoWayLoopLinkHead& lllh) {
	if (llh.p_next == NULL || i <= 0 || llh.p_next == &lllh) { cout << "移除失败\n"; return NULL; }
	size_t j = 2;
	TwoWayLoopLinkNode* p = llh.p_next;
	while ((p) != &lllh || p != nullptr) {
		if (i == 1) {
			if (p) {
				TwoWayLoopLinkNode* tp = p->p_next;
				llh.p_next = p->p_next; tp->p_front = &llh;
				delete p->date; delete p; cout << "移除成功\n"; return tp;
			}
		}
		else if (j == i) {
			if (p->p_next == nullptr|| p->p_next == &lllh) { cout << "移除失败\n"; return NULL; }
			TwoWayLoopLinkNode* tp = (*(p)).p_next->p_next;
			TwoWayLoopLinkNode* tp1 = (*(p)).p_next;
			p->p_next = tp; tp->p_front = p;
			delete (tp1->date); delete (tp1);  cout << "移除成功\n"; return tp;
		}
		else if (j < i) {
			if ((*(p)).p_next == NULL||(*(p)).p_next == &lllh) {
				cout << "移除失败\n"; return NULL;
			}
			p = (*(p)).p_next; j++;
		}
	}cout << "移除失败\n";
	return nullptr;
	
}

bool deleteTwoWayLoopLinkNode(TwoWayLoopLinkHead& twllh) {
	if (twllh.p_next == NULL || twllh.p_next == &twllh) { cout << "没有元素删除失败,如果头节点在堆请自行清空\n"; return false; }
	//size_t j = 2;
	TwoWayLoopLinkNode* p;
	p = twllh.p_next;
	while (p != &twllh) {
		TwoWayLoopLinkNode* tp = p;
		p = p->p_next;
		delete (*(tp)).date; delete tp;
	}twllh.p_next = &twllh; cout << "删除成功\n"; return true;
}

TwoWayLoopLinkNode** findTwoWayLoopLinkNode(TwoWayLoopLinkHead& twllh, int i) {
	if (twllh.p_next == NULL || twllh.p_next == &twllh) { cout << "查找失败\n"; return NULL; }
	TwoWayLoopLinkNode* p; TwoWayLoopLinkNode** pArr = new TwoWayLoopLinkNode * [FIND_COUNT](); int count = 0;
	p = twllh.p_next;
	while (p != &twllh) {
		if (*(p->date) == i) {
			cout << "查找成功\t所在节点地址为" << p << endl; pArr[count] = p; count++;
			p = p->p_next;
		}
		else {
			p = p->p_next;
		}
	}if (pArr) {
		return pArr;
	}
	else {
		cout << "查找失败\n"; return nullptr;
	}
}

void printfTwoWayLoopLinkNode(TwoWayLoopLinkHead& twllh) {
	if (twllh.p_next == NULL || twllh.p_next == &twllh) { cout << "输出失败\n"; return; }
	TwoWayLoopLinkNode* p;
	p = twllh.p_next;
	while (p != &twllh) {
		cout << *(p->date) << "\t";
		p = p->p_next;
	}cout << "正向输出成功\n";
	p = twllh.p_front;
	while (p != &twllh) {
		cout << *(p->date) << "\t";
		p = p->p_front;
	}cout << "反向输出成功\n";
}
inline void initTwoWayLoopLinkNode(TwoWayLoopLinkNode* ll1, TwoWayLoopLinkHead& twllh) {
	if (ll1->p_next == nullptr) {
		ll1->p_next = &twllh;
		twllh.p_front = ll1;
	}
}


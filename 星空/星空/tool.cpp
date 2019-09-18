#include"Tool.h"
#include"Star.h"
#include"SqList.h"
#include"LinkedList1.h"
void initStar(sqList& sq) {
	initSqList(sq);
	srand((unsigned)time(NULL));//产生随机(时间)种子
	for (int i = 0; i < sq.size; i++) {
		sq.starArr[i].x = rand() % WIDTH;
		sq.starArr[i].y = rand() % (LENGTH - 100);
		sq.starArr[i].radius = rand() % 4 + 1;
		sq.starArr[i].step = rand() % MAX_STEP + 1;
		sq.starArr[i].rbg = rand() % 255 / MAX_STEP * sq.starArr[i].step;
		setfillcolor(RGB(sq.starArr[i].rbg, sq.starArr[i].rbg, sq.starArr[i].rbg));
		solidcircle(sq.starArr[i].x, sq.starArr[i].y, sq.starArr[i].radius); Sleep(20);
		sq.length++;
		/*if (addSqList(sq,)) {

		}*/
	}sq.length--;
}
inline void addEndLinkedList2(LinkedList1& ll1, LinkedListHead& llh);
inline LinkedList1* subLinkedList2(LinkedListHead& llh, size_t i);
void initStar(LinkedListHead& llh) {
	LinkedListHead* qh = &llh;
		srand((unsigned)time(NULL));//产生随机(时间)种子
		for (int i = 0; i < STAR_COUNT; i++) {
			LinkedList1* ll1=new LinkedList1();
			ll1->date->x = rand() % WIDTH;
			ll1->date->y = rand() % (LENGTH - 100);
			ll1->date->radius = rand() % 4 + 1;
			ll1->date->step = rand() % MAX_STEP + 1;
			ll1->date->rbg = rand() % 255 / MAX_STEP * ll1->date->step;
			setfillcolor(RGB(ll1->date->rbg, ll1->date->rbg, ll1->date->rbg));
			solidcircle(ll1->date->x, ll1->date->y, ll1->date->radius); Sleep(20);		
			addEndLinkedList2(*ll1, *qh); qh = ll1;//改变头节点为上一个添加的节点，减少消耗
			//addEndLinkedList2(*ll1, llh);
		}
}
void moveStar(LinkedListHead& llh) {
	if (llh.p_next == NULL)return ; 
		LinkedList1* p;		
		bool quit = 0;
		while (!quit) {
			//size_t i = 1; 
			p = &llh;
			while (p->p_next) {
				setfillcolor(BLACK);
				solidcircle(p->p_next->date->x, p->p_next->date->y, p->p_next->date->radius);
				if ((p->p_next->date->y) > (p->p_next->date->step)) {
					(p->p_next->date->y) -= (p->p_next->date->step);
					setfillcolor(RGB(p->p_next->date->rbg, p->p_next->date->rbg, p->p_next->date->rbg));
					solidcircle(p->p_next->date->x, p->p_next->date->y, p->p_next->date->radius);
					p = p->p_next;				
				}
				else {
					p = subLinkedList2(*p, 1); 
					//p = subLinkedList2(llh, i); i--;
					break;					
				} //i++; 
			}if (llh.p_next==NULL) {
				deleteLinkedList1(llh);
				 quit = 1;
						 }
			Sleep(20);
		}		
}
void moveStar(sqList& sq) {
	 bool quit = 0;
	 while (!quit) {
		 for (int i = 0; i <=sq.length; i++) {
			 if (i > sq.length) break;
			 setfillcolor(BLACK);
			 solidcircle(sq.starArr[i].x, sq.starArr[i].y, sq.starArr[i].radius);
			 if (sq.starArr[i].y > sq.starArr[i].step) {				
				 sq.starArr[i].y -= sq.starArr[i].step;
				 setfillcolor(RGB(sq.starArr[i].rbg, sq.starArr[i].rbg, sq.starArr[i].rbg));
				 solidcircle(sq.starArr[i].x, sq.starArr[i].y, sq.starArr[i].radius);
			 }
			 else {
				 subSqList(sq, i);  if (i == sq.length) break;
				 i--;
			 }
		 }if (sq.length==-1) {
			 deleteSqList(sq);
			 quit = 1;
		 }
		 Sleep(20);
	 }
 }
inline void addEndLinkedList2(LinkedList1& ll1, LinkedListHead& llh) {
	if (llh.p_next == NULL) { llh.p_next = &ll1; return; }
	LinkedListHead* p = llh.p_next;
	while (1) {
		if (p->p_next == NULL) {
			p->p_next = &ll1;  break;
		}
		else {
			p = p->p_next;
		}
	}
}
inline LinkedList1* subLinkedList2(LinkedListHead& llh, size_t i) {
	if (llh.p_next == NULL || i <= 0) { return NULL; }
	size_t j = 2;
	LinkedList1* p = NULL;
	p = llh.p_next;
	while (p) {
		if (j == i) {
			LinkedList1* tp = (*(p)).p_next;
			(*(p)).p_next = ((*(p)).p_next)->p_next;
			delete (*(tp)).date; delete tp;return p->p_next;
		}
		else if (i == 1 && p != NULL) {
			if (p->p_next) {
				LinkedList1* tp = p->p_next;
				llh.p_next = p->p_next; delete (*(p)).date; delete p; return tp;
			}
			else {
				llh.p_next = NULL; delete (*(p)).date; delete p;return NULL;
			}
		}
		else if (j < i) {
			if ((*(p)).p_next == NULL) {
			return NULL;
			}
			p = (*(p)).p_next; j++;
		}
	}
	return NULL;
}
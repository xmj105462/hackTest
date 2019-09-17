#pragma once
#include <cstddef>
class Star;
constexpr auto FIND_COUNT = 10;
typedef class LinkedList1 {//µ•œÚ¡¥±Ì
public:
	//Star *date;
	int* date;
	 LinkedList1* p_next;
	 LinkedList1(); 
	
}LinkedListHead;

//void initLinkedList1(LinkedList1& ll1);
bool addLinkedList1(LinkedList1& ll1, LinkedListHead& llh, int i);
void addHeadLinkedList1(LinkedList1& ll1, LinkedListHead& llh);
void addEndLinkedList1(LinkedList1& ll1, LinkedListHead& llh);
bool subLinkedList1(LinkedListHead& llh, size_t i);
bool deleteLinkedList1(LinkedListHead& llh);
LinkedList1** findLinkedList1(LinkedListHead& llh, int i);
void printfLinkedList1(LinkedListHead& llh);
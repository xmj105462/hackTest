#pragma once
#ifndef LINKEDLIST1_H
#define LINKEDLIST1_H
#include <cstddef>




class Star;
constexpr auto FIND_COUNT = 10;
 typedef class LinkedList1  {//��������
public:
	Star *date;
	//int* date;
	 LinkedList1* p_next;
	 LinkedList1(); 
	
}LinkedListHead;
 //typedef class{
	// Star* date;
	// //int* date;
	// LinkedList1* p_next;
	// //LinkedListHead();
 //}LinkedListHead;


bool addLinkedList1(LinkedList1& ll1, LinkedListHead& llh, int i);
void addHeadLinkedList1(LinkedList1& ll1, LinkedListHead& llh);
void addEndLinkedList1(LinkedList1& ll1, LinkedListHead& llh);
LinkedList1* subLinkedList1(LinkedListHead& llh, size_t i);
bool deleteLinkedList1(LinkedListHead& llh);
LinkedList1** findLinkedList1(LinkedListHead& llh, int i);
void printfLinkedList1(LinkedListHead& llh);
void initLinkedList1(LinkedList1& ll1);
#endif // !LINKEDLIST1_H
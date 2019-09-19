#pragma once
#ifndef LOOPLINKEDLIST_H
#define LOOPLINKEDLIST_H
#include <cstddef>

class Star;
//constexpr auto FIND_COUNT = 10;
typedef class LoopLinkedList {//µ•œÚ¡¥±Ì
public:
	Star* date;
	//int* date;
	LoopLinkedList* p_next;
	LoopLinkedList();

}LoopLinkedListHead;
bool addLoopLinkedList(LoopLinkedList& ll1, LoopLinkedListHead& llh, int i);
void addHeadLoopLinkedList(LoopLinkedList& ll1, LoopLinkedListHead& lllh);
void addEndLoopLinkedList(LoopLinkedList& ll1, LoopLinkedListHead& llh, LoopLinkedListHead& lllh);
LoopLinkedList* subLoopLinkedList(LoopLinkedListHead& llh, size_t i, LoopLinkedListHead& lllh);
bool deleteLoopLinkedList(LoopLinkedListHead& llh);
LoopLinkedList** findLoopLinkedList(LoopLinkedListHead& llh, int i);
void printfLoopLinkedList(LoopLinkedListHead& llh);
//void initLoopLinkedList(LoopLinkedList& ll1, LoopLinkedListHead& llh);
#endif // !LOOPLINKEDLIST_H

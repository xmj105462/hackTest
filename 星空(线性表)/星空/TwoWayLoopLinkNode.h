#pragma once
#ifndef TWOWAYLOOPLINKNODE_H
#define TWOWAYLOOPLINKNODE_H
constexpr auto FIND_COUNT = 10;
typedef class TwoWayLoopLinkNode {//Ë«ÏòÁ´±í
public:
	//Star* date;
	int* date;
	TwoWayLoopLinkNode* p_front;
	TwoWayLoopLinkNode* p_next;
	TwoWayLoopLinkNode();

}TwoWayLoopLinkHead;
bool addTwoWayLoopLinkNode(TwoWayLoopLinkNode& ll1, TwoWayLoopLinkHead& llh, int i);
void addHeadTwoWayLoopLinkNode(TwoWayLoopLinkNode& ll1, TwoWayLoopLinkHead& lllh);
void addEndTwoWayLoopLinkNode(TwoWayLoopLinkNode& ll1, TwoWayLoopLinkHead& llh, TwoWayLoopLinkHead& lllh);
TwoWayLoopLinkNode* subTwoWayLoopLinkNode(TwoWayLoopLinkHead& llh, size_t i, TwoWayLoopLinkHead& lllh);
bool deleteTwoWayLoopLinkNode(TwoWayLoopLinkHead& llh);
TwoWayLoopLinkNode** findTwoWayLoopLinkNode(TwoWayLoopLinkHead& llh, int i);
void printfTwoWayLoopLinkNode(TwoWayLoopLinkHead& llh);
#endif // !TWOWAYLOOPLINKNODE_H

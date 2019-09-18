#pragma once
#ifndef TOOL_H
#define TOOL_H
#include<iostream>
#include<time.h>
#include<graphics.h>
//#include"Star.h"
class Star;
struct sqList;
typedef class  LinkedList1 LinkedListHead;
constexpr short WIDTH = 1200;
constexpr short LENGTH = 780;
constexpr short STAR_COUNT = 120;
constexpr short MAX_STEP = 5;
typedef enum {
	UP, DOWN, LEFT, RIGHT, cALL
}starCondition;
using namespace std;
void initStar(sqList& sq);
void initStar(LinkedListHead& llh);
 void moveStar(sqList& sq);
void moveStar(LinkedListHead& llh);
#endif // !TOOL_H

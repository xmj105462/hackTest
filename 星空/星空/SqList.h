#pragma once

class Star;
struct sqList;
//typedef struct{
//	 //Star* starArr = new Star[STAR_COUNT]{};
//}sqList;
struct sqList {
	Star* starArr;
	int length;
	int size;
};
bool initSqList(sqList& sq);
bool addSqList(sqList& sq, Star* s);
bool subSqList(sqList& sq, int i);
bool insertSqList(sqList& sq, Star* s,int i);//˳���Ԫ�أ�λ��
bool deleteSqList(sqList& sq);

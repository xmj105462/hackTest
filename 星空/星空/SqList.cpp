#include"SqList.h"
#include"Star.h"
#include "Tool.h"


bool initSqList(sqList & sq) {
	sq.starArr= new Star[STAR_COUNT]{};
	if (!sq.starArr)return false;	
	sq.length=0;
	sq.size=STAR_COUNT;
	return true;
}

bool addSqList(sqList& sq, Star *s) {
	if (sq.length == sq.size)return false;
	if (sq.length < sq.size) {
		sq.starArr[sq.length] = *s;	
			sq.length++;	
	}
	return true;
}

bool subSqList(sqList& sq, int i) {
	if (i > sq.length || i < 0 || sq.length == sq.size)return false;//尾不能插入		
	if (i==sq.length) {
		//sq.starArr[i] = NULL;
		sq.length--; return true;
	}
	for (int j = i; j < sq.length; j++) {
		sq.starArr[j] = sq.starArr[j + 1];
	}
	sq.length--;
	return true;
}

bool insertSqList(sqList& sq, Star* s,int i) {
	if (i >= sq.length|| i<0|| sq.length == sq.size)return false;//尾不能插入		
		sq.length++;
		for ( int j = sq.length; j > i; j--) {
			sq.starArr[j] = sq.starArr[j-1];
		}
		sq.starArr[i] = *s;
	return true;
}

bool deleteSqList(sqList& sq) {
	if (sq.starArr) {
		delete sq.starArr;
		sq.length = 0;
		sq.size = 0;
	}
	return false;
}

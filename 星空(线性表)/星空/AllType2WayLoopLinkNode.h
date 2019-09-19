#pragma once
#ifndef AT2WLLN_H
#define AT2WLLN_H
class Star;
struct Int;
typedef struct AllType2WayLLN {
	AllType2WayLLN* p_front;
	AllType2WayLLN* p_next;
	AllType2WayLLN();
}AllType2WayH;
//constexpr auto FIND_COUNT = 10;

bool addAllType2WayLLN(AllType2WayLLN& ll1, AllType2WayH& llh, int i);
void addHeadAllType2WayLLN(AllType2WayLLN& ll1, AllType2WayH& lllh);
void addEndAllType2WayLLN(AllType2WayLLN& ll1, AllType2WayH& llh, AllType2WayH& lllh);
AllType2WayLLN* subAllType2WayLLN(AllType2WayH& llh, size_t i, AllType2WayH& lllh);
bool deleteAllType2WayLLN(AllType2WayH& llh);
AllType2WayLLN** findAllType2WayLLN(AllType2WayH& llh, int i);
void printfAllType2WayLLN(AllType2WayH& llh);
#endif // !AT2WLLN_H


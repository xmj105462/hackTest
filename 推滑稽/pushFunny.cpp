
#include<conio.h>
#include"pushFunny.h"

constexpr auto SCREEN_WIDTH = 1041;
constexpr auto SCREEN_HEIGHT = 700;
constexpr auto LINE = 9;
constexpr auto COLUMN = 12;
constexpr auto IMAGE_SIZE = 61;
constexpr auto KEY_UP = 72;
constexpr auto KEY_RIGHT = 77;
constexpr auto KEY_DOWN = 80;
constexpr auto KEY_LEFT = 75;
constexpr auto KEY_SPACE = 32;
constexpr auto START_X = 180;
constexpr auto START_Y = 80;
//给FLOOR_MAN_MOVE调用先画地板
#define MOVE(man,Y) START_X + man->x * IMAGE_SIZE, START_Y + man->y * IMAGE_SIZE, &imageArr[Y]
//人物移动时先赋值地板/目的地
#define FLOOR_MOVE map[man->y][man->x] = FLOOR
#define DEST_MOVE map[man->y][man->x] = dest
//移动后再画人物
#define FLOOR_MAN_MOVE(T1,T2,T3) putimage(MOVE(man,T1));\
man->T2 T3= 1; \
map[man->y][man->x] = MAN;\
putimage(MOVE(man, MAN));
//判断是否可以移动
#define IFMOVE(T1,T2,T3,T4,T8,T5,T6,T7) map[man->y T1 T2][man->x T3 T4] == T8 && man->T5 T6 T7
#define IF_DEST_MOVE(T1,T2,T3,T4,T8) map[man->y T1 T2][man->x T3 T4] == T8
//判断是否可以推箱子
#define IFPUSH(T1,T2,T3,T4,T5)  map[man->y T1 T2][man->x T3 T4] ==T5
/*map[man->y -1][man->x ] == box && man->y >0&& map[man->y - 2][man->x] == FLOOR*/

//loadimage(&imageArr[hit], _T("./推箱子素材/hit.gif"), IMAGE_SIZE, IMAGE_SIZE, true);
#define LOAD_IMG(T1,T2) loadimage(&imageArr[T1], _T(T2), IMAGE_SIZE, IMAGE_SIZE, true)

//putimage(START_X + man->x * IMAGE_SIZE, START_Y + (man->y - 1) * IMAGE_SIZE, &imageArr[box]);
#define DRAW_BOX(T1,T2,T3,T4,T5) putimage(START_X + (man->x T1 T2) * IMAGE_SIZE, START_Y + (man->y T3 T4) * IMAGE_SIZE, &imageArr[T5])

//目的地恢复原样
#define RECOVER(T1,T2) if (recover) {DEST_MOVE;FLOOR_MAN_MOVE(dest, T1, T2)recover = 0; }\
else {FLOOR_MOVE;FLOOR_MAN_MOVE(FLOOR, T1, T2)}

/*游戏地图
1地板，0墙，2箱子目的地, 3小人, 4箱子, 5箱子命中目标
*/  int map[LINE][COLUMN] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
{ 0, 1, 4, 1, 0, 2, 1, 0, 2, 1, 0, 0 },
{ 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0 },
{ 0, 1, 0, 2, 0, 1, 1, 4, 1, 1, 1, 0 },
{ 0, 1, 1, 1, 0, 3, 1, 1, 1, 4, 1, 0 },
{ 0, 1, 2, 1, 1, 4, 1, 1, 1, 1, 1, 0 },
{ 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, };

typedef enum {
	wall, FLOOR, dest, MAN, box, hit, all
}iEnum;
IMAGE imageArr[all] = {};
IMAGE bkImage;
struct Person {
	int x;
	int y;
};

void initFrame() {
	initgraph(SCREEN_WIDTH, SCREEN_HEIGHT);
	loadimage(&bkImage, _T("./推箱子素材/blackground.gif"), SCREEN_WIDTH, SCREEN_HEIGHT, true);
	putimage(0, 0, &bkImage);//背景	
	LOAD_IMG(wall, "./推箱子素材/泳装千代.bmp");
	LOAD_IMG(FLOOR, "./推箱子素材/floor.bmp");
	LOAD_IMG(dest, "./推箱子素材/des.bmp");
	LOAD_IMG(MAN, "./推箱子素材/人物.bmp");
	LOAD_IMG(box, "./推箱子素材/箱子.bmp");
	LOAD_IMG(hit, "./推箱子素材/hit.gif");
	for (int j = 0; j < LINE; j++) {
		for (int i = 0; i < COLUMN; i++) {//绘制地图
			putimage(START_X + i * IMAGE_SIZE, START_Y + j * IMAGE_SIZE, &imageArr[map[j][i]]);
		}
	}
	setcolor(LIGHTGREEN);
	settextstyle(20, 0, _T("宋体")); outtextxy(480,20,_T("请在100步以内完成"));
}
bool keyCheck(int key, Person* man,bool&, unsigned short &);
void gameControl() {
	struct Person man = { 5,5 };
	bool quit = 1; bool recover = 0; unsigned short endCount= 0;
	settextstyle(100, 0, _T("微软雅黑"));
	while (quit) {
		if (_kbhit()) {//如果按键
			short key = _getch();//监听按下的键
			quit = keyCheck(key, &man,recover,endCount);
		}
		if (endFrame()) {
			cleardevice(); 			
			outtextxy(100,100,_T("nb,666"));
			break;
		}
		else if (endCount>100) {
			cleardevice();
			outtextxy(100, 100, _T("渣渣lj"));
			break;
		}
	}

}
bool endFrame() {
	for (size_t j = 1; j < LINE; j++) {
		for (size_t i = 1; i < COLUMN; i++) {
			if (map[j][i] == 2) return 0;
		}
	}return 1;
}
bool keyCheck(int key, Person* man,bool& recover,unsigned short& endCount) {
	//if (man->x<1 || man->x >COLUMN - 1 || man->y < 1 || man->y>LINE - 1)return 0;
	switch (key) {
	case KEY_UP://上
		if (IFMOVE(-, 1, , , FLOOR, y, > , 1)) {
			endCount++;
			if (recover) {//目的地恢复原样
				DEST_MOVE;
				FLOOR_MAN_MOVE(dest,y,-)
					recover = 0; break;
			}
			else  {
				FLOOR_MOVE;
				FLOOR_MAN_MOVE(FLOOR,y,-)
			}//前面目的地			
		}else if (IFMOVE(-, 1, , , dest, y, > , 1)) {
				FLOOR_MOVE;				
				FLOOR_MAN_MOVE(FLOOR,y,-)
					recover = 1; endCount++;;
			}//前面是箱子的情况
		else if (IFMOVE(-, 1, , , box, y, > , 1)) {			
			 if (IFPUSH(-, 2, , , FLOOR)) {
				 RECOVER(y, -)//dest恢复
				DRAW_BOX(, , -, 1, box);
				map[man->y - 1][man->x] = box; endCount++;				
			}
			else if (IFPUSH(-, 2, , , dest)) {
				FLOOR_MOVE;
				FLOOR_MAN_MOVE(FLOOR, y, -)
				DRAW_BOX(, , -, 1, hit);
				map[man->y - 1][man->x] = hit; endCount++;
			}
		}
		else if (IFMOVE(-, 1, , , hit, y, > , 1)) {			
			if (IFPUSH(-, 2, , , FLOOR)) {
				FLOOR_MOVE;
				FLOOR_MAN_MOVE(FLOOR, y, -)
					DRAW_BOX(, , -, 1, box);
				map[man->y - 1][man->x] = box; recover = 1; endCount++;
			}
		}
		Sleep(100);
		break;
	case KEY_RIGHT://右map[man->y][man->x + 1] == FLOOR && man->x < COLUMN)		
		if (IFMOVE(, , +, 1, FLOOR, x, < , COLUMN-2)) {
			endCount++;
			if (recover) {//目的地恢复原样
				DEST_MOVE;
				FLOOR_MAN_MOVE(dest,x,+)
					recover = 0; break;
			}
			else  {
				FLOOR_MOVE;
				FLOOR_MAN_MOVE(FLOOR, x, +)
			}			
		}
		else if (IFMOVE(,,+,1, dest,x,< ,COLUMN-2)) {
			FLOOR_MOVE;
			FLOOR_MAN_MOVE(FLOOR,x,+)
				recover = 1; endCount++;
		}
		else if (IFMOVE(, , +, 1, box, x, < , COLUMN-2)) {
			
			 if (IFPUSH(, , +, 2, FLOOR)) {//判断箱子前面是否是地板
				/*FLOOR_MOVE;
				FLOOR_MAN_MOVE(FLOOR, x, +)*/
				 RECOVER(x, +)
				DRAW_BOX(+, 1, , , box);
				map[man->y][man->x + 1] = box; endCount++;
				
			}
			else if (IFPUSH(, , +, 2, dest)) {//判断箱子前面是否是目的地
				FLOOR_MOVE;
				FLOOR_MAN_MOVE(FLOOR, x, +)
				DRAW_BOX(+, 1, , , hit);
				map[man->y][man->x + 1] = hit; endCount++;
			}
		}
		else if (IFMOVE(, , +, 1, hit, x, < , COLUMN - 2)) {			
			if (IFPUSH(, , +, 2, FLOOR)) {//判断箱子前面是否是地板
				FLOOR_MOVE;
				FLOOR_MAN_MOVE(FLOOR, x, +)
					DRAW_BOX(+, 1, , , box);
				map[man->y][man->x + 1] = box; recover = 1; endCount++;
			}
		}
		Sleep(100); break;
	case KEY_DOWN://下map[man->y + 1][man->x] == FLOOR && man->y < LINE	
		if (IFMOVE(+, 1, , , FLOOR, y, < , LINE - 2)) {
			endCount++;
			if (recover) {//目的地恢复原样
				DEST_MOVE;
				FLOOR_MAN_MOVE(dest, y, +)
					recover = 0; break;
			}
			else {
				FLOOR_MOVE;
				FLOOR_MAN_MOVE(FLOOR, y, +)
			}
		}
		else if (IFMOVE(+, 1, , , dest, y, < , LINE - 2)) {
			FLOOR_MOVE;
			FLOOR_MAN_MOVE(FLOOR, y, +)
				recover = 1; endCount++;
		}
		else if (IFMOVE(+, 1, , , box, y, < , LINE-2)) {			
			 if (IFPUSH(+, 2, , , FLOOR)) {
				 RECOVER(y, +)
				DRAW_BOX(, , +, 1, box);
				map[man->y + 1][man->x] = box; endCount++;
			}
			else if (IFPUSH(+, 2, , , dest)) {
				FLOOR_MOVE;
				FLOOR_MAN_MOVE(FLOOR, y, +)
				DRAW_BOX(, , +, 1, hit);
				map[man->y + 1][man->x] = hit; endCount++;
			}
		}
		else if (IFMOVE(+, 1, , , hit, y, < , LINE - 2)) {
			if (IFPUSH(+, 2, , , FLOOR)) {
				FLOOR_MOVE;
				FLOOR_MAN_MOVE(FLOOR, y, +)
					DRAW_BOX(, , +, 1, box);
				map[man->y + 1][man->x] = box; recover = 1; endCount++;
			}
		}
		Sleep(100); break;
	case KEY_LEFT://左map[man->y][man->x - 1] == FLOOR && man->x > 0
		if (IFMOVE(, , -, 1, FLOOR, x, > , 1)) {
			endCount++;
				if (recover) {//目的地恢复原样
					DEST_MOVE;
					FLOOR_MAN_MOVE(dest, x, -)
						recover = 0; break;
				}
				else {
					FLOOR_MOVE;
					FLOOR_MAN_MOVE(FLOOR, x, -)
				}
		}
		else if (IFMOVE(, , -, 1, dest, x, > , 1)) {
				FLOOR_MOVE;
				FLOOR_MAN_MOVE(FLOOR, x, -)
					recover = 1; endCount++;
			}		
		//man->x >0 && map[man->y][man->x - 2] == box
		else if (IFMOVE(, , -, 1, box, x, > , 1)) {			
			 if (IFPUSH(, , -, 2, FLOOR)) {
				 RECOVER(x, -)
				DRAW_BOX(-, 1, , , box);
				map[man->y][man->x - 1] = box; endCount++;
			}
			else if (IFPUSH(, , -, 2, dest)) {
				FLOOR_MOVE;
				FLOOR_MAN_MOVE(FLOOR, x, -)
				DRAW_BOX(-, 1, , , hit);
				map[man->y][man->x - 1] = hit; endCount++;
			}
		}
		else if (IFMOVE(, , -, 1, hit, x, > , 1)) {
			if (IFPUSH(, , -, 2, FLOOR)) {
				FLOOR_MOVE;
				FLOOR_MAN_MOVE(FLOOR, x, -)
					DRAW_BOX(-, 1, , , box);
				map[man->y][man->x - 1] = box; recover = 1; endCount++;
			}
		}
		Sleep(100); break;
	case KEY_SPACE://空格退出
		//key = _getch();//
		return 0;
	}
	return 1;
}

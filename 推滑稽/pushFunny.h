#pragma once
#include<graphics.h>
#include<Windows.h>
 #include <iostream> 
#include <stdlib.h> 
#include <string>
#include<MMStream.h>//播放音乐需要的头文件
#pragma comment(lib,"winmm.lib")//加载winmm库文件

#ifndef PUSHFUNNY_H

#define PUSHFUNNY_H





void initFrame();

void gameControl();
bool endFrame();
#endif // 
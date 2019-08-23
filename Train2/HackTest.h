#pragma once
#include<graphics.h>
#include<Windows.h>
//#include<MMStream.h>;//播放音乐需要的头文件
//#pragma comment(lib,"winmm.lib")//加载winmm库文件
void hackFrame() {
	initgraph(1024, 639);//初始化画布

	loadimage(0, _T("0009021115180121_b.jpg"));//从原点开始填充图片，图片在项目包里
	rectangle(80, 20, 500, 80);//画矩形
	settextstyle(40, 0, "宋体"); settextcolor(YELLOW);
	outtextxy(85, 30, "1网站404攻击");
	rectangle(80, 100, 500, 160);
	outtextxy(85, 110, "2网站篡改攻击");
	rectangle(80, 180, 500, 240);
	outtextxy(85, 190, " 3网站攻击记录");
	rectangle(80, 260, 500, 320);
	outtextxy(85, 270, " 4DNS攻击");
	rectangle(80, 340, 500, 400);
	outtextxy(85, 350, " 5服务器重启攻击");
	system("pause");
	closegraph();
}
//mciSendString(_T("play UhOh.mp3 repeat"),0,0,0);//播放音乐
//setbkcolor(RGB(0, 128, 128));//绿色

//cleardevice();//喷涂背景
//setlinecolor(RGB(237, 28, 36));
//setlinestyle(PS_SOLID, 8);
//circle(320, 240, 200);
//settextcolor(YELLOW);
//settextstyle(90, 0, "宋体");
//outtextxy(150, 190, "无码高清");
//line(180, 380, 460, 100);
//setlinestyle(PS_SOLID, 3);
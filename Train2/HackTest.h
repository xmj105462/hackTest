#pragma once
#include<graphics.h>
#include<Windows.h>
//#include<MMStream.h>;//����������Ҫ��ͷ�ļ�
//#pragma comment(lib,"winmm.lib")//����winmm���ļ�
void hackFrame() {
	initgraph(1024, 639);//��ʼ������

	loadimage(0, _T("0009021115180121_b.jpg"));//��ԭ�㿪ʼ���ͼƬ��ͼƬ����Ŀ����
	rectangle(80, 20, 500, 80);//������
	settextstyle(40, 0, "����"); settextcolor(YELLOW);
	outtextxy(85, 30, "1��վ404����");
	rectangle(80, 100, 500, 160);
	outtextxy(85, 110, "2��վ�۸Ĺ���");
	rectangle(80, 180, 500, 240);
	outtextxy(85, 190, " 3��վ������¼");
	rectangle(80, 260, 500, 320);
	outtextxy(85, 270, " 4DNS����");
	rectangle(80, 340, 500, 400);
	outtextxy(85, 350, " 5��������������");
	system("pause");
	closegraph();
}
//mciSendString(_T("play UhOh.mp3 repeat"),0,0,0);//��������
//setbkcolor(RGB(0, 128, 128));//��ɫ

//cleardevice();//��Ϳ����
//setlinecolor(RGB(237, 28, 36));
//setlinestyle(PS_SOLID, 8);
//circle(320, 240, 200);
//settextcolor(YELLOW);
//settextstyle(90, 0, "����");
//outtextxy(150, 190, "�������");
//line(180, 380, 460, 100);
//setlinestyle(PS_SOLID, 3);
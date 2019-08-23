#include<graphics.h>
//#include<Windows.h>
#include<iostream>
#include<string>
#include "HackTest.h"
//#include<MMStream.h>;//播放音乐需要的头文件
//#pragma comment(lib,"winmm.lib")//加载winmm库文件

using namespace std;

int main(void){
	string name;
	string password;
	while (1)
	{
		system("cls");//清屏控制台
		cout << "请输入账号：" << endl;
		cin >> name;//得输入字符，不然不能输出密码	
		cout << "请输入密码:" << endl;
		cin >> password;
		if (name == "xmj" && password == "1054628060") {
			break;
			
		}
		else {
			cout << "你TM输错号密了" << endl;
			system("pause");
		}
	}
	hackFrame();
	
	
	


	
	return 0;




}
//if (cin.fail()) {
	//	cout << "你TM给我输入整数";
	//	cin.clear();//清空错误标志
	//	cin.sync();//清空输入缓冲区
	//	cout << "请输入账号：" << endl;

	//	cin >> name;//得输入字符，不然不能输出密码
	//}
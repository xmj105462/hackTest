#include<graphics.h>
//#include<Windows.h>
#include<iostream>
#include<string>
#include "HackTest.h"
//#include<MMStream.h>;//����������Ҫ��ͷ�ļ�
//#pragma comment(lib,"winmm.lib")//����winmm���ļ�

using namespace std;

int main(void){
	string name;
	string password;
	while (1)
	{
		system("cls");//��������̨
		cout << "�������˺ţ�" << endl;
		cin >> name;//�������ַ�����Ȼ�����������	
		cout << "����������:" << endl;
		cin >> password;
		if (name == "xmj" && password == "1054628060") {
			break;
			
		}
		else {
			cout << "��TM��������" << endl;
			system("pause");
		}
	}
	hackFrame();
	
	
	


	
	return 0;




}
//if (cin.fail()) {
	//	cout << "��TM������������";
	//	cin.clear();//��մ����־
	//	cin.sync();//������뻺����
	//	cout << "�������˺ţ�" << endl;

	//	cin >> name;//�������ַ�����Ȼ�����������
	//}
#include<iostream>
using namespace std;
#include<string>
#include"speechmanager.h"
int main()
{
	//创建管理类的对象
	Speechmanager sm;
	//测试12名选手是否存在
	//map<int, Speaker>::iterator it;
	//for (it =sm.m_Speaker.begin();it!=sm.m_Speaker.end();it++)
	//{
	//	cout << "选手编号：" << it->first << "选手姓名：" << it->second.m_name << "选手成绩："<<it->second.score[0] << endl;
	//}


	int choice = 0;//用于存储用户的输入
	while (true)
	{
		sm.show_menu();
		cout << "请输入您的选择：" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1://开始比赛
			sm.startspeech();
			break;
		case 2://查看往届记录
			break;
		case 3://清空往届记录
			break;
		case 0://退出界面
			sm.exitsystem();
			break;
		default:
			system("cls");//清空界面
			break;
		}
	}
	system("pause");
	return 0;
}
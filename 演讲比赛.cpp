#include<iostream>
using namespace std;
#include<string>
#include"speechmanager.h"
int main()
{
	//����������Ķ���
	Speechmanager sm;
	//����12��ѡ���Ƿ����
	//map<int, Speaker>::iterator it;
	//for (it =sm.m_Speaker.begin();it!=sm.m_Speaker.end();it++)
	//{
	//	cout << "ѡ�ֱ�ţ�" << it->first << "ѡ��������" << it->second.m_name << "ѡ�ֳɼ���"<<it->second.score[0] << endl;
	//}


	int choice = 0;//���ڴ洢�û�������
	while (true)
	{
		sm.show_menu();
		cout << "����������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1://��ʼ����
			sm.startspeech();
			break;
		case 2://�鿴�����¼
			break;
		case 3://��������¼
			break;
		case 0://�˳�����
			sm.exitsystem();
			break;
		default:
			system("cls");//��ս���
			break;
		}
	}
	system("pause");
	return 0;
}
#pragma once//��ֹͷ�ļ��ظ�����
#include<iostream>
#include<vector>
#include<map>
#include"speaker.h"
#include<algorithm>
#include<deque>
#include<functional>
#include<numeric>
#include<string>
#include<fstream>
using namespace std;
//����ݽ�������
class Speechmanager
{
public:
	//���캯��
	Speechmanager();//����ʵ�֣���.cpp�ļ���ʵ��
	//չʾ�˵�
	void show_menu();
	//�˳�ϵͳ
	void exitsystem();
	//��������
	~Speechmanager();
	//��ʼ������������
	void initspeech();

	//����12��ѡ��
	void creatspeeker();
	//��ʼ�����������������̵Ŀ��ƺ���
	void startspeech();
	//��ǩ
	void speechdraw();

	//����
	void speechcontest();
	//��ʾ�÷�
	void showscore();
	//�������
	void saverecord();



	//�������
	//�����һ��ѡ�ֱ�ŵ�����
	vector<int>v1;
	//��һ�ֽ�����ѡ�ֱ�ŵ�����
	vector<int>v2;
	//����ʤ����ǰ������ѡ�ֵı��
	vector<int>v3;
	//��ű�����Ӧ��ѡ�ֵ�����
	map<int, Speaker>m_Speaker;
	//��ű�������
	int i;
};

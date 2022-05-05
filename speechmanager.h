#pragma once//防止头文件重复编译
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
//设计演讲管理类
class Speechmanager
{
public:
	//构造函数
	Speechmanager();//不用实现，在.cpp文件中实现
	//展示菜单
	void show_menu();
	//退出系统
	void exitsystem();
	//析构函数
	~Speechmanager();
	//初始化容器和属性
	void initspeech();

	//创建12名选手
	void creatspeeker();
	//开始比赛，比赛整个流程的控制函数
	void startspeech();
	//抽签
	void speechdraw();

	//比赛
	void speechcontest();
	//显示得分
	void showscore();
	//保存分数
	void saverecord();



	//添加属性
	//保存第一轮选手编号的容器
	vector<int>v1;
	//第一轮晋级的选手编号的容器
	vector<int>v2;
	//最终胜出的前三名的选手的编号
	vector<int>v3;
	//存放编号与对应的选手的容器
	map<int, Speaker>m_Speaker;
	//存放比赛轮数
	int i;
};

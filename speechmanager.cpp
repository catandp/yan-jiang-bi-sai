#include"speechmanager.h"
//构造函数实现
Speechmanager::Speechmanager()
{
	this->initspeech();
	creatspeeker();
}
//菜单界面的实现
void Speechmanager::show_menu()
{
	cout << "*******************************"<< endl;
	cout << "*********欢迎参加演讲比赛 *****"<< endl;
	cout << "*********1.开始演讲比赛********" << endl;
	cout << "*********2.查看往届记录********" << endl;
	cout << "*********3.清空比赛记录********" << endl;
	cout << "*********0.退出比赛程序********" << endl;
	cout << "*******************************" << endl;
}
//退出系统
void Speechmanager::exitsystem()
{
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);
}
//容器初始化
void Speechmanager::initspeech()
{
	//容器都置空
	this->v1.clear();
	this->v2.clear();
	this->v3.clear();
	this->m_Speaker.clear();
	//初始化比赛的轮数
	this->i = 1;
}

//创建选手实现
void Speechmanager::creatspeeker()
{
	string nameseed = "ABCDEFGHIJK";
	for (int k = 0; k < 12; k++)
	{
		string name = "选手";
		name += nameseed[k];
		//创建具体的选手
		Speaker  sp;
		sp.m_name = name;
		for (int j = 0; j < 2; j++)
		{
			sp.score[j] = 0;
		}
		//创建选手编号并放入v1容器中
		this->v1.push_back(k + 1001);
		//选手编号与对应的选手放入map中
		this->m_Speaker.insert(make_pair(k + 1001, sp));
	}
}
//开始比赛，比赛整个流程的控制函数的实现
void Speechmanager::startspeech()
{
	//第一轮比赛

	//抽签
	this->speechdraw();
	//比赛
	this->speechcontest();
	//显示晋级名单
	this->showscore();
	//第二轮比赛
	this->i++;
	//抽签
	this->speechdraw();
	//比赛
	this->speechcontest();
	//显示最终结果
	this->showscore();
	//保存分数到文件中
	this->saverecord();
	cout << "本届比赛完毕" << endl;
	system("pause");
	system("cls");
}
//抽签的实现
void Speechmanager::speechdraw()
{
	cout << "第" << this->i << "轮选手正在抽签" << endl;
	cout << "---------------------------------------" << endl;
	cout << "抽签的结果如下：" << endl;
	if (this->i == 1)
	{
//第一轮
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	else
	{
//第二轮
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << "";
		}
		cout << endl;
	}
	cout << "------------------------------" << endl;
	system("pause");
	cout << endl;
}
//比赛
void Speechmanager::speechcontest()
{

	cout << "第" << this->i << "轮比赛正式开始" << endl;
	//准备一个临时的容器存放每个小组的成绩
	multimap<double, int, greater<double>>groupscore;
	int num = 0;//记录人员个数6人一组
	vector<int>v;//代表比赛选手的容器
	if (this->i == 1)
	{
		v = v1;
	}
	else
	{
		v = v2;
	}
	//遍历所有的选手进行比赛
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		num++;
		//评委打分
		deque<double>d;
		for (int s = 0; s < 10; s++)
		{
			double score = (rand() % 401 + 600) / 10.f;//除以10.f代表一个小数
			//cout << score << " ";
			d.push_back(score);
		}
		//cout << endl;
		sort(d.begin(), d.end(), greater<double>());//降序排列
		d.pop_front();//去除最高分
		d.pop_back();//去除最低分
		double sum = accumulate(d.begin(), d.end(), 0.0f);//总分
		double avg = sum / (double)d.size();//平均分
		//打印平均分
		//cout << "编号：" << *it << "姓名：" << this->m_Speaker[*it].m_name << "平均分：" << avg << endl;

		//将平均分放入容器中
		this->m_Speaker[*it].score[this->i - 1] = avg;
		//将打分放入临时容器中
		groupscore.insert(make_pair(avg, *it));//key是得分，value是编号
		//每6人取出前三名
		if (num % 6 == 0)
		{
			cout << "第" << num / 6 << "小组名次：" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupscore.begin(); it != groupscore.end(); it++)
			{
				cout << "编号：" << it->second << "姓名：" << this->m_Speaker[it->second].m_name << "分数：" <<
					this->m_Speaker[it->second].score[this->i - 1] << endl;

			}
			//取走前三名
			int cout = 0;
			for (multimap<
				double, int, greater<double>>:: iterator it = groupscore.begin(); it != groupscore.end() && cout < 3; it++, cout++)
			{
				if (this->i == 1)
				{
					v2.push_back((*it).second);
				}
				else
				{
					v3.push_back((*it).second);
				}
			}
			groupscore.clear();//小组清空
		
		
		
		}
	}
	cout << "第" << this->i << "轮比赛结束" << endl;
	system("pause");

}
//显示得分
void Speechmanager::showscore()
{
	cout << "第" << this->i << "轮选手晋级如下：" << endl;
	vector<int>v0;
	if (this->i == 1)
	{
		v0 = v2;
	}
	else
	{
		v0 = v3;
	}
	for (vector<int>::iterator it = v0.begin(); it != v0.end(); it++)
	{
		cout << "编号：" << *it << "姓名：" <<this-> m_Speaker[*it].m_name << "分数:" <<this-> m_Speaker[*it].score[this->i-1] << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
	this->show_menu();
}
//保存分数
void Speechmanager::saverecord()
{
	ofstream ofs;
	ofs.open("speech.csv",ios::out|ios::app);//用追加的方式写文件
	//将每个选手的数据写到文件中
	for (vector<int>::iterator it = v3.begin(); it != v3.end(); it++)
	{
		ofs << *it << "," << this->m_Speaker[*it].score[1] << ",";

	}
	ofs << endl;
	//关闭文件
	ofs.close();
	cout << "分数已经保存" << endl;
}

//析构函数实现
Speechmanager::~Speechmanager()
{

}
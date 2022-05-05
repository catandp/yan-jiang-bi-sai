#include"speechmanager.h"
//���캯��ʵ��
Speechmanager::Speechmanager()
{
	this->initspeech();
	creatspeeker();
}
//�˵������ʵ��
void Speechmanager::show_menu()
{
	cout << "*******************************"<< endl;
	cout << "*********��ӭ�μ��ݽ����� *****"<< endl;
	cout << "*********1.��ʼ�ݽ�����********" << endl;
	cout << "*********2.�鿴�����¼********" << endl;
	cout << "*********3.��ձ�����¼********" << endl;
	cout << "*********0.�˳���������********" << endl;
	cout << "*******************************" << endl;
}
//�˳�ϵͳ
void Speechmanager::exitsystem()
{
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}
//������ʼ��
void Speechmanager::initspeech()
{
	//�������ÿ�
	this->v1.clear();
	this->v2.clear();
	this->v3.clear();
	this->m_Speaker.clear();
	//��ʼ������������
	this->i = 1;
}

//����ѡ��ʵ��
void Speechmanager::creatspeeker()
{
	string nameseed = "ABCDEFGHIJK";
	for (int k = 0; k < 12; k++)
	{
		string name = "ѡ��";
		name += nameseed[k];
		//���������ѡ��
		Speaker  sp;
		sp.m_name = name;
		for (int j = 0; j < 2; j++)
		{
			sp.score[j] = 0;
		}
		//����ѡ�ֱ�Ų�����v1������
		this->v1.push_back(k + 1001);
		//ѡ�ֱ�����Ӧ��ѡ�ַ���map��
		this->m_Speaker.insert(make_pair(k + 1001, sp));
	}
}
//��ʼ�����������������̵Ŀ��ƺ�����ʵ��
void Speechmanager::startspeech()
{
	//��һ�ֱ���

	//��ǩ
	this->speechdraw();
	//����
	this->speechcontest();
	//��ʾ��������
	this->showscore();
	//�ڶ��ֱ���
	this->i++;
	//��ǩ
	this->speechdraw();
	//����
	this->speechcontest();
	//��ʾ���ս��
	this->showscore();
	//����������ļ���
	this->saverecord();
	cout << "����������" << endl;
	system("pause");
	system("cls");
}
//��ǩ��ʵ��
void Speechmanager::speechdraw()
{
	cout << "��" << this->i << "��ѡ�����ڳ�ǩ" << endl;
	cout << "---------------------------------------" << endl;
	cout << "��ǩ�Ľ�����£�" << endl;
	if (this->i == 1)
	{
//��һ��
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	else
	{
//�ڶ���
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
//����
void Speechmanager::speechcontest()
{

	cout << "��" << this->i << "�ֱ�����ʽ��ʼ" << endl;
	//׼��һ����ʱ���������ÿ��С��ĳɼ�
	multimap<double, int, greater<double>>groupscore;
	int num = 0;//��¼��Ա����6��һ��
	vector<int>v;//�������ѡ�ֵ�����
	if (this->i == 1)
	{
		v = v1;
	}
	else
	{
		v = v2;
	}
	//�������е�ѡ�ֽ��б���
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		num++;
		//��ί���
		deque<double>d;
		for (int s = 0; s < 10; s++)
		{
			double score = (rand() % 401 + 600) / 10.f;//����10.f����һ��С��
			//cout << score << " ";
			d.push_back(score);
		}
		//cout << endl;
		sort(d.begin(), d.end(), greater<double>());//��������
		d.pop_front();//ȥ����߷�
		d.pop_back();//ȥ����ͷ�
		double sum = accumulate(d.begin(), d.end(), 0.0f);//�ܷ�
		double avg = sum / (double)d.size();//ƽ����
		//��ӡƽ����
		//cout << "��ţ�" << *it << "������" << this->m_Speaker[*it].m_name << "ƽ���֣�" << avg << endl;

		//��ƽ���ַ���������
		this->m_Speaker[*it].score[this->i - 1] = avg;
		//����ַ�����ʱ������
		groupscore.insert(make_pair(avg, *it));//key�ǵ÷֣�value�Ǳ��
		//ÿ6��ȡ��ǰ����
		if (num % 6 == 0)
		{
			cout << "��" << num / 6 << "С�����Σ�" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupscore.begin(); it != groupscore.end(); it++)
			{
				cout << "��ţ�" << it->second << "������" << this->m_Speaker[it->second].m_name << "������" <<
					this->m_Speaker[it->second].score[this->i - 1] << endl;

			}
			//ȡ��ǰ����
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
			groupscore.clear();//С�����
		
		
		
		}
	}
	cout << "��" << this->i << "�ֱ�������" << endl;
	system("pause");

}
//��ʾ�÷�
void Speechmanager::showscore()
{
	cout << "��" << this->i << "��ѡ�ֽ������£�" << endl;
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
		cout << "��ţ�" << *it << "������" <<this-> m_Speaker[*it].m_name << "����:" <<this-> m_Speaker[*it].score[this->i-1] << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
	this->show_menu();
}
//�������
void Speechmanager::saverecord()
{
	ofstream ofs;
	ofs.open("speech.csv",ios::out|ios::app);//��׷�ӵķ�ʽд�ļ�
	//��ÿ��ѡ�ֵ�����д���ļ���
	for (vector<int>::iterator it = v3.begin(); it != v3.end(); it++)
	{
		ofs << *it << "," << this->m_Speaker[*it].score[1] << ",";

	}
	ofs << endl;
	//�ر��ļ�
	ofs.close();
	cout << "�����Ѿ�����" << endl;
}

//��������ʵ��
Speechmanager::~Speechmanager()
{

}
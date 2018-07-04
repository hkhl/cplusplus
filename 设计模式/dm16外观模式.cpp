#include <iostream>
using namespace std;


//���ģʽ
//һ���ͻ��˲��������ϵͳ�� ����һ���ı��ˣ��ͻ��˽ӿھ���Ҫ�ı�
//������ϵͳ�Ϳͻ���֮���װһ���м�㡣


class SubSystemA
{
public:
	void dothing()
	{
		cout << "A system run!" << endl;
	}
};

class SubSystemB
{
public:
	void dothing()
	{
		cout << "B system run!" << endl;
	}
};

class SubSystemC
{
public:
	void dothing()
	{
		cout << "C system run!" << endl;
	}
};




//--�������ģʽ
class Facade
{
public:
	Facade()
	{
		m_subSystemA = new SubSystemA;
		m_subSystemB = new SubSystemB;
		m_subSystemC = new SubSystemC;
	}

	void dothing()
	{
		m_subSystemA->dothing();
		m_subSystemB->dothing();
		m_subSystemC->dothing();
	}
private:
	SubSystemA *m_subSystemA;
	SubSystemB *m_subSystemB;
	SubSystemC *m_subSystemC;
};


//������Ŀͻ�����ϵͳ�Ľ�����ʽ
void main1()
{
	SubSystemA *a = new SubSystemA;
	SubSystemB *b = new SubSystemB;
	SubSystemC *c = new SubSystemC;
	a->dothing();
	b->dothing();
	c->dothing();

	delete a;
	delete b;
	delete c;
}


void main2()
{
	Facade	*facade = new Facade;
	facade->dothing();
	delete facade;
}


void main()
{
	cout << "������ķ�ʽ\n";
	main1();  //not
	cout << "����ķ�ʽ\n";
	main2();  //ok

	system("pause");
}
#include <iostream>
#include <string>
using namespace std;

//�н���ģʽ
class Person;


//�����н�
class Mediator
{
public:
	virtual void setThing() = 0;
	virtual void setA(Person *) = 0;
	virtual void setB(Person *) = 0;
};

//������
class Person
{
public:
	Person(string name, char sex, int condi, Mediator *mediator)
	{
		m_name = name;
		m_sex = sex;
		m_condi = condi;
		m_mediator = mediator;
	}

	string getName()
	{
		return m_name;
	}

	char getSex()
	{
		return m_sex;
	}

	int getCondi()
	{
		return m_condi;
	}

public:
	virtual void getPater(Person *person) = 0;
//private:
protected:  //���������ֱ��ʹ�ø����Ա����
	string m_name;
	char m_sex;
	int m_condi;
	Mediator *m_mediator;
};

//�����н�
class MarriageMediator : public Mediator
{
public:
	virtual void setA(Person *man)
	{
		m_man = man;
	}

	virtual void setB(Person *woman)
	{
		m_woman = woman;
	}
	
	virtual void setThing()
	{
		if (m_man->getSex() == m_woman->getSex())
		{
			cout << "ͬ����" << endl;
		}
		if (m_man->getCondi() == m_woman->getCondi())
		{
			cout << m_man->getName() << "��" << m_woman->getName() << "����" << endl;
		}
		else
		{
			cout << m_man->getName() << "��" << m_woman->getName() << "no��" << endl;
		}
	}
private:
	Person *m_man;
	Person *m_woman;
};





class Woman : public Person
{
public:
	Woman(string name, char sex, int condi, Mediator *m) : Person(name, sex, condi, m){}

	virtual void getPater(Person *person)
	{
		m_mediator->setA(person);
		m_mediator->setB(this);
		m_mediator->setThing();
	}
};


class Man : public Person
{
public:
	Man(string name, char sex, int condi, Mediator *m) : Person(name, sex, condi, m){}

	virtual void getPater(Person *person)
	{
		m_mediator->setA(this);
		m_mediator->setB(person);
		m_mediator->setThing();
	}
};





void main1()
{
	//Person * xiaofang = new Woman("С��", 'f', 5);
	//Person * zhangsan = new Woman("����", 'm', 5);
	//Person * lisi = new Woman("����", 'm', 2);

	////С���Լ��Ҷ��� ż�˶�̫�ߣ� �����н���
	//xiaofang->getPater(zhangsan);
	//xiaofang->getPater(lisi);
}




void main2()
{
	Mediator *mediator = new MarriageMediator;
	Person * xiaofang = new Woman("С��", 'f', 5, mediator);
	Person * zhangsan = new Woman("����", 'm', 5, mediator);
	Person * lisi = new Woman("����", 'm', 2, mediator);

	//С���Լ��Ҷ��� ż�˶�̫�ߣ� �����н���
	xiaofang->getPater(zhangsan);
	xiaofang->getPater(lisi);

}

void main()
{
	//main1();
	main2();

	system("pause");
}
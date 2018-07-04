#include <iostream>
#include <string>
#include <list>

using namespace std;


//������ģʽ
//�����߿��Է��ʹ�԰��ĳ����
//�����߿��Է���������԰

class Park;
//���������
class Visitor
{
public:
	virtual void Visit(Park *park) = 0;
};

//����԰ ���շ���
class Park
{
public:
	virtual void Accept(Visitor *visitor) = 0;
};


class VisitorA : public Visitor
{
public:
	virtual void Visit(Park *park)
	{
		cout << "A����  ��԰A����" << endl;  //park->getName();
	}
};

class VisitorB : public Visitor
{
public:
	virtual void Visit(Park *park)
	{
		//park->Accept(this);
		cout << "B���� ��԰B����" << endl;
	}
};

class ParkA : public Park
{
public:

	virtual void Accept(Visitor *visitor)
	{
		visitor->Visit(this);
	}
private:
};

class ParkB : public Park
{
public:

	virtual void Accept(Visitor *visitor)
	{
		visitor->Visit(this);
	}
private:
};


//������԰
class AllPark : public Park
{
public:
	AllPark()
	{
		m_list.clear();
	}

	void setAllPark(Park * park)
	{
		m_list.push_back(park);
	}

	virtual void Accept(Visitor *v)
	{
		//list����ǹ�԰�ĸ������֣� ����ÿ�����ֵ����Լ���accpet����
		for (list<Park*> ::iterator it = m_list.begin(); it != m_list.end(); it++)
		{
			(*it)->Accept(v);
		}
	}

private:
	list<Park *> m_list;
};


//������		
class ManagerVisitor : public Visitor
{
public:
	virtual void Visit(Park *park)
	{
		cout << "����������԰" << endl;  //park->getName();
	}

};



void main01()
{
	Visitor *visitor = new VisitorA;
	Park *park = new ParkA;

	park->Accept(visitor);
	
	delete park;
	delete visitor;
}
void main02()
{
	Visitor *manager = new ManagerVisitor;
	Park *parka = new ParkA;
	Park *parkb = new ParkB;
	AllPark *parkall = new AllPark;

	//����԰�������ַ���������԰ setAllPark() �� ������������Ǽ̳к���µĳ�Ա�� ���Ը���ֻ����AllPark

	parkall->setAllPark(parka);
	parkall->setAllPark(parkb);

	//������԰���չ����߷��ʡ�
	parkall->Accept(manager);

}
void main()
{
	//main01();
	main02();

	system("pause");
}

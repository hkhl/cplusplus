#include <iostream>
#include <string>
#include <list>
using namespace std;

//֪ͨ��  ������
class Secretary;

//�۲���
class Observer
{
public:
	Observer() {}
	Observer(Secretary *secretary)
	{
		this->secretary = secretary;
	}
	void Update(string action)
	{
		cout << "action : " << action << endl;
	}

private:
	Secretary *secretary;
};


//�����й۲���֪ͨ
class Secretary
{
public:
	Secretary()
	{
		//m_list = new list<Observer *>;
		//m_list->clear();
		m_list.clear();
	}

	void setObserver(Observer *ob)
	{
		m_list.push_back(ob);
	}
	void Notify(string info)
	{
		cout << "֪ͨ: ";
		for (list<Observer *>::iterator it = m_list.begin();
				it != m_list.end(); it++)
		{
			cout << (*it) << " ";
			(*it)->Update(info);
		}
		cout << endl;
	}
private:
	list<Observer *> m_list;
	//list<Observer *>* m_list;
};


void main()
{
	Secretary *secretary = new Secretary;
	Observer *ob1 = new Observer();
	Observer *ob2 = new Observer();

	secretary->setObserver(ob1);
	secretary->setObserver(ob2);

	secretary->Notify("BOSS����");
	//ob1->Update("work");

	system("pause");
}	

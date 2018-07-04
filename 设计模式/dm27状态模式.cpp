#include <iostream>
#include <string>
using namespace std;

class Worker;
class State
{
public:
	virtual void doSomeThing(Worker *w) = 0;
};

class State1 : public State 
{
public:
	void doSomeThing(Worker *w);
};

class State2 : public State 
{
public:
	void doSomeThing(Worker *w);
};

class Worker
{
public:
	Worker();
	int getHour()
	{
		return m_hour;
	}

	void setHour(int hour)
	{
		m_hour = hour;
	}

	State* getCurrentState()
	{
		return m_currstate;
	}

	void setCurrentState(State* state)
	{
		m_currstate = state;
	}

	void doSomeThing()   //ĳ��״̬��ĳ����
	{
		m_currstate->doSomeThing(this);
	}

private:
	int m_hour;
	State *m_currstate;
};



//״̬ת�����Լ��ڲ�ת��
void State1::doSomeThing(Worker *w)
{
	if (w->getHour() == 7 || w->getHour() == 8)
	{
		cout << "���緹" << endl;
	}
	else
	{
		//״̬1������ �л���״̬2
		delete w->getCurrentState();			//ɾ����ǰ״̬
		w->setCurrentState(new State2);			//������״̬
		w->getCurrentState()->doSomeThing(w);	//�л�״̬
	}
}

void State2::doSomeThing(Worker *w)
{
	if (w->getHour() == 9 || w->getHour() == 10)
	{
		cout << "����" << endl;
	}
	else
	{
		//״̬2������ �л���״̬3   ״̬�ָ�������״̬
		delete w->getCurrentState();
		w->setCurrentState(new State1);
		cout << "��ǰʱ���" << w->getHour() << "δ֪״̬" << endl;
	}
}

Worker::Worker()
{
	m_currstate = new State1;
}

void main()
{
	Worker *worker = new Worker;
	worker->setHour(8);
	worker->doSomeThing();

	worker->setHour(11);
	worker->doSomeThing();

	delete worker;

	system("pause");
}

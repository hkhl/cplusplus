#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
	virtual Person* clone() = 0;
	virtual void Print() = 0;
};

class OnePerson : public Person
{
public:
	OnePerson()
	{
		m_name = "";
		m_age = 18;
		m_num = NULL;
	}
	OnePerson(string name, int age, int *num)
	{
		m_name = name;
		m_age = age;
		m_num = num;
	}

	void setNum()
	{
		*m_num = 10000;
	}
	virtual void Print()
	{
		cout << "name:" << m_name << "    "    
				"age:" << m_age <<"    " 
				"num:" << *m_num << endl;
	}

	virtual Person* clone()   //cloneһ��ͬ���Ķ���
	{
		//ǳ����
		//OnePerson *tmp = new OnePerson;
		//*tmp = *this;
		////OnePerson *tmp = this;
		//return tmp;


		//���
		OnePerson *tmp = new OnePerson;
		*tmp = *this;
		tmp->m_num = new int;
		*tmp->m_num = *this->m_num;
		return tmp;
	}
private:
	string m_name;
	int m_age;
	int *m_num;
};


void main()
{
	int num = 3;

	Person  *q = NULL;
	OnePerson *p = new	OnePerson("����", 21, &num);
	cout << "p-> ";
	p->Print();
	
	q = p->clone();
	//ǳ����p�ı���ָ���ֵ�� q���ŷ����˸ı� 
	p->setNum();

	cout << "q-> ";

	cout << "������ĶԱȱ仯" << endl;
	q->Print();
	p->Print();

	system("pause");
}
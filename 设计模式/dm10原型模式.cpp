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

	virtual Person* clone()   //clone一个同样的对象
	{
		//浅拷贝
		//OnePerson *tmp = new OnePerson;
		//*tmp = *this;
		////OnePerson *tmp = this;
		//return tmp;


		//深拷贝
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
	OnePerson *p = new	OnePerson("张三", 21, &num);
	cout << "p-> ";
	p->Print();
	
	q = p->clone();
	//浅拷贝p改变了指针的值， q跟着发生了改变 
	p->setNum();

	cout << "q-> ";

	cout << "拷贝后的对比变化" << endl;
	q->Print();
	p->Print();

	system("pause");
}
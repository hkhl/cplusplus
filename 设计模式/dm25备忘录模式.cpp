#include <iostream>
#include <string>

using namespace std;

class Memory
{
public:
	Memory() {}
	Memory(string name, int age)
	{
		m_name = name;
		m_age = age;
	}
	string getName()
	{
		return m_name;
	}

	int getAge()
	{
		return m_age;
	}

	void setAge(int age)
	{
		m_age = age;
	}

	void setName(string name)
	{
		m_name = name;
	}
private:
	string m_name;
	int m_age;

};

class Person
{
public:
	Person(string name, int age)
	{
		m_name = name;
		m_age = age;
	}
	Memory* CreateMemory()
	{
		return new Memory(m_name, m_age);
	}

	void getMemory(Memory *memory)
	{
		m_name = memory->getName();
		m_age = memory->getAge();
	}

	string getName()
	{
		return m_name;
	}

	int getAge()
	{
		return m_age;
	}

	void setAge(int age)
	{
		m_age = age;
	}

	void setName(string name)
	{
		m_name = name;
	}
private:
	string m_name;
	int m_age;
};

void main()
{

	Memory *memory = NULL;
	Person *zhangsan = new Person("����", 25);
	
	memory = zhangsan->CreateMemory();

	cout << zhangsan->getName() << endl;
	zhangsan->setName("����");
	cout << zhangsan->getName() << endl;

	zhangsan->getMemory(memory);
	cout << zhangsan->getName() << endl;

	system("pause");

}				
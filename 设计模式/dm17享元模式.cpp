#include <iostream>
#include <string>
#include <map>
using namespace std;

class Person
{
public:
	Person(string name, int age)
	{
		m_name = name;
		m_age = age;
	}
	virtual void PrintT() = 0;
protected:
	string m_name;
	int m_age;
};

//��Ԫ����
class Teacher : public Person
{
public:
	Teacher(string name, int age, string id) : Person(name, age)
	{
		m_id = id;
	}
	virtual void PrintT()
	{
		cout << "name : " << m_name << "  age: "
			<< m_age << "  id:" << m_id << " " << endl;
	}
private:
	string m_id;
};


//��Ԫ����  ��ͬ�Ķ��󴴽��� ��ͬ�Ķ��󷵻�
class FlyWeightTeacherFactory
{
public:
	FlyWeightTeacherFactory()
	{
		map1.clear();
	}
	~FlyWeightTeacherFactory()
	{
		while (map1.empty())  //�ڹ����д�����ʦ��㣬 �ڹ���������
		{
			Person *tmp = NULL;
			map<string, Person *>::iterator it = map1.begin();
			tmp = it->second;
			map1.erase(it);
			delete tmp;
		}
	}

	Person* GetTeacher(string id)
	{
		Person *tmp = NULL;
		map<string, Person *>::iterator it;
		it = map1.find(id);
		if (it == map1.end()) //û�ҵ�
		{
			string tmpname;
			int tmpage;
			cout << "\n��������ʦ����:";
			cin >> tmpname;

			cout << "\n��������ʦ����:";
			cin >> tmpage;

			tmp = new Teacher(tmpname, tmpage, id);
			map1.insert(pair<string, Person*>(id, tmp));

		}
		else
		{
			tmp = it->second;
		}
		return tmp;
	}
private:
	map<string, Person *> map1;
};


//��Ԫģʽ   �����ö��󱣴������� �´λ�ȡ�������Ƿ��Ѿ����ڣ� 
//���ڵĻ�ֱ������ȡ, ���ڵĻ����´���
void main1()
{
	Person	 *p1 = NULL;
	Person	 *p2 = NULL;
	FlyWeightTeacherFactory *fw = new FlyWeightTeacherFactory;
	p1 = fw->GetTeacher("001");
	p1->PrintT();

	p2 = fw->GetTeacher("002");
	p2->PrintT();
	
	//p1 p2 ���ý����ͬ
	delete fw;
}

void main()
{
	main1();

	system("pause");
}
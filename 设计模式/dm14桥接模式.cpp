#include <iostream>
using namespace std;

//��ͬ�ĳ�  ��װ  ��ͬ�ķ�����
//��������  ��������
class Engine
{
public:
	virtual void InstallEngine() = 0;
};

//��ͬ�ķ�����
class cc550 : public Engine
{
public:
	virtual void InstallEngine()
	{
		cout << "���� cc550" << endl;
	}
};

class cc440 : public Engine
{
public:
	virtual void InstallEngine()
	{
		cout << "���� cc440" << endl;
	}
};

//�������ϲ�ͬ�ķ�����  Ȼ����а�װ
class Car
{
public:
	Car(Engine *engine)
	{
		m_engine = engine;
	}
	//��װ������
	virtual void install() = 0;
protected:
	Engine *m_engine;
};

//����
class BMW : public Car
{
public:
	BMW(Engine *engine) : Car(engine)
	{
		;
	}
	void install()
	{
		cout << "���� ";
		//�����ܱ�����ʽ�� �˴����Ե���
		m_engine->InstallEngine();
	}
private:
	//Engine *mm_engine;  //���п���
};


void main()
{
	Car *car = NULL;
	Engine *engine = NULL;

	engine = new cc440;
	car = new BMW(engine);
	car->install();


	system("pause");
}
#include <iostream>
#include <string>
using namespace std;

//����ˮ����  ����ˮ����
//���󹤳���  ���幤����
//���幤�������������ˮ����  new ���
//���籱�������������������㽶��ƻ��   �Ϸ����������Ϸ�ˮ��

class Fruit
{
public:
	virtual void getFruit() = 0;
};

class AbFactory
{
public:
	//virtual Fruit *createFruit() = 0;
	virtual Fruit *createBanana() = 0;
	virtual Fruit *createApple() = 0;
};

class SourthBanana : public Fruit
{
public:
	void getFruit()
	{
		cout << "I am Sourth Banana" << endl;
	}
};

class SourthApple : public Fruit
{
public:
	void getFruit()
	{
		cout << "I am Sourth Apple" << endl;
	}
};

class NorthBanana : public Fruit
{
public:
	void getFruit()
	{
		cout << "I am North Banana" << endl;
	}
};

class NorthApple : public Fruit
{
public:
	void getFruit()
	{
		cout << "I am North Apple" << endl;
	}
};

class SourthFactory : public AbFactory
{
public:
	virtual Fruit *createBanana()
	{
		return new SourthBanana;
	}
	virtual Fruit *createApple()
	{
		return new SourthApple;
	}
};

class NorthFactory : public AbFactory
{
public:
	virtual Fruit *createBanana()
	{
		return new NorthBanana;
	}
	virtual Fruit *createApple()
	{
		return new NorthApple;
	}
};

void main()
{
	AbFactory *factor = NULL;
	Fruit *fruit = NULL;

	//���Ϸ�ˮ��
	factor = new SourthFactory;
	fruit = factor->createApple();
	fruit->getFruit();
	delete fruit;
	fruit = factor->createBanana();
	fruit->getFruit();
	delete fruit;
	delete factor;


	//��Ա���ˮ���� ֻ��Ҫnewһ������������ok  �������벻��ı�
	factor = new NorthFactory;
	fruit = factor->createApple();
	fruit->getFruit();
	delete fruit;
	fruit = factor->createBanana();
	fruit->getFruit();
	delete fruit;
	delete factor;

	system("pause");
}
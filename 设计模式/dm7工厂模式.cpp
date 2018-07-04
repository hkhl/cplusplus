#include <iostream>
#include <string>
using namespace std;

//����ˮ����  ����ˮ����
//���󹤳���  ���幤����

class Fruit
{
public:
	virtual void getFruit() = 0;
};


class Banana : public Fruit
{
public:
	void getFruit()
	{
		cout << "I am banana" << endl;
	}
};

class Apple : public Fruit
{
public:
	void getFruit()
	{
		cout << "I am apple" << endl;
	}
};

//����
class AbFactory
{
public:
	virtual Fruit *createFruit() = 0;
};

class BananaFactory : public AbFactory
{
public:
	Fruit *createFruit()
	{
		return new Banana;
	}
};

class AppleFactory : public AbFactory
{
public:
	Fruit *createFruit()
	{
		return new Apple;
	}
};

void main()
{
	AbFactory *factor = NULL;
	Fruit *fruit = NULL;

	//���ʲô �û����ʲô������ ����Ķ�ԭ���Ĵ���
	//ʵ���˿ͻ��˺� �����Ʒ �� ���幤���� �����

	//�����㽶
	factor = new BananaFactory;
	fruit = factor->createFruit();
	fruit->getFruit();
	delete fruit;
	delete factor;

	factor = new AppleFactory;
	fruit = factor->createFruit();
	fruit->getFruit();
	delete fruit;
	delete factor;


	system("pause");
}
#include <iostream>
using namespace std;

//装饰模式， 功能任意组装

class  Car
{
public:
	virtual void show() = 0;
};

//都可以跑
class RunCar : public Car
{
public:
	virtual void show()
	{
		cout << "跑车" << endl;
	}
};


//装饰  游泳 飞
class SwimCar : public Car
{
public:
	SwimCar(Car *car)
	{
		m_car = car;
	}
	void swim()
	{
		cout << "游泳 +　";
	}
	virtual void show()
	{
		swim();
		m_car->show();
	}
private:
	Car *m_car;
};


class FlyCar : public Car
{
public:
	FlyCar(Car *car)
	{
		m_car = car;
	}
	void fly()
	{
		cout << "飞天 +　";
	}
	virtual void show()
	{
		fly();
		m_car->show();
	}
private:
	Car *m_car;
};

void main()
{

	Car *car = NULL;
	car = new RunCar();
	car->show();

	cout << endl << endl;
	FlyCar *f = new FlyCar(car);
	f->show();
	cout << endl << endl;

	SwimCar *s = new SwimCar(car);
	s->show();
	cout << endl << endl;

	SwimCar *sf = new SwimCar(f);
	sf->show();

	system("pause");
}
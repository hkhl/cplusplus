#include <iostream>
#include <string>
using namespace std;


class Fruit
{
public:
	virtual void getFruit() = 0;
protected:
private:
};


class Banan : public Fruit
{
public:
	void getFruit()
	{
		cout << "I am banan" << endl;
	}
protected:
private:
};

class Apple : public Fruit
{
public:
	void getFruit()
	{
		cout << "I am apple" << endl;
	}
protected:
private:
};

//¹¤³§
class Factory
{
public:
	Fruit *createFruit(const char *str)
	{
		if (strcmp(str, "banan") == 0)
		{
			return new Banan;
		}
		else if (strcmp(str, "apple") == 0)
		{
			return new Apple;
		}
		else
		{
			cout << "error" << endl;
		}
		return NULL;
	}
protected:
private:
};

void main()
{
	Factory *fac = new Factory;
	Fruit *fruit = NULL;

	fruit = fac->createFruit("banan");  //new banan
	fruit->getFruit();
	delete fruit;

	fruit = fac->createFruit("apple");  //new apple
	fruit->getFruit();
	delete fruit;

	delete fac;


	system("pause");

}
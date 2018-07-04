#include <iostream>
using namespace  std;


class Singelton
{
private:
	Singelton()
	{
		cout << "构造函数" << endl;
	}
protected:
public:
	static Singelton *getInstance()
	{
		if (m_sne == NULL)
		{ 
			m_sne = new Singelton;
		}
		return m_sne;
	}

	//释放内存
	static void freeInstance()
	{
		if (m_sne != NULL)
		{
			delete m_sne;
			m_sne = NULL;
			cout << "内存释放" << endl;
		}
	}
private:
	static Singelton *m_sne;
};

//静态变量初始化
Singelton *Singelton::m_sne = NULL;

void main31()
{
	//静态函数的调用
	Singelton *p1 = Singelton::getInstance();
	Singelton *p2 = Singelton::getInstance();

	if (p1 == p2)
	{
		cout << "一个实例" << endl;
	}
	else
	{
		cout << "两个实例" << endl;
	}

	Singelton::freeInstance();

	return;
}

void main()
{
	main31();
	system("pause");
}
#include <iostream>
using namespace  std;

//饿汉式单例模式   直接生成实例
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
Singelton *Singelton::m_sne = new Singelton;

void main31()
{
	//静态函数的调用
	Singelton *p1 = Singelton::getInstance();
	Singelton *p2 = Singelton::getInstance();

	if (p1 == p2)
	{
		cout << "一个实例 同一个对象" << endl;
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
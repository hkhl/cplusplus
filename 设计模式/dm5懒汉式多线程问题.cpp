#include <iostream>
#include <Windows.h>	
#include <process.h>
//#include <CRTDBG.h>

//懒汉式多线程会创建多个实例
using namespace  std;



/* 优化问题
   需要两次判断

   伪代码：
static Singelton *getInstance()
{
	if (m_p == NULL)
	{
		s.lock();
		if (m_p == NULL)        //当几个线程竞争锁后需要判断m_p是否为NULL以确保只产生一个实例
		{
			m_p = new Singelton;
		}
		s.unlock();
	}
}
*/

class Singelton
{
private:
	Singelton()
	{
		cout << "begin构造函数\n";
		Sleep(2000);
		cout << "end\n";
	}
protected:
public:
	static Singelton *getInstance()
	{
		if (m_sne == NULL)
		{
			count++;
			m_sne = new Singelton;
		}
		return m_sne;
	}
	static void Prints()
	{
		cout << count <<"\n" << endl;
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
	static int count;
};




//静态变量初始化
int Singelton::count = 0;
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

void MyThreadFunc(void *)
{
	cout << "我是线程体... \n" << endl;
	Singelton::getInstance()->Prints();
}

void main()
{
	HANDLE hThread[10];
	for (int i = 0; i < 3; i++)
	{
		hThread[i] = (HANDLE)_beginthread(MyThreadFunc, 0, NULL);
	}
	main31();


	//等待线程
	for (int i = 0; i < 3; i++)
	{
		WaitForSingleObject(hThread[i], INFINITE);
	}
	system("pause");
}
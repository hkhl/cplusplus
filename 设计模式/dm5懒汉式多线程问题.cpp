#include <iostream>
#include <Windows.h>	
#include <process.h>
//#include <CRTDBG.h>

//����ʽ���̻߳ᴴ�����ʵ��
using namespace  std;



/* �Ż�����
   ��Ҫ�����ж�

   α���룺
static Singelton *getInstance()
{
	if (m_p == NULL)
	{
		s.lock();
		if (m_p == NULL)        //�������߳̾���������Ҫ�ж�m_p�Ƿ�ΪNULL��ȷ��ֻ����һ��ʵ��
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
		cout << "begin���캯��\n";
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

	//�ͷ��ڴ�
	static void freeInstance()
	{
		if (m_sne != NULL)
		{
			delete m_sne;
			m_sne = NULL;
			cout << "�ڴ��ͷ�" << endl;
		}
	}
private:
	static Singelton *m_sne;
	static int count;
};




//��̬������ʼ��
int Singelton::count = 0;
Singelton *Singelton::m_sne = NULL;

void main31()
{
	//��̬�����ĵ���
	Singelton *p1 = Singelton::getInstance();
	Singelton *p2 = Singelton::getInstance();

	if (p1 == p2)
	{
		cout << "һ��ʵ��" << endl;
	}
	else
	{
		cout << "����ʵ��" << endl;
	}

	Singelton::freeInstance();

	return;
}

void MyThreadFunc(void *)
{
	cout << "�����߳���... \n" << endl;
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


	//�ȴ��߳�
	for (int i = 0; i < 3; i++)
	{
		WaitForSingleObject(hThread[i], INFINITE);
	}
	system("pause");
}
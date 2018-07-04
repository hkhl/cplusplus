#include <iostream>
using namespace  std;


class Singelton
{
private:
	Singelton()
	{
		cout << "���캯��" << endl;
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
};

//��̬������ʼ��
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

void main()
{
	main31();
	system("pause");
}
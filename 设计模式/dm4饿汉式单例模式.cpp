#include <iostream>
using namespace  std;

//����ʽ����ģʽ   ֱ������ʵ��
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
Singelton *Singelton::m_sne = new Singelton;

void main31()
{
	//��̬�����ĵ���
	Singelton *p1 = Singelton::getInstance();
	Singelton *p2 = Singelton::getInstance();

	if (p1 == p2)
	{
		cout << "һ��ʵ�� ͬһ������" << endl;
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
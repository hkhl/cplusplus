#include <iostream>
using namespace std;

	//�����㷨 ����ģʽ

//�����㷨��
class Strategy
{
public:
	virtual void crypt() = 0;
};

class AES : public Strategy
{
public:
	virtual void crypt()
	{
		cout << "AES�����㷨" << endl;
	}
};

//�㷨�ľ���ʵ��
class DES : public Strategy
{
public:
	virtual void crypt()
	{
		cout << "DES�����㷨" << endl;
	}
};


//�㷨�Ĳ���
class Context
{
public:
	void setStrategy(Strategy *strategy)
	{
		m_strategy = strategy;
	}

	void myoperator()
	{
		m_strategy->crypt();
	}

private:
	Strategy *m_strategy;
};

void main()
{
	//�ͻ�ֻ������ýӿڣ��������ڲ�ʵ��
	Strategy * strategy1 = new DES();
	Strategy * strategy2 = new AES();

	Context *context = new Context;
	context->setStrategy(strategy1);
	context->myoperator();



	system("pause");
}
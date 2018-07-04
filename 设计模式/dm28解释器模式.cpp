#include <iostream>
#include <string>
using namespace std;

//����Ȩģʽ  ����һ���﷨
			
//���綨�� ��һ������ �� ��һ������
class Context
{
public:
	Context(int num)
	{
		m_num = num;
		m_res = num;
	}
public:
	void setNum(int num)
	{
		m_num = num;
	}

	void setRes(int res)
	{
		m_res = res;
	}

	int getNum()
	{
		return m_num;
	}

	int getRes()
	{
		return m_res;
	}
private:
	int m_num;
	int m_res;
};		

//������

class Expression
{
public:
	virtual void interpreter(Context *context) = 0;
};

//����������
class PlusExpression : public Expression
{
public:
	virtual void interpreter(Context *context)
	{
		int num = context->getNum();
		++num;
		context->setNum(num);
		context->setRes(num);
	}
};

//�Լ�������
class MinuExpression : public Expression
{
public:
	virtual void interpreter(Context *context)
	{
		int num = context->getNum();
		--num;
		context->setNum(num);
		context->setRes(num);
	}
};
void main()
{
	Context *context = new Context(100);
	cout << context->getNum() << endl;

	//������
	Expression *exp = new PlusExpression;
	exp->interpreter(context);
	cout << context->getRes() << endl;
	delete exp;

	exp = new MinuExpression;
	exp->interpreter(context);
	cout << context->getRes() << endl;
	delete exp;

	delete  context;
	system("pause");
}

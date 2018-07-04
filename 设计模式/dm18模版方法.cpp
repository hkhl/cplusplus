#include <iostream>
using namespace std;


//ҵ���߼���ǰ������ã�����֮��ĵ��ù�ϵ���� 
//����ֻ��Ҫ�������ľ���ʵ��

class MakeCar
{
public:
	virtual void MakeHead() = 0;
	virtual void MakeBody() = 0;
	virtual void MakeTail() = 0;

	//ģ�溯��
	void Make()
	{
		MakeTail();
		MakeBody();
		MakeHead();
	}
private:
};

class Jeep : public MakeCar
{
public:
	virtual void MakeHead()
	{
		cout << "jeep head" << endl;
	}

	virtual void MakeTail()
	{

		cout << "jeep tail" << endl;
	}

	virtual void MakeBody()
	{
		cout << "jeep body" << endl;
	}
};




void main()
{
	MakeCar *makecar = NULL;
	makecar = new Jeep;
	makecar->Make();

	delete makecar;
	system("pause");
}
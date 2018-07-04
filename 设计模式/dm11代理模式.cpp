#include <iostream>
#include <Windows.h>
using namespace std;

class Subject
{
public:
	virtual	void sellbook() = 0;
};
class RealBookStore : public Subject
{
public:
	virtual void sellbook()
	{
		cout << "sell  book" << endl;
	}
};

//����������ʵ�������
//class DangDang : public Subject
//{
//public:
//	virtual void sellbook()
//	{
//		Subject *sub = new RealBookStore;
//		//RealBookStore *rb = new RealBookStore;
//		dazhe();
//		sub->sellbook();
//	}
//	void dazhe()
//	{
//		cout << "����" << endl;
//	}
//
//private:
//	 //Subject *m_sub;
//};

//��Ϸ�ʽ
class DangDang
{
public:
	DangDang()
	{
		m_sub = new RealBookStore;
	}
	void sellbook()
	{
		dazhe();
		m_sub->sellbook();
	}
	void dazhe()
	{
		cout << "����" << endl;
	}

private:
	 Subject *m_sub;
};


//void main1()
//{
//	Subject *s = new DangDang;
//	s->sellbook();
//	delete s;
//
//	system("pause");
//	return;
//}


void main()
{
	DangDang d;
	d.sellbook();
	
	system("pause");
}
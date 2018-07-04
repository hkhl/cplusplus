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

//当当网代理实体店卖书
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
//		cout << "打折" << endl;
//	}
//
//private:
//	 //Subject *m_sub;
//};

//组合方式
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
		cout << "打折" << endl;
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
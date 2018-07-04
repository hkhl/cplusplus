#include <iostream>
#include <string>
using namespace std;



//���� set  get ����
class House
{
public:
	void setDoor(string door)
	{
		this->m_door = door;
	}
	void setWall(string wall)
	{
		this->m_wall = wall;
	}
	void setWindow(string window)
	{
		this->m_window = window;
	}

	string getDoor()
	{
		cout << m_door << endl;
		return this->m_door;
	}
	string getWall()
	{
		cout << m_wall << endl;
		return this->m_wall;
	}
	string getWindow()
	{
		cout << m_window << endl;
		return this->m_window;
	}
protected:
private:
	string m_door;
	string m_wall;
	string m_window;
};



//���󹤳̶�
class Builder
{
public:
	virtual void buildWall() = 0;
	virtual void buildDoor() = 0;
	virtual void buildWindow() = 0;
	virtual House *getHouse() = 0;
};

//ʵ�ʹ��̶�  ���췿��
//��Ԣ���̶�
class FlatBuilder : public Builder
{
public:
	FlatBuilder()
	{
		m_house = new House;
	}
	virtual void buildWall()
	{
		m_house->setWall("flat wall");
	}			  

	virtual void buildDoor()
	{
		m_house->setDoor("flat door");
	}

	virtual void buildWindow()
	{
		m_house->setWindow("flat window");
	}

	virtual House *getHouse()
	{
		return m_house;
	}
private:
	House *m_house;
};

//�������̶�
class VillaBuilder : public Builder
{
public:
	VillaBuilder()
	{
		m_house = new House;
	}
	virtual void buildWall()
	{
		m_house->setWall("villa wall");
	}

	virtual void buildDoor()
	{
		m_house->setDoor("villa door");
	}

	virtual void buildWindow()
	{
		m_house->setWindow("villa window");
	}

	virtual House *getHouse()
	{
		return m_house;
	}
private:
	House *m_house;
};


//�ͻ��˸������ʦ����
//���ʦ ָ�Ӷ�Ӧ�Ĺ��̶ӽ���   ���Ҹ������߼�
class Director
{
public:
	Director(Builder *build)
	{
		m_build = build;
	}

	void Construct()
	{
		m_build->buildDoor();
		m_build->buildWall();
		m_build->buildWindow();
	}
private:
	Builder *m_build;
};

void main()
{
	House *house = NULL;
	Builder *build = NULL;
	Director *director = NULL;


	//��һ���������̶ӽ���
	build = new VillaBuilder;

	//���ʦָ�ӹ��̶�
	director = new Director(build);
	director->Construct();
	house = build->getHouse();
	house->getDoor();
	house->getWall();
	house->getWindow();
	delete house;
	delete build;


	//��һ����Ԣ���̶ӽ���
	build = new FlatBuilder;

	//���ʦָ�ӹ��̶�
	director = new Director(build);
	director->Construct();
	house = build->getHouse();
	house->getDoor();
	house->getWall();
	house->getWindow();

	delete house;
	delete build;

	delete director;
	system("pause");
}
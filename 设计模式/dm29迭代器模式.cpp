#include <iostream>
#include <string>
using namespace std;
typedef int Object;
#define SIZE 5

//������ģʽ���� ����stl������


//������������
class MyIterator
{
public:
	virtual void First() = 0;
	virtual void Next() = 0;
	virtual bool IsDone() = 0;
	virtual Object CurrentItem() = 0;
};

//���ϳ�����
class Aggregate
{
public:
	virtual Object getItem(int index) = 0;
	virtual int getSize() = 0;
	virtual MyIterator* getIterator() = 0;
};


//�����������
//��������Ӧ�ó���һ�����ϵ�ָ�루���ã����Դ�ͨ�����������ʼ���
class ContreteIterator : public MyIterator
{
public:
	ContreteIterator(Aggregate *ag)
	{
		_ag = ag;
		_current = 0;
	}
public:
	virtual void First()
	{
		_current = 0;
	}
	virtual void Next()
	{
		if (_current < _ag->getSize())
			_current++;
	}
	virtual bool IsDone()
	{
		return _current == _ag->getSize();
	}
	virtual Object CurrentItem()
	{
		return _ag->getItem(_current);
	}

private:
	//��ǰλ�ã��Լ�����
	int			_current;
	Aggregate*	_ag;
};

//���弯����
class ContreteAggregate : public Aggregate
{
public:
	ContreteAggregate()
	{
		for (int i = 0; i < SIZE; i++)
		{
			object[i] = i + 1;
		}
	}
public:
	virtual Object getItem(int index)
	{
		return object[index];
	}
	virtual int getSize()
	{
		return SIZE;
	}
	virtual MyIterator* getIterator()
	{
		return new ContreteIterator(this);
	}
private:
	Object 	object[SIZE];
};

void main()
{
	Aggregate *arr = new ContreteAggregate;
	MyIterator* it = arr->getIterator();
	

	for (; !(it->IsDone()) ; it->Next())
	{
		cout << it->CurrentItem() << " ";
	}

	delete it;
	delete arr;
	cout << endl;
	system("pause");
}

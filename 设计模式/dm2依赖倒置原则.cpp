#include <iostream>
using namespace std;


//���� cpu Ӳ�̵�
//��computer��ܺ� ���峧�� �����

class HardDisk
{
public:
	virtual void work() = 0;
};

class Memory
{
public:
	virtual void work() = 0;
};

class Cpu
{
public:
	virtual void work() = 0;
};


class Computer
{
public:
	Computer(HardDisk *harddisk, Memory *memory, Cpu *cpu)
	{
		m_harddisk = harddisk;
		m_memory = memory;
		m_cpu = cpu;
	}
	//HardDisk
	//Memory
	//Cpu
public:
	void work()
	{
		m_harddisk->work();
		m_memory->work();
		m_cpu->work();
	}
protected:
private:              //������
	HardDisk *m_harddisk;
	Memory *m_memory;
	Cpu *m_cpu;
};


class InterCpu : public Cpu
{
public:
	void work()
	{
		cout << "����inter CPU" << endl;
	}
};

class XSDisk : public HardDisk
{
public:
	void work()
	{
		cout << "����XSӲ��" << endl;
	}
};

class MMM : public Memory
{
public:
	void work()
	{
		cout << "����MMM�ڴ�" << endl;
	}
};

void main10()
{
	HardDisk *hard = NULL;
	Memory *mm = NULL;
	Cpu *cp = NULL;

	hard = new XSDisk;
	mm = new MMM;
	cp = new InterCpu;


	//��װ����
	Computer *mycompute = new Computer(hard, mm, cp);
	mycompute->work();

	//�ͷ��ڴ�
	delete cp;
	delete mm;
	delete hard;

	system("pause");
}
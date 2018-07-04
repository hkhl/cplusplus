#include <iostream>
using namespace std;


//电脑 cpu 硬盘等
//让computer框架和 具体厂商 解耦合

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
private:              //类的组合
	HardDisk *m_harddisk;
	Memory *m_memory;
	Cpu *m_cpu;
};


class InterCpu : public Cpu
{
public:
	void work()
	{
		cout << "我是inter CPU" << endl;
	}
};

class XSDisk : public HardDisk
{
public:
	void work()
	{
		cout << "我是XS硬盘" << endl;
	}
};

class MMM : public Memory
{
public:
	void work()
	{
		cout << "我是MMM内存" << endl;
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


	//组装电脑
	Computer *mycompute = new Computer(hard, mm, cp);
	mycompute->work();

	//释放内存
	delete cp;
	delete mm;
	delete hard;

	system("pause");
}
#include <iostream>
using namespace std;

//����Ա��ҵ��
class BankWorker
{
public:
	void save()
	{
		cout << "���" << endl;
	}
	void moveM()
	{
		cout << "ת��" << endl;
	}

	void jiaofei()
	{
		cout << "����" << endl;
	}
protected:
private:
};



//����BankWorker��⣬  ���Ϊһ�����������������
//���麯�������ǳ�����
class AbBankWorker
{
public:
	virtual void dothing() = 0;
};

//ҵ��Ա
class SaveBanker : public AbBankWorker
{
public:
	virtual void dothing()
	{
		cout << "���1" << endl;
	}
protected:
private:
};

class MoveBanker : public AbBankWorker
{
public:
	virtual void dothing()
	{
		cout << "ת��" << endl;
	}
protected:
private:
};

class JiaofeiBanker : public AbBankWorker
{
public:
	virtual void dothing()
	{
		cout << "����" << endl;
	}
protected:
private:
};



//���  ��������� ִ�и��ຯ�� 
//	    ��������� ִ�����ຯ��
void  howdo(AbBankWorker *bw)
{
	bw->dothing();
}


class pichuli : public MoveBanker
{
public:
	virtual void dothing()
	{
		cout << "������ת��" << endl;
	}
protected:
private:
};


void main01()
{
	/*����Ա���� һ��Ա���ɶ���ҵ�� ��*/
	/*һ��Ա��ֻ��һ��ҵ���ҵ��Ա ��*/

	//�������µĹ��ܣ� ��Ҫ�޸�ԭ���룬 ����ȡ
	//���������
	BankWorker *bw = new BankWorker;
	bw->jiaofei();
	bw->moveM();
	bw->save();
	getchar();
}

void main02()
{
	//��̬ ����ָ��ָ���������
	//AbBankWorker *bw = new MoveBanker;
	AbBankWorker *bw = NULL;
	bw = new MoveBanker;
	howdo(bw);
	delete bw;
	
	bw = new SaveBanker;
	howdo(bw);
	delete bw;

	bw = new pichuli;
	howdo(bw);
	delete bw;
	return;
}


void main11()
{
	//main01();
	main02();
	system("pause");

	/*
	ָ�룺
		����ָ�����ָ���������  ��֮��
	����
		���������Ը�ֵ��������� ��֮����
	*/
}


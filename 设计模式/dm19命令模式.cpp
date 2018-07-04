#include <iostream>
using namespace std;


//ҽ������
class Doctor
{
public:
	void treat_eye()
	{
		cout << "�ۿ�" << endl;
	}
	void treat_nose()
	{
		cout << "�ǿ�" << endl;
	}
};

class CommandTreatEye
{
public:
	CommandTreatEye(Doctor *doctor)
	{
		m_doctor = doctor;
	}

	void treat()
	{
		m_doctor->treat_eye();
	}

private:
	Doctor *m_doctor;
};


class CommandTreatNose
{
public:
	CommandTreatNose(Doctor *doctor)
	{
		m_doctor = doctor;
	}

	void treat()
	{
		m_doctor->treat_nose();
	}
private:
	Doctor *m_doctor;
};




void main01()
{
	//1  ҽ��ֱ�ӿ���  ����ȡ
	Doctor *doctor = new Doctor;
	doctor->treat_eye();
	doctor->treat_nose();
	delete doctor;
}


//ͨ������ģʽ
void main02()
{
	Doctor *doctor = new Doctor;
	CommandTreatEye *comte = new CommandTreatEye(doctor);
	comte->treat();
	delete comte;

	CommandTreatNose *comtn = new CommandTreatNose(doctor);
	comtn->treat();
	delete comtn;

	delete doctor;
}
void main()
{
	main01();  //��϶�̫��

	main02();


	system("pause");
}
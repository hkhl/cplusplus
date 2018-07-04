#include <iostream>
#include <list>
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


////////��������
class Command
{
public:
	virtual void treat() = 0;
};

//��ʿ
class  Nurse
{
public:
	Nurse(Command *command)
	{
		m_command = command;
	}
	void  SubmittedCase() //�ύ������ �µ�����
	{
		m_command->treat();
	}
private:
	Command *m_command;
};


//��ʿ��  /�Ի�ʿ�ύ��������а�������
class HeadNurse
{
public:
	HeadNurse()
	{
		m_list.clear();
	}
	void setCommand(Command *command)
	{
		m_list.push_back(command);
	}
	void  SubmittedCase() //�ύ������ �µ�����
	{
		for (list<Command *>::iterator it = m_list.begin();
			it != m_list.end(); it++)
		{
			(*it)->treat();
		}
	}
private:
	list<Command *> m_list;
};



///////////////

class CommandTreatEye : public Command
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


class CommandTreatNose : public Command
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


//ͨ������ģʽ
void main001()
{
	Doctor *doctor = new Doctor;
	Command *comte = new CommandTreatEye(doctor);
	comte->treat();
	delete comte;

	Command *comtn = new CommandTreatNose(doctor);
	comtn->treat();
	delete comtn;

	delete doctor;
}

//��ʿ
void main002()
{
	Doctor *doctor = new Doctor;
	//Command *com = new CommandTreatNose(doctor);
	Command *com = new CommandTreatEye(doctor);
	Nurse *nurse = new Nurse(com);
	nurse->SubmittedCase();

	delete nurse;
	delete com;
	delete doctor;
}

//��ʿ��
void main003()
{

	Doctor *doctor = new Doctor;
	HeadNurse *headNurse = new HeadNurse();
	Command *com1 = new CommandTreatNose(doctor);
	Command *com2 = new CommandTreatEye(doctor);


	headNurse->setCommand(com1);
	headNurse->setCommand(com2);
	headNurse->SubmittedCase();

	delete com2;
	delete com1;
	delete headNurse;
	delete doctor;
}



void main()
{
	main003();


	system("pause");
}
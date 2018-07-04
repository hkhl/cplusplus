#include <iostream>
#include <string>
#include <list>
using namespace std;


//���ģʽ
//Ŀ¼��
//��һ�������϶���ʹ��һ���ԵĽӿ�


class IFile
{
public:
	virtual void			display() = 0;
	virtual	int				add(IFile *ifile) = 0;
	virtual	int				remove(IFile *ifile) = 0;
	virtual list<IFile *>*	getChild() = 0;
};
class File : public IFile
{
public:

	File(string name)
	{
		m_name = name;
	}
	virtual void display()
	{
		cout << m_name << endl;
	}
	virtual	int	add(IFile *ifile)
	{
		return -1;
	}
	virtual	int	remove(IFile *ifile)
	{
		return - 1;
	}
	virtual list<IFile *>* getChild()
	{
		return NULL;
	}

private:
	string m_name;
};

class Dir : public IFile
{
public:

	Dir(string name)
	{
		m_name = name;
		//ָ����� ��Ҫnew����
		m_list = new list<IFile	*>;       //ÿ��һ������ Ҫ�´���һ������list��������Ŀ¼
		m_list->clear();
	}
	virtual void display()
	{
		cout << m_name << endl;
	}
	virtual	int	add(IFile *ifile)
	{
		m_list->push_back(ifile);
		return 0;
	}
	virtual	int	remove(IFile *ifile)
	{
		m_list->remove(ifile);
		return 0;
	}
	virtual list<IFile *>* getChild()
	{
		return m_list;
	}

private:
	string m_name;
	list<IFile *>* m_list;
};



//��ӡĿ¼��  
//�ݹ��ӡ�Ĺ���

/*
	0. begin
	1.��ӡ����
	2.������ļ� 4  
	3.�����Ŀ¼�к��� 0
	4.�޺��� 4
	4.end
*/

void PrintDir(IFile *root, int level)
{
	if (root == NULL)
		return;

	root->display();
	//�洢��ǰ��Ŀ¼���м���Ŀ¼
	list<IFile *> *mlist = root->getChild();

	if (mlist == NULL)
		return;

	//����ÿ��Ŀ¼�� ȷ���Ƿ�ݹ�
	for (list<IFile *>::iterator it = mlist->begin(); 
					it != mlist->end(); it++)
	{
		if ((*it)->getChild() == NULL)
		{  //�ļ�
			for (int i = 0; i <= level; i++)
			{
				cout << "     ";
			}
			(*it)->display();
		}
		else
		{	//Ŀ¼
			PrintDir((*it), level++);
		}
	}
}
void main()
{
	/*
	
		c----
			|--dir1
			|
			|--dir2---
					 |--text1
					 |
					 |--text2
	
	*/
	IFile *root = new Dir("C");
	Dir *dir1 = new Dir("dir1");
	Dir *dir2 = new Dir("dir2");
	File *file1 = new File("text1");
	File *file2 = new File("text2");

	root->add(dir1);
	root->add(dir2);
	dir2->add(file1);
	dir2->add(file2);

	PrintDir(root, 0);

	//delete *
	system("pause");
}
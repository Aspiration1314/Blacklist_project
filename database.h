#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include"blacklist.h"
#include"mdatabase.h"
#include"control.h"
using namespace std;
//string pathName = "d:/blacklist_management.txt";
class Database
{
public:
	static Database* getBase()
	{
		if (NULL == _Base)
		{
			_Base = new Database();
		}
		return _Base;
	}
	// ��
	void add();
	
	// ɾ
	void del();

	// ��
	void update();

	// �� by id
	void find();

	//��ʾ����
	void show();


	//save to file
	void save();


	// read from file
	void read();
private:
	Database()
	{

	}
	static Database* _Base;
	
	static map<int, Blacklist> m1;

	friend class Mdatabase;
};

Database* Database::_Base = NULL;
map<int, Blacklist> Database::m1 = map<int, Blacklist>();

//��
void Database::add()
{
	Mdatabase mbla;
	int id;
	string name;
	Blacklist bla;
	system("cls");
	cout << "���\n";
	cout << "id:";
	cin >> id;
	cout << "name:";
	cin >> name;
	bla.setId(id);
	bla.setName(name);
	mbla.add(m1,bla);
}
//ɾ
void Database::del()
{
	system("cls");
	cout << "������Ҫɾ����ѧ����id" << endl;
	int id;
	cin >> id;
	Mdatabase mbla;
	bool b = mbla.del(m1,id);

	if (b)
	{
		cout << "ɾ���ɹ�" << endl;
	}
	else {
		cout << "���޴���" << endl;
	}

	system("pause");
	system("cls");

}
//��
void Database::update()
{
	system("cls");

	cout << "������Ҫ�޸ĵ�ѧ����id" << endl;
	int id;
	cin >> id;
	string name;

	cout << "name:";
	cin >> name;

	int age;
	cout << "age:";
	cin >> age;


	Blacklist bla;
	bla.setId(id);
	bla.setName(name);
	Mdatabase mbla;
	Blacklist bla1 = mbla.update(m1,bla);



	if (bla1.getId() != -1)
	{
		cout << bla1 << endl;
		cout << "�޸ĳɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}

	system("pause");
	system("cls");
}
//��
void Database::find()
{

	system("cls");
	cout << "������Ҫ�����ο͵�id" << endl;
	int id;
	cin >> id;
	Mdatabase mbla;
	Blacklist bla;
	bla = mbla.find(m1,id);


	if (bla.getId() != -1)
	{
		cout << bla << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}

	system("pause");
	system("cls");

}
//��ʾ����
void Database::show()
{
	system("cls");
	cout << "id    |" << "name  |" << "age" << endl;
	Mdatabase mbla;
	mbla.show(m1);

	system("pause");
	system("cls");

}
//save to file
void Database::save()
{
	if (m1.begin() == m1.end())
	{
		system("cls");
		cout << "��û���κ��ο���Ϣ���޷�����" << endl;
	}
	else
	{
		// ����
		Mdatabase mbla;
		bool b = mbla.save(m1);

		if (b)
		{
			system("cls");
			cout << "����ɹ�" << endl;
		}
		else
		{
			cout << "����ʧ��" << endl;
		}
	}

	system("pause");
	system("cls");

}

// read from file
void Database::read()
{
	system("cls");
	Mdatabase mbla;
	bool b = mbla.read(m1);

	if (b)
	{
		cout << "��ȡ�ɹ�" << endl;
	}
	else
	{
		cout << "��ȡʧ��" << endl;
	}
	system("pause");
	system("cls");

}
#endif;
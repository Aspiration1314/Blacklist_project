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
	// 增
	void add();
	
	// 删
	void del();

	// 改
	void update();

	// 查 by id
	void find();

	//显示所有
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

//增
void Database::add()
{
	Mdatabase mbla;
	int id;
	string name;
	Blacklist bla;
	system("cls");
	cout << "添加\n";
	cout << "id:";
	cin >> id;
	cout << "name:";
	cin >> name;
	bla.setId(id);
	bla.setName(name);
	mbla.add(m1,bla);
}
//删
void Database::del()
{
	system("cls");
	cout << "请输入要删除的学生的id" << endl;
	int id;
	cin >> id;
	Mdatabase mbla;
	bool b = mbla.del(m1,id);

	if (b)
	{
		cout << "删除成功" << endl;
	}
	else {
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");

}
//改
void Database::update()
{
	system("cls");

	cout << "请输入要修改的学生的id" << endl;
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
		cout << "修改成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");
}
//查
void Database::find()
{

	system("cls");
	cout << "请输入要查找游客的id" << endl;
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
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");

}
//显示所有
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
		cout << "还没有任何游客信息，无法保存" << endl;
	}
	else
	{
		// 保存
		Mdatabase mbla;
		bool b = mbla.save(m1);

		if (b)
		{
			system("cls");
			cout << "保存成功" << endl;
		}
		else
		{
			cout << "保存失败" << endl;
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
		cout << "读取成功" << endl;
	}
	else
	{
		cout << "读取失败" << endl;
	}
	system("pause");
	system("cls");

}
#endif;
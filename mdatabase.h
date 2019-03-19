#ifndef C_STUDENT_MG_H
#define C_STUDENT_MG_H
#include "blacklist.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#define pathName "d:/blacklist_management.txt"
//string pathName = "d:/blacklist_management.txt";
class Mdatabase
{
public:
	Mdatabase();
	~Mdatabase();

	// 增
	Blacklist add(map<int, Blacklist> & m1, Blacklist & bla);

	// 删
	bool del(map<int, Blacklist> & m1, const int & id);

	// 改
	Blacklist update(map<int, Blacklist> & m1, const Blacklist & bla);

	// 查 by id
	Blacklist find(const map<int, Blacklist> & m1, const int & id) const;


	// showAll
	void show(const map<int, Blacklist> & m1) const;

	//save to file
	bool save(const map <int, Blacklist> & m1) const;

	// read from file
	bool read(map<int, Blacklist> & m1);


private:

};


Mdatabase::Mdatabase()
{
}

Mdatabase::~Mdatabase()
{
}

// 增
Blacklist Mdatabase::add(map<int, Blacklist> & m1, Blacklist & bla)
{

	// 先假设id可以重复了
	m1.insert(make_pair(bla.getId(), bla));
	return bla;
}

// 删
bool Mdatabase::del(map<int, Blacklist> & m1, const int & id)
{

	bool b = false;

	map<int, Blacklist> ::iterator iter;
	iter = m1.find(id);
	if (iter != m1.end())
	{
		m1.erase(iter);
		b = true; // 删除成功
	}

	return b;
}

// 改
Blacklist Mdatabase::update(map<int, Blacklist> & m1, const Blacklist & bla)
{

	// 迭代器是一个smart point！
	// 是可以通过迭代器去访问到 m1里的东西，并且做出修改的！
	// 除非迭代器是const迭代器

	Blacklist bla1;
	int id = bla.getId();

	map<int, Blacklist> ::iterator iter;
	iter = m1.find(id);
	if (iter != m1.end())
	{
		// 修改
		iter->second = bla;
		bla1 = bla; // 把修改后的对象，赋值，再返回上层
	}

	return bla1;
}

// 查 by id
Blacklist Mdatabase::find(const map<int, Blacklist> & m1, const int & id)const
{

	Blacklist stu;

	map<int, Blacklist> ::const_iterator iter;
	iter = m1.find(id);
	if (iter != m1.end())
	{
		stu = iter->second;
	}

	return stu;
}

// showAll
void Mdatabase::show(const std::map<int, Blacklist> & m1)const
{
	for (auto p : m1)
	{
		cout << p.second << endl;
	}
}

//save to file
bool Mdatabase::save(const map <int, Blacklist> & m1)const
{

	bool b = true;

	//fstream ofs(pathName,ios::out+ios::binary); // 为什么不是以binary保存？
	fstream ofs("d:/blacklist_management.txt", ios::out);
	if (ofs) 
	{
		stringstream ss;

		cout << "文件打开" << endl;

		Blacklist stu;
		for (auto p = m1.begin(); p != m1.end(); p++)
		{
			stu = p->second;
			ss << stu << endl;
		}

		ofs << ss.str(); // 注意，输出一定是 ss.str();

		ofs.close();
	}
	else
	{
		cout << "文件打开失败" << endl;
		b = false;
	}

	return b;
}


// read from file
bool Mdatabase::read(map<int, Blacklist> & m1)
{
	bool b = true;

	m1.clear(); // 清掉原来的

	fstream ifs(pathName, ios::in);
	if (ifs) 
	{
		cout << "文件打开" << endl;
		string s;
		stringstream ss;
		while (getline(ifs, s)) // 怎么一行行地读取？
		{
			Blacklist bla;
			ss << s;
			// cout<<ss.str();
			ss >> bla;
			ss.clear();

			m1.insert(make_pair(bla.getId(), bla));

		}

		ifs.close();

	}
	else 
	{
		cout << "文件打开失败" << endl;
		b = false;
	}

	return b;
}



#endif

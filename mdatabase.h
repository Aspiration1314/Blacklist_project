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

	// ��
	Blacklist add(map<int, Blacklist> & m1, Blacklist & bla);

	// ɾ
	bool del(map<int, Blacklist> & m1, const int & id);

	// ��
	Blacklist update(map<int, Blacklist> & m1, const Blacklist & bla);

	// �� by id
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

// ��
Blacklist Mdatabase::add(map<int, Blacklist> & m1, Blacklist & bla)
{

	// �ȼ���id�����ظ���
	m1.insert(make_pair(bla.getId(), bla));
	return bla;
}

// ɾ
bool Mdatabase::del(map<int, Blacklist> & m1, const int & id)
{

	bool b = false;

	map<int, Blacklist> ::iterator iter;
	iter = m1.find(id);
	if (iter != m1.end())
	{
		m1.erase(iter);
		b = true; // ɾ���ɹ�
	}

	return b;
}

// ��
Blacklist Mdatabase::update(map<int, Blacklist> & m1, const Blacklist & bla)
{

	// ��������һ��smart point��
	// �ǿ���ͨ��������ȥ���ʵ� m1��Ķ��������������޸ĵģ�
	// ���ǵ�������const������

	Blacklist bla1;
	int id = bla.getId();

	map<int, Blacklist> ::iterator iter;
	iter = m1.find(id);
	if (iter != m1.end())
	{
		// �޸�
		iter->second = bla;
		bla1 = bla; // ���޸ĺ�Ķ��󣬸�ֵ���ٷ����ϲ�
	}

	return bla1;
}

// �� by id
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

	//fstream ofs(pathName,ios::out+ios::binary); // Ϊʲô������binary���棿
	fstream ofs("d:/blacklist_management.txt", ios::out);
	if (ofs) 
	{
		stringstream ss;

		cout << "�ļ���" << endl;

		Blacklist stu;
		for (auto p = m1.begin(); p != m1.end(); p++)
		{
			stu = p->second;
			ss << stu << endl;
		}

		ofs << ss.str(); // ע�⣬���һ���� ss.str();

		ofs.close();
	}
	else
	{
		cout << "�ļ���ʧ��" << endl;
		b = false;
	}

	return b;
}


// read from file
bool Mdatabase::read(map<int, Blacklist> & m1)
{
	bool b = true;

	m1.clear(); // ���ԭ����

	fstream ifs(pathName, ios::in);
	if (ifs) 
	{
		cout << "�ļ���" << endl;
		string s;
		stringstream ss;
		while (getline(ifs, s)) // ��ôһ���еض�ȡ��
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
		cout << "�ļ���ʧ��" << endl;
		b = false;
	}

	return b;
}



#endif

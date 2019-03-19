#ifndef BLACKLIST_H
#define BLACKLIST_H
#include <iostream>
#include <string>
using namespace std;

class Blacklist
{
	/* friend function */
	friend ostream & operator<<(ostream & os, Blacklist & bla);
	friend istream & operator>>(istream & is, Blacklist & bla);

public:

	Blacklist();
	~Blacklist();

	int getId() const;
	void setId(int val);

	string getName() const;
	void setName(string val);

private:

	int _id;
	string _name;
	string _date;
	string _event;
	string _limit;

};

// 游客默认id是-1，说明这暂时是一个无效的游客。
Blacklist::Blacklist(){ this->_id = -1; }
Blacklist::~Blacklist(){}


int Blacklist::getId() const { return _id; }
void Blacklist::setId(int val) { _id = val; }

string Blacklist::getName() const { return _name; }
void Blacklist::setName(string val) { _name = val; }


ostream & operator<<(ostream & os, Blacklist &bla)
{
	os << bla.getId() << "     " << bla.getName();
	return os;
}

istream & operator>>(istream & is, Blacklist & bla)
{
	is >> bla._id >> bla._name;
	return is;
}
#endif
#ifndef SYS_H
#define SYS_H
#include<iostream>
#include <string>
#include<iomanip>
#include<map>
#include"Control.h"

#define NULL 0
using namespace std;

class Sys
{
public:
	Sys(){};
	string getusrname() const;
	void setusrname(string val);
	string getpsword() const;
	void setpsword(string val);

	void handle();
	Sys add(map<string, Sys> & m1, Sys & usr);
	void enroll();
	void login();
private:
	Control control;
	string usrname;
	string psword;
	map<string, Sys> musr;
};
string Sys::getusrname() const { return usrname; }
void Sys::setusrname(string val) { usrname = val; }
string Sys::getpsword() const{ return psword; }
void Sys::setpsword(string val){ psword = val; }
Sys add(map<string, Sys> & musr, Sys & usr)
{
	musr.insert(make_pair(usr.getusrname(), usr));
	return usr;
}
void Sys::enroll()
{
	Sys usr;
	system("cls");

	cout << "×¢²á\n";
	cout << "usrname:";
	cin >> usrname;

	cout << "psword:";
	cin >> psword;

	usr.setusrname(usrname);
	usr.setpsword(psword);

	musr.insert(make_pair(usr.getusrname(), usr));
	musr.insert(make_pair(usr.getpsword(), usr));
	system("cls");
}
void Sys::login()
{
	cout << "µÇÂ¼\n";
	string usrname;
	cin >> usrname;
	int count = 0;
	while (count<3)
	{
		count++;
		if (musr.count(usrname) > 0)
		{
			cout << "login succeed" << endl;
			control.process();
		}
		else
		{
			cout << "your psword is not true!please input again:";
			cin >> usrname;
			continue;
		}
	}
	cout << "login fail" << endl;
	system("cls");
}

void Sys::handle(){
	Sys X;
	cout << "welcome to the user of blacklist,please input choice:" << endl
		<< "input 0 : quit" << endl
		<< "1.**********enroll" << endl << "2.**********login" << endl
		<< "3.**********update" << endl;
	while (true){
		int choice;
		cout << "please input choice: " << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			X.enroll(); break;
		case 2:
			X.login(); break;
		case 0:
			break;
		default:
			cout << "sorry!system is improving!^-^" << endl; break;
		}
		if (!choice) break;
	}
}



#endif




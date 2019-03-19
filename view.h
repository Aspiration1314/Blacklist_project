#ifndef VIEW_H
#define VIEW_H
#include <iostream>
#include <map>
#include <string>
#include"database.h"
using namespace std;
class View
{
public:
	virtual void myView()
	{}
};
class addView :public View
{
public:
	addView(){};
	void myView()
	{
		Database::getBase()->add();
	}
private:
	
};
class delView :public View
{
public:
	delView(){};
	void myView()
	{
		Database::getBase()->del();
	}
private:
	
};

class updateView :public View
{
public:
	updateView(){};
	void myView()
	{
		Database::getBase()->update();
	}
private:
	
};
class findView :public View
{
public:
	findView(){};
	void myView()
	{
		Database::getBase()->find();
	}
private:
	

};
class showView :public View
{
public:
	showView(){};
	void myView()
	{
		Database::getBase()->show();
	}
private:
	

};
class saveView :public View
{
public:
	saveView(){};
	void myView()
	{
		Database::getBase()->save();
	}
private:
	
};
class readView :public View
{
public:
	readView(){};
	void myView()
	{
		Database::getBase()->read();
	}
private:
	
};
#endif
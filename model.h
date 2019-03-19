#ifndef MODEL_H
#define MODEL_H
#include<iostream>
#include<string>
#include<assert.h>
#include<map>
#include"View.h"

using namespace std;

class Model
{
public:
	Model();
	map<int, View*> create()
	{
		_model.insert(make_pair(1, &addView));
		_model.insert(make_pair(2, &delView));
		_model.insert(make_pair(3, &updateView));
		_model.insert(make_pair(4, &findView));
	    _model.insert(make_pair(5, &showView));
		_model.insert(make_pair(6, &saveView));
		_model.insert(make_pair(7, &readView));
		return _model;
	}

private:
	static map<int, View*> _model;
	addView addView;
	delView delView;
	updateView updateView;
	findView findView;
	showView showView;
	saveView saveView;
	readView readView;
};
Model::Model()
{

}
map<int, View*> Model::_model = map<int, View*>();
#endif
#ifndef CONTROL_H
#define CONTROL_H
#include<iostream>
#include"model.h"
#include<map>
#include<string>
using namespace std;

class Control
{
public:
	Control();
	void welcome() {
		system("cls");
		cout << "欢迎来到游客黑名单系统" << endl;
	}

	/* 显示菜单 */
	void Menu() {

		cout << "\n";
		cout << "请输入您的选择" << endl;

		cout << "1. 添加" << endl;
		cout << "2. 删除" << endl;
		cout << "3. 修改" << endl;
		cout << "4. 查找" << endl;
		cout << "5. 显示所有" << endl;
		cout << "6. 保存至文件" << endl;
		cout << "7. 从文件导入" << endl;
		cout << "0. 退出" << endl;
		cout << "\n";

		cout << "\n";
		cout << "请选择操作：";
	}

	void process()
	{
		while (1)
		{
			//string pathName = "d:/blacklist_management.txt";
			
			welcome();
			Menu();

			int choice;
			cin >> choice;
			
			if (choice == 0)
			{
				exit(0);
			}
			_map = _model.create();
			/*for (map<int, View*>::iterator it = _map.begin(); it != _map.end(); it++)
			{
				cout <<it->first<<" " <<it->second<< endl;
			}
			system("pause");*/
			_map[choice]->myView();
			system("cls");
		}

	}
private:

	Model _model;
	map<int, View*> _map;


};
Control::Control()
{

}

#endif







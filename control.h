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
		cout << "��ӭ�����οͺ�����ϵͳ" << endl;
	}

	/* ��ʾ�˵� */
	void Menu() {

		cout << "\n";
		cout << "����������ѡ��" << endl;

		cout << "1. ���" << endl;
		cout << "2. ɾ��" << endl;
		cout << "3. �޸�" << endl;
		cout << "4. ����" << endl;
		cout << "5. ��ʾ����" << endl;
		cout << "6. �������ļ�" << endl;
		cout << "7. ���ļ�����" << endl;
		cout << "0. �˳�" << endl;
		cout << "\n";

		cout << "\n";
		cout << "��ѡ�������";
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







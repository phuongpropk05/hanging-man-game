#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Menu
{
private:
	string name;
	string description;
	vector<Menu*> subMenu;
	int action;
public:
	Menu();
	Menu(string name, string description, int action = -1);
	~Menu();
	void setName(string name);
	void setDescription(string description);
	//void setSubMenu(vector<Menu> subMenu);
	void setAction(int action);
	string getName();
	string getDescription();
	int getAction();
	void displayMenu();
	void addSubMenu(Menu* m);
	int promtOption();
	Menu* getSubMenu(int index);
};


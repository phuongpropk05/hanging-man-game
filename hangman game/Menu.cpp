#include "Menu.h"

Menu::Menu()
{
	name = "";
	description = "";
	subMenu.clear();
	action = -1;
}

Menu::Menu(string name, string description, int action)
{
	this->name = name;
	this->description = description;
	this->action = action;
	this->subMenu.clear();
}

Menu::~Menu()
{
	if (!subMenu.empty()) {
		for (int i = 0; i < subMenu.size(); i++) {
			if (subMenu[i]) {
				delete subMenu[i];
			}
		}
		subMenu.clear();
	}
}

void Menu::setName(string name)
{
	this->name = name;
}

void Menu::setDescription(string description)
{
	this->description = description;
}

void Menu::setAction(int action)
{
	this->action = action;
}

string Menu::getName()
{
	return name;
}

string Menu::getDescription()
{
	return description;
}

int Menu::getAction()
{
	return action;
}

void Menu::displayMenu()
{
	cout << "\t\t\t" << name << "\t\t\t" << endl;
	cout << description << endl;
	for (int i = 0; i < subMenu.size(); i++) {
		cout << i + 1 << "." << subMenu[i]->getName() << endl;
	}
}

void Menu::addSubMenu(Menu* m)
{
	this->subMenu.push_back(m);
}

int Menu::promtOption()
{
	while (true) {
		cout << "Pick an option: ";
		int option;
		cin >> option;
		try {
			if (cin.fail()) {
				throw "Invalid input";
				cin.ignore();
			}
			else if (option < 1 || option > subMenu.size()) {
				throw "Menu out of range";
			}
			else {
				return option;
			}
		}
		catch (const char* error) {
			cin.ignore();
			cin.clear();
			cout << "Error: " << error << endl;
		}
	}
}

Menu* Menu::getSubMenu(int index)
{
	if (index > 0 && index <= subMenu.size()) {
		index--;
		return subMenu[index];
	}
	else {
		return NULL;
	}
}

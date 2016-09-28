#ifndef MENU_H
#define MENU_H

#include "Student.h"
#include "List.h"
class Menu {
public:
	List a;
	void listmenu();
	void modifymenu();
	void searchmenu();
	void sortmenu(int);
	int main1();
};
#endif

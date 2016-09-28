#ifndef MENU_H
#define MENU_H

#include"Student_management_model.h"
#include"Student_management_controller.h"
class Menu {
public:
	List a;
	void listmenu();
	void modifymenu();
	void searchmenu();
	void sortmenu(int);
	int main_menu();
};
#endif

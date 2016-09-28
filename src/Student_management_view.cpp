#include<iostream>
#include<string>
#include<fstream>
#include"Student_management_model.h"
#include"Student_management_controller.h"
#include"Student_management_view.h"

using namespace std;

void Menu::listmenu() {
	int select;
	cout << "\n1.Enter by keyboard.";
	cout << "\n2.Get from file.";
	cout << "\n3.Back.\n";
	cin >> select;
	if (select <= 3)
		switch (select)
		{
		case 1: {
			cout << "\n Enter number of student.\n";
			cout << "n = ";
			cin >> a.m;
			a.CreateList1(a.m); break; }
		case 2: a.CreateList2(); break;
		case 3: main_menu(); break;
		}
	else {
		cout << "Error. Please try again.";
		listmenu();
	}
}

void Menu::modifymenu() {
	int select;
	cout << "\nDo you want to add, modify or delete a student? Please remember its id.";
	cout << "\n1. Yes I want to modify a student.";
	cout << "\n2. Yes I want to delete a student.";
	cout << "\n3. Yes I want to add a student.";
	cout << "\n4. No\n";
	cin >> select;
	if (select <= 4)
		switch (select)
		{
		case 1: a.modify(); main_menu(); break;
		case 2: a.del(); main_menu(); break;
		case 3: a.add(); main_menu(); break;
		case 4: main_menu(); break;
		}
	else {
		cout << "Error. Please try again.";
		modifymenu();
	}
}



void Menu::searchmenu() {
	int select;
	int s;
	cout << "\n1. Search by sum grade of 3 subject (mathematic, chemical, physical).";
	cout << "\n2. Search by id.";
	cout << "\n3. Search by name.";
	cout << "\n4. Search by grade of mathematic.";
	cout << "\n5. Search by grade of chemical.";
	cout << "\n6. Search by grade of physical.";
	cout << "\n7. Back to menu.\n";
	cin >> select;
	if (select <= 7)	
		switch (select)
		{
		case 1: sortmenu(s = 1); break;
		case 2: a.searchid(); break;
		case 3: a.searchname(); break;
		case 4: sortmenu(s = 4); break;
		case 5: sortmenu(s = 5); break;
		case 6: sortmenu(s = 6); break;
		case 7: main_menu(); break;

		}
	else { cout << "Error. Please try again.";
	searchmenu();
	}
}

void Menu::sortmenu(int s) {
	int select;
	cout << "\n1. Sort by id.";
	cout << "\n2. Sort by alphabet.";
	cout << "\n3. Sort by sum of grade.";
	cout << "\n4. Back.\n";
	cin >> select;
	if (select <= 3)
	{
		remove("output.txt");
		switch (s)
		{
		case 1: a.searchsum(select); break;
		case 4: a.searchmath(select); break;
		case 5: a.searchchem(select); break;
		case 6: a.searchphys(select); break;
		}
	}
	else
		if (select == 4) searchmenu();
		else
		{
			cout << "Error. Please try again.";
			sortmenu(s);
	}
}


int Menu::main_menu()
{
	int select;
	cout << "1. Creat student list. \n";
	cout << "2. Search.\n";
	cout << "3. Modify a student.\n";
	cout << "4. Get student list.\n";
	cout << "5. Exit.\n";
	cin >> select;
	while (select <= 5)
	{
		switch (select)
		{
		case 1: listmenu(); break;
		case 2: searchmenu(); break;
		case 3: modifymenu(); break;
		case 4: a.printList(); main_menu(); break;
		case 5: break;
		}
	}
	return 0;
}
#ifndef LIST_H
#define LIST_H
#include "Student_management_model.h"
class List {
public:
	int *n;
	int m=0;
	Student *st[];
	void CreateList1(int);
	void CreateList2();
	void searchsum(int);
	void searchid();
	void searchname();
	void searchmath(int);
	void searchchem(int);
	void searchphys(int);
	void modify();
	void del();
	void add();
	void printList();
	void nosort(int*[]);
	void sortid(int*[]);
	void sortal(string*[]);
	void sortsum(float*[]);
	int check(int, int, string, string, string, float, float, float);
};
#endif

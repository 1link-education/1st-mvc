#include<iostream>
#include<string>
#include<fstream>
#include"StudentManagementModel.h"
#include"StudentManagementController.h"

using namespace std;
// i, j mặc định là các biến đếm.

void  controller::bykeyboard(int m) {
	n = &m;
	*n = m;
	int id = 0;
	string name;
	string address;
	string gender;
	float math = 0.0;
	float chem = 0.0;
	float phys = 0.0;
	//cout << "\n Enter number of student.\n";
	//cout << "n = ";
	//cin >> n;
	for (int j = 0; j < *n; j++) {
		st[j] = new Student;
		cout << "\nEnter student id: ";
		cin >> id;
		fflush(stdin);
		getline(std::cin, name);
		cout << "\nEnter student name: ";
		getline(std::cin, name);
		fflush(stdin);
		cout << "\nEnter student address: ";
		getline(std::cin, address);
		fflush(stdin);
		cout << "\nEnter student gender: ";
		getline(std::cin, gender);
		cout << "\nEnter math grade: ";
		cin >> math;
		cout << "\nEnter chemical grade: ";
		cin >> chem;
		cout << "\nEnter physical grade: ";
		cin >> phys;
		st[j]->SetSV(id, name, address, gender, math, chem, phys);
	}
	for (int i = 0; i < *n; i++)
		if (check(i, st[i]->id, st[i]->name, st[i]->address, st[i]->gender, st[i]->math, st[i]->chem, st[i]->phys) == 0)
		{
			cout << "\nEntered is failed. Please try again!";
			bykeyboard(*n);
		}
}
int  controller::check(int i, int _id, string _name, string _address, string _gender, float _math, float _chem, float _phys) {
	if (i == 0) return 1;
	else
	{

		for (int j = 0; j < i; j++)
			if (st[j]->id == _id || _math < 0.0 || _math > 10.0 || _chem <0.0 || _chem>10.0 || _phys< 0.0 || _phys>10.0)
			{
				return 0;
			}
		return 1;
	}
}

void  controller::byfile() {
	string filename;
	int i = 0;
	int id = 0;
	string name;
	string address;
	string gender;
	float math = 0.0;
	float phys = 0.0;
	float chem = 0.0;
	cout << "\n Enter file link:";
	//getline(std::cin, filename);
	cin >> filename;
	ifstream file(filename);
	while (!file.eof()) {
		st[i] = new Student;
		file >> id >> name >> address >> gender >> math >> phys >> chem;
		st[i]->SetSV(id, name, address, gender, math, chem, phys);
		i++;
		cout << "ID: " << id << "   Name: " << name << "    Address: " <<
			address << "   Gender: " << gender << "   Math: " << math
			<< "   Chemical: " << chem << "   Physical: " << phys << endl;
	}
	if (file.eof())
	{
		cout << "Read file successful, all data from file has already been here.";
	}
}

void  controller::sortid(int*K[]) {
	int *x;
	for (int j = 0; j < sizeof(K) / sizeof(int); j++)
	{
		int m = j;
		for (int t = j + 1; t < sizeof(K) / sizeof(int); t++)
		{
			if (*K[t] < *K[m]) m = j;
			if (j < m)
			{
				x = K[j];
				K[j] = K[m];
				K[m] = x;
			}
		}
	}
	for (int i = 0; i < *n; i++)
		for (int j = 0; j < sizeof(K); j++)
			if (controller::st[i]->id = *K[j])
				controller::st[i]->GetSV();
}

void  controller::sortal(string *A[]) {
	string *y;
	for (int j = 0; j < 50; j++)
	{
		int m = j;
		for (int t = j + 1; t < sizeof(A); t++)
		{
			if (*A[t] < *A[m]) m = j;
			if (j < m)
			{
				y = A[j];
				A[j] = A[m];
				A[m] = y;
			}
		}
	}
	for (int i = 0; i < *n; i++)
		for (int j = 0; j < sizeof(A); j++)
			if (controller::st[i]->name.compare(*A[j]))
				controller::st[i]->GetSV();
}
void  controller::sortsum(float *S[]) {
	float *z;
	for (int j = 0; j < sizeof(S); j++)
	{
		int m = j;
		for (int t = j + 1; t < sizeof(S); t++)
		{
			if (*S[t] < *S[m]) m = j;
			if (j < m)
			{
				z = S[j];
				S[j] = S[m];
				S[m] = z;
			}
		}
	}
	for (int i = 0; i < *n; i++)
		for (int j = 0; j < sizeof(S); j++)
			if (controller::st[i]->sum = *S[j])
				controller::st[i]->GetSV();
}
void  controller::searchsum(int k) {
	int j = 0;
	int **K = new int *[50]; // lưu sbd sinh viên K = key ~ id
	string  **A = new string *[50]; // lưu tên sinh viên A = ABC ~ name
	float **S = new float*[50]; // lưu tổng điểm sinh viên S = sum
	float key;
	cout << "\n Enter sum: ";
	cin >> key;
	bool check = 1;
	if (check = 1)
		for (int i = 0; i < *n; i++)
		{
			if (key = controller::st[i]->sum) {
				controller::st[i]->id = *K[j];
				controller::st[i]->name = *A[j];
				controller::st[i]->sum = *S[j];
				j++;
				check = 0;
			}
		}
	else
	{
		cout << "\nNo student found. Please try again!";
		controller::searchsum(k);
	}
	switch (k)
	{
	case 1:
		sortid(K);
		break;
	case 2:
		sortal(A);
		break;
	case 3:
		sortsum(S);
		break;
	}
}

void  controller::searchid() {
	int key;
	cout << "\nEnter id: ";
	cin >> key;
	bool check = 1;
	if (check = 1)
		for (int i = 0; i < *n; i++)
		{
			if (key = controller::st[i]->id) {
				controller::st[i]->GetSV();
				check = 0;
			}
		}
	else
	{
		cout << "\nNo student found. Please try again!";
		controller::searchid();
	}
}

void  controller::searchname() {
	string key;
	fflush(stdin);
	getline(std::cin, key);
	bool check = 1;
	if (check = 1)
		for (int i = 0; i < *n; i++)
		{
			if (key.compare(controller::st[i]->name)) {
				controller::st[i]->GetSV();
				check = 0;
			}
		}
	else
	{
		cout << "\nNo student found. Please try again!";
		controller::searchname();
	}
}

void  controller::searchmath(int k) {
	int j = 0;
	int i;
	int **K = new int *[50];
	string  **A = new string *[50];
	float **S = new float*[50];
	float key;
	cout << "\nEnter math grade: ";
	cin >> key;
	bool check = 1;
	if (check = 1)
		for (int i = 0; i < *n; i++)
			if (key = controller::st[i]->math) {
				controller::st[i]->id = *K[j];
				controller::st[i]->name = *A[j];
				controller::st[i]->sum = *S[j];
				j++;
				check = 0;
			}
			else
			{
				cout << "\nNo student found. Please try again!";
				controller::searchmath(k);
			}
	switch (k)
	{
	case 1:
		sortid(K);
		break;
	case 2:
		sortal(A);
		break;
	case 3:
		sortsum(S);
		break;
	}
}

void  controller::searchchem(int k) {
	int j = 0;
	int i;
	int **K = new int *[50];
	string  **A = new string *[50];
	float **S = new float*[50];
	float key;
	cout << "\nEnter chemical grade: ";
	cin >> key;
	bool check = 1;
	if (check = 1)
		for (int i = 0; i < *n; i++)
			if (key = controller::st[i]->chem) {
				controller::st[i]->id = *K[j];
				controller::st[i]->name = *A[j];
				controller::st[i]->sum = *S[j];
				j++;
				check = 0;
			}
			else
			{
				cout << "\nNo student found. Please try again!";
				controller::searchchem(k);
			}
	switch (k)
	{
	case 1:
		sortid(K);
		break;
	case 2:
		sortal(A);
		break;
	case 3:
		sortsum(S);
		break;
	}
}

void  controller::searchphys(int k) {
	int j = 0;
	int i;
	int **K = new int *[50];
	string  **A = new string *[50];
	float **S = new float*[50];
	float key;
	cout << "\nEnter physical grade: ";
	cin >> key;
	bool check = 1;
	if (check = 1)
		for (int i = 0; i < *n; i++)
			if (key = controller::st[i]->math) {
				controller::st[i]->id = *K[j];
				controller::st[i]->name = *A[j];
				controller::st[i]->sum = *S[j];
				j++;
				check = 0;
			}
			else
			{
				cout << "\nNo student found. Please try again!";
				controller::searchphys(k);
			}
	switch (k)
	{
	case 1:
		sortid(K);
		break;
	case 2:
		sortal(A);
		break;
	case 3:
		sortsum(S);
		break;
	}
}

void  controller::modify() {
	cout << "\nChoose id of student which need to modify.\nEnter it: ";
	int key;
	cin >> key;
	int id;
	string name;
	string address;
	string gender;
	float math;
	float chem;
	float phys;
	for (int k = 0; k <= *n; k++)
		if (key = controller::st[k]->id) {
			cout << "Enter student ip: ";
			cin >> id;
			fflush(stdin);
			getline(std::cin, name);
			cout << "\nEnter student name: ";
			getline(std::cin, name);
			fflush(stdin);
			cout << "\nEnter student address: ";
			getline(std::cin, address);
			fflush(stdin);
			cout << "\nEnter student gender: ";
			getline(std::cin, gender);
			cout << "\nEnter math grade: ";
			cin >> math;
			cout << "\nEnter chemical grade: ";
			cin >> chem;
			cout << "\nEnter physical grade: ";
			cin >> phys;
			controller::st[k]->SetSV(id, name, address, gender, math, chem, phys);
		}
	for (int i = 0; i < *n; i++)
		if (check(i, st[i]->id, st[i]->name, st[i]->address, st[i]->gender, st[i]->math, st[i]->chem, st[i]->phys) == 0)
		{
			cout << "\nEntered is failed. Please try again!";
			modify();
		}
}


void  controller::del() {
	cout << "\nEnter an id of student which you want to delete.\nEnter it: ";
	int key;
	cin >> key;
	for (int i = 0; i < *n; i++)
		if (controller::st[i]->id = key)
			delete  controller::st[i];
}

void  controller::add() {
	controller::st[*n + 1] = new Student;
	int key;
	cin >> key;
	int id;
	string name;
	string address;
	string gender;
	float math;
	float chem;
	float phys;
	cout << "Enter student ip: ";
	cin >> id;
	fflush(stdin);
	getline(std::cin, name);
	cout << "\nEnter student name: ";
	getline(std::cin, name);
	fflush(stdin);
	cout << "\nEnter student address: ";
	getline(std::cin, address);
	fflush(stdin);
	cout << "\nEnter student gender: ";
	getline(std::cin, gender);
	cout << "\nEnter math grade: ";
	cin >> math;
	cout << "\nEnter chemical grade: ";
	cin >> chem;
	cout << "\nEnter physical grade: ";
	cin >> phys;
	controller::st[*n + 1]->SetSV(id, name, address, gender, math, chem, phys);

	for (int i = 0; i < *n; i++)
		if (check(i, st[i]->id, st[i]->name, st[i]->address, st[i]->gender, st[i]->math, st[i]->chem, st[i]->phys) == 0)
		{
			cout << "\nEntered is failed. Please try again!";
			add();
		}
}

void  controller::printList() {
	for (int i = 0; i < *n; i++)
		st[i]->GetSV();
	return;
}


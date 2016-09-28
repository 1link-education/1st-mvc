#include<iostream>
#include<string>
#include<fstream>
#include"Student.h"
#include"List.h"

using namespace std;


void List::CreateList1(int m) {
	n = &m;
	*n = m;
	int id;
	string name;
	string address;
	string gender;
	float math;
	float chem;
	float phys;
	//cout << "\n Enter number of student.\n";
	//cout << "n = ";
	//cin >> n;
	for (int k = 0; k < *n; k++) {
		st[k] = new Student;
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
		st[k]->SetSV(id, name, address, gender, math, chem, phys);
	}
	for (int i = 0; i < *n; i++)
		if (check(i, st[i]->id, st[i]->name, st[i]->address, st[i]->gender, st[i]->math, st[i]->chem, st[i]->phys) == 0)
		{
			cout << "\nEntered is failed. Please try again!";
			CreateList1(*n);
		}
}
int List::check(int i, int _id, string _name, string _address, string _gender, float _math, float _chem, float _phys) {
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

void List::CreateList2() {
	string filename;
	int i = 0;
	int id;
	string name;
	string address;
	string gender;
	float math;
	float phys;
	float chem;
	cout << "\n Enter file link:";
	//getline(std::cin, filename);
	cin >> filename;
	ifstream file(filename);
	while (!file.eof()) {
		st[i] = new Student;
		file >> id >> name >> address >> gender >> math >> phys >> chem;
		st[i]->SetSV(id, name, address, gender, math, chem, phys);
		i++;
		cout << "ID: " << id << "   Name: " << name << "    Address: " << address << "   Gender: " << gender << "   Math: " << math << "   Chemical: " << chem << "   Physical: " << phys <<endl;
	}
	if (file.eof())
	{
		cout << "Read file successful, all data from file has already been here.";
	}
}

void List::nosort(int *K[]) {
	for (int i = 0; i < *n; i++)
		for (int j = 0; j < sizeof(K)/sizeof(int); j++)
			if (List::st[i]->id = *K[j])
				List::st[i]->GetSV();
}

void List::sortid(int*K[]) {
	int *x;
	int j;
	for ( j = 0; j < sizeof(K)/sizeof(int); j++)
	{
		int m = j;
		for (int t = j + 1; t < sizeof(K)/sizeof(int); t++)
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
			if (List::st[i]->id = *K[j])
				List::st[i]->GetSV();
}

void List::sortal(string *A[]) {
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
			if (List::st[i]->name.compare(*A[j]))
				List::st[i]->GetSV();
}
void List::sortsum(float *S[]) {
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
			if (List::st[i]->sum = *S[j])
				List::st[i]->GetSV();
}
void List::searchsum(int k) {
	int j = 0;
	int **K = new int *[50];
	string  **A = new string *[50];
	float **S = new float*[50];
	float key;
	cout << "\n Enter sum: ";
	cin >> key;
	bool check = 1;
	if (check = 1)
		for (int i = 0; i < *n; i++)
		{
			if (key = List::st[i]->sum) {
				List::st[i]->id = *K[j];
				List::st[i]->name = *A[j];
				List::st[i]->sum = *S[j];
				j++;
				check = 0;
			}
		}
	else
	{
		cout << "\nNo student found. Please try again!";
		List::searchsum(k);
	}
	switch (k)
	{
	case 0:
		nosort(K);
		break;
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

void List::searchid() {
	int key;
	cout << "\nEnter id: ";
	cin >> key;
	bool check = 1;
	if (check = 1)
		for (int i = 0; i < *n; i++)
		{
			if (key = List::st[i]->id) {
				List::st[i]->GetSV();
				check = 0;
			}
		}
	else
	{
		cout << "\nNo student found. Please try again!";
		List::searchid();
	}
}

void List::searchname() {
	string key;
	fflush(stdin);
	getline(std::cin, key);
	bool check = 1;
	if (check = 1)
		for (int i = 0; i < *n; i++)
		{
			if (key.compare(List::st[i]->name)) {
				List::st[i]->GetSV();
				check = 0;
			}
		}
	else
	{
		cout << "\nNo student found. Please try again!";
		List::searchname();
	}
}

void List::searchmath(int k) {
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
			if (key = List::st[i]->math) {
				List::st[i]->id = *K[j];
				List::st[i]->name = *A[j];
				List::st[i]->sum = *S[j];
				j++;
				check = 0;
			}
			else
			{
				cout << "\nNo student found. Please try again!";
				List::searchmath(k);
			}
	switch (k)
	{
	case 0:
		nosort(K);
		break;
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

void List::searchchem(int k) {
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
			if (key = List::st[i]->chem) {
				List::st[i]->id = *K[j];
				List::st[i]->name = *A[j];
				List::st[i]->sum = *S[j];
				j++;
				check = 0;
			}
			else
			{
				cout << "\nNo student found. Please try again!";
				List::searchchem(k);
			}
	switch (k)
	{
	case 0:
		nosort(K);
		break;
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

void List::searchphys(int k) {
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
			if (key = List::st[i]->math) {
				List::st[i]->id = *K[j];
				List::st[i]->name = *A[j];
				List::st[i]->sum = *S[j];
				j++;
				check = 0;
			}
			else
			{
				cout << "\nNo student found. Please try again!";
				List::searchphys(k);
			}
	switch (k)
	{
	case 0:
		nosort(K);
		break;
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

void List::modify() {
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
		if (key = List::st[k]->id) {
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
			List::st[k]->SetSV(id, name, address, gender, math, chem, phys);
		}
		for (int i = 0; i < *n; i++)
			if (check(i,st[i]->id, st[i]->name, st[i]->address, st[i]->gender, st[i]->math, st[i]->chem, st[i]->phys) == 0)
	{		cout << "\nEntered is failed. Please try again!";
			CreateList1(*n);
	}
}


void List::del() {
	cout << "\nEnter an id of student which you want to delete.\nEnter it: ";
	int key;
	cin >> key;
	for (int i = 0; i < *n; i++)
		if (List::st[i]->id = key)
			delete List::st[i];
}

void List::add() {
	List::st[*n + 1] = new Student;
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
	for (int j = 0; j <= *n; j++)
		if (id == st[j]->id) { cout << "This id was entered. Please try again."; cin >> id; }
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
	List::st[*n + 1]->SetSV(id, name, address, gender, math, chem, phys);

	for (int i = 0; i < *n; i++)
		if (check(i,st[i]->id, st[i]->name, st[i]->address, st[i]->gender, st[i]->math, st[i]->chem, st[i]->phys) == 0)
	{		cout << "\nEntered is failed. Please try again!";
	CreateList1(*n);
	}
}

void List::printList() {
	for (int i = 0; i < *n; i++)
		st[i]->GetSV();
}

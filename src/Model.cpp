#include<iostream>
#include<string>
#include<fstream>
#include<ostream>
#include"MODEL.h"

using namespace std;

void Student::SetSV(int _id, string _name, string _address, string _gender, float _math, float _chem, float _phys) {
	id = _id;
	name = _name;
	address = _address;
	gender = _gender;
	math = _math;
	chem = _chem;
	phys = _phys;
}

void Student::GetSV() {
	cout << "Id: " << id << endl;
	cout << "Name: " << name << endl;
	cout << "Address: " << address << endl;
	cout << "Gender: " << gender << endl;
	cout << "Mathematic: " << math << endl;
	cout << "Chemical: " << chem << endl;
	cout << "Physical: " << phys << endl;
	WriteStudentToFile();
}

void Student::WriteStudentToFile() {
	ofstream output;
	output.open("output.txt", ios::out | ios::app);
	output << id << name << address << gender << math << chem << phys << endl;
}

Student::~Student() {
	cout << "Delete success! \n";
}
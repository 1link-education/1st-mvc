#ifndef STUDENT_H
#define STUDENT_H

#include<string>

using namespace std;

class Student
{
public:
	int id;
	string name;
	string address;
	string gender;
	float math;
	float chem;
	float phys;
	float sum = math + chem + phys;

	void SetSV(int, string, string, string, float, float, float);

	void GetSV();

	void WriteStudentToFile();

	~Student();
};
#endif

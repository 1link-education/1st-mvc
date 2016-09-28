#ifndef MODEL_H
#define MODEL_H

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

	void SetSV(int, string, string, string, float, float, float); // lưu sinh viên vào mảng sinh viên

	void GetSV(); // in thông tin sinh viên ra màn hình

	void WriteStudentToFile(); // lưu thông tin sinh viên vào file output

	~Student();
};
#endif

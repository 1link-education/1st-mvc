#ifndef STUDENTMANAGEMENTCONTROLLER_H
#define STUDENTMANAGEMENTCONTROLLER_H
#include "StudentManagementModel.h"
class controller 
// Student Management Controller
{
public:
	int *n; // số sinh viên

	int m=0; // biến tùy chỉnh

	Student *st[]; // mảng sinh viên 

	void bykeyboard(int); // tạo danh sách từ bàn phím

	void byfile(); // tạo danh sách từ file

	void searchsum(int); // tìm kiếm theo tổng điểm

	void searchid(); // tìm kiếm theo sbd

	void searchname(); // tìm kiếm theo tên

	void searchmath(int); // tìm kiếm theo điểm toán

	void searchchem(int); // tìm kiếm theo điểm hóa

	void searchphys(int); // tìm kiếm theo điểm lý

	void modify(); // sửa thông tin sinh viên

	void del(); // xóa sinh viên

	void add(); // thêm sinh viên

	void printList(); // in danh sách sinh viên

	void sortid(int*[]); // sắp xếp theo danh sách

	void sortal(string*[]); // sắp xếp theo alphabel

	void sortsum(float*[]); // sắp xếp theo tổng điểm

	int check(int, int, string, string, string, float, float, float);
	// hàm kiểm tra điều kiện danh sách nhập
};
#endif

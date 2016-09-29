#ifndef STUDENTMANAGEMENTVIEW_H
#define STUDENTMANAGEMENTVIEW_H

#include"StudentManagementModel.h"
#include"StudentManagementController.h"
class View
// Student Management View
{
public:
	controller a;
	void listMenu();// tùy chọn tạo danh sách sinh viên
	void modifyMenu(); // tùy chọn sửa đổi sinh viên
	void searchMenu(); // tùy chọn tìm kiếm sinh viên
	void sortMenu(int); // tùy chọn sắp xếp sinh viên
	int mainMenu(); // tùy chọn các chức năng
};
#endif

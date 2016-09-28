#ifndef VIEW_H
#define VIEW_H

#include"model.h"
#include"controller.h"
class Menu {
public:
	List a;
	void listmenu();// tùy chọn tạo danh sách sinh viên
	void modifymenu(); // tùy chọn sửa đổi sinh viên
	void searchmenu(); // tùy chọn tìm kiếm sinh viên
	void sortmenu(int); // tùy chọn sắp xếp sinh viên
	int main_menu(); // tùy chọn các chức năng
};
#endif

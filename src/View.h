#ifndef VIEW_H
#define VIEW_H

#include"model.h"
#include"controller.h"
class View {
public:
	controller a;
	void listView();// tùy chọn tạo danh sách sinh viên
	void modifyView(); // tùy chọn sửa đổi sinh viên
	void searchView(); // tùy chọn tìm kiếm sinh viên
	void sortView(int); // tùy chọn sắp xếp sinh viên
	int main_View(); // tùy chọn các chức năng
};
#endif

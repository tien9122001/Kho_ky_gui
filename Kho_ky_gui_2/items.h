#pragma once
#include<iostream>
using namespace std;
typedef class items* stack_items;
class items 
{
private:
	string tenSanPham;
	int soLuong;
	float giaTri;
	string ngayNhapKho;
	string code_items;
	string code_DT;
	items* ptr;
public:
	items();
	items(string tenSanPham, int soLuong, float giaTri, string ngayNhapKho, string code_items, string code_DT) {
		this->tenSanPham = tenSanPham;
		this->soLuong = soLuong;
		this->giaTri = giaTri;
		this->ngayNhapKho = ngayNhapKho;
		this->code_items = code_items;
		this->code_DT = code_DT;
	}
	void setTenSanPham(string tenSanPham);
	void setSoLuong(int soLuong);
	void setGiaTri(float giaTri);
	void setNgayNhapKHo(string ngayNhapKho);
	void setCode_items(string code_items);
	void setCode_DT(string code_DT);
	string getTenSanPham();
	int getSoLuong();
	float getGiaTri();
	string getNgayNhapKho();
	string getCode_items();
	string getCode_DT();
	bool isEmpty(stack_items stack_list_items);
	items* getStack_list_items();
	items* createNode(string tenSanPham, int soLuong, float giaTri, string ngayNhapKho, string code_items, string code_DT);
	virtual void readFile();
	virtual void saveFile();
	virtual void add();
	virtual void show();

	

	items* Next;
};


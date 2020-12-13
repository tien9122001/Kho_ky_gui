#include "items.h"
#include<fstream>
#include<string>
#include<iomanip>
#include"Header.h"


items::items() {

}
void items::setTenSanPham(string tenSanPham) {
	this->tenSanPham = tenSanPham;
}
void items::setSoLuong(int soLuong) {
	this->soLuong = soLuong;
}
void items::setGiaTri(float giaTri) {
	this->giaTri = giaTri;
}
void items::setNgayNhapKHo(string ngayNhapKho) {
	this->ngayNhapKho = ngayNhapKho;
}
void items::setCode_items(string code_items) {
	this->code_items = code_items;
}
void items::setCode_DT(string code_DT) {
	this->code_DT = code_DT;
}
string items::getTenSanPham() {
	return this->tenSanPham;
}
int items::getSoLuong() {
	return this->soLuong;
}
float items::getGiaTri() {
	return this->giaTri;
}
string items::getNgayNhapKho() {
	return this->ngayNhapKho;
}
string items::getCode_items() {
	return this->code_items;
}
string items::getCode_DT() {
	return this->code_DT;
}
bool items::isEmpty(stack_items stack_list_items) {
	return (stack_list_items == NULL);
}
items* items::createNode(string tenSanPham, int soLuong, float giaTri, string ngayNhapKho, string code_items, string code_DT) {
	items* ptr = new items(tenSanPham, soLuong, giaTri, ngayNhapKho, code_items, code_DT);
	if (ptr == NULL)
		return NULL;
	return ptr;
}
void items::readFile() {
	fstream fstr;
	fstr.open("items.txt");
	string tenSanPham;
	string soLuong;
	string giaTri;
	string ngayNhapKho;
	string code_items;
	string code_DT;

	while (!fstr.eof()) {
		getline(fstr, tenSanPham, ',');
		getline(fstr, soLuong, ',');
		getline(fstr, giaTri, ',');
		getline(fstr, ngayNhapKho, ',');
		getline(fstr, code_items, ',');
		getline(fstr, code_DT);
		if (tenSanPham == "")
			break;
		items* ptr = createNode(tenSanPham, stoi(soLuong), stoi(giaTri), ngayNhapKho, code_items, code_DT);

		if (isEmpty(stack_list_items)) {
			stack_list_items = ptr;
		}
		else {
			ptr->Next = stack_list_items;
			stack_list_items = ptr;
		}
	}
	fstr.close();
}
void items::saveFile() {
	fstream fstr;
	fstr.open("items.txt", ios::out);
	items* ptr = stack_list_items;
	while (!isEmpty(ptr)) {
		if (ptr != stack_list_items)
			fstr << endl;
		fstr << ptr->getTenSanPham() << "," << to_string(ptr->getSoLuong()) << "," << to_string(ptr->getGiaTri())
			<< "," << ptr->getNgayNhapKho() << "," << ptr->getCode_items() << "," << ptr->getCode_DT();

		ptr = ptr->Next;
	}
	fstr.close();
}
void items::add() {
	string tenSanPham;
	int soLuong;
	float giaTri;
	string ngayNhapKho;
	string code_items;
	string code_DT;
	cout << "Nhap ten san pham: ";
	getline(cin, tenSanPham);
	cout << endl << "Nhap so luong: ";
	cin >> soLuong;
	cout << endl << "Nhap gia tri: ";
	cin >> giaTri;
	cin.ignore();
	cout << endl << "Ngay nhap kho: ";
	getline(cin, ngayNhapKho);
	cout << endl << "Nhap code items: ";
	getline(cin, code_items);
	cout << endl << "Nhap code doi tac: ";
	getline(cin, code_DT);
	items* ptr = new items(tenSanPham, soLuong, giaTri, ngayNhapKho, code_items, code_DT);
	ptr->Next = stack_list_items;
	stack_list_items = ptr;
}
void items::show() {
	items* ptr = stack_list_items;
	cout << setfill('=') << setw(102) << "=" << endl;
	cout << setfill(' ');
	cout << setw(30) << left << "Ten san pham" << setw(20) << left << "So luong"
		<< setw(30) << left << "Gia tri" << setw(12) << left << "Ngay nhap kho" << endl;
	while (!isEmpty(ptr)) {
		cout << setw(30) << left << ptr->getTenSanPham() << setw(20) << left << ptr->getSoLuong()
			<< setw(30) << left << ptr->getGiaTri() << setw(12) << left << ptr->getNgayNhapKho() << endl;
		ptr = ptr->Next;
	}
	cout << setfill('=') << setw(102) << "=" << endl;
	cout << setfill(' ');
}
items* items::getStack_list_items() {
	return stack_list_items;
}


#include "transaction_history.h"
#include"items.h"
#include"Header.h"
#include<iomanip>
#include<string>


bool transaction_history::isEmpty(stack_history stack_list_history) {
	return (stack_list_history == NULL);
}
transaction_history* transaction_history::createNode(string code_giaodich, string tenSanPham, string ngayMua, int soLuong) {
	transaction_history* ptr = new transaction_history;
	ptr->ID_KH = code_giaodich;
	ptr->setTenSanPham(tenSanPham);
	ptr->ngayMua = ngayMua;
	ptr->setSoLuong(soLuong);
	return ptr;
}
void transaction_history::setID_KH(string ID_H) {
	this->ID_KH = ID_H;
}
string transaction_history::getID_KH() {
	return this->ID_KH;
}
void transaction_history::setNgayMua(string ngayMua) {
	this->ngayMua = ngayMua;
}
string transaction_history::getNgayMua() {
	return this->ngayMua;
}
void transaction_history::readFile() {
	fstream fstr;
	fstr.open("transaction_history.txt");
	string ID_KH;
	string tenSanPham;
	string ngayMua;
	string soLuong;

	while (!fstr.eof()) {
		getline(fstr, ID_KH, ',');
		if (ID_KH == "")
			break;
		getline(fstr, tenSanPham, ',');
		getline(fstr, ngayMua, ',');
		getline(fstr, soLuong);
		transaction_history* ptr = createNode(ID_KH, tenSanPham, ngayMua, stoi(soLuong));

		if (isEmpty(stack_list_history)) {
			stack_list_history = ptr;
		}
		else {
			ptr->Next = stack_list_history;
			stack_list_history = ptr;
		}
	}
	fstr.close();

}
void transaction_history::saveFile() {
	fstream fstr;
	fstr.open("transaction_history.txt", ios::out);
	transaction_history* ptr = stack_list_history;
	while (!isEmpty(ptr)) {
		if (ptr != stack_list_history)
			fstr << endl;
		fstr << ptr->getID_KH() << "," << ptr->getTenSanPham() << "," << ptr->getNgayMua()
			<< "," << ptr->getSoLuong();

		ptr = ptr->Next;
	}
	fstr.close();
}
void transaction_history::add() {
	items* ptr1 = new items;
	items* ptr2 = ptr1->getStack_list_items();
	info_KH* ptr3 = new info_KH;
	info_KH* ptr4 = ptr3->getStack_info_KH();
	transaction_history* ptr = new transaction_history;
	string tenSanPham;
	string ngayMua;
	int soLuong;
	cout << "Nhap ten san pham: ";
	getline(cin, tenSanPham);
	if (ptr2 == NULL) {
		cout << "Khong co san pham. " << endl;
	}
	else
		while (ptr2 != NULL) {
			if (ptr2->getTenSanPham() == tenSanPham) {
				string ex = ptr4->getID();
				ptr->setID_KH(ex);
				ptr->setTenSanPham(tenSanPham);
				cout << endl << "Ngay mua: ";
				getline(cin, ngayMua);
				ptr->setNgayMua(ngayMua);
				do {
					cout << endl << "Nhap so luong: ";
					cin >> soLuong;
					if (soLuong > ptr2->getSoLuong())
						cout << endl << "So luong can be hon hoac bang " << ptr2->getSoLuong();
				} while (soLuong > ptr2->getSoLuong());
				ptr2->setSoLuong(ptr2->getSoLuong() - soLuong);
				ptr->setSoLuong(soLuong);
				if (ptr == NULL) {
					stack_list_history = ptr;
				}
				else {
					ptr->Next = stack_list_history;
					stack_list_history = ptr;
				}
			}
			ptr2 = ptr2->Next;
		}
	
}
void transaction_history::show() {
	transaction_history* ptr = stack_list_history;
	cout << setfill('=') << setw(102) << "=" << endl;
	cout << setfill(' ');
	cout << setw(10) << left << "ID_KH" << setw(30) << left << "Ten san pham"
		<< setw(50) << left << "Ngay mua" << setw(12) << left << "So luong" << endl;
	while (!isEmpty(ptr)) {
		cout << setw(10) << left << ptr->getID_KH() << setw(30) << left << ptr->getTenSanPham()
			<< setw(50) << left << ptr->getNgayMua() << setw(12) << left << ptr->getSoLuong() << endl;
		ptr = ptr->Next;
	}
	cout << setfill('=') << setw(102) << "=" << endl;
	cout << setfill(' ');

}

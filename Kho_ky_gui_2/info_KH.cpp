#include "info_KH.h"
#include<iostream>
#include"info.h"
#include<string>
#include<fstream>
#include<iomanip>
#include"Header.h"
using namespace std;

// Kiem tra rong
bool info_KH::isEmpty(stack_KH stack_info_KH){
	return(stack_info_KH == NULL);
}

//Tao node
info_KH* info_KH::createNode(string id, string name, string address, string cmnd, string code_giaodich ){
	info_KH* x = new info_KH(id,name,address,cmnd,code_giaodich);
	if (x == NULL)
		return NULL;
	return x;
}

//Doc file
void info_KH::readFile() {
	fstream fstr;
	fstr.open("info_KH.txt");
	string id;
	string name;
	string address;
	string cmnd;
	
	while (!fstr.eof()) {
		getline(fstr, id, ',');
		getline(fstr, name, ',');
		getline(fstr, address, ',');
		getline(fstr, cmnd, ',');
		getline(fstr, code_giaodich);
		if (id == "")
			break;
		info_KH* ptr = createNode(id, name, address, cmnd, code_giaodich);
		
		if (isEmpty(stack_info_KH)) {
			stack_info_KH = ptr;
		}
		else {
			ptr->Next = stack_info_KH;
			stack_info_KH = ptr;
		}
	}
	fstr.close();

}

//Ghi file
void info_KH::saveFile() {
	fstream fstr;
	fstr.open("info_KH.txt",ios::out);
	info_KH* ptr = stack_info_KH;
	while (!isEmpty(ptr)) {
		if (ptr != stack_info_KH)
			fstr << endl;
		fstr << ptr->getID() << "," << ptr->getName() << "," << ptr->getAddress()
			<< "," << ptr->getCMND() << "," << ptr->code_giaodich;
		
		ptr = ptr->Next;
	}
	fstr.close();
}

//Hien thong tin
void info_KH::show() {
	info_KH* ptr = stack_info_KH;
	cout << setfill('=') << setw(102) << "=" << endl;
	cout << setfill(' ');
	cout << setw(10) << left << "ID" << setw(30) << left << "HoTen"
		<< setw(50) << left << "Dia chi" << setw(12) << left << "CMND" << endl;
	while (!isEmpty(ptr)) {
		cout << setw(10) << left << ptr->getID() << setw(30) << left << ptr->getName()
			<< setw(50) << left << ptr->getAddress() << setw(12) << left << ptr->getCMND() << endl;
		ptr = ptr->Next;
	}
	cout << setfill('=') << setw(102) << "=" << endl;
	cout << setfill(' ');
}

//Tim kiem theo CMND
info_KH* info_KH::find(string cmnd) {
	info_KH* ptr = stack_info_KH;
	if (isEmpty(ptr)) {
		return NULL;
	}
	while (!isEmpty(ptr)) {
		if (ptr->getCMND() == cmnd) {
			return ptr;
		}
		ptr = ptr->Next;
		if (isEmpty(ptr)) {
			return NULL;
		}
	}
}

void info_KH::setCode_giaodich(string code_giaodich) {
	this->code_giaodich = code_giaodich;
}

string info_KH::getCode_giaodich() {
	return this->code_giaodich;
}


info_KH* info_KH::getStack_info_KH() {
	return stack_info_KH_1;
}

void info_KH::setStack_info_KH(info_KH* ptr) {
	stack_info_KH_1 = ptr;
}
inline string ToUpper_Reg(string str)
{
	for (int pos = 0, sz = str.length(); pos < sz; ++pos)
	{
		if (str[pos] >= 'a' && str[pos] <= 'z') { str[pos] += ('A' - 'a'); }
	}

	return str;
}
void info_KH::buy() {
	string id;
	string name;
	string address;
	string cmnd;
	info_KH* ptr = new info_KH;
	transaction_history* ptr1 = new transaction_history;
	cout << endl << "Nhap CMND: ";
	getline(cin, cmnd);
	transaction_history* ptr5 = stack_list_history;
	if (find(cmnd) == NULL) {
		cout << endl << "Nhap ID: ";
		getline(cin, id);
		ptr->setId(id);
		cout << endl << "Nhap ten: ";
		getline(cin, name);
		ptr->setName(ToUpper_Reg(name));
		cout << endl << "Nhap dia chi: ";
		getline(cin, address);
		ptr->setAddress(address);
		cout << endl << "Nhap code giao dich: ";
		getline(cin, code_giaodich);
		ptr->setCode_giaodich(code_giaodich);
		ptr->setCMND(cmnd);
		if (stack_info_KH == NULL) {
			stack_info_KH = ptr;
		}
		else {
			ptr->Next = stack_info_KH;
			stack_info_KH = ptr;
		}
		ptr->setStack_info_KH(ptr);
		ptr1->add();
		if (stack_list_history == NULL) {
			stack_list_history = ptr1;
		}
		else {
			ptr1->Next = stack_list_history;
			stack_list_history = ptr1;
		}
	}
	else {
		ptr = find(cmnd);
		ptr->setStack_info_KH(find(cmnd));
		ptr1->add();
		if (stack_list_history == NULL) {
			stack_list_history = ptr1;
		}
		else {
			ptr1->Next = stack_list_history;
			stack_list_history = ptr1;
		}
	}
}


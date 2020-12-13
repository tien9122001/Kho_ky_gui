#include "info_DT.h"
#include<fstream>
#include<string>
#include<iomanip>
#include"Header.h"
using namespace std;

bool info_DT::isEmpty(stack_DT stack_info_DT) {
	return (stack_info_DT == NULL);
}
info_DT* info_DT::createNode(string id, string name, string address, string cmnd, string code_DT) {
	info_DT* ptr = new info_DT(id, name, address, cmnd, code_DT);
	if (ptr == NULL)
		return NULL;
	return ptr;
}
void info_DT::readFile() {
	fstream fstr;
	fstr.open("info_DT.txt");
	string id;
	string name;
	string address;
	string cmnd;
	string code_DT;

	while (!fstr.eof()) {
		getline(fstr, id, ',');
		getline(fstr, name, ',');
		getline(fstr, address, ',');
		getline(fstr, cmnd, ',');
		getline(fstr, code_DT);
		if (id == "")
			break;
		info_DT* ptr = createNode(id, name, address, cmnd, code_DT);

		if (isEmpty(stack_info_DT)) {
			stack_info_DT = ptr;
		}
		else {
			ptr->Next = stack_info_DT;
			stack_info_DT = ptr;
		}
	}
	fstr.close();
}
void info_DT::saveFile() {
	fstream fstr;
	fstr.open("info_DT.txt", ios::out);
	info_DT* ptr = stack_info_DT;
	while (!isEmpty(ptr)) {
		if (ptr != stack_info_DT)
			fstr << endl;
		fstr << ptr->getID() << "," << ptr->getName() << "," << ptr->getAddress()
			<< "," << ptr->getCMND() << "," << ptr->getCode_DT();

		ptr = ptr->Next;
	}
	fstr.close();
}
void info_DT::add() {
	string id;
	string name;
	string address;
	string cmnd;
	string code_DT;
	cout << "ID: ";
	getline(cin, id);
	cout << endl << "Name: ";
	getline(cin, name);
	cout << endl << "Address: ";
	getline(cin, address);
	cout << endl << "CMND: ";
	getline(cin, cmnd);
	cout << endl << "Code_DT: ";
	getline(cin, code_DT);
	info_DT* ptr = new info_DT(id, name, address, cmnd, code_DT);
	if (isEmpty(ptr)) {
		cout << "Khong du bo nho";
	}
	else {
		ptr->Next = stack_info_DT;
		stack_info_DT = ptr;
	}
}
void info_DT::show() {
	info_DT* ptr = stack_info_DT;
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


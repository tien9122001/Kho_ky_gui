#pragma once
#include<iostream>
using namespace std;
typedef class info* stack_info;
class info
{
private:
	string id;
	string name;
	string address;
	string cmnd;
public:
	virtual void add(){}
	virtual void show() {}
	virtual void buy() {}
	virtual void readFile() {}
	virtual void saveFile() {}
	info(){}
	info(string id, string name, string address, string cmnd) {
		this->id = id;
		this->name = name;
		this->address = address;
		this->cmnd = cmnd;
	}
	void setId(string id);
	void setName(string name);
	void setAddress(string address);
	void setCMND(string cmnd);
	string getID();
	string getName();
	string getAddress();
	string getCMND();
};


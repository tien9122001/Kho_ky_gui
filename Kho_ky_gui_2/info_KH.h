#pragma once
#include"info.h"
#include<fstream>
#include"items.h"
#include"transaction_history.h"
typedef class info_KH* stack_KH;
class info_KH : public info, public transaction_history//, public items
{
private:
	string code_giaodich;
	info_KH* ptr;
public:
	//Kiem tra rong
	bool isEmpty(stack_KH stack_info_KH);
	//Ham khoi tao
	info_KH():info(){}
	info_KH(string id, string name, string address, string cmnd, string code_giaodich) : info(id, name, address, cmnd) {
		
		this->code_giaodich = code_giaodich;
	}
	void setCode_giaodich(string code_giaodich);
	string getCode_giaodich();
	//Tao node
	info_KH * createNode(string id, string name, string address, string cmnd, string code_giaodich);
	//Doc file
	void readFile();
	//Ghi file
	void saveFile();
	//Hien thi thong tin
	void show();
	//Tim kiem theo CMND
	info_KH* find(string cmnd);
	void setStack_info_KH(info_KH*);
	info_KH* getStack_info_KH();
	//Mua hang
	void buy();
	

	info_KH* Next = NULL;
};


#pragma once
#include"items.h"
#include"info.h"

typedef class info_DT* stack_DT;
class info_DT : public items, public info
{
private:
	
public:
	void setIF() {
		cout << "info_DT" << endl;
	}
	bool isEmpty(stack_DT stack_info_DT);

	
	info_DT():items(){}
	info_DT(string id, string name, string address, string cmnd, string code_DT):info(id, name, address, cmnd) {
		this->setCode_DT(code_DT);
	}
	
	//info_DT(string tenSanPham, int soLuong, float giaTri):items(tenSanPham,soLuong,giaTri){}
	info_DT* createNode(string id, string name, string address, string cmnd, string code_items);
	void readFile();
	void saveFile();
	//Them doi tac
	void add();
	//Hien tat ca doi tac
	void show();

	info_DT* Next;
};


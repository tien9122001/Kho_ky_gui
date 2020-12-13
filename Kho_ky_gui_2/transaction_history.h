#pragma once
#include"items.h"
#include<string>
#include<fstream>


typedef class transaction_history* stack_history;
class transaction_history : public items//,public info_KH
{
private:
	string ngayMua;
	string ID_KH;
public:
	bool isEmpty(stack_history stack_list_history);
	transaction_history* createNode(string code_giaodich, string tenSanPham, string ngayMua, int soLuong);
	void add();
	void setNgayMua(string ngayMua);
	string getNgayMua();
	void setID_KH(string code_giaodich);
	string getID_KH();
	void readFile();
	void saveFile();
	void show();
	//friend class info_KH;
	transaction_history* Next;
};


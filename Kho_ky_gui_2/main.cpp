#include<iostream>
#include"Header.h"
#include<iomanip>
using namespace std;

void start();
void body();
void menu(int&);
void switch_case(int&);
void end();

int main()
{
    start();
    body();
    end();

    system("pause");
}

void start() {
    info* call_info;
    items* call_items;
    call_info = new info_DT;
    call_info->readFile();
    call_info = new info_KH;
    call_info->readFile();
    call_items = new items;
    call_items->readFile();
    call_items = new transaction_history;
    call_items->readFile();
}
void body() {
    info* call_info;
    items* call_items;
    int n;
    do {
        
        menu(n);
        system("cls");
        switch_case(n);
        
    } while (n != 0);
    
}
void menu(int& n) {
    cout << endl << "0.Thoat. "
        << endl << "1.Hien danh sach doi tac. "
        << endl << "2.Them doi tac. "
        << endl << "3.Hien danh sach khach hang. "
        << endl << "4.Mua hang. "
        << endl << "5. Hien danh sach san pham. "
        << endl << "6.Them san pham. "
        << endl << "7.Hien lich su giao dich. "
        << endl << "Moi nhap lua chon: ";
    
    cin >> n;
    cin.ignore();
}
void switch_case(int& n) {
    info* call_info;
    items* call_items;
    switch (n) {
    case 1: {
        cout << setw(40) << right << "DANH SACH DOI TAC" << endl;
        call_info = new info_DT;
        call_info->show();
        break;
    }
    case 2: {
        call_info = new info_DT;        
        call_info->add();
        break;
    }
    case 3: {
        cout << setw(40) << right << "DANH SACH KHACH HANG" << endl;
        call_info = new info_KH;
        call_info->show();
        break;
    }
    case 4: {
        cout << setw(40) << right << "DANH SACH SAN PHAM" << endl;
        call_items = new items;
        call_items->show();
        call_info = new info_KH;
        cout << setw(40) << right << "DANH SACH KHACH HANG" << endl;
        call_info->show();
        call_info->buy();
        break;
    }
    case 5: {
        cout << setw(40) << right << "DANH SACH SAN PHAM" << endl;
        call_items = new items;
        call_items->show();
        break;
    }
    case 6: {
        call_info = new info_DT;
        call_info->show();
        call_items = new items;
        call_items->add();
        break;
    }
    case 7: {
        cout << setw(40) << right << "LICH SU GIAO DICH" << endl;
        call_items = new transaction_history;
        call_items->show();
        break;
    }
    case 0: {
        n = 0;
        break;
    }
    }
}
void end() {
    info* call_info;
    items* call_items;
    call_info = new info_DT;
    call_info->saveFile();
    call_info = new info_KH;
    call_info->saveFile();
    call_items = new items;
    call_items->saveFile();
    call_items = new transaction_history;
    call_items->saveFile();
}
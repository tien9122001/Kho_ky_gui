#include "info.h"
#include<iostream>
using namespace std;

void info::setId(string id){
	this->id = id;
}
void info::setName(string name){
	this->name = name;
}
void info::setAddress(string address){
	this->address = address;
}
void info::setCMND(string cmnd){
	this->cmnd = cmnd;
}
string info::getID(){
	return this->id;
}
string info::getName() {
	return this->name;
}
string info::getAddress() {
	return this->address;
}
string info::getCMND() {
	return this->cmnd;
}


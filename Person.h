#pragma once
#include <string>
#include <iostream>
using namespace std;

class  Person
{
private:
	string lastname;
	string name;
	string patronymic;
public:
	Person();
	Person(const string& ln, const string& n, const string p = "");
	void show(); // ln + n
	void showFormal(); //ln + n + p 
};
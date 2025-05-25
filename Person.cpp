#include "Person.h"

Person::Person()
{
	lastname = "";
	name = "";
	patronymic = "";
}

Person::Person(const string& ln, const string& n, const string p)
{
	lastname = ln;
	name = n;
	patronymic = p;
}

void Person::show()
{
	cout << lastname << " " << name << endl;
}

void Person::showFormal()
{
	cout << lastname << " " << name << " " << patronymic << endl;
}
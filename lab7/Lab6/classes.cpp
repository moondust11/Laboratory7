#include "stdafx.h"
#include "classes.h"
#include <iostream>

using namespace std;

//���� ������� ������ cake
void cake::set()
{
	cout << "������� ��������: "; cin >> name;
	cout << "������� ���: "; cin >> weight;
	cout << "������� ����: "; cin >> price;
}
void cake::set(string Name)
{
	name = Name;
}
void cake::set(int Price)
{
	price = Price;
}
void cake::set(int Weight, int Price)
{
	weight = Weight;
	price = Price;
}
void cake::set(string Name, int Weight, int Price)
{
	name = Name;
	weight = Weight;
	price = Price;
}
void cake::get()
{
	cout << "1)" << name << endl;
	cout << "2)��� " << weight << endl;
	cout << "3)���� " << price << endl;
}
void cake::get(cake obj)
{
	obj.get();
}
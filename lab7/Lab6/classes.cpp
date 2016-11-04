#include "stdafx.h"
#include "classes.h"
#include <iostream>

using namespace std;

//Блок методов класса cake
void cake::set()
{
	cout << "Введите название: "; cin >> name;
	cout << "Введите вес: "; cin >> weight;
	cout << "Введите цену: "; cin >> price;
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
	cout << "2)Вес " << weight << endl;
	cout << "3)Цена " << price << endl;
}
void cake::get(cake obj)
{
	obj.get();
}
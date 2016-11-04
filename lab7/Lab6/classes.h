#pragma once

#include <iostream>
#include <string>

using namespace std;

class cake
{
private:
	string name;
	int weight;
	int price;
public:
	~cake()
	{
		name = "Не определён";
		weight = NULL;
		price = NULL;
	}
	cake() : name("Не определён"), weight(NULL), price(NULL)
	{}
	cake(string Name, int Weight, int Price) : name(Name), weight(Weight), price(Price)
	{}
	void set();
	void set(string Name);
	void set(int Price);
	void set(int Weight, int Price);
	void set(string Name, int Weight, int Price);
	void get();
	static void get(cake);
};

//Шаблон класса списка
template <typename Number = int, typename T = cake>
class List
{
private:
	Number num;
	List *Next;
	List *Head;
	int count;
	T Cake;
	template <typename type = int> friend type minValue(List <type, cake>);
public:
	List()
	{
		Head = NULL;
		Next = NULL;
	}
	void get();
	void add(Number);
	void del();
	List operator+(List obj)
	{
		List *p = Head;
		List *po = obj.Head;
		for (; p->Next != NULL; p = p->Next);
		p->Next = po;
		return *this;
	}
	void operator--()
	{
		List *p = Head;
		Head = Head->Next;
		delete p;
	}
	bool operator==(List obj)
	{
		List *p = Head, *po = obj.Head;
		bool stop = false;
		if (count == obj.count)
		{
			for (; p != NULL; p = p->Next, po = po->Next)
			{
				if (p->num != po->num)
				{
					stop = true;
					break;
				}
			}
		}
		if (stop == false)
			return true;
		else
			return false;
	}
	bool IsEmpty()
	{
		if (Head == NULL)
			return true;
		else
			return false;
	}
	//Использование параметра T
	void setDessert(T);
	void getDessert();
};

//Методы шаблона
template <typename Number = int, typename T = cake> void List<Number, T>::get()
{
	cout << "======Вывод=========\n";
	List *p = Head;
	for (int i = 1; p != NULL; p = p->Next, i++)
	{
		cout << "Элемент №" << i << " = " << p->num << endl;
	}
	cout << "Дессерт данного списка:\n";
	cake::get(Cake);
	cout << "====================\n";
}
template <typename Number = int, typename T = cake> void List<Number, T>::add(Number n)
{
	List *p = Head;
	List *N = new List();
	if (Head == NULL)
	{
		N->num = n;
		N->Next = NULL;
		Head = N;
	}
	else
	{
		for (; p->Next != NULL; p = p->Next);
		N->num = n;
		N->Next = NULL;
		p->Next = N;
	}
	count++;
}
template <typename Number = int, typename T = cake> void List<Number, T>::del()
{
	List *p = Head, *temp;
	int l;
	cout << "~~~~~~Удаление~~~~~~~~~~~~~~~~~\n";
	get();
	cout << "Выберите номер элемента: "; cin >> l;
	if (l > count)
	{
		cout << "А почему не 100-ый?" << endl;
		return;
	}
	for (int i = 1; i < l; i++, p = p->Next);
	temp = p;
	p = Head;
	for (int i = 2; i < l; i++, p = p->Next);
	p->Next = temp->Next;
	delete temp;
	count--;
	cout << "Удаление выполнено успешно" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}
template <typename Number = int, typename T = cake> void List<Number, T>::setDessert(T obj)
{
	Cake = obj;
}
template <typename Number = int, typename T = cake> void List<Number, T>::getDessert()
{
	cake::get(Cake);
}

template <typename type = int> type minValue(List <type, cake> obj)
{
	List <type, cake> *p = obj.Head;
	type min = obj.Head->num;
	for (; p != NULL; p = p->Next)
	{
		if (p->num < min)
			min = p->num;
	}
	return min;
}
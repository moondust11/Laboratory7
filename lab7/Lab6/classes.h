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
		name = "�� ��������";
		weight = NULL;
		price = NULL;
	}
	cake() : name("�� ��������"), weight(NULL), price(NULL)
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

//������ ������ ������
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
	//������������� ��������� T
	void setDessert(T);
	void getDessert();
};

//������ �������
template <typename Number = int, typename T = cake> void List<Number, T>::get()
{
	cout << "======�����=========\n";
	List *p = Head;
	for (int i = 1; p != NULL; p = p->Next, i++)
	{
		cout << "������� �" << i << " = " << p->num << endl;
	}
	cout << "������� ������� ������:\n";
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
	cout << "~~~~~~��������~~~~~~~~~~~~~~~~~\n";
	get();
	cout << "�������� ����� ��������: "; cin >> l;
	if (l > count)
	{
		cout << "� ������ �� 100-��?" << endl;
		return;
	}
	for (int i = 1; i < l; i++, p = p->Next);
	temp = p;
	p = Head;
	for (int i = 2; i < l; i++, p = p->Next);
	p->Next = temp->Next;
	delete temp;
	count--;
	cout << "�������� ��������� �������" << endl;
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
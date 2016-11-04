#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include "classes.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	List <int, cake> First;
	First.add(5);
	First.add(10);
	First.add(15);
	First.add(20);
	First.add(4);
	cout << "<int>First.get().....\n";
	First.get();
	List <> Second;
	Second.add(11);
	Second.add(67);
	Second.add(114);
	Second.add(7);
	Second.add(12);
	cout << "<int>Second.get.....\n";
	Second.get();
	List <int, cake> summ = First + Second;
	cout << "<int>LOL.GET....... = first + second\n";
	summ.get();
	List <float, cake> Third;
	Third.add((float)5.6);
	Third.add((float)7.7);
	Third.add((float)7.3);
	List <double, cake> Fourth;
	Fourth.add(7.67);
	Fourth.add(7.378);
	Fourth.add(5.243);
	List <char, cake> Fifth;
	Fifth.add(25);
	Fifth.add(5);
	Fifth.add(30);
	List <long, cake> Sixth;
	Sixth.add(7);
	Sixth.add(7);
	Sixth.add(5);
	cout << "<float>Third.get()......\n";
	Third.get();
	cout << "<double>Fourth.get()......\n";
	Fourth.get();
	cout << "<char>Fifth.get()......\n";
	Fifth.get();
	cout << "<long>Sixth.get()......\n";
	Sixth.get();
	cout << "\n-------------------------------------------\n";
	cake Cake1("Наполеон", 20, 10);
	cake Cake2("Песочник", 25, 15);
	First.setDessert(Cake1);
	Second.setDessert(Cake2);
	First.getDessert();
	cout << "=========\n";
	Second.getDessert();
	cout << "\n-------------------------------------------\n";
	cout << "minValue(First) = " << minValue(First) << endl;
	cout << "minValue(Second) = " << minValue(Second) << endl;
    return 0;
}


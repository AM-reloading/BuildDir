


#pragma once
#include <iostream>

using namespace std;



class MyDate
{

	int Day, Month, Year;

public:

	MyDate();
	MyDate(int Year, int Month, int Day);

	void setDate(int Year, int Month, int Day);
	string getYear();
	string getMonth();
	string getDay();


	string Showinfo();


};


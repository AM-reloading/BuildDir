


#include "MyDate.h"
#include "string"


MyDate::MyDate()
{
	Year = 0;
	Month = 0;
	Day = 0;
}
MyDate::MyDate(int Year, int Month, int Day)
{
	this->Year = Year;
	this->Month = Month;
	this->Day = Day;
}


//set&get Date
void MyDate::setDate(int Year, int Month, int Day)
{
	this->Year = Year;
	this->Month = Month;
	this->Day = Day;
}
string MyDate::getYear()
{
	return to_string(Year);
}
string MyDate::getMonth()
{
	return to_string(Month);
}
string MyDate::getDay()
{
	return to_string(Day);
}


string MyDate::Showinfo()
{
	if (Year == 0 && Month == 0 && Day == 0)
		return "Undefined";
	else
		return /*"Production date: " + */to_string(Year) + "/" + to_string(Month) + "/" + to_string(Day);
}

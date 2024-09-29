


#include "City.h"


City::City()
{
	Name = "Undefined";
}
City::City(string Name)
{
	this->Name = Name;
}


//set&get Name
void City::setName(string Name)
{
	this->Name = Name;
}
string City::getName()
{
	return Name;
}


string City::Showinfo()
{
	return "City name: " + Name;
}
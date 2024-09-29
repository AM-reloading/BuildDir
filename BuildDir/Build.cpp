


#include "Build.h"
#include "MyDate.h"
#include "City.h"
#include "sstream"

Build::Build()
{
	Name = "Undifind";
	Cityname = City::City();
	Date = MyDate::MyDate();
	u = Undefined;
	Area = 0;

}
Build::Build(string Name, City Cityname, MyDate Date, Usage u, double Area)
{
	this->Name = Name;
	this->Cityname = Cityname;
	this->Date = Date;
	this->u = u;
	this->Area = Area;
}


//set&get Name
bool Build::setName(string Name, Build *BuildDir, int b)
{
	for (int i = 0; i <= b; i++)
	{
		if (Name == BuildDir[i].getName())
		{
			return false;

		}

	}
	this->Name = Name;
	return true;
	
}
string Build::getName()
{
	return Name;
}
//set&get Cityname
void Build::setCityname(City Cityname)
{
	//if (Cityname.getName() == "")
	//	Cityname.setName("Undifind");
	this->Cityname = Cityname;
}
City Build::getCityname()
{
	return Cityname;
}
//set&get Date
void Build::setDate(MyDate Date)
{
	this->Date = Date;
}
MyDate Build::getDate()
{
	return Date;
}
//set&get Usage
bool Build::setUsage(int u)
{
	if (u > START && u < END)
	{
		this->u = static_cast<Usage>(u);
		return true;
	}
	else
	{
		return false;
	}
}
int Build::getUsage()
{
	return u;
}
//set&get Area
void Build::setArea(double Area)
{
	this->Area = Area;
}
double Build::getArea()
{
	return Area;
}


string Build::Showinfo()
{
	stringstream ss;

	ss << "Name: " << Name << "\n";
	ss << Cityname.Showinfo() << "\n";
	ss << "Production date: " << Date.Showinfo() << "\n";

	if (u == 4)
		ss << "Usage: Undefined\n";
	else if (u == 1)
		ss << "Usage: Mosque\n";
	else if (u == 2)
		ss << "Usage: Bathhouse\n";
	else if (u == 3)
		ss << "Usage: Palace\n";

	if (Area == 0)
		ss << "Area: Undefined\n";
	else
		ss << "Area: " << Area << "\n";
	
	return ss.str();
}


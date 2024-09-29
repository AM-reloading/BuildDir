


#pragma once

#include <iostream>
#include "MyDate.h"
#include "City.h"

using namespace std;



enum Usage
{
	START = 0,
	Undefined = 4,
	Mosque = 1,
	Bathhouse = 2,
	Palace = 3,
	END = 5
};

class Build
{

	string Name;
	City Cityname;
	MyDate Date;
	Usage u;
	double Area;

public:

	Build();
	Build(string Name, City Cityname, MyDate Date, Usage u, double Area);

	//set&get Name
	bool setName(string Name, Build* BuildDir, int b);
	string getName();
	//set&get Cityname
	void setCityname(City Cityname);
	City getCityname();
	//set&get Date
	void setDate(MyDate Date);
	MyDate getDate();
	//set&get Usage
	bool setUsage(int u);
	int getUsage();
	//set&get Area
	void setArea(double Area);
	double getArea();


	string Showinfo();

};


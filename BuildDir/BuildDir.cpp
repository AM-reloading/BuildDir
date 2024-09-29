


#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Build.h"
#include "City.h"
#include "MyDate.h"
//#include <algorithm>
//#include <vector>
//#include <filesystem>
//#include <csignal>
#include <cstdlib> // for getenv & exit(Save)

using namespace std;

//Build* BuildDir = nullptr;
//int b = 0;
//int BuildDirSize = 1;

int Onlyint()
{
	int i;
	while (true)
	{
		cin >> i;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Please enter a number: ";
		}
		else
		{
			return i;
		}

	}

}
double Onlydouble()
{
	double i;
	while (true)
	{
		cin >> i;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Please enter a number: ";
		}
		else
		{
			return i;
		}
	}
}

void Save(Build* BuildDir, int BuildDirSize)
{
	ofstream fileOut("db.txt");

	fileOut << BuildDirSize << "\n";

	for (int i = 0; i < BuildDirSize; i++)
	{
		fileOut << BuildDir[i].getName() << ";"
			<< BuildDir[i].getCityname().getName() << ";"
			<< BuildDir[i].getDate().getYear() << "/"
			<< BuildDir[i].getDate().getMonth() << "/"
			<< BuildDir[i].getDate().getDay() << ";"
			<< BuildDir[i].getUsage() << ";"
			<< BuildDir[i].getArea() << "\n";

	}

}
void Load(Build* BuildDir)
{
	ifstream fileIn("db.txt");

	//fileIn >> BuildDirSize;
	fileIn.ignore();

	//BuildDirSize = b;
	//BuildDir = new Build[BuildDirSize];

	string line;
	int i = 0;
	while (getline(fileIn, line))
	{
		istringstream ss(line);
		string name, citystr, datestr;
		int usage;
		double area;
		char delimiter;

		getline(ss, name, ';');
		getline(ss, citystr, ';');
		getline(ss, datestr, ';');
		ss >> usage >> delimiter >> area;

		City city = City(citystr);
		istringstream ndate(datestr);
		int year, month, day;
		char dateDelim1, dateDelim2;

		ndate >> year >> dateDelim1 >> month >> dateDelim2 >> day;

		MyDate date = MyDate(year, month, day);

		BuildDir[i] = Build(name, city, date, static_cast<Usage>(usage), area);

		i++;

	}

}

//void signalHandler(int signum)
//{
//	Save();
//	delete[] BuildDir;
//	//exit(signum);
//}

int main()
{
	//signal(SIGBREAK, signalHandler);
	//atexit(Save);

	int b = 0, BuildDirSize, anum, choice;

	//int n = 2;
	//cout << "Enter Max size of BuildDir: ";
	//n = Onlyint();

	//string homeDrive = getenv("HOMEDRIVE");
	//string homePath = getenv("HOMEPATH");
	//string filename = homeDrive + homePath + "\\Documents\\BuildDir.txt";

	ifstream fileIn("db.txt");
	if (fileIn)
	{
		fileIn >> b;
		BuildDirSize = b;

	}
	else
		BuildDirSize = 1;

	anum = b + 1;

	//if (b == 0)
	//{
	//	choice = -1;
	//	b = 1;
	//}

	Build* BuildDir = new Build[BuildDirSize];

	//if (choice == -1)
	//	b = 0;

	//vector<Build> BuildDir;

	Load(BuildDir);


	//Build test = Build();
	//Build t("aa", tc, td, Mosque, 11.11);
	//BuildDir[0] = test;
	//b++;

	while (true)
	{
		cout << "Select an option:\n\
        1. Add a building\n\
        2. Remove a building\n\
        3. Edit a building\n\
        4. Display all buildings\n\
        5. Search\n\
        0. Exit\n";
		cout << "root#~: ";
		choice = Onlyint();

		if (choice == 0)
		{
			//Save(BuildDir, b);
			//delete[] BuildDir;
			//return 0;
			break;
		}
		else if (choice == -1)
		{
			cout << "\tThis page only for Developers!\n";
			cout << "b = " << b << "\n";
			cout << "BuildDir[" << /*sizeof(BuildDir)*/ BuildDirSize * sizeof(Build) / sizeof(Build) << "]" << "\n";
			//if (BuildDirSize != 0)
			//	cout << BuildDir[b].Showinfo();
			//cout << sizeof(Build) << "Build \n";
			//cout << sizeof(BuildDir) << "BuildDir \n";

		}
		else if (choice > 5 || choice < -1)
		{
			cout << "\"" << choice << "\" Out of range!\n";
			cout << "Try again...\n----------------\n";
		}
		else if (choice == 1)
		{
			//Add...

			//if (b == n)
			//{
			//	cout << "\tBuildDir is Full (Remove some item to add new one!)\n";
			//	continue;
			//}

			Build build;
			MyDate date;
			City city;
			string name;
			int year, month, num/* for Day & Usage */;
			double area;
			//bool IsCholmang = false;

			//Name..
			cout << "(use 0 for back to menu all the time)\n\tEnter Build's name (-1 to auto fill) : ";

			while (true)
			{
				cin >> name;
				if (name == "0" || name == "-1")
					break;

				if (build.setName(name, BuildDir, b))
				{
					//cout << "----------------\n\"" << name << "\"successfully registered.\n";
					break;
				}
				else
				{
					cout << "----------------\n\"" << name << "\" already exists!\n\tEnter Build's name again: ";
					//IsCholmang = true;
				}
			}
			if (name == "0")
				continue;
			else if (name == "-1")
			{
				Build autobuild = Build();
				if (!autobuild.setName("Auto_" + to_string(anum), BuildDir, b))
					autobuild.setName("Auto_" + to_string(anum + 1), BuildDir, b);


				if (BuildDirSize > b)
				{
					BuildDir[b] = autobuild;

				}
				else
				{
					Build* nBuildDir = new Build[BuildDirSize + 1];
					for (int i = 0; i < BuildDirSize; i++)
					{
						nBuildDir[i] = BuildDir[i];
					}
					nBuildDir[BuildDirSize] = autobuild;
					BuildDirSize++;

					//delete[] BuildDir;
					//BuildDir = nBuildDir;
					BuildDir = new Build[BuildDirSize];
					for (int i = 0; i < BuildDirSize; i++)
					{
						BuildDir[i] = nBuildDir[i];
					}

				}

				anum++;
				b++;

				cout << "bsize: " << BuildDirSize << "...: " << BuildDir[BuildDirSize - 1].getName();
				Save(BuildDir, BuildDirSize);
				cout << "\"" << autobuild.getName() << "\" Saved successfully :)\n";
				continue;
			}

			//City..
			cout << "\tEnter Build's city name: ";
			cin >> name;

			if (name == "0")
				continue;

			city.setName(name);
			build.setCityname(city);

			//Date
			cout << "\tEnter Build's production date (Year, Month, Day) : ";
			year = Onlyint();
			if (year == 0)
				continue;

			month = Onlyint();
			if (month == 0)
				continue;

			num = Onlyint();
			if (num == 0)
				continue;

			date.setDate(year, month, num/*day*/);

			//Usage
			while (true)
			{
				cout << "\tEnter Build usage (1_Mosque | 2_Bathhouse | 3_Palace | 4_Undifind) : ";
				num = Onlyint();

				if (build.setUsage(num))
					break;
				else
					cout << "You can only choose a number between 1 and 4, idiot\n";
			}

			//Area
			cout << "\tEnter Build's area (You can enter Double) : ";
			area = Onlydouble();
			if (area == 0)
				continue;

			build.setArea(area);

			//////////////////////////////////////////////////////////////
			if (BuildDirSize > b)
			{
				BuildDir[b] = build;

			}
			else
			{
				Build* nBuildDir = new Build[BuildDirSize + 1];
				for (int i = 0; i < BuildDirSize; i++)
				{
					nBuildDir[i] = BuildDir[i];
				}
				BuildDir = new Build[BuildDirSize + 2];
				for (int i = 0; i < BuildDirSize; i++)
				{
					BuildDir[i] = nBuildDir[i];
				}

				BuildDir[b] = build;

				BuildDirSize++;
			}
			//////////////////////////////////////////////////////////////

			b++;
			BuildDirSize++;

			Save(BuildDir, b);
			cout << "\"" << build.getName() << "\" Saved successfully :)\n";
		}
		else if (choice == 2)
		{
			//Remove...

			int i = 0;
			string name, sure;
			cout << "\tEnter Build's name: ";
			cin >> name;
			if (name == "0")
				continue;

			for (; i < b; i++)
			{
				if (BuildDir[i].getName() == name)
				{
					cout << name << " will delete, are you sure? (Y/n) :";
					cin >> sure;
					if (sure != "Y" && sure != "y")
						break;

					ofstream fileOut("Deleted_Builds.txt", ios_base::app);

					fileOut << BuildDir[i].getName() << ";"
						<< BuildDir[i].getCityname().getName() << ";"
						<< BuildDir[i].getDate().getYear() << "/"
						<< BuildDir[i].getDate().getMonth() << "/"
						<< BuildDir[i].getDate().getDay() << ";"
						<< BuildDir[i].getUsage() << ";"
						<< BuildDir[i].getArea() << "\n";



					for (int j = i; j < b - 1; j++)
					{
						BuildDir[j] = BuildDir[j + 1];

					}

					//Build* nBuildDir = new Build[b - 1];
					//for (int i = 0; i < b - 1; i++)
					//{
					//	nBuildDir[i] = BuildDir[i];
					//}
					//delete[] BuildDir;
					//    //BuildDir = new Build[b - 2];
					//BuildDir = nBuildDir;

					b--;

					Save(BuildDir, b);
					cout << "\"" << name << "\" removed successfully :)\n";

					name = "0";
					break;

				}

			}
			if (name == "0")
				continue;

			if (i == b)
				cout << "\"" << name << "\" not found :(\n";

		}
		else if (choice == 3)
		{
			//Edit...

			Build nbuild;
			string oname, nname;
			City ncity;
			MyDate ndate;
			double area;
			int i = 0, year, month, num /* for Day & Usage */;


			cout << "\tEnter Build's name: ";

			//Find
			while (true)
			{
				cin >> oname;
				if (oname == "0")
					break;

				for (; i < b; i++)
				{
					if (BuildDir[i].getName() == oname)
					{
						break;

					}

				}
				if (i == b)
					cout << "\"" << oname << "\" not exists!\n\tEnter Build's name again: ";
				else
					break;

			}
			if (oname == "0")
				continue;

			//Name
			cout << "Old name: " << oname/*BuildDir[i].getName()*/ << "\n";
			cout << "Enter new name (use -1 for no change) : ";

			while (true)
			{
				cin >> nname;

				if (nname == "0")
					break;
				else if (nname == "-1")
				{
					BuildDir[i].setName("0", BuildDir, b);
					nbuild.setName(oname, BuildDir, b);
					break;
				}

				if (nbuild.setName(nname, BuildDir, b))
				{
					break;
				}
				else
				{
					cout << "----------------\n\"" << nname << "\" already exists!\n\tEnter new name again: ";

				}

			}
			if (nname == "0")
				continue;

			//City
			cout << "Old city name: " << (BuildDir[i].getCityname()).getName() << "\n";
			cout << "\tEnter new city name (use -1 for no change) : ";
			cin >> nname;

			if (nname == "0")
				continue;
			else if (nname == "-1")
			{
				nbuild.setCityname(BuildDir[i].getCityname());

			}
			else
			{
				ncity.setName(nname);
				nbuild.setCityname(ncity);

			}

			//Date
			cout << "Old production date: " << (BuildDir[i].getDate()).Showinfo() << "\n";
			cout << "\tEnter new Build's production date or use -1 for no change : \nYear: ";

			year = Onlyint();
			if (year == 0)
				break;
			else
			{
				month = 1; num = 1;
				while (year == -1 || month == -1 || num == -1)
				{
					if (year == -1)
					{
						nbuild.setDate(BuildDir[i].getDate());
						break;
					}

					cout << "Month: ";
					month = Onlyint();
					if (month == 0)
						break;
					else if (month == -1)
					{
						nbuild.setDate(BuildDir[i].getDate());
						break;
					}

					cout << "Day: ";
					num = Onlyint();
					if (num == 0)
						break;
					else if (num == -1)
					{
						nbuild.setDate(BuildDir[i].getDate());
						break;
					}

					ndate.setDate(year, month, num/*day*/);
					nbuild.setDate(ndate);

					num = -1;
				}
			}

			//Usage
			while (true)
			{
				cout << "\tEnter Build new usage (1_Mosque | 2_Bathhouse | 3_Palace | 4_Undifind) or use -1 for no change : ";
				num = Onlyint();

				if (num == 0)
					break;
				else if (num == -1)
				{
					nbuild.setUsage(BuildDir[i].getUsage());
					break;
				}

				if (nbuild.setUsage(num))
					break;
				else
					cout << "You can only choose a number between 1 and 4!\n";
			}
			if (num == 0)
				continue;

			//Area
			cout << "\tEnter Build's area (You can enter Double) or use -1 for no change : ";
			area = Onlydouble();
			if (area == 0)
				break;
			else if (area == -1)
			{
				nbuild.setArea(BuildDir[i].getArea());
			}
			else
			{
				nbuild.setArea(area);

			}

			ofstream fileOut("Edited_Builds.txt", ios_base::app);

			if (BuildDir[i].getName() == "0")
				BuildDir[i].setName(oname, BuildDir, b);

			fileOut << BuildDir[i].getName() << ";"
				<< BuildDir[i].getCityname().getName() << ";"
				<< BuildDir[i].getDate().getYear() << "/"
				<< BuildDir[i].getDate().getMonth() << "/"
				<< BuildDir[i].getDate().getDay() << ";"
				<< BuildDir[i].getUsage() << ";"
				<< BuildDir[i].getArea() << " | -> | "
				<< nbuild.getName() << ";"
				<< nbuild.getCityname().getName() << ";"
				<< nbuild.getDate().getYear() << "/"
				<< nbuild.getDate().getMonth() << "/"
				<< nbuild.getDate().getDay() << ";"
				<< nbuild.getUsage() << ";"
				<< nbuild.getArea() << "\n";

			BuildDir[i] = nbuild;

			Save(BuildDir, b);
			cout << "\"" << nbuild.getName() << "\" Changed successfully :)\n";

		}
		else if (choice == 4)
		{
			cout << "\n";
			for (int i = 0; i < b; i++)
			{
				cout << BuildDir[i].Showinfo() << "----------------\n";

			}
			cout << "\tThe number of Build's: " << b << "\n\n";
		}
		else if (choice == 5)
		{
			if (b == 0)
			{
				cout << "BuildDir is empty, Pleas add some item first.\n";
				continue;
			}

			cout << "\tWhat is the basis of the search?\n1_Build'S name\n2_Buil city name\n\t: ";
			choice = Onlyint();

			while (true)
			{
				if (choice == 0)
					break;

				string name;

				if (choice == 1)
				{
					while (true)
					{
						cout << "\tEnter Buils's name: ";
						cin >> name;

						if (name == "0")
							break;

						int i = 0;
						for (; i < b; i++)
						{
							if (BuildDir[i].getName() == name)
							{
								cout << "\n----------------\n";
								cout << BuildDir[i].Showinfo();
								cout << "----------------\n\n";

								break;
							}

						}
						if (i == b)
							cout << name << "not exists!\nTry agin...\n";

					}

				}
				else if (choice == 2)
				{
					int counter = 0;

					while (true)
					{
						cout << "\tEnter Buils city name: ";
						cin >> name;

						if (name == "0")
							break;

						for (int i = 0; i < b; i++)
						{
							if (BuildDir[i].getCityname().getName() == name)
							{
								cout << "\n----------------\n";
								cout << BuildDir[i].Showinfo();
								cout << "----------------\n\n";
								counter++;
							}

						}

						if (counter == 0)
							cout << name << "not exists!\nTry agin...\n";
						else
						{
							cout << "\n\tThe number of Builds in " << name << ": " << counter << "\n";

							break;
						}

					}

				}
				else
				{
					cout << "\"" << choice << "\" Out of range!\n";
					cout << "Try again...\n----------------\n";
				}

				if (name == "0")
					break;

			}

		}

	}
	delete[] BuildDir;


}




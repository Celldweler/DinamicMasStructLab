
#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#define garbage_collector() cin.ignore(cin.rdbuf()->in_avail())

using namespace std;

struct Person
{
	char FirstName[15],
		 SecondName[15],
		 LastName[15];
	int Age;
	char Sex[50];

};
//TODO:возвращяет указатель на масив структур размерности Dimension
Person* InitArray(int Dimension);
Person InitPerson();
void DisplayArray(Person* Massive, int Dimaension);
void DisplayChoise(Person*, int,char*,int,int);
void DisplayPerson(Person);
void SortFirstName(Person*, int);
int& CheckCorectDigitValue(int&);



int main(int argc,char* argv)
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(0, "");

	int Dimension;
	char SexTag[7];
	int LowAge, UpperAge;
	bool begin = true;
	tryagain:
	Person* MassiveStruct =  nullptr;
	do
	{
		cout << "\nEnter the number of persons]$~ ";
		do {
			cin >> Dimension;
			if (cin.fail())
			{
				cout << "~$]Previous input failed, please re-enter !!!" << endl;
				cin.clear();
				cin.ignore(32222, '\n');
			}
			else
				break;
		} while (true);
		MassiveStruct = InitArray(Dimension);
		if (MassiveStruct == nullptr)
		{
			cout << "\n~$]Dynamic array don't exist!\n";

			do {
				cout << "~$]Введите '+' для того чтобы повторить попытку или нажмите '-' чтобы выйти из програмы... ";
				char symbol;
				symbol = getchar();
				(symbol == '+') ? begin==true  : begin==false;
				if (symbol == '+')
					goto tryagain;
				exit(777);

			} while (!begin);
		}
		
				
	} while (begin!=true);

	cout << "\nThe list of persons: ";
	DisplayArray(MassiveStruct, Dimension);

	cout << "\n~$]Enter the sex-tag: ";
	do {
		cin >> SexTag;
	} while (isdigit((char)SexTag[1]));
	cout << "\nEnter of boundary of age]$~";
	do
	{
		cin >> LowAge >> UpperAge;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32222, '\n');
		}
		else
			break;
	} while (true);

	cout << "\nThe list of choice-persons: ";
	DisplayChoise(MassiveStruct,Dimension,SexTag,LowAge,UpperAge);

	cout << "\nThe sorting list of persons: ";
	SortFirstName(MassiveStruct, Dimension);
	DisplayArray(MassiveStruct, Dimension);
	
	delete MassiveStruct;
	
}
Person InitPerson()
{
	Person Man;
	cout << "\nEnter first name:";
	garbage_collector();
		cin.getline(Man.FirstName,255);
	cout << "Enter second name:";
	garbage_collector();
		cin.getline(Man.SecondName,255);
	cout << "Enter last name:";
	garbage_collector();
	  cin.getline(Man.LastName, 255);
	cout << "Enter age: ";
	garbage_collector();
		CheckCorectDigitValue(Man.Age);
	cout << "Enter sex: ";
	garbage_collector();
		cin.getline(Man.Sex,255);

	return Man;

}

Person* InitArray(int Dimension)
{
	Person* Massive = new Person[Dimension];
	if (Massive == nullptr)
		return nullptr;
	for (size_t i = 0; i < Dimension; i++)
	{
		printf("\n]$~Enter the information about %d person ",i+1);
		Massive[i] = InitPerson();
	}
	return Massive;
}

void DisplayArray(Person* Massive, int Dimension)
{
	for (size_t i = 0; i < Dimension; i++) { DisplayPerson(Massive[i]); }
}

void DisplayChoise(Person* Massive, int Dimension, char* SexTag, int LowAge, int UpperAge)
{
	for (size_t i = 0; i < Dimension; i++)
	{
		if (
			strcmp(Massive[i].Sex, SexTag) == 0 &&
			Massive[i].Age <= UpperAge &&
			Massive[i].Age >= LowAge
			)
		{
			DisplayPerson(Massive[i]);
		}
	}
}

void DisplayPerson(Person Man)
{
	printf("\n%s %s %s %d year %s", Man.FirstName, Man.SecondName, Man.LastName, Man.Age, Man.Sex);
}


void SortFirstName(Person* Massive, int Dimension)
{
	Person Temp;
	for (size_t i = 0; i <= Dimension; i++)
	{
		for (size_t q = Dimension - 1; q > i; q--)
		{
			if (strcmp(Massive[q].FirstName, Massive[q - 1].FirstName) < 0)
			{
				Temp = Massive[q];
				Massive[q] = Massive[q - 1];
				Massive[q - 1] = Temp;
			}
		}
	}
}
int& CheckCorectDigitValue(int& value)
{
	bool flag = false;
	do {
		if (flag) {
			cout << "Please re-enter!!!";
		}flag = false;
		cin >> value;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32222, '\n');
		}
		else
		{
			return value;
		}
	} while (true);
}
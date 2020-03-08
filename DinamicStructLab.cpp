#include <iostream>
#include <limits>
#include <string>
#include <Windows.h>
using namespace std;

struct Person
{
	char FirstName[15],SecondName[15],LastName[15];
	int Age;
	char Sex[7];

};

//TODO:возвращяет указатель на масив структур размерности Dimension
Person* InitArray(int Dimension/*size*/);
Person InitPerson();
void DisplayArray(Person* Massive, int Dimaension);
void DisplayChoise(Person*, int,char*,int,int);
void DisplayPerson(Person);
void SortFirstName(Person*, int);

void main(void)
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
		//Person* Copy_MassiveStruct = nullptr;
		cout << "\nEnter the number of persons:";
		do {
			cin >> Dimension;
			if (cin.fail())
			{
				cout << "Предыдущий ввод завершился некоректно пожалуйста повторите ввод!!!" << endl;
				cin.clear();
				cin.ignore(32222, '\n');
			}
			else
				break;
		} while (true);

		MassiveStruct = InitArray(Dimension);

		
		if (MassiveStruct == nullptr)
		{
			cout << "\nDynamic array don't exist!\n";

			do {
				cout << "Введите '+' для того чтобы повторить попытку или нажмите '-' чтобы выйти из програмы...";
				char symbol;
				symbol = getchar();
				(symbol == '+') ? begin==true  : begin==false;
				if (symbol == '+')
					goto tryagain;
				exit(777);

			} while (!begin);
		}
		
				
	} while (begin!=true);

	cout << "\nThe list of persons: \n";
	DisplayArray(MassiveStruct, Dimension);

	cout << "\nEnter the sex-tag: ";
	    cin >> SexTag;
	cout << "\nEnter of boundary of age: \n";
	do
	{
		cin >> LowAge >> UpperAge;
		if (cin.fail())
		{
			//cin.ignore(std::cin.rdbuf()->in_avail());
			cin.clear();
			cin.ignore(32222, '\n');
		}
		else
			break;
	} while (true);

	cout << "\n\nThe list of choice-persons: \n";
	DisplayChoise(MassiveStruct,Dimension,SexTag,LowAge,UpperAge);

	cout << "\n\nThe sorting list of persons: \n";
	SortFirstName(MassiveStruct, Dimension);
	DisplayArray(MassiveStruct, Dimension);
	
	delete MassiveStruct;

	
}


Person InitPerson()
{
	Person Man;
	cout << "\nEnter first name:";
	cin.ignore(std::cin.rdbuf()->in_avail());
	                          cin.getline(Man.FirstName,255);
	cout << "Enter second name]$~";
	cin.ignore(std::cin.rdbuf()->in_avail());
                          cin.getline(Man.SecondName,255);
	cout << "Enter last name:";
	cin.ignore(std::cin.rdbuf()->in_avail());
	                       cin.getline(Man.LastName,255);
	cout << "Enter age: ";
	cin.ignore(std::cin.rdbuf()->in_avail());
	                     cin>>(Man.Age);
	cout << "Enter sex: ";
	cin.ignore(std::cin.rdbuf()->in_avail());
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
	Person tmp;
	for (size_t i = 0; i <= Dimension; i++)
	{
		for (size_t q = Dimension - 1; q > i; q--)
		{
			if (strcmp(Massive[q].FirstName, Massive[q - 1].FirstName) < 0)
				
		    tmp = Massive[q];
			Massive[q] = Massive[q - 1];
			Massive[q - 1] = tmp;

		}
	}
}
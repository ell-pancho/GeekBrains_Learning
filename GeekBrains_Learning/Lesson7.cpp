#include <iostream>
#include "mylib.h"
#include <string>
#include <fstream>

using namespace std;

#define CHECK(x, y) ((0 <= x && x < y) ? cout << "true" : cout << "false")
#define SIZE 4
#define SwapINT(a, b) int temp; temp = a; a = b; b = temp;

#pragma pack(push, 1)
struct Employee
{
	string name;
	long salary;
	int age;
	string position;
};
#pragma pack(pop)

void lesson7Task5()
{
	int size = MyLib::getInputInteger();
	int* randomArray = MyLib::initArray(size);

	MyLib::printMyArray(randomArray, size);
	MyLib::countElements(randomArray, size);

	delete[] randomArray;
	randomArray = nullptr;
}

void lesson7Task2()
{
	int number1 = MyLib::getInputInteger();
	int number2 = MyLib::getInputInteger();
	bool result;

	CHECK(number1, number2);

	cout << endl;
}

void lesson7Task3()
{
	int myArray[SIZE];

	for (size_t i = 0; i < SIZE; i++)
	{
		cout << "Enter element # " << i << ": ";
		cin >> myArray[i];
	}

	cout << "Array before bubble: " << endl;
	MyLib::printMyArray(myArray, SIZE);
	cout << endl;

	for (size_t i = 0; i < SIZE-1; i ++)
		for (size_t j = 0; j < SIZE-1; j++)
			if (myArray[j] > myArray[j + 1])
			{
				SwapINT(myArray[j], myArray[j + 1]);
			}

	cout << "Array after bubble: " << endl;
	MyLib::printMyArray(myArray, SIZE);
	cout << endl;
}

void lesson7Task4()
{	
	const int size = 2;
	Employee* employee = new Employee;
	const string fileName = "struc_info.txt";

	employee->name = "John";
	employee->salary = 1000;
	employee->age = 35;
	employee->position = "Programmer";

	cout << "Employee name: " << employee->name << endl;
	cout << "Employee salary: " << employee->salary << endl;
	cout << "Employee age: " << employee->age << endl;
	cout << "Employee position: " << employee->position << endl;
	
	cout << "Size of structure: " << sizeof(employee) << endl;

	ofstream fout(fileName, ios_base::binary);
	if (fout.is_open())
	{
		fout.write((char*)&employee, sizeof(employee));
		fout.close();
	}

	delete employee;
}

int main()
{

	lesson7Task2();
	lesson7Task3();
	lesson7Task4();
	lesson7Task5();

	return 0;
}

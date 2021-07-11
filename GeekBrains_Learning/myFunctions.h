#pragma once
#include <iostream>

using namespace std;

void printArray(int* array, int size)
{
	for (size_t i = 0; i < size; i++)
		cout << array[i] << " ";;
	cout << endl;
}

void print2Array(int** array, int sizeX, int sizeY)
{
	for (size_t i = 0; i < sizeX; i++)
	{
		for (size_t j = 0; j < sizeY; j++)
			cout << array[i][j] << " ";;
		cout << endl;
	}
}

int getIntegerInput()
{
	int size;

	while (true)
	{
		cout << "Enter an integer value: ";
		cin >> size;

		if (cin.fail())
		{
			cout << "Please enter an integer number!" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
		}
		else
			return size;
	}
}

string getFileName(string message)
{
	string fileName;

	while (true)
	{
		cout << message;
		cin >> fileName;

		if (cin.fail())
		{
			cout << "Please enter an string value!" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
		}
		else
			return fileName + ".txt";
	}
}

string getFindString(string message)
{
	string stringName;

	while (true)
	{
		cout << message;
		cin >> stringName;

		if (cin.fail())
		{
			cout << "Please enter an string value!" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
		}
		else
			return stringName;
	}
}
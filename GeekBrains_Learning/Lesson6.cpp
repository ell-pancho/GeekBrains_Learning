#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

#include "myFunctions.h"

namespace fs = std::filesystem;
using namespace std;

void task1()
{
	int inputSize;
	int* ptrArray;

	inputSize = getIntegerInput();

	if (inputSize > 0)
	{
		ptrArray = new (nothrow) int[inputSize];

		if (ptrArray != nullptr)
		{
			int powValue;
			for (size_t i = 0; i < inputSize; i++)
			{
				powValue = 1 << i;
				ptrArray[i] = powValue;
			}

			printArray(ptrArray, inputSize);

			delete[] ptrArray;
			ptrArray = nullptr;
		}
		else
			cout << "Can't allocate memory" << endl;
	}
}

void task2()
{
	const int m = 4, n = 4;
	int** ptrArray;

	ptrArray = new (nothrow) int* [m];
	for (size_t i = 0; i < m; i++)
		ptrArray[i] = new (nothrow) int[n];

	if (ptrArray != nullptr)
	{
		for (size_t i = 0; i < m; i++)
			for (size_t j = 0; j < n; j++)
				ptrArray[i][j] = rand();

		print2Array(ptrArray, m, n);

		for (size_t i = 0; i < m; i++) {
			delete[] ptrArray[i];
		}
		delete[] ptrArray;
		ptrArray = nullptr;
	}
	else
		cout << "Can't allocate memory" << endl;
}

string task3(string message)
{
	string fileName, randomLetter = "start_letter ";
	char tmpLetter;
	int lenghtLetter;
	fileName = getFileName(message);
	int max = 10, min = 1;

	ofstream fout(fileName);

	int fillNumber = 100;
	for (size_t i = 0; i<fillNumber; i++)
	{
		lenghtLetter = rand() % (max - min + 1) + min;
		
		for (size_t j = 0; j < lenghtLetter; j++)
		{
			tmpLetter = 'a' + rand() % 26;
			randomLetter += tmpLetter;
		}
		fout << randomLetter << endl;
		randomLetter = "new_line ";
	}

	fout.close();

	return fileName;
}

void task4(string fileName1, string fileName2)
{
	string fileName;
	string tmpString;
	fileName = getFileName("Enter the name of the file to write to: ");

	ifstream fin1(fileName1);
	ifstream fin2(fileName2);
	ofstream fout(fileName);

	if (fin1.is_open())
	{
		while (!fin1.eof())
		{
			getline(fin1, tmpString);
			fout << tmpString << endl;
		}
		fin1.close();
	}

	if (fin2.is_open())
	{
		while (!fin2.eof())
		{
			getline(fin2, tmpString);
			fout << tmpString << endl;
		}
		fin2.close();
	}

	fout.close();
}

bool task5(string fileName, string findString)
{
	if (!fs::exists(fileName))
	{
		cout << "File doesn't exists" << endl;
		return false;
	}
		
	string tmpString;
	ifstream fin(fileName);

	if (fin.is_open())
	{
		while (!fin.eof())
		{
			getline(fin, tmpString);

			if (tmpString.find(findString) != string::npos)
			{
				cout << tmpString << endl;
				return true;
			}
		}
		fin.close();
	}

	return false;
}

int main()
{
	task1();
	task2();

	string fileName1, fileName2;

	fileName1 = task3("Enter an file name #1: ");
	fileName2 = task3("Enter an file name #2: ");

	task4(fileName1, fileName2);

	bool stringExist;
	string fileName, findString;
	fileName = getFileName("Enter an file name where find string: ");
	findString = getFindString("Enter the string you want to find: ");

	stringExist = task5(fileName, findString);

	if (stringExist)
		cout << "String found" << endl;
	else
		cout << "String no found" << endl;

	return 0;
}
#include <iostream>

using namespace std;


namespace MyLib 
{
	int getInputInteger()
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

	int* initArray(int size)
	{
		int* ptrArray;
		ptrArray = new (nothrow) int[size];
		for (size_t i = 0; i < size; i++)
			ptrArray[i] = (rand() % 2101) - 100;
		return ptrArray;
	}

	void printMyArray(int* array, int size)
	{
		for (size_t i = 0; i < size; i++)
			cout << array[i] << " ";;
		cout << endl;
	}

	void countElements(int* array, int size)
	{
		int positiveCount = 0, negativeCount = 0;

		for (size_t i = 0; i < size; i++)
			if (array[i] > 0)
				positiveCount += 1;
			else
				negativeCount += 1;

		cout << "Cout positive elements: " << positiveCount << endl;
		cout << "Cout negative elements: " << negativeCount << endl;
	}
}

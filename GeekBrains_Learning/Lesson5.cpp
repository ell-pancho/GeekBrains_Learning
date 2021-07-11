#include <iostream>

void spacer()
{
	std::cout << std::endl;
}

void print_array(double * array, int size)
{
	for (size_t i = 0; i < size; i++)
		std::cout << array[i] << " ";
}

void print_array(int* array, int size)
{
	for (size_t i = 0; i < size; i++)
		std::cout << array[i] << " ";;
}

void invert_array(int* array, int size)
{
	for (size_t i = 0; i < size; i++)
		array[i] = !array[i];
}

void fill_array(int* array, int size)
{
	array[0] = 1;
	for (size_t i = 1; i < size; i++)
		array[i] = array[i-1] + 3;
}

void shift_array(int* array, int size, int shift)
{
	int tmp;

	for (size_t i = 0; i < abs(shift); i++)
	{

		if (shift > 0)
		{
			tmp = array[size - 1];
			for (size_t j = size - 1; j > 0; j--)
				array[j] = array[j - 1];
			array[0] = tmp;
		}
		else
		{
			tmp = array[0];
			for (size_t j = 0; j < size; j++)
				array[j] = array[j + 1];
			array[size-1] = tmp;
		}
	}
}

bool check_array(int* array, int size)
{
	int tmp;
	int sum;

	tmp = 0;

	for (size_t i = 0; i < size; i++)
	{
		tmp += array[i];
		sum = 0;
		for (size_t j = i + 1; j < size; j++)
		{
			sum += array[j];
			if (sum > tmp)
				break;
		}
		if (sum == tmp)
			return true;
	}

	return false;
}

int lesson5()
{
	
	// Task1

	const int arraySize = 5;
	double myArray[arraySize] = {2.45555, 3.4444, 5.6666, 3.44444, 98.65656};

	print_array(myArray, arraySize);
	spacer();

	// Task2

	const int arraySize2 = 6;
	int myArray2[arraySize2] = { 0, 1, 0, 0, 1, 0 };

	print_array(myArray2, arraySize2);
	invert_array(myArray2, arraySize2);
	spacer();
	print_array(myArray2, arraySize2);
	spacer();

	// Task3

	const int arraySize3 = 8;
	int myArray3[arraySize3];

	fill_array(myArray3, arraySize3);
	print_array(myArray3, arraySize3);
	spacer();

	// Task4

	print_array(myArray3, arraySize3);
	shift_array(myArray3, arraySize3, 3);
	spacer();
	print_array(myArray3, arraySize3);
	shift_array(myArray3, arraySize3, -3);
	spacer();
	print_array(myArray3, arraySize3);

	// Task5
	
	spacer();
	const int arraySize4 = 5;
	int myArray4[arraySize4] = { 1, 1, 1, 2, 1 };

	const int arraySize5 = 5;
	int myArray5[arraySize5] = { 2, 1, 1, 2, 1 };

	const int arraySize6 = 5;
	int myArray6[arraySize6] = { 10, 1, 2, 3, 4 };

	const int arraySize7 = 3;
	int myArray7[arraySize7] = { 1, 2, 3 };

	const int arraySize8 = 10;
	int myArray8[arraySize8] = { 1, 2, 3, 1, 3, 5, 5, 0, 1, 2 };

	bool result;

	result = check_array(myArray4, arraySize4);
	std::cout << result << std::endl; //true

	result = check_array(myArray5, arraySize5);
	std::cout << result << std::endl; //false

	result = check_array(myArray6, arraySize6);
	std::cout << result << std::endl; //true

	result = check_array(myArray7, arraySize7);
	std::cout << result << std::endl; //true

	result = check_array(myArray8, arraySize8);
	std::cout << result << std::endl; //false

	return 0;
}
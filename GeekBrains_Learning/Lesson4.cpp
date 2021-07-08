#include <iostream>

int lesson4()
{
	// Task 1
	
	{
		int firstValue, secondValue;

		std::cout << "Enter first number:" << std::endl;
		std::cin >> firstValue;

		std::cout << "Enter second number:" << std::endl;
		std::cin >> secondValue;

		int sum = firstValue + secondValue;

		if (sum >= 10 && sum <= 20)
			std::cout << "true";
		else
			std::cout << "false";

		std::cout << std::endl;
	}

	// Task 2

	{
		int firstValue, secondValue;

		firstValue = 5;
		secondValue = 5;

		if ((firstValue == 10 && secondValue == 10) || (firstValue + secondValue) == 10)
			std::cout << "true";
		else
			std::cout << "false";

		std::cout << std::endl;
	}

	// Task 3

	{	
		std::cout << "Your numbers: ";

		for (size_t i = 0; i <= 50; i++)
			if (i % 2 != 0)
				std::cout << i << " ";

		std::cout << std::endl;
	}

	// Task 4

	{
		int checkValue = 12;
		bool isSimple = true;

		for (size_t i = 2; i < checkValue; i++)
			if (checkValue % i == 0)
			{
				isSimple = false;
				break;
			}
		
		if (isSimple)
			std::cout << "Number is simple";
		else
			std::cout << "Number is not simple";

		std::cout << std::endl;
	}

	// Task 5

	{
		int yearValue;

		std::cout << "Enter year (from 1 to 3000)" << std::endl;
		std::cin >> yearValue;

		if (yearValue % 4 == 0)
			if (yearValue % 100 == 0)
				if (yearValue % 400 == 0)
					std::cout << "true";
				else
					std::cout << "false";
			else
				std::cout << "true";
		else
			std::cout << "false";

		std::cout << std::endl;

	}

	return 0;

}
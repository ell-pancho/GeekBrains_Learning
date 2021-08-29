#include <iostream>
#include <random>
#include <stdlib.h>
#include <chrono>
#include <string>

using namespace std;

enum Cell {
	CROSS = 'X',
	ZERO = 'O',
	EMPTY = '_'
};

struct Coord {
	size_t y;
	size_t x;
};

struct Settings {
	size_t fieldSize;
	size_t cellForWon;
};

enum Progress {
	IN_PROGRESS,
	HUMAN_WON,
	AI_WON,
	DRAW
};

struct Field {
	Cell** pField = nullptr;
	size_t SIZE = 3;
	size_t CELL_FOR_WON = 3;
	size_t turn = 0;
	Progress progress = IN_PROGRESS;
	Cell human;
	Cell ai;
};

void clear()
{
	system("cls");
}

Progress getWon(const Field& f);

int32_t getRandomNum(int32_t min, int32_t max)
{
	const static auto seed = chrono::system_clock::now().time_since_epoch().count();
	static mt19937_64 generator(seed);
	uniform_int_distribution<int32_t> dis(min, max);
	return dis(generator);
}

void setFieldSize(Field& f)
{

	while (true)
	{
		cout << "Enter field size (3, infinity): ";
		cin >> f.SIZE;

		if (cin.fail())
		{
			cout << "Please enter an integer value!" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
		}
		else if(f.SIZE < 3)
			continue;
		else
			break;
	}
}

void setCountWonCellSize(Field& f)
{

	while (true)
	{
		cout << "Enter cout cell for won: ";
		cin >> f.CELL_FOR_WON;

		if (cin.fail())
		{
			cout << "Please enter an integer value!" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
		}
		else if (f.CELL_FOR_WON > f.SIZE)
		{
			cout << "Please enter size lower, or equal " << f.SIZE << "!" << endl;
			continue;
		}
		else
			break;
	}
}

int getCellCoord(const Field& f, string message)
{
	int size;

	while (true)
	{
		cout << "Enter an integer value for " << message << ":";
		cin >> size;

		if (cin.fail())
		{
			cout << "Please enter an integer number!" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
		}
		else if (size > f.SIZE)
		{
			cout << "Please enter size lower, or equal " << f.SIZE << "!" << endl;
			continue;
		}
		else
			return size;
	}
}

void initField(Field& f)
{
	f.pField = new (nothrow) Cell * [f.SIZE];

	for (size_t i = 0; i < f.SIZE; i++)
		f.pField[i] = new (nothrow) Cell[f.SIZE];

	for (size_t y = 0; y < f.SIZE; y++)
		for (size_t x = 0; x < f.SIZE; x++)
			f.pField[y][x] = EMPTY;

	if (getRandomNum(0, 1000) > 500)
	{
		f.human = CROSS;
		f.ai = ZERO;
		f.turn = 0;
	}
	else
	{
		f.human = ZERO;
		f.ai = CROSS;
		f.turn = 1;
	}
}

void deinitField(Field& f)
{
	for (size_t i = 0; i < f.SIZE; i++)
		delete[] f.pField[i];

	delete[] f.pField;
	f.pField = nullptr;
}

void printField(const Field& f)
{
	cout << "      ";

	for (size_t x = 0; x < f.SIZE; x++)
	{
		cout << "x" << x + 1 << "  ";
	}

	cout << endl;

	for (size_t y = 0; y < f.SIZE; y++)
	{
		cout << " y" << y + 1 << " | ";

		for (size_t x = 0; x < f.SIZE; x++)
		{
			cout << (char)f.pField[y][x] << " | ";
		}

		cout << endl;
	}

	cout << endl;
	cout << "Human: " << (char)f.human << endl;
	cout << "AI: " << (char)f.ai << endl;
}

Coord getHumanCoord(const Field& f)
{
	Coord c{ 0, 0 };

	do {
		c.x = getCellCoord(f, "X Coord");
		c.y = getCellCoord(f, "Y Coord");

		c.x--;
		c.y--;
	} while (f.pField[c.y][c.x] != EMPTY);

	return c;
}

Coord getAICoord(Field& f)
{
	for (size_t y = 0; y < f.SIZE; y++)
	{
		for (size_t x = 0; x < f.SIZE; x++)
		{
			if (f.pField[y][x] == EMPTY)
			{
				f.pField[y][x] = f.ai;
				if (getWon(f) == AI_WON)
				{
					f.pField[y][x] = EMPTY;
					return { y, x };
				}
				f.pField[y][x] = EMPTY;
			}
		}
	}

	for (size_t y = 0; y < f.SIZE; y++)
	{
		for (size_t x = 0; x < f.SIZE; x++)
		{
			if (f.pField[y][x] == EMPTY)
			{
				f.pField[y][x] = f.human;
				if (getWon(f) == HUMAN_WON)
				{
					f.pField[y][x] = EMPTY;
					return { y, x };
				}
				f.pField[y][x] = EMPTY;
			}
		}
	}

	// Center

	for (size_t y = 1; y < f.SIZE-1; y++)
		for (size_t x = 1; x < f.SIZE-1; x++)
			if (f.pField[y][x] == EMPTY)
				return { y, x };

	// Angle

	size_t size = f.SIZE - 1;

	if (f.pField[0][0] == EMPTY)
		return { 0, 0 };
	if (f.pField[size][0] == EMPTY)
		return { size, 0 };
	if (f.pField[0][size] == EMPTY)
		return { 0, size };
	if (f.pField[size][size] == EMPTY)
		return { size, size };
	
	if (getRandomNum(0, 1000) > 500)
	{
		// Side vertical

		for (size_t y = 1; y < f.SIZE; y++)
		{
			if (f.pField[y][0] == EMPTY)
				return { y, 0 };
			if (f.pField[y][size - 1] == EMPTY)
				return { y, size - 1 };
		}
	}
	else 
	{
		// Side horizontal

		for (size_t x = 1; x < f.SIZE; x++)
		{
			if (f.pField[0][x] == EMPTY)
				return { 0, x };
			if (f.pField[size - 1][x] == EMPTY)
				return { size - 1, x };
		}
	}
}	

Progress getWon(const Field& f)
{
	int humanCount = 1, aiCount = 1;
	Cell prevCell = EMPTY, currentCell = EMPTY;

	// Check horizontal cells

	for (size_t y = 0; y < f.SIZE; y++)
	{

		humanCount = 0;
		aiCount = 0;
		prevCell = f.pField[y][0];

		if (prevCell == f.human)
			humanCount = 1;
		if (prevCell == f.ai)
			aiCount = 1;

		for (size_t x = 1; x < f.SIZE; x++)
		{	
			currentCell = f.pField[y][x];

			if (currentCell != prevCell)
			{
				if (humanCount == f.CELL_FOR_WON)
					return HUMAN_WON;
				if (aiCount == f.CELL_FOR_WON)
					return AI_WON;

				if (prevCell == f.human)
					humanCount = 0;
				if (prevCell == f.ai)
					aiCount = 0;
			}

			if (currentCell == f.human)
				humanCount++;
			else if (currentCell == f.ai)
				aiCount++;

			if (humanCount == f.CELL_FOR_WON)
				return HUMAN_WON;
			if (aiCount == f.CELL_FOR_WON)
				return AI_WON;

			prevCell = currentCell;
		}
	}

	// Check vertical cells

	for (size_t x = 0; x < f.SIZE; x++)
	{
		humanCount = 0;
		aiCount = 0;
		prevCell = f.pField[0][x];

		if (prevCell == f.human)
			humanCount = 1;
		if (prevCell == f.ai)
			aiCount = 1;

		for (size_t y = 1; y < f.SIZE; y++)
		{
			currentCell = f.pField[y][x];

			if (currentCell != prevCell)
			{
				if (humanCount == f.CELL_FOR_WON)
					return HUMAN_WON;
				if (aiCount == f.CELL_FOR_WON)
					return AI_WON;

				if (prevCell == f.human)
					humanCount = 0;
				if (prevCell == f.ai)
					aiCount = 0;
			}

			if (currentCell == f.human)
				humanCount++;
			else if (currentCell == f.ai)
				aiCount++;

			if (humanCount == f.CELL_FOR_WON)
				return HUMAN_WON;
			if (aiCount == f.CELL_FOR_WON)
				return AI_WON;

			prevCell = currentCell;
		}
	}

	// Check main diagonal

	humanCount = 0;
	aiCount = 0;
	prevCell = f.pField[0][0];

	if (prevCell == f.human)
		humanCount = 1;
	if (prevCell == f.ai)
		aiCount = 1;

	for (size_t y = 1; y < f.SIZE; y++)
	{
		currentCell = f.pField[y][y];

		if (currentCell != prevCell)
		{
			if (humanCount == f.CELL_FOR_WON)
				return HUMAN_WON;
			if (aiCount == f.CELL_FOR_WON)
				return AI_WON;

			if (prevCell == f.human)
				humanCount = 0;
			if (prevCell == f.ai)
				aiCount = 0;
		}

		if (currentCell == f.human)
			humanCount++;
		else if (currentCell == f.ai)
			aiCount++;

		if (humanCount == f.CELL_FOR_WON)
			return HUMAN_WON;
		if (aiCount == f.CELL_FOR_WON)
			return AI_WON;

		prevCell = currentCell;
	}

	// Check secondary diagonal

	int step = 1;
	humanCount = 0;
	aiCount = 0;
	prevCell = f.pField[0][f.SIZE-1];

	if (prevCell == f.human)
		humanCount = 1;
	if (prevCell == f.ai)
		aiCount = 1;

	for (size_t x = f.SIZE-1; x > 0; x --)
	{
		currentCell = f.pField[step][x-1];

		if (currentCell != prevCell)
		{
			if (humanCount == f.CELL_FOR_WON)
				return HUMAN_WON;
			if (aiCount == f.CELL_FOR_WON)
				return AI_WON;

			if (prevCell == f.human)
				humanCount = 0;
			if (prevCell == f.ai)
				aiCount = 0;
		}

		if (currentCell == f.human)
			humanCount++;
		else if (currentCell == f.ai)
			aiCount++;

		if (humanCount == f.CELL_FOR_WON)
			return HUMAN_WON;
		if (aiCount == f.CELL_FOR_WON)
			return AI_WON;

		prevCell = currentCell;
		step++;
	}

	// Check empty cells

	for (size_t y = 0; y < f.SIZE; y ++)
	{
		for (size_t x = 0; x < f.SIZE; x ++)
		{
			if (f.pField[y][x] == EMPTY)
				return IN_PROGRESS;
		}
	}

	return DRAW;
}

int main()
{
	Field f;

	clear();
	setFieldSize(f);
	setCountWonCellSize(f);
	clear();
	initField(f);
	printField(f);

	do {
		
		if (f.turn % 2 == 0)
		{
			Coord c = getHumanCoord(f);
			f.pField[c.y][c.x] = f.human;
		}
		else
		{
			Coord c = getAICoord(f);
			f.pField[c.y][c.x] = f.ai;
		}

		clear();
		printField(f);

		f.turn++;
		f.progress = getWon(f);

	} while (f.progress == IN_PROGRESS);

	cout << endl;

	if (f.progress == HUMAN_WON)
		cout << "Human won!";
	else if (f.progress == AI_WON)
		cout << "AI won!";
	else
		cout << "Draw!";

	cout << endl;

	deinitField(f);

	return 0;
}

#include <iostream>

short int short_int_value = 50;
int iValue = 12345;
long long lValue = 1000000;

char char_value[] = "string";
bool bValue = true;

float float_value = 0.5;
double double_value = 0.1;

CellState Field[3][3] = {
    {CROSS, CROSS, ZERO},
    {ZERO, ZERO, CROSS},
    {CROSS, ZERO, CROSS}
};

enum CellState { EMPTY, ZERO, CROSS };

struct Game
{
    char player1;               // Имя первого игрока
    char player2;               // Имя второго игрока
    bool playerMove;            // Какой игрок ходит
    CellState Field[3][3];      // Состояние игрового поля
    unsigned int iPosX : 2;     // Текущая позиция по X
    unsigned int iPosY : 2;     // Текущая позиция по Y
};

union Storage
{
    int iValue;
    float fValue;
    char cValue;
};

struct Variant
{
    Storage uValue;
    bool isInt;
    bool isFloat;
    bool isChar;
};


int main()
{

    Variant newVariant;

    newVariant.uValue.iValue = 10;
    newVariant.isInt = true;
    newVariant.isFloat = false;
    newVariant.isChar = false;

    newVariant.uValue.cValue = 'Test';
    newVariant.isInt = false;
    newVariant.isFloat = false;
    newVariant.isChar = true;

    return 0;
};

#include <iostream>
#include "cipher.h"

RouteCipher::RouteCipher()
{
    this->columns = 0;
    this->rows = 0;
    this->text = "";
}

RouteCipher::RouteCipher(std::string text, int columns, int rows)
{
    this->text = text;
    this->columns = columns;
    this->rows = rows;
}

std::string RouteCipher::Cipher(RouteType routeType)
{
    ClockwiseLeft();
    return "";
}

std::string RouteCipher::ClockwiseLeft()
{
    char **chipherRectangle = new char * [rows];
    for(int i = 0; i < columns; i++)
        chipherRectangle[i] = new char[columns];

    int k = 0;
    std::string emptyChar = "X";
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            if(k < text.length())
                chipherRectangle[i][j] = text[k];
            else
                chipherRectangle[i][j] = emptyChar[0];
            ++k;
        }
    }

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            std::cout << chipherRectangle[i][j] << " ";
        }
        std::cout << "\n";
    }

    for(int i = 0; i < rows; i++)
        delete [] chipherRectangle[i];
    delete [] chipherRectangle;
    chipherRectangle = nullptr;

    return "";
}
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
        std::vector< std::vector<char>> chipherRectangle;

    chipherRectangle.resize(rows);
    for(int i = 0; i < rows; i++)
        chipherRectangle[i].resize(columns);


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

    std::string cipherText;

    switch(routeType)
    {
        case CLOCKWISE_LEFT:
            cipherText = ClockwiseLeft(chipherRectangle);
            break;
        case CLOCKWISE_RIGHT:
            cipherText = ClockwiseRight(chipherRectangle);
            break;
        default:
            std::cout << "Not Implemented";
    }
    
    
    return cipherText;
}

std::string RouteCipher::ClockwiseLeft(const std::vector<std::vector<char>> & chipherRectangle)
{

    int chipherRectangleArea = rows * columns;
    std::string cipherText = "";

    int topLimit = 0;
    int leftLimit = 0;
    int bottomLimit = rows - 1;
    int rightLimit = columns - 1;
    MoveDirection moveDirection = RIGHT;

    for(int i = 0, j = 0, k = 0; i < chipherRectangleArea; i++)
    {
        cipherText += chipherRectangle[j][k];
        switch(moveDirection)
        {
            case RIGHT:
                k++;
                if(k == rightLimit)
                {
                    moveDirection = DOWN;
                    topLimit++;
                }
                break;
            case LEFT:
                k--;
                if(k == leftLimit)
                {
                    moveDirection = UP;
                    bottomLimit--;
                }
                break;
            case UP:
                j--;
                if(j == topLimit)
                {
                    moveDirection = RIGHT;
                    leftLimit++;
                }
                break;
            case DOWN:
                j++;
                if(j == bottomLimit)
                {
                    moveDirection = LEFT;
                    rightLimit--;
                }
                break;
        }
    }

    return cipherText;
}

std::string RouteCipher::ClockwiseRight(const std::vector<std::vector<char>> & chipherRectangle)
{
    int chipherRectangleArea = rows * columns;
    std::string cipherText = "";

    int topLimit = 0;
    int leftLimit = 0;
    int bottomLimit = rows - 1;
    int rightLimit = columns - 1;
    MoveDirection moveDirection = DOWN;

    for(int i = 0, j = 0, k = columns - 1; i < chipherRectangleArea; i++)
    {
        cipherText += chipherRectangle[j][k];
        switch(moveDirection)
        {
            case RIGHT:
                k++;
                if(k == rightLimit)
                {
                    moveDirection = DOWN;
                    topLimit++;
                }
                break;
            case LEFT:
                k--;
                if(k == leftLimit)
                {
                    moveDirection = UP;
                    bottomLimit--;
                }
                break;
            case UP:
                j--;
                if(j == topLimit)
                {
                    moveDirection = RIGHT;
                    leftLimit++;
                }
                break;
            case DOWN:
                j++;
                if(j == bottomLimit)
                {
                    moveDirection = LEFT;
                    rightLimit--;
                }
                break;
        }
    }

    return cipherText;
}
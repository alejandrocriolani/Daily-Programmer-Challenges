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
            cipherText = Clockwise(chipherRectangle, LEFT);
            break;
        case CLOCKWISE_RIGHT:
            cipherText = Clockwise(chipherRectangle, RIGHT);
            break;
        case COUNTERCLOCKWISE_LEFT:
            cipherText = CounterClockwise(chipherRectangle, LEFT);
            break;
        case COUNTERCLOCKWISE_RIGHT:
            cipherText = CounterClockwise(chipherRectangle, RIGHT);
            break;
        default:
            std::cout << "ERROR";
    }
    
    
    return cipherText;
}

std::string RouteCipher::Clockwise(const std::vector<std::vector<char>> & chipherRectangle,
                                       MoveDirection startPosition)
{
    int topLimit = 0;
    int leftLimit = 0;
    int bottomLimit = rows - 1;
    int rightLimit = columns - 1;
    int j, k;
    int chipherRectangleArea = rows * columns;
    std::string cipherText = "";
    MoveDirection moveDirection;

    switch(startPosition)
    {
        case LEFT:
            moveDirection = RIGHT;
            j = k = 0;
            break;
        case RIGHT:
            moveDirection = DOWN;
            j = 0;
            k = columns - 1;
            break;
    }

    for(int i = 0; i < chipherRectangleArea; i++)
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

std::string RouteCipher::CounterClockwise(const std::vector<std::vector<char>> & chipherRectangle,
                                          MoveDirection startPosition)
{
    int topLimit = 0;
    int leftLimit = 0;
    int bottomLimit = rows - 1;
    int rightLimit = columns - 1;
    int j, k;
    int chipherRectangleArea = rows * columns;
    std::string cipherText = "";
    MoveDirection moveDirection;

    switch(startPosition)
    {
        case LEFT:
            moveDirection = DOWN;
            j = k = 0;
            break;
        case RIGHT:
            moveDirection = LEFT;
            j = 0;
            k = columns - 1;
            break;
    }

    for(int i = 0; i < chipherRectangleArea; i++)
    {
        cipherText += chipherRectangle[j][k];
        switch(moveDirection)
        {
            case RIGHT:
                k++;
                if(k == rightLimit)
                {
                    moveDirection = UP;
                    bottomLimit--;
                }
                break;
            case LEFT:
                k--;
                if(k == leftLimit)
                {
                    moveDirection = DOWN;
                    topLimit++;
                }
                break;
            case UP:
                j--;
                if(j == topLimit)
                {
                    moveDirection = LEFT;
                    rightLimit--;
                }
                break;
            case DOWN:
                j++;
                if(j == bottomLimit)
                {
                    moveDirection = RIGHT;
                    leftLimit++;
                }
                break;
        }
    }
    return cipherText;
}
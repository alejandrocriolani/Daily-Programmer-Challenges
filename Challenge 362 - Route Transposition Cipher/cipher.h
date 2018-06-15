#ifndef CIPHER_H
#define CIPHER_H

#include <string>
#include <vector>

enum RouteType {
            CLOCKWISE_LEFT, CLOCKWISE_RIGHT,
            COUNTERCLOCKWISE_LEFT, COUNTERCLOCKWISE_RIGHT
        };

class RouteCipher
{
    public:
        enum MoveDirection
        {
            RIGHT, LEFT, UP, DOWN
        };

        RouteCipher();
        RouteCipher(std::string text, int columns, int rows);
        std::string Cipher(RouteType routeType = CLOCKWISE_LEFT);

    private:
        std::string Clockwise(const std::vector<std::vector<char>> & chipherRectangle,
                              MoveDirection startPosition);
        std::string CounterClockwise(const std::vector<std::vector<char>> & chipherRectangle,
                                    MoveDirection startPosition);
        std::string text;
        int columns;
        int rows;
};

#endif
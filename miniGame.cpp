#include <iostream>
#include <stdlib.h>
#include <time.h>

int posX = 6;
int posY = 1;
int foodX = 0;
int foodY = 0;

void generateFood()
{
    foodX = (rand() % 67) + 2;
    foodY = (rand() % 13) + 1;
    // if (foodX == 0)
    //     foodX = 5;
    if (foodY == 6 && foodX < 39)
        foodY++;
    if (foodY > 6 && (foodY != 9 && foodY != 10) && foodX == 38 && foodX != 0)
        foodX++;
}

void draw()
{
    // print first row
    for (int i = 0; i < 70; i++)
    {
        std::cout << "#";
        if (i == 69)
            std::cout << "\n";
    }

    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 70; j++)
        {
            // print middle row
            if (i == 6 && j < 39 && j != 0)
                std::cout << "\b#";
            // print vertical middle column
            if (i > 6 && (i != 10) && j == 38 && j != 0)
                std::cout << "\b#";
            //print food
            if (i == foodY && j == foodX)
                std::cout << "\bF";

            // print player
            if (i == posY && j == posX)
                std::cout << "\bP";

            if (j == 0 || j == 69)
                std::cout << "#";
            else
                std::cout << " ";
            if (i == 14)
                std::cout << "\b#";
        }
        std::cout << "\n";
    }
}

void move()
{
    char choice;
    std::cin >> choice;
    switch (choice)
    {
    case 'w':
        posY--;
        break;
    case 's':
        posY++;
        break;
    case 'd':
        posX++;
        break;
    case 'a':
        posX--;
        break;
    default:
        break;
    }
}

bool win()
{
    if (posX == foodX && posY == foodY)
        return true;
    return false;
}

bool lose()
{

    if (posY == 6 && posX < 39)
        return true;
    if (posX == 1)
        return true;
    if (posX == 38 && (posY == 7 || posY == 8 || posY == 9 || posY == 11 || posY == 12 || posY == 13 || posY == 14))
        return true;
    if (posX == 70)
        return true;
    if (posY == -1)
        return true;
    if (posY == 14)
        return true;
    return false;
}

int main()
{
    system("clear");
    srand(time(NULL));
    generateFood();

    while (1)
    {
        system("clear");
        draw();
        move();

        if (win())
        {
            system("clear");
            draw();
            puts("\n\t\t\tYou Win\n\n");
            break;
        }
        if (lose())
        {
            system("clear");
            draw();
            puts("\n\t\t\tYou lose\n\n");
            break;
        }
    }

    return 0;
}
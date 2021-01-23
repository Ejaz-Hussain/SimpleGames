#include <iostream>
// to be pasted in windows and "clear" needs to be "cls"; thats it;
int posX = 3;
int posY = 2;

int foodX = 55;
int foodY = 5;

void help();

void display()
{
    for (int i = 0; i < 60; i++)
    {
        std::cout << "#";
        if (i == 59)
            std::cout << "\n";
    }

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 60; j++)
        {
            if (j == 0 || j == 59)
            {
                std::cout << "#";
            }
            else if (i == posY && j == posX)
                std::cout << "P";
            else if (i == foodY && j == foodX)
                std::cout << "F";
            else
                std::cout << " ";
        }
        std::cout << "\n";
    }

    for (int i = 0; i < 60; i++)
    {
        std::cout << "#";
        if (i == 59)
            std::cout << "\n";
    }
}

void move()
{
    char ch;
    std::cin >> ch;
    switch (ch)
    {
    case 'w':
        posY--;
        break;
    case 'a':
        posX--;
        break;
    case 'd':
        posX++;
        break;
    case 's':
        posY++;
        break;
    default:
        break;
    }
}

bool win()
{
    if (posX == foodX && posY == foodY)
    {
        system("clear");
        help();

        display();

        puts("\n\t\t\tYou win\n");
        return true;
    }
    if (posX == 59 || posX == 0 || posY == -1 || posY == 7)
    {
        system("clear");
        help();
        display();

        puts("\n\t\t\tYou lose\n");
        return true;
    }
    return false;
}

void help()
{
    std::cout << "\n\n\t    w = UP, s = DOWN, a = LEFT, d = RIGHT\n\n";
}

int main()
{

    while (!win())
    {
        system("clear");
        help();
        display();
        move();
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    return 0;
}
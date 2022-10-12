#include "Blob-2.h"
using namespace std;

Blob::Blob()
{
    health = 100;
    power = 10;
    color = 1;
    xcoord = rand() % 10;
    ycoord = rand() % 10;
}

Blob::Blob(int x, int y)
{
    health = 100;
    power = 10;
    color = 1;
    xcoord = x;
    ycoord = y;
}

int Blob::gethealth() const
{
    return health;
}

void Blob::sethealth(int h)
{
    health = h;
}

int Blob::getpower() const
{
    return power;
}

void Blob::setpower(int p)
{
    power = p;
}

char Blob::getcolor() const
{
    return color;
}

void Blob::setcolor(char c)
{
    color = c;
}

int Blob::getxcoord() const
{
    return xcoord;
}

void Blob::setxcoord(int x)
{
    xcoord = x;
}

int Blob::getycoord() const
{
    return ycoord;
}

void Blob::setycoord(int y)
{
    ycoord = y;
}

ostream& operator<<(ostream& os, const Blob& b)
{
    os << b.xcoord << "," << b.ycoord;
    return os;
}

Blob operator+(Blob a, Blob b)
{
    Blob c;
    c.health = a.health + b.health;
    if (a.power > b.power)
    {
        c.power = a.power + 2;
    }
    else
    {
        c.power = b.power + 2;
    }
    c.xcoord = a.xcoord;
    c.ycoord = a.ycoord;
    c.color = a.color;
    return c;
}

bool CheckPosition(Blob a, Blob b)
{
    if (a.xcoord == b.xcoord && a.ycoord == b.ycoord)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Blob Move(Blob a, char c)
{
    if (c == 'N' || c == 'n')
    {
        if (a.ycoord == 9)
        {
            cout << "You are already at the border of the map. Please try again next turn" << endl;
        }

        else
        {
            ++a.ycoord;
        }
    }
    else if (c == 'S' || c == 's')
    {
        if (a.ycoord == 0)
        {
            cout << "You are already at the border of the map. Please try again next turn" << endl;
        }
        else
        {
            --a.ycoord;
        }
    }
    else if (c == 'E' || c == 'e')
    {
        if (a.xcoord == 9)
        {
            cout << "You are already at the border of the map. Please try again next turn" << endl;
        }
        else
        {
            ++a.xcoord;
        }
    }
    else if (c == 'W' || c == 'w')
    {
        if (a.xcoord == 0)
        {
            cout << "You are already at the border of the map. Please try again next turn" << endl;
        }
        else
        {
            --a.xcoord;
        }
    }
    else
    {
        cout << "Please enter a valid input" << endl;
    }
    return a;

}


Blob MoveBack(Blob a, char c)
{
    if (c == 'N' || c == 'n')
    {
        a.ycoord--;
    }
    else if (c == 'S' || c == 's')
    {
        a.ycoord++;
    }
    else if (c == 'E' || c == 'e')
    {
        a.xcoord--;
    }
    else if (c == 'W' || c == 'w')
    {
        a.xcoord++;
    }
    cout << "There is an opposing teams blob at this location, please move elsewhere or attack next turn." << endl;
    return a;
}

void Blob::DeadFlag()
{
    this->setxcoord(rand() % 1000 + 10);
    this->setycoord(rand() % 1000 + 10);
}

Blob CheckAttack(Blob a, char c)
{
    Blob temp;
    temp.ycoord = a.ycoord;
    temp.xcoord = a.xcoord;
    if (c == 'N' || c == 'n')
    {
        ++temp.ycoord;
    }
    else if (c == 'S' || c == 's')
    {
        --temp.ycoord;
    }
    else if (c == 'E' || c == 'e')
    {
        ++temp.xcoord;
    }
    else if (c == 'W' || c == 'w')
    {
        --temp.xcoord;
    }
    return temp;
}

Blob Attack(Blob a, Blob b)
{
    Blob c;
    c.health = b.health - a.power;
    c.xcoord = b.xcoord;
    c.ycoord = b.ycoord;
    c.power = b.power;
    return c;
}
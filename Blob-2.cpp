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


ostream& operator<<(std::ostream& os, const Blob& b) {
    os << b.getXCoord() << "," << b.getYCoord();
    return os;
}

Blob Blob::operator+(const Blob& a)
{
   Blob c;
   c.setHealth(a.getHealth() + getHealth());
   if (a.getPower() >= getPower()){
    c.setPower(a.getPower()+2);
   }
   else {
    c.setPower(getPower()+2);
   }
   c.setXCoord(a.getXCoord());
   c.setYCoord(a.getYCoord());
   c.setColor(a.getColor());
   return c;
}


void Blob::Move(Direction direction)
{
    switch (direction) {
        case Direction::North:
            if (getYCoord() == 9) {
                cout << "You are already at the border of the map. Please try again next turn" << endl;
            } else {
                setYCoord(getYCoord() + 1);
            }
            break;
        case Direction::South:
            if (getYCoord() == 0) {
                cout << "You are already at the border of the map. Please try again next turn" << endl;
            } else {
                setYCoord(getYCoord() - 1);
            }
            break;
        case Direction::East:
            if (getXCoord() == 9) {
                cout << "You are already at the border of the map. Please try again next turn" << endl;
            } else {
                setXCoord(getXCoord() + 1);
            }
            break;
        case Direction::West:
            if (getXCoord() == 0) {
                cout << "You are already at the border of the map. Please try again next turn" << endl;
            } else {
                setXCoord(getXCoord() - 1);
            }
            break;
    }

}


void Blob::MoveBack(Direction direction)
{
   switch (direction){
        case Direction::North:
            setYCoord(getYCoord()+1);
            break;
        case Direction::South:
            setYCoord(getYCoord()-1);
            break;
        case Direction::East:
            setXCoord(getXCoord()+1);
            break;
        case Direction::West:
            setXCoord(getXCoord()-1);
            break;
   }
   cout << "There is an opposing teams blob at this location, please move elsewhere or attack next turn." << endl;
}

void Blob::DeadFlag()
{
    this->setXCoord(rand() % 1000 + 10);
    this->setYCoord(rand() % 1000 + 10);
}

Blob Blob::CheckAttack(const Blob& a, Direction direction) const
{
    Blob temp;
    temp.setXCoord(a.getXCoord());
    temp.setYCoord(a.getYCoord());
    switch (direction){
        case Direction::North:
            temp.setYCoord(getYCoord()+1);
            break;
        case Direction::South:
            temp.setYCoord(getYCoord()-1);
            break;
        case Direction::East:
            temp.setXCoord(getXCoord()+1);
            break;
        case Direction::West:
            temp.setXCoord(getXCoord()-1);
            break;
    }
    return temp;
}

Blob Blob::Attack(const Blob& a, const Blob& b) const
{
    Blob c;
    c.setHealth(b.getHealth()-a.getPower());
    c.setXCoord(b.getXCoord());
    c.setYCoord(b.getYCoord());
    c.setPower(b.getPower());
    return c;
}
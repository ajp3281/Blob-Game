#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
class Blob
{
    friend ostream& operator<<(ostream& os, const Blob& b);
    friend Blob operator+(Blob a, Blob b);
    friend Blob Move(Blob a, char c);
    friend Blob MoveBack(Blob a, char c);
    friend bool CheckPosition(Blob a, Blob b);
    friend Blob CheckAttack(Blob a, char c);
    friend Blob Attack(Blob a, Blob b);
public:
    Blob();
    Blob(int x, int y);
    void DeadFlag();
    int gethealth() const;
    void sethealth(int);
    int getpower() const;
    void setpower(int);
    char getcolor() const;
    void setcolor(char);
    int getxcoord() const;
    void setxcoord(int);
    int getycoord() const;
    void setycoord(int);
private:
    int health;
    int power;
    char color;
    int xcoord;
    int ycoord;
};

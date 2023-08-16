#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
class Blob
{
    friend std::ostream& operator<<(std::ostream& os, const Blob& b);
public:
    enum class Direction {North, South, East, West};
    Blob();
    Blob(int x, int y);
    void DeadFlag();
    int getHealth() const { return health; }
    void setHealth(int h) { health = h; }
    int getPower() const { return power; }
    void setPower(int p) { power = p; }
    char getColor() const { return color; }
    void setColor(char c) { color = c; }
    int getXCoord() const { return xcoord; }
    void setXCoord(int x) { xcoord = x; }
    int getYCoord() const { return ycoord; }
    void setYCoord(int y) { ycoord = y; }
    void Move(Direction);
    void MoveBack(Direction);
    void deadFlag();
    static bool checkPosition(const Blob& a, const Blob& b) { return a.getXCoord() == b.getXCoord() && a.getYCoord() == b.getYCoord(); }
    Blob CheckAttack(const Blob&, Direction) const;
    Blob Attack(const Blob& a, const Blob& b) const;
    Blob operator+(const Blob& a);
private:
    int health;
    int power;
    char color;
    int xcoord;
    int ycoord;
};

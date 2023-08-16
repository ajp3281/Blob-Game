#include "Blob-2.h"

int main()
{
    int Blobturn, selectedblob;
    char inputDirection;
    bool attkcheck = false;
    int gameover = 0;
    int playercounter = 0;
    Blob Blobs[8];
    srand(time(NULL));
    for (int i = 0; i < 8; i++)
    {
        int match = 0;
        do
        {
            int x = rand() % 10;
            int y = rand() % 10;
            for (int j = 0; j < i; j++)
            {
                if (x == Blobs[j].getXCoord() && y == Blobs[j].getYCoord())
                {
                    match = 1;
                    cout << "Please rerun the program to get a new random seed." << endl;
                    return 0;
                    break;
                }
            }
            if (match == 0)
            {
                Blobs[i] = Blob(x, y);
            }
        } while (match == 1);
    }
    while (!gameover)
    {
        if ((Blobs[0].getHealth() <= 0 && Blobs[1].getHealth() <= 0 && Blobs[2].getHealth() <= 0 && Blobs[3].getHealth() <= 0)
            || (Blobs[4].getHealth() <= 0 && Blobs[5].getHealth() <= 0 && Blobs[6].getHealth() <= 0 && Blobs[7].getHealth() <= 0))
        {
            gameover = 1;
        }
        cout << "The blobs are located at: " << endl;
        for (int i = 0; i < 8; i++)
        {
            cout << "Blob " << i << ": (" << Blobs[i] << ")" << "\t" << Blobs[i].getHealth() << "HP" << "\t" << Blobs[i].getPower() << "PWR" << endl;
        }
        int turnvalid = 1;
        cout << "It is player " << playercounter << "'s turn!" << endl;
        cout << "Which blob would you like to play?" << endl;
        cin >> selectedblob;
        if ((playercounter == 0 && selectedblob < 4 && selectedblob >= 0)
            || (playercounter == 1 && selectedblob >= 4 && selectedblob < 8))
        {
            cout << "Player selected blob " << selectedblob << endl;
            cout << "If you would like to move with this Blob please enter 1 if you would like to attack please enter 2" << endl;
            cin >> Blobturn;
            Blob::Direction Blobdirection;
            if (Blobturn == 1)
            {
                cout << "Please enter the initial of the direction you would like to move in" << endl;
                cin >> inputDirection;
                switch (inputDirection) {
                    case 'n':
                    case 'N':
                        Blobdirection = Blob::Direction::North;
                    break;
                    case 's':
                    case 'S':
                        Blobdirection = Blob::Direction::South;
                    break;
                    case 'e':
                    case 'E':
                        Blobdirection = Blob::Direction::East;
                        break;
                    case 'w':
                    case 'W':
                        Blobdirection = Blob::Direction::West;
                        break;
                    default:
                        cout << "Invalid direction! Try again." << endl;
                }
                Blobs[selectedblob].Move(Blobdirection);
                if (playercounter == 0)
                {
                    for (int i = 1; i < 8; i++)
                    {
                        if (Blob::checkPosition(Blobs[selectedblob], Blobs[i]) && selectedblob != i && i < 4)
                        {
                            Blobs[selectedblob] = Blobs[selectedblob] + Blobs[i];
                            Blobs[i].DeadFlag();
                        }
                        else if (Blob::checkPosition(Blobs[selectedblob], Blobs[i]) && selectedblob != i)
                        {
                            Blobs[selectedblob].MoveBack(Blobdirection);
                        }
                    }
                }
                else if (playercounter == 1)
                {
                    for (int i = 1; i < 8; i++)
                    {
                        if (Blob::checkPosition(Blobs[selectedblob], Blobs[i]) && selectedblob != i && i > 4)
                        {
                            Blobs[selectedblob] = Blobs[selectedblob] + Blobs[i];
                            Blobs[i].DeadFlag();
                        }
                        else if (Blob::checkPosition(Blobs[selectedblob], Blobs[i]) && selectedblob != i)
                        {
                            Blobs[selectedblob].MoveBack(Blobdirection);
                        }
                    }
                }
            }
            else if (Blobturn == 2)
            {
                cout << "Please enter the initial of the direction you would like to attack in" << endl;
                cin >> inputDirection;
                switch (inputDirection) {
                    case 'n':
                    case 'N':
                        Blobdirection = Blob::Direction::North;
                    break;
                    case 's':
                    case 'S':
                        Blobdirection = Blob::Direction::South;
                    break;
                    case 'e':
                    case 'E':
                        Blobdirection = Blob::Direction::East;
                        break;
                    case 'w':
                    case 'W':
                        Blobdirection = Blob::Direction::West;
                        break;
                    default:
                        cout << "Invalid direction! Try again." << endl;
                }
                if (playercounter == 0)
                {
                    for (int i = 4; i < 8; i++)
                    {
                        if (Blob::checkPosition(Blobs[selectedblob].CheckAttack(Blobs[selectedblob], Blobdirection), Blobs[i]))
                        {
                            Blobs[i] = Blobs[selectedblob].Attack(Blobs[selectedblob], Blobs[i]);
                            attkcheck = true;
                            if (Blobs[i].getHealth() <= 0)
                            {
                                Blobs[i].DeadFlag();
                                turnvalid = 0;
                            }
                        }
                    }
                    if (attkcheck == false)
                    {
                        cout << "There is no opposing Blob to attack at this location. Please try again next turn" << endl;
                    }
                }
                else if (playercounter == 1)
                {
                    for (int i = 0; i < 4; i++)
                    {
                        if (Blob::checkPosition(Blobs[selectedblob].CheckAttack(Blobs[selectedblob], Blobdirection), Blobs[i]))
                        {
                            Blobs[i] = Blobs[selectedblob].Attack(Blobs[selectedblob], Blobs[i]);
                            attkcheck = true;
                            if (Blobs[i].getHealth() <= 0)
                            {
                                Blobs[i].DeadFlag();
                                turnvalid = 0;
                            }
                        }
                    }
                    if (attkcheck == false)
                    {
                       cout << "There is no opposing Blob to attack at this location. Please try again next turn" << endl;
                    }
                }
            }
            else
            {
                cout << "Invalid Blob selection! Try again" << endl;
                turnvalid = 0;
            }
            if (turnvalid)
            {
                playercounter = (playercounter + 1) % 2;
            }
        }
    }
    return 0;
}


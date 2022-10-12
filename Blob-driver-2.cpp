#include "Blob-2.h"

int main()
{
    int Blobturn, selectedblob;
    char Blobattack, Blobdirection;
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
                if (x == Blobs[j].getxcoord() && y == Blobs[j].getycoord())
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
        if ((Blobs[0].gethealth() <= 0 && Blobs[1].gethealth() <= 1 && Blobs[2].gethealth() <= 0 && Blobs[3].gethealth() <= 0)
            || (Blobs[4].gethealth() <= 0 && Blobs[5].gethealth() && Blobs[6].gethealth() <= 0 && Blobs[7].gethealth()))
        {
            gameover = 1;
        }
        cout << "The blobs are located at: " << endl;
        for (int i = 0; i < 8; i++)
        {
            cout << "Blob " << i << ": (" << Blobs[i] << ")" << "\t" << Blobs[i].gethealth() << "HP" << "\t" << Blobs[i].getpower() << "PWR" << endl;
        }
        int turnvalid = 1;
        cout << "It is player " << playercounter << "'s turn!" << endl;
        cout << "Which blob  would you like to play?" << endl;
        cin >> selectedblob;
        if ((playercounter == 0 && selectedblob < 4 && selectedblob >= 0)
            || (playercounter == 1 && selectedblob >= 4 && selectedblob < 8))
        {
            cout << "Player selected blob " << selectedblob << endl;
            cout << "If you would like to move with this Blob please enter 1 if you would like to attack please enter 2" << endl;
            cin >> Blobturn;
            if (Blobturn == 1)
            {
                cout << "Please enter the initial of the direction you would like to move in" << endl;
                cin >> Blobdirection;
                if (Blobturn == 1)
                {
                    Blobs[selectedblob] = Move(Blobs[selectedblob], Blobdirection);
                    if (playercounter == 0)
                    {
                        for (int i = 1; i < 8; i++)
                        {
                            if (CheckPosition(Blobs[selectedblob], Blobs[i]) == true && selectedblob != i && i < 4)
                            {
                                Blobs[selectedblob] = Blobs[selectedblob] + Blobs[i];
                                Blobs[i].DeadFlag();
                            }
                            else if (CheckPosition(Blobs[selectedblob], Blobs[i]) == true && selectedblob != i)
                            {
                                Blobs[selectedblob] = MoveBack(Blobs[selectedblob], Blobdirection);
                            }
                        }
                    }
                    else if (playercounter == 1)
                    {
                        for (int i = 1; i < 8; i++)
                        {
                            if (CheckPosition(Blobs[selectedblob], Blobs[i]) == true && selectedblob != i && i > 4)
                            {
                                Blobs[selectedblob] = Blobs[selectedblob] + Blobs[i];
                                Blobs[i].DeadFlag();
                            }
                            else if (CheckPosition(Blobs[selectedblob], Blobs[i]) == true && selectedblob != i)
                            {
                                Blobs[selectedblob] = MoveBack(Blobs[selectedblob], Blobdirection);
                            }
                        }
                    }
                }
            }
            else if (Blobturn == 2)
            {
                cout << "Please enter the direction you would like to attack in" << endl;
                cin >> Blobattack;
                if (playercounter == 0)
                {
                    for (int i = 4; i < 8; i++)
                    {
                        if (CheckPosition(CheckAttack(Blobs[selectedblob], Blobattack), Blobs[i]) == true)
                        {
                            Blobs[i] = Attack(Blobs[selectedblob], Blobs[i]);
                            attkcheck = true;
                            if (Blobs[i].gethealth() <= 0)
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
                        if (CheckPosition(CheckAttack(Blobs[selectedblob], Blobattack), Blobs[i]) == true)
                        {
                            Blobs[i] = Attack(Blobs[selectedblob], Blobs[i]);
                            attkcheck = true;
                            if (Blobs[i].gethealth() <= 0)
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

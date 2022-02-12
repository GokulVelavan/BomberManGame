#include <iostream>
using namespace std;

int p1, p2; // player index
int b1, b2; // bomb index
int b3, b4; // bomb index

bool play = true;
int BOMB = 0;

bool Power1 = false;
bool Power2 = false;
bool Power3 = false;

void printmap(char Map[12][12], int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << Map[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
};

void ChangeEightDirection(char Map[12][12], int i, int j) // When the bomb needs to blast in all the directions and not affecting the powers and key and *blocks
{
    if (Map[i + 1][j] != '*' && Map[i + 1][j] != 'K' && Map[i + 1][j] != '1' && Map[i + 1][j] != '2' && Map[i + 1][j] != '3')
        Map[i + 1][j] = ' ';
    if (Map[i - 1][j] != '*' && Map[i - 1][j] != 'K' && Map[i - 1][j] != '1' && Map[i - 1][j] != '2' && Map[i - 1][j] != '3')
        Map[i - 1][j] = ' ';
    if (Map[i][j + 1] != '*' && Map[i][j + 1] != 'K' && Map[i][j + 1] != '1' && Map[i][j + 1] != '2' && Map[i][j + 1] != '3')
        Map[i][j + 1] = ' ';
    if (Map[i][j - 1] != '*' && Map[i][j - 1] != 'K' && Map[i][j - 1] != '1' && Map[i][j - 1] != '2' && Map[i][j - 1] != '3')
        Map[i][j - 1] = ' ';
    if (Map[i - 1][j - 1] != '*' && Map[i - 1][j - 1] != 'K' && Map[i - 1][j - 1] != '1' && Map[i - 1][j - 1] != '2' && Map[i - 1][j - 1] != '3')
        Map[i - 1][j - 1] = ' ';
    if (Map[i + 1][j + 1] != '*' && Map[i + 1][j + 1] != 'K' && Map[i + 1][j + 1] != '1' && Map[i + 1][j + 1] != '2' && Map[i + 1][j + 1] != '3')
        Map[i + 1][j + 1] = ' ';
    if (Map[i + 1][j - 1] != '*' && Map[i + 1][j - 1] != 'K' && Map[i + 1][j - 1] != '1' && Map[i + 1][j - 1] != '2' && Map[i + 1][j - 1] != '3')
        Map[i + 1][j - 1] = ' ';
    if (Map[i - 1][j + 1] != '*' && Map[i - 1][j + 1] != 'K' && Map[i - 1][j + 1] != '1' && Map[i - 1][j + 1] != '2' && Map[i - 1][j + 1] != '3')
        Map[i - 1][j + 1] = ' ';
}
void ChangeFourDirection(char Map[12][12], int i, int j)
{
    if (Map[i + 1][j] != '*' && Map[i + 1][j] != 'K' && Map[i + 1][j] != '1' && Map[i + 1][j] != '2' && Map[i + 1][j] != '3')
        Map[i + 1][j] = ' ';
    if (Map[i - 1][j] != '*' && Map[i - 1][j] != 'K' && Map[i - 1][j] != '1' && Map[i - 1][j] != '2' && Map[i - 1][j] != '3')
        Map[i - 1][j] = ' ';
    if (Map[i][j + 1] != '*' && Map[i][j + 1] != 'K' && Map[i][j + 1] != '1' && Map[i][j + 1] != '2' && Map[i][j + 1] != '3')
        Map[i][j + 1] = ' ';
    if (Map[i][j - 1] != '*' && Map[i][j - 1] != 'K' && Map[i][j - 1] != '1' && Map[i][j - 1] != '2' && Map[i][j - 1] != '3')
        Map[i][j - 1] = ' ';
}
void dynamite(char Map[12][12], int i, int j)
{
    if (Map[i + 1][j] == 'P' || Map[i - 1][j] == 'P' || Map[i][j + 1] == 'P' || Map[i][j - 1] == 'P' || Map[i][j] == 'P')
    {
        cout << "PLAYER DEAD" << endl;
        play = false;
    }

    ChangeEightDirection(Map, i, j); // dynamite blast in all the directions
    Map[i][j] = ' ';                 // TO EMPTY THE CURRENT INDEX
}
void CheckDynamiteEightdirection(char Map[12][12], int i, int j)
{
    if (Map[i + 1][j] == 'M')
    {

        dynamite(Map, i + 1, j);
    }
    else if (Map[i - 1][j] == 'M')
    {
        dynamite(Map, i - 1, j);
    }
    else if (Map[i][j + 1] == 'M')
    {
        dynamite(Map, i, j + 1);
    }
    else if (Map[i][j - 1] == 'M')
    {
        dynamite(Map, i, j - 1);
    }
    else if (Map[i + 1][j + 1] == 'M')
    {
        dynamite(Map, i + 1, j - 1);
    }
    else if (Map[i - 1][j - 1] == 'M')
    {
        dynamite(Map, i - 1, j - 1);
    }
    else if (Map[i + 1][j - 1] == 'M')
    {
        dynamite(Map, i + 1, j - 1);
    }
    else if (Map[i - 1][j + 1] == 'M')
    {
        dynamite(Map, i - 1, j + 1);
    }
}
void CheckDynamiteFourdirection(char Map[12][12], int i, int j)
{
    if (Map[i + 1][j] == 'M')
    {

        dynamite(Map, i + 1, j);
    }
    else if (Map[i - 1][j] == 'M')
    {
        dynamite(Map, i - 1, j);
    }
    else if (Map[i][j + 1] == 'M')
    {
        dynamite(Map, i, j + 1);
    }
    else if (Map[i][j - 1] == 'M')
    {
        dynamite(Map, i, j - 1);
    }
}

void PLACEBOMB(char Map[12][12], int i, int j) // when palyer has 3rd power
{
    if (BOMB == 0)
    {
        b1 = i;
        b2 = j;
    }
    else
    {
        b3 = i;
        b4 = j;
    }
}

void BLASTBOMB_POWER1(char Map[12][12], int i, int j) // when user have power 1 only
{
    int count = 0;

    while (count < 2)
    {
        if (Map[i + 1][j] == 'P' || Map[i - 1][j] == 'P' || Map[i][j + 1] == 'P' || Map[i][j - 1] == 'P' || Map[i][j] == 'P')
        {
            cout << "PLAYER DEAD" << endl;
            play = false;
        }
        CheckDynamiteFourdirection(Map, i, j);
        ChangeFourDirection(Map, i, j);
        if (count == 0)
        {
            Map[i][j] = ' ';
        }

        i++;
        j++;
        count++;
    }
    Power1 = false;
}
void BLASTBOMB_POWER2(char Map[12][12], int i, int j) // when player has power 2 only
{
    if (Map[i + 1][j] == 'P' || Map[i - 1][j] == 'P' || Map[i][j + 1] == 'P' || Map[i][j - 1] == 'P' || Map[i][j] == 'P' || Map[i - 1][j - 1] == 'P' || Map[i + 1][j + 1] == 'P' || Map[i + 1][j - 1] == 'P' || Map[i - 1][j + 1] == 'P')
    {
        cout << "PLAYER DEAD" << endl;
        play = false;
    }
    CheckDynamiteEightdirection(Map, i, j);

    ChangeEightDirection(Map, i, j);
    Map[i][j] = ' ';

    Power2 = false;
}
void BLASTBOMB_POWER3(char Map[12][12], int i, int j)
{
    int count = 0;
    while (count < 2)
    {
        if (Map[i + 1][j] == 'P' || Map[i - 1][j] == 'P' || Map[i][j + 1] == 'P' || Map[i][j - 1] == 'P' || Map[i][j] == 'P' || Map[i - 1][j - 1] == 'P' || Map[i + 1][j + 1] == 'P' || Map[i + 1][j - 1] == 'P' || Map[i - 1][j + 1] == 'P')
        {
            cout << "PLAYER DEAD" << endl;
            play = false;
        }
        CheckDynamiteEightdirection(Map, i, j);
        ChangeEightDirection(Map, i, j);
        if (count == 0)
        {
            Map[i][j] = ' ';
        }

        i++;
        j++;
        count++;
    }
    Power1 = false;
    Power2 = false;
}

void BLASTBOMB(char Map[12][12], int i, int j)
{

    if (Power1 & Power2)
    {
        BLASTBOMB_POWER3(Map, i, j);
    }
    else if (Power1)
    {
        BLASTBOMB_POWER1(Map, i, j);
    }
    else if (Power2)
    {
        BLASTBOMB_POWER2(Map, i, j);
    }
    else
    {
        if (Map[i + 1][j] == 'P' || Map[i - 1][j] == 'P' || Map[i][j + 1] == 'P' || Map[i][j - 1] == 'P' || Map[i][j] == 'P')
        {
            cout << "PLAYER DEAD" << endl;
            play = false;
        }
        CheckDynamiteFourdirection(Map, i, j);
        ChangeFourDirection(Map, i, j);
        Map[i][j] = ' ';
    }
}

void MOVE(char Map[12][12], int i, int j, int i2, int j2)
{
    if (Map[i2][j2] == ' ')
    {

        Map[i2][j2] = 'P';
        Map[i][j] = ' ';
        p1 = i2;
        p2 = j2;
    }
    else if (Map[i2][j2] == 'V')
    {
        cout << "YOU ARE KILLED BY VILLAN" << endl;
        play = false;
    }
    else if (Map[i2][j2] == 'K')
    {
        cout << "YOU WIN!" << endl;
        cout << "Thanks For Playing The Game" << endl;

        play = false;
    }
    else if (Map[i2][j2] == '1')
    {
        Power1 = true;
        Map[i2][j2] = 'P';
        Map[i][j] = ' ';
        p1 = i2;
        p2 = j2;
    }
    else if (Map[i2][j2] == '2')
    {
        Power2 = true;
        Map[i2][j2] = 'P';
        Map[i][j] = ' ';
        p1 = i2;
        p2 = j2;
    }
    else if (Map[i2][j2] == '3')
    {
        Power3 = true;
        Map[i2][j2] = 'P';
        Map[i][j] = ' ';
        p1 = i2;
        p2 = j2;
    }
    else
    {
        cout << "Cant Move in That DIRECTION" << endl;
    }
}

int main()
{

    int n = 12; // array size
    int n2;
    char Map[12][12];
    int alpha = 65;
    int alpha2 = 65;
    int v, m;
    char i, j;
    int k, l;
    char v1, v2;

    for (int i = 0; i < n; i++) // Map creation
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j != 0)
            {
                Map[i][j] = (char)alpha++; // top map letters
            }
            else if (j == 0 && i != 0)
            {
                Map[i][j] = alpha2++; // left map letters
            }
            else if ((i == 1 && j != 0) || (i != 0 && j == 1) || (i == 11) || (j == 11))
            { // map inside border
                Map[i][j] = '*';
            }
            else if ((i == 3 && j % 2 != 0) || (i == 5 && j % 2 != 0) || (i == 7 && j % 2 != 0) || (i == 9 && j % 2 != 0))
            {
                Map[i][j] = '*';
            }
            else
            {
                Map[i][j] = ' ';
            }
        }
        alpha = 65;
    }

    printmap(Map, 12);

l1:
    cout << "ENTER THE PowerR1 POSITION" << endl;
    cin >> i >> j;
    k = (int)i - 'A' + 1;
    l = (int)j - 'A' + 1;
    if (Map[k][l] == ' ')
    {
        Map[k][l] = '1'; // ADDING PLAYER
    }
    else
    {

        cout << "ENTER THE VALID PowerR1 POSITION" << endl;
        goto l1;
    }
    cout << endl;
    system("CLS");
    printmap(Map, 12);

l2:
    cout << "ENTER THE PowerR2 POSITION" << endl;
    cin >> i >> j;
    k = (int)i - 'A' + 1;
    l = (int)j - 'A' + 1;
    if (Map[k][l] == ' ')
    {
        Map[k][l] = '2';
    }
    else
    {

        cout << "ENTER THE VALID PowerR2 POSITION" << endl;
        goto l2;
    }
    cout << endl;

    system("CLS");
    printmap(Map, 12);

l3:
    cout << "ENTER THE PowerR3 POSITION" << endl;
    cin >> i >> j;
    k = (int)i - 'A' + 1;
    l = (int)j - 'A' + 1;
    if (Map[k][l] == ' ')
    {
        Map[k][l] = '3';
    }
    else
    {
        cout << "ENTER THE VALID PowerR3 POSITION" << endl;
        goto l3;
    }
    cout << endl;

    system("CLS");
    printmap(Map, 12);

    cout << "ENTER THE DYNAMITE COUNT" << endl;
    cin >> m;
    for (int P = 1; P <= m; P++)
    {
    D:
        cout << "ENTER THE DYNAMITE POSITION:" << P << endl;
        cin >> i >> j;
        k = (int)i - 'A' + 1;
        l = (int)j - 'A' + 1;
        if (Map[k][l] == ' ')
        {
            Map[k][l] = 'M'; // ADDING PLAYER
        }
        else
        {
            cout << "ENTER THE VALID Dynamite POSITION" << endl;
            goto D;
        }
    }
    cout << endl;

    system("CLS");
    printmap(Map, 12);

P:
    cout << "ENTER THE PLAYER POSITION" << endl;
    cin >> i >> j;
    k = (int)i - 'A' + 1;
    l = (int)j - 'A' + 1;
    if (Map[k][l] == ' ')
    {
        Map[k][l] = 'P'; // ADDING PLAYER
    }
    else
    {
        cout << "ENTER THE VALID PLAYER POSITION" << endl;
        goto P;
    }
    cout << endl;

    system("CLS");
    printmap(Map, 12);

    p1 = k;
    p2 = l;
K:
    cout << "ENTER THE KEY POSITION" << endl;
    cin >> i >> j;
    k = (int)i - 'A' + 1;
    l = (int)j - 'A' + 1;
    if (Map[k][l] == ' ')
    {
        Map[k][l] = 'K'; // ADDING KEY
    }
    else
    {
        cout << "ENTER THE VALID KEY POSITION" << endl;
        goto K;
    }
    cout << endl;

    system("CLS");
    printmap(Map, 12);

    cout << "ENTER THE VILLAN COUNT" << endl;
    cin >> v;
    for (int i = 1; i <= v; i++)
    {
    V:
        cout << "ENTER THE VILLAN POSITION: " << i << endl;
        cin >> v1 >> v2;
        k = (int)v1 - 'A' + 1;
        l = (int)v2 - 'A' + 1;
        if (Map[k][l] == ' ')
        {
            Map[k][l] = 'V'; // ADDING VILLAN
        }
        else
        {

            cout << "ENTER THE VALID VILLAN POSITION" << endl;
            goto V;
        }
    }

    system("CLS");
    printmap(Map, 12);

    cout << "ENTER THE BRICK COUNT" << endl;
    cin >> v;
    for (int i = 1; i <= v; i++)
    {
    B:
        cout << "ENTER THE BRICK POSITION: " << i << endl;
        cin >> v1 >> v2;
        k = (int)v1 - 'A' + 1;
        l = (int)v2 - 'A' + 1;
        if (Map[k][l] == ' ')
        {
            Map[k][l] = 'B'; // ADDING BRICK
        }
        else
        {
            cout << "ENTER THE VALID BRICK POSITION" << endl;
            goto B;
        }
    }
    system("CLS");

    while (play)
    {

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << Map[i][j] << " ";
            }
            cout << endl;
        }
        cout << "-----------------" << endl;

        char Move;
        cout << "ENTER THE PLAYER MOVING DIRECTION: " << endl;
        cin >> Move;
        system("CLS");

        if (b1 != 0 && b2 != 0)
        {
            Map[b1][b2] = 'X';
        }
        if (b3 != 0 && b4 != 0)
        {
            Map[b3][b4] = 'X';
        }
        switch (Move)
        {

        case 'W':
            MOVE(Map, p1, p2, p1 - 1, p2);
            break;
        case 'S':
            MOVE(Map, p1, p2, p1 + 1, p2);
            break;
        case 'A':
            MOVE(Map, p1, p2, p1, p2 - 1);
            break;
        case 'D':
            MOVE(Map, p1, p2, p1, p2 + 1);
            break;
        case 'Q':
            MOVE(Map, p1, p2, p1 - 1, p2 - 1);
            break;
        case 'Z':
            MOVE(Map, p1, p2, p1 + 1, p2 - 1);
            break;
        case 'E':
            MOVE(Map, p1, p2, p1 - 1, p2 + 1);
            break;
        case 'C':
            MOVE(Map, p1, p2, p1 + 1, p2 + 1);
            break;
        case 'X':
        {
            int c;
            cout << "1.Plant" << endl;
            cout << "2.detonent" << endl;
            cin >> c;
            if (c == 1)
            {
                if (BOMB == 0 || Power3 == true)
                {
                    PLACEBOMB(Map, p1, p2);
                    if (BOMB == 1 && Power3 == true)
                    {
                        Power3 = false;
                    }
                    BOMB++;
                }
                else
                {
                    cout << "BOMB IS NOT BLASTED" << endl;
                }
            }
            else
            {
                if (BOMB == 0)
                {
                    cout << "YOU DIDNT PLANT ANY BOMB" << endl;
                }
                else
                {
                    BLASTBOMB(Map, b1, b2);
                    BLASTBOMB(Map, b3, b4);
                    b1 = 0, b2 = 0;
                    b3 = 0, b4 = 0;
                    BOMB = 0;
                    Power3 = false;
                }
            }
        }
        break;
        default:
            cout << "IT'S NOT A VALID DIRECTION: " << endl;
            break;
        }
    }
}
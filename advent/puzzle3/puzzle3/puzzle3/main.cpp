#include <iostream>
#include <map>

using namespace std;

#define INPUT_SIZE 368078
#define LEFT_DIR 0
#define RIGHT_DIR 1
#define UP_DIR 2
#define DOWN_DIR 3

typedef struct Cordinates
{
    int x;
    int y;
};

unsigned long spiralTable[20][20] = { 0 };

static long int rightCorner = 0;

int findRing()
{
    long int i = 1;
    int row = 0;

    while (rightCorner < INPUT_SIZE)
    {
        ++row;
        i += 2;
        rightCorner = i * i;
    }
    return row;
}

int calculatePos(int rightRowPos)
{
    int x = rightRowPos;
    int y = rightRowPos;
    int valPos = 0;
    long int tmpRightCorner = rightCorner;

    while (INPUT_SIZE != tmpRightCorner)
    {
        --tmpRightCorner;
        --x;
    }

    x *= -1;

    valPos = (x - 0) + (rightRowPos - 0);

    return valPos;
}

int leftDirFill(int *x, int *y, int *dir)
{
    int tmp_x = *x;
    int tmp_y = *y;
    long int spiralVal = 0;

    while (0 != spiralTable[tmp_x][tmp_y])
    {
        spiralVal = spiralTable[tmp_x][tmp_y] + spiralTable[tmp_x][tmp_y + 1] + spiralTable[tmp_x][tmp_y - 1] + spiralTable[tmp_x - 1][tmp_y + 1];
        if (spiralVal > INPUT_SIZE)
        {
            spiralTable[tmp_x - 1][tmp_y] = spiralVal;
            *x = tmp_x - 1;
            *y = tmp_y;
            return 1;
        }
        spiralTable[tmp_x - 1][tmp_y] = spiralVal;
        tmp_y--;
    }

    *x = tmp_x - 1;
    *y = tmp_y + 1;
    *dir = DOWN_DIR;

    return 0;
}

int rightDirFill(int *x, int *y, int *dir)
{
    int tmp_x = *x;
    int tmp_y = *y;
    long int spiralVal = 0;

    while (0 != spiralTable[tmp_x][tmp_y])
    {
        spiralVal = spiralTable[tmp_x][tmp_y] + spiralTable[tmp_x][tmp_y - 1] + spiralTable[tmp_x][tmp_y + 1] + spiralTable[tmp_x + 1][tmp_y - 1];
        if (spiralVal > INPUT_SIZE)
        {
            spiralTable[tmp_x + 1][tmp_y] = spiralVal;
            *x = tmp_x + 1;
            *y = tmp_y;
            return 1;
        }
        spiralTable[tmp_x + 1][tmp_y] = spiralVal;
        tmp_y++;
    }

    *x = tmp_x + 1;
    *y = tmp_y - 1;
    *dir = UP_DIR;

    return 0;
}

int upDirFill(int *x, int *y, int *dir)
{
    int tmp_x = *x;
    int tmp_y = *y;
    long int spiralVal = 0;

    while (0 != spiralTable[tmp_x][tmp_y])
    {
        spiralVal = spiralTable[tmp_x][tmp_y] + spiralTable[tmp_x - 1][tmp_y] + spiralTable[tmp_x + 1][tmp_y] + spiralTable[tmp_x + 1][tmp_y + 1];
        if (spiralVal > INPUT_SIZE)
        {
            spiralTable[tmp_x][tmp_y + 1] = spiralVal;
            *x = tmp_x;
            *y = tmp_y + 1;
            return 1;
        }
        spiralTable[tmp_x][tmp_y + 1] = spiralVal;
        tmp_x--;
    }

    *x = tmp_x + 1;
    *y = tmp_y + 1;
    *dir = LEFT_DIR;

    return 0;
}

int downDirFill(int *x, int *y, int *dir)
{
    int tmp_x = *x;
    int tmp_y = *y;
    long int spiralVal = 0;

    while (0 != spiralTable[tmp_x][tmp_y])
    {
        spiralVal = spiralTable[tmp_x][tmp_y] + spiralTable[tmp_x + 1][tmp_y] + spiralTable[tmp_x - 1][tmp_y] + spiralTable[tmp_x - 1][tmp_y - 1];
        if (spiralVal > INPUT_SIZE)
        {
            spiralTable[tmp_x][tmp_y - 1] = spiralVal;
            *x = tmp_x;
            *y = tmp_y - 1;
            return 1;
        }
        spiralTable[tmp_x][tmp_y - 1] = spiralVal;
        tmp_x++;
    }

    *x = tmp_x - 1;
    *y = tmp_y - 1;
    *dir = RIGHT_DIR;

    return 0;
}

int fillSpiral()
{
    unsigned long spiralValue = 0;
    int dir = 0;
    int x = 0;
    int y = 0;
    int retVal = 0;

    spiralTable[10][9] = 1;
    spiralTable[10][10] = 1;
    spiralTable[9][10] = 2;
    spiralTable[9][9] = 4;
    x = 9;
    y = 9;
    dir = DOWN_DIR;

    while (1 != retVal)
    {
        switch (dir)
        {
        case LEFT_DIR:
            retVal = leftDirFill(&x, &y, &dir);
            break;
        case RIGHT_DIR:
            retVal = rightDirFill(&x, &y, &dir);
            break;
        case UP_DIR:
            retVal = upDirFill(&x, &y, &dir);
            break;
        case DOWN_DIR:
            retVal = downDirFill(&x, &y, &dir);
            break;
        default:
            break;
        }
    }

    cout << "Value is: " << spiralTable[x][y];

    return 0;
}



int main()
{
    {
        // First part solution 
        int rightRowPos = findRing();
        calculatePos(rightRowPos);
    }
    {
        // Second part solution
        fillSpiral();
    }


    return 0;
}
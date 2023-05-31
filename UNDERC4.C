#include <stdio.h>

#define rows 4
#define columns 4

char b[rows][columns];
char cp = 'X';

// Function to initialize the game board
void initializeBoard()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            b[i][j] = ' ';
        }
    }
}

// Function to print the game board
void printBoard()
{
    printf("\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("! %c ", b[i][j]);
        }
        printf("!\n");
    printf("****************\n");
    }
    printf("  1   2   3   4\n");
}

// Function to check if a column is full
bool isColumnFull(int column)
{
    return b[0][column - 1] != ' ';
}

// Function to make a move
void makeMove(int column)
{
    int row = rows - 1;
    while (row >= 0)
    {
        if (b[row][column - 1] == ' ')
        {
            b[row][column - 1] = cp;
            break;
        }
        row--;
    }
}

// Function to check if a player has won
int checkWin()
{
    int v = 0;
    // Check horizontally
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns - 3; j++)
        {
            if (b[i][j] == cp &&
                b[i][j + 1] == cp &&
                b[i][j + 2] == cp &&
                b[i][j + 3] == cp)
            {
                v++;
            }
        }
    }

    // Check vertically
    for (int i = 0; i < rows - 3; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (b[i][j] == cp &&
                b[i + 1][j] == cp &&
                b[i + 2][j] == cp &&
                b[i + 3][j] == cp)
            {
                v++;
            }
        }
    }

    // Check diagonally (top left to bottom right)
    for (int i = 0; i < rows - 3; i++)
    {
        for (int j = 0; j < columns - 3; j++)
        {
            if (b[i][j] == cp &&
                b[i + 1][j + 1] == cp &&
                b[i + 2][j + 2] == cp &&
                b[i + 3][j + 3] == cp)
            {
                v++;
            }
        }
    }

    // Check diagonally (top right to bottom left)
    for (int i = 0; i < rows - 3; i++)
    {
        for (int j = 3; j < columns; j++)
        {
            if (b[i][j] == cp &&
                b[i + 1][j - 1] == cp &&
                b[i + 2][j - 2] == cp &&
                b[i + 3][j - 3] == cp)
            {
                v++;
            }
        }
    }

    return v;
}

int main()
{
    int column;
    int gameOver = 0;

    initializeBoard();
    printf("PlayIT\n");
    printf("\t\t\t\t-----the ULTImate ---->\n");
    printf("\t\t\t\t\t\t\t\t\t=== Connect 4 ===\n");
    char w;
    printf("enter X to continue");

    scanf("%c", &w);
     
    if (w == 'X')
    {
        
        printf("\n\n\nPlayer 1: X | Player 2: O\n\n");
        int g;
        printf("ENTER 0 TO START THE GAME");
        scanf("%d", &g);
        if (g == 0)
        {
            while (gameOver != 17)
            {
                printBoard();
                if (gameOver == 16)
                    printf("enter any no. to view result\n\n\n");
                else
                {
                    int t;
                    if (cp == 'X')
                    {
                        t = 1;
                    }
                    else
                    {
                        t = 2;
                    }
                    printf("Player %d, choose a column (1-4): ", t);
                    scanf("%d", &column);
                }
                if (column < 1 || column > 4)
                {
                    if (gameOver == 16)
                    {
                        gameOver = 17;
                        continue;
                    }
                    printf("out of range column number. Please try again.\n");
                    continue;
                }

                if (isColumnFull(column))
                {
                    if (gameOver == 16)
                    {
                        gameOver = 17;
                        continue;
                    }
                    printf("Column is already full. Please try again.\n");
                    continue;
                }

                makeMove(column);
                if (cp == 'X')
                {
                    cp = 'O';
                }
                else
                {
                    cp = 'X';
                }
                gameOver++;
            }
            int p1 = checkWin();
            cp = 'O';
            int p2 = checkWin();
            printf("\nFINAL SCORE:\n\nPLAYER 1: PLAYER 2:\n%d\t\t%d", p1, p2);
            if (p1 > p2)
            {
                printf("\nplayer 1 wins");
                printf("WE HOPE PLAYER 2 GETS ANOTHER CHANCE TO PROVE HIS COMPETENCE");
            }
            else if (p2 > p1)
            {
                printf("\nplayer 2 wins");
                printf("WE HOPE PLAYER 1 GETS ANOTHER CHANCE TO PROVE HIS COMPETENCE");
            }
            else
            {
                printf("\nTHE GAME WAS DRAW\n");
                printf("\t\t\t\tRESULTS WOULD HAVE BEEN MORE INTERESTING IF WE HAD A WINNER\n");
                printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tPLAY AGAin TO FIND OUT");
            }
        }
    }
    return 0;
}
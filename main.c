#include<stdio.h>
#include <stdlib.h>
#include <conio.h>

// define a grid for the game to take place
#define ROWS 20
#define COLUMNS 30

//define all functions
int Intro();
void MovePLane();
void PrintGrid(char grid[ROWS][COLUMNS]);
void ConfigPlane(char grid[ROWS][COLUMNS], int pos, char line, char plus, char zero);
void ClearPlane(char grid[ROWS][COLUMNS], int pos);
void MovePlane(int *pos, char grid[ROWS][COLUMNS], int line, int plus, int zero);
int MoveBullet(char grid[ROWS][COLUMNS], int score);
void MakeObject(char n, char grid[ROWS][COLUMNS]);
int MoveObjects(char n, char s, char grid[ROWS][COLUMNS]);
void PrintScore(int score);

// main function of the game
int main()
{
    char s = ' ';
    char star = '*';
    char plus = '+';
    char n = 'N';
    char zero = '0';
    char line = '|';
    char at = '@';
    char hash = '#';
    int pos= 10, m = 1;
    int l = 0, i = 0, k;
    int score = 0;
    int gameplay = 1;
    
    int difficulty = Intro();
    k = difficulty * 10000;
    char grid[ROWS][COLUMNS] = {{hash,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,hash},
                                {hash,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,hash},
                                {hash,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,hash},
                                {hash,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,hash},
                                {hash,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,hash},
                                {hash,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,hash},
                                {hash,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,hash},
                                {hash,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,hash},
                                {hash,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,hash},
                                {hash,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,hash},
                                {hash,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,hash},
                                {hash,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,hash},
                                {hash,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,hash},
                                {hash,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,hash},
                                {hash,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,hash},
                                {hash,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,hash},
                                {hash,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,hash},
                                {hash,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,hash},
                                {hash,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,hash},
                                
    };
    srand(time(NULL));

    //infinite while loop for the game
    while (gameplay == 1)
    {
        MovePlane(&pos, grid, line, plus, zero);
        
        if (l == 1000)
        {
            score = MoveBullet(grid, score);
            l = 0;
        }
        
        
        if (i == k)
        {
            MakeObject(n, grid);
            gameplay = MoveObjects(n, s, grid);
            i = 0;
            k = k - 200;
        }
        i++;
        l++;
        PrintScore(score);
    }
}

//this method prints the grid of the game
void PrintGrid(char grid[ROWS][COLUMNS])
{
    system("cls");
    int i, j;
    for (i = 0; i< ROWS; i++)
    {
        for (j =0; j<COLUMNS; j++)
        {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

// this method configures the plane in the game according to its coordinates 
void ConfigPlane(char grid[ROWS][COLUMNS], int pos, char line, char plus, char zero)
{
    grid[16][pos] = line;
    grid[17][pos-1] = zero;
    grid[17][pos] = zero;
    grid[17][pos+1] = zero;
    grid[18][pos-1] = plus;
    grid[18][pos+1] = plus;
}

// This game removes the game from its previous coordintas
void ClearPlane(char grid[ROWS][COLUMNS], int pos)
{
    grid[16][pos] = ' ';
    grid[17][pos-1] = ' ';
    grid[17][pos] = ' ';
    grid[17][pos+1] = ' ';
    grid[18][pos-1] = ' ';
    grid[18][pos+1] = ' ';
}

// this function moves the plane according to its new position and keyboard input
void MovePlane(int *pos, char grid[ROWS][COLUMNS], int line, int plus, int zero)
{
    char ch;
    int set = *pos;
    if (kbhit() )
    {
        ch = getch();
        if (ch == 97)
        {
            ClearPlane(grid, set);
            set = set -1;
        }
        if (ch == 100)
        {
            ClearPlane(grid, set);
            set = set +1;
        }
        if (ch == 32)
        {
            grid[15][set] = '*';
        }
        *pos = set;
        ConfigPlane(grid, set, line, plus, zero);
        PrintGrid(grid);
    }
    
    
}

//intro to the game display
int Intro()
{
    int h; 
    printf("\n\n\n\n\n                     Enter Difficulty: (3 for easy, 1 for extreme)\n                     ");
    scanf("%d", &h);
    return h;
}

//this function moves all the bullets in the game by 1 and checks for hits
int MoveBullet(char grid[ROWS][COLUMNS], int score)
{
    int i, j;
    for (i = 0; i<ROWS-1; i++)
    {
        for (j = 0; j < COLUMNS-1; j++)
        {
            if (grid[i][j] == '*' && grid[i-1][j] == 'N')
            {
                grid[i][j] = ' ';
                grid[i-1][j] = ' ';
                score++;
                
            }
            if (grid[i][j] == '*')
            {
                grid[i][j] = ' ';
                grid[i-1][j] = '*';
                
            }
        }
    }
    
    
    PrintGrid(grid);
    
    return score;
}

// this function creates new objects for the plane to hit/or crash into
void MakeObject(char n, char grid[ROWS][COLUMNS])
{
    
    int p = (rand() % 20)+ 5;
    grid[0][p] = n;
    
}

//this function moves all objects in the game.
int MoveObjects(char n, char s, char grid[ROWS][COLUMNS])
{
    int i, j;
    for (i = ROWS-1; i>-1; i--)
    {
        for (j = COLUMNS-1; j > -1; j--)
        {
            if (grid[i][j] == n)
            {
                if (i == 19)
                {
                    return 0;
                }
                grid[i][j] = s;
                grid[i+1][j] = n;
            }
        }
    }
    PrintGrid(grid);
    return 1;
}

//this function prints the score to the bottom of the screen.
void PrintScore(int score)
{
    printf("\r");
    printf("     SCORE: %d", score);
}


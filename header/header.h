#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int column;
    char **gameBoard;
} Board;


// A position on the map, with "x" horizontal axis, and "y" vertical axis
typedef struct
{
    int x;
    int y;
} Position;

typedef struct
{
    Position *position;
} Player;

typedef struct
{
    Player **players;
    int playerCount;
    Board *board;
} Game;


Player *create_player();

void *create_map(int width, int height, Player **players, int playerCount);

Game *init_game(int width, int height, int playerCount, int winCount);

void loadMenu();

void print_board(int rows, int columns,Game *game);

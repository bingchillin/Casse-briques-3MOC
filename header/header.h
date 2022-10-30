#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int width;
    int height;
    char **gameMap2D;
} Map;

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
    Map *map;
} Game;

void *create_map(int width, int height, Game *game);

Game *init_game(int width, int height, int playerCount, int winCount);

void set_players_positions(Game *game);

void loadMenu();

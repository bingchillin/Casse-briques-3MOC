#include <stdio.h>
#include <stdlib.h>

#define RESET "\x1B[0m"
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define BLUE "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN "\x1B[36m"
#define WHITE "\x1B[37m"

typedef struct {
    int defaultNbBomb;
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

Game *create_map(Game *game);

Game *init_game(int width, int height, int bomb, int playerCount, int winCount);

void set_players_positions(Game *game);

void loadMenu();

#include "../header/map.h"

Game *create_map1(Game *game)
{
    char **gameMap2D = game->map->gameMap2D;
    int playerCount = game->playerCount;
    Player **players = game->players;
    // Draw borders
    for (int i = 0; i < game->map->height; i++)
    {
        for (int j = 0; j < game->map->width; j++)
        {
            if (i == 0 || i == game->map->height - 1 || j == 0 || j == game->map->width - 1)
            {
                gameMap2D[i][j] = 'x';
            }
            else
            {
                gameMap2D[i][j] = ' ';
            }
        }
    }

    // Put player on the map
    set_players_positions(game);
    for (int i = 0; i < playerCount; i++)
    {
        Position *playerPosition = players[i]->position;
        gameMap2D[playerPosition->x][playerPosition->y] = 'p';
    }

    // Put first and last row of walls
    for (int i = 1; i < game->map->width - 1; i++)
    {
        if (gameMap2D[1][i] == ' ')
        {
            gameMap2D[1][i] = 'm';
        }
        if (gameMap2D[game->map->height - 2][i] == ' ')
        {
            gameMap2D[game->map->height - 2][i] = 'm';
        }
    }

    // Put the other walls between them
    for (int i = 2; i < game->map->height - 2; i++)
    {
        for (int j = 1; j < game->map->width - 1; j++)
        {
            if (i % 2 == 0) // Alternate unbreakable walls and mixed-walls between each row
            {
                if (j % 2 == 0) // Alternate unbreakable and breakable walls between each column
                {
                    gameMap2D[i][j] = 'x';
                }
                else
                {
                    gameMap2D[i][j] = 'm';
                }
            }
            else
            {
                gameMap2D[i][j] = 'm';
            }
        }
    }


    // Put some space around players
    if (playerCount >= 1)
    {
        gameMap2D[1][2] = ' ';
        gameMap2D[2][1] = ' ';
    }
    if (playerCount >= 2)
    {
        gameMap2D[game->map->height - 2][game->map->width - 3] = ' ';
        gameMap2D[game->map->height - 3][game->map->width - 2] = ' ';
    }
    if (playerCount >= 3)
    {
        gameMap2D[1][game->map->width - 3] = ' ';
        gameMap2D[2][game->map->width - 2] = ' ';
    }
    if (playerCount >= 4)
    {
        gameMap2D[game->map->height - 2][2] = ' ';
        gameMap2D[game->map->height - 3][1] = ' ';
    }
    return game;
}

Game *create_map2(Game *game)
{
    char **gameMap2D = game->map->gameMap2D;
    int playerCount = game->playerCount;
    Player **players = game->players;
    // Draw borders
    for (int i = 0; i < game->map->height; i++)
    {
        for (int j = 0; j < game->map->width; j++)
        {
            if (i == 0 || i == game->map->height - 1 || j == 0 && i != game->map->height / 2 || j == game->map->width - 1 && i != game->map->height / 2)
            {
                gameMap2D[i][j] = 'x';
            }
            else
            {
                gameMap2D[i][j] = ' ';
            }
        }
    }

    // Put player on the map
    set_players_positions(game);
    for (int i = 0; i < playerCount; i++)
    {
        Position *playerPosition = players[i]->position;
        gameMap2D[playerPosition->x][playerPosition->y] = 'p';
    }

    // Put first and last row of walls
    for (int i = 1; i < game->map->width - 1; i++)
    {
        if (gameMap2D[1][i] == ' ' && i % 2 == 0)
        {
            gameMap2D[1][i] = 'm';
        }
        if (gameMap2D[game->map->height - 2][i] == ' ' && i % 2 == 0)
        {
            gameMap2D[game->map->height - 2][i] = 'm';
        }
    }

    // Put the other walls between them
    for (int i = 2; i < game->map->height - 2; i++)
    {
        for (int j = 1; j < game->map->width - 1; j++)
        {
            if (i % 2 == 0) // Alternate unbreakable walls and mixed-walls between each row
            {
                if (j % 2 == 0) // Alternate unbreakable and breakable walls between each column
                {
                    if (j % 4 == 0) // Alternate unbreakable and breakable walls between each column
                    {
                        gameMap2D[i][j] = 'x';
                    }
                    else
                    {
                        gameMap2D[i][j] = ' ';
                    }
                }
                else
                {
                    gameMap2D[i][j] = 'm';
                }
            }
            else
            {
                if (j % 2 == 0) // Alternate unbreakable and breakable walls between each column
                {
                    gameMap2D[i][j] = ' ';
                }
                else
                {
                    gameMap2D[i][j] = 'm';
                }
            }
        }
    }


    // Put some space around players
    if (playerCount >= 1)
    {
        gameMap2D[1][2] = ' ';
        gameMap2D[2][1] = ' ';
    }
    if (playerCount >= 2)
    {
        gameMap2D[game->map->height - 2][game->map->width - 3] = ' ';
        gameMap2D[game->map->height - 3][game->map->width - 2] = ' ';
    }
    if (playerCount >= 3)
    {
        gameMap2D[1][game->map->width - 3] = ' ';
        gameMap2D[2][game->map->width - 2] = ' ';
    }
    if (playerCount >= 4)
    {
        gameMap2D[game->map->height - 2][2] = ' ';
        gameMap2D[game->map->height - 3][1] = ' ';
    }
    return game;
}

Game *create_map3(Game *game)
{
    char **gameMap2D = game->map->gameMap2D;
    int playerCount = game->playerCount;
    Player **players = game->players;
    // Draw borders
    for (int i = 0; i < game->map->height; i++)
    {
        for (int j = 0; j < game->map->width; j++)
        {
            if (i == 0 || i == game->map->height - 1 || j == 0 || j == game->map->width - 1)
            {
                gameMap2D[i][j] = 'x';
            }
            else
            {
                gameMap2D[i][j] = ' ';
            }
        }
    }

    // Put player on the map
    set_players_positions(game);
    for (int i = 0; i < playerCount; i++)
    {
        Position *playerPosition = players[i]->position;
        gameMap2D[playerPosition->x][playerPosition->y] = 'p';
    }

    // Put first and last row of walls
    for (int i = 1; i < game->map->width - 1; i++)
    {
        if (gameMap2D[1][i] == ' ')
        {
            if (i % 2 != 0) // Alternate unbreakable and breakable walls between each column
            {
                gameMap2D[1][i] = ' ';
            }
            else
            {
                gameMap2D[1][i] = 'm';
            }
        }
        if (gameMap2D[game->map->height - 2][i] == ' ')
        {
            if (i % 2 != 0) // Alternate unbreakable and breakable walls between each column
            {
                gameMap2D[game->map->height - 2][i] = ' ';
            }
            else
            {
                gameMap2D[game->map->height - 2][i] = 'm';
            }
        }
    }

    // Put the other walls between them
    for (int i = 2; i < game->map->height - 2; i++)
    {
        for (int j = 1; j < game->map->width - 1; j++)
        {
            if (i % 2 == 0) // Alternate unbreakable walls and mixed-walls between each row
            {
                if (j % 2 == 0) // Alternate unbreakable and breakable walls between each column
                {
                    gameMap2D[i][j] = ' ';
                }
                else
                {
                    gameMap2D[i][j] = 'x';
                }
            }
            else
            {
                if (j % 4 == 0) // Alternate unbreakable and breakable walls between each column
                {
                    gameMap2D[i][j] = ' ';
                }
                else
                {
                    gameMap2D[i][j] = 'm';
                }
            }
        }
    }

    // Put some space around players
    if (playerCount >= 1)
    {
        gameMap2D[1][2] = ' ';
        gameMap2D[2][1] = ' ';
    }
    if (playerCount >= 2)
    {
        gameMap2D[game->map->height - 2][game->map->width - 3] = ' ';
        gameMap2D[game->map->height - 3][game->map->width - 2] = ' ';
    }
    if (playerCount >= 3)
    {
        gameMap2D[1][game->map->width - 3] = ' ';
        gameMap2D[2][game->map->width - 2] = ' ';
    }
    if (playerCount >= 4)
    {
        gameMap2D[game->map->height - 2][2] = ' ';
        gameMap2D[game->map->height - 3][1] = ' ';
    }
    return game;
}

void set_players_positions(Game *game) {
    Player **players = game->players;
    int playerCount = game->playerCount;
    int height = game->map->height;
    int width = game->map->width;

    // Players starting positions
    Position topLeftPosition[2] = {1, 1};
    Position topRightPosition[2] = {1, width - 2};
    Position bottomLeftPosition[2] = {height - 2, 1};
    Position bottomRightPosition[2] = {height - 2, width - 2};

    for (int i = 0; i < playerCount; i++)
    {
        Player *player = players[i];

        switch (i)
        {
            case 0:
                player->position = topLeftPosition;
                break;
            case 1:
                player->position = bottomRightPosition;
                break;
            case 2:
                player->position = topRightPosition;
                break;
            case 3:
                player->position = bottomLeftPosition;
                break;
            default:
                break;
        }
    }
}

void print_map(Game *game){
    int height = game->map->height;
    int width = game->map->width;
    printf("\n %d \n",game->map->defaultNbBomb);
    printf("%d %d \n",game->map->width, game->map->height);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            char currentCell = game->map->gameMap2D[i][j];
            printf("%c", currentCell);
        }
        printf("\n");
    }
}
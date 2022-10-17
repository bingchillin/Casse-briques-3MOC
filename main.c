#include <stdio.h>
#include <stdlib.h>

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
} Game;

Player *create_player()
{
    Player *player;
    player = malloc(sizeof(Player));

    return player;
}

void *create_map(int width, int height, Player **players, int playerCount)
{
    // Create a map
    char map[height][width];

    // Draw borders
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
            {
                map[i][j] = 'x';
            }
            else
            {
                map[i][j] = ' ';
            }
        }
    }

    // Put players on the map
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Put player on the map
            for (int k = 0; k < playerCount; k++)
            {
                Position *playerPosition = players[k]->position;

                if (playerPosition->x == i && playerPosition->y == j)
                {
                    map[i][j] = 'p';
                    j++;
                }
            }
        }
    }

    // Put first and last row of walls
    for (int i = 0; i < width; i++)
    {
        if (map[1][i] == ' ')
        {
            map[1][i] = 'm';
        }
        if (map[height - 2][i] == ' ')
        {
            map[height - 2][i] = 'm';
        }
    }

    // Put the other walls between them
    for (int i = 2; i < height - 2; i++)
    {
        for (int j = 1; j < width - 1; j++)
        {
            // Alternate unbreakable walls and mixed-walls between each row
            if (i % 2 == 0)
            {
                // Alternate unbreakable and breakable walls between each column
                if (j % 2 == 0)
                {
                    map[i][j] = 'x';
                }
                else
                {
                    map[i][j] = 'm';
                }
            }
            else
            {
                map[i][j] = 'm';
            }
        }
    }

    // Put some space around players
    if (playerCount >= 1)
    {
        map[1][2] = ' ';
        map[2][1] = ' ';
    }
    if (playerCount >= 2)
    {
        map[height - 2][width - 3] = ' ';
        map[height - 3][width - 2] = ' ';
    }
    if (playerCount >= 3)
    {
        map[1][width - 3] = ' ';
        map[2][width - 2] = ' ';
    }
    if (playerCount >= 4)
    {
        map[height - 2][2] = ' ';
        map[height - 3][1] = ' ';
    }

    // Print map
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            char currentCell = map[i][j];
            printf("%c", currentCell);
        }
        printf("\n");
    }
};

Game *init_game(int width, int height, int playerCount, int winCount)
{
    Player *players[playerCount];

    // Players starting positions
    Position topLeftPosition[2] = {1, 1};
    Position topRightPosition[2] = {1, width - 2};
    Position bottomLeftPosition[2] = {height - 2, 1};
    Position bottomRightPosition[2] = {height - 2, width - 2};

    for (int i = 0; i < playerCount; i++)
    {
        Player *player = create_player();

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
        players[i] = player;
    }
    create_map(width, height, players, playerCount);
}

int main()
{
    init_game(9, 5, 1, 0);
    return 0;
}

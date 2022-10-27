#include "../header/header.h"


Player *create_player()
{
    Player *player;
    player = malloc(sizeof(Player));

    return player;
}

void *create_map(int width, int height, Player **players, int playerCount)
{
    // Allocate global variable "map"
    map = (int**)malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++){
        map[i] = (int*)malloc(width * sizeof(int));
    }

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

    // Put player on the map
    for (int i = 0; i < playerCount; i++)
    {
        Position *playerPosition = players[i]->position;
        map[playerPosition->x][playerPosition->y] = 'p';
    }

    // Put first and last row of walls
    for (int i = 1; i < width - 1; i++)
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
            if (i % 2 == 0) // Alternate unbreakable walls and mixed-walls between each row
            {
                if (j % 2 == 0) // Alternate unbreakable and breakable walls between each column
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
}

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


void loadMenu() {
    int menuChoice = 0;

    printf("########## Casse briques ##########\n\n");

    printf(" - 1 : Lancer le jeu\n");
    printf(" - 2 : Paramètres\n");
    printf(" - 3 : Quitter\n\n");

    while(1) {
        scanf("%d", &menuChoice);

        switch (menuChoice) {
            case 1:
                printf("Jeu : OK\n");
                init_game(9, 5, 2, 0);
                break;
            case 2:
                printf("Paramètres : OK\n");
                break;
            case 3:
                printf("Merci d'avoir joué !\n");
                exit(0);
                break;
            default:
                printf("Mauvais choix ! Veuillez reéssayer :\n");
                break;
        }
    }
}

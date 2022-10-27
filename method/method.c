#include "../header/header.h"


Player *create_player()
{
    Player *player;
    player = malloc(sizeof(Player));

    return player;
}


void print_board(int rows, int columns, Game *game){
    int col = columns;
    int row = rows;

    printf("\n");
    printf("pRINT BOARD AAAA");
    // Map
    for(int i = 0; i < row; i++){
        for (int j = 0; j < col; ++j) {
            if (i == 0 || i == row - 1 || j == 0 || j == col - 1)
            {
                game->board->gameBoard[i][j] = ' ';
            }
            else
            {
                game->board->gameBoard[i][j] = ' ';
            }
        }
    }
    // Put player on the map
    for (int i = 0; i < game->playerCount; i++)
    {
        Position *playerPosition = game->players[i]->position;
        game->board->gameBoard[playerPosition->x][playerPosition->y] = 'p';
    }

    // Players

    if (game->playerCount >= 1)
    {
        game->board->gameBoard[1][2] = ' ';
        game->board->gameBoard[2][1] = ' ';
    }
    if (game->playerCount>= 2)
    {
        game->board->gameBoard[row - 2][col - 3] = ' ';
        game->board->gameBoard[row - 3][col - 2] = ' ';
    }
    if (game->playerCount >= 3)
    {
        game->board->gameBoard[1][col - 3] = ' ';
        game->board->gameBoard[2][col - 2] = ' ';
    }
    if (game->playerCount >= 4)
    {
        game->board->gameBoard[row - 2][2] = ' ';
        game->board->gameBoard[row - 3][1] = ' ';
    }

    // Put first and last row of walls
    for (int i = 1; i < col - 1; i++)
    {
        if (game->board->gameBoard[1][i] == ' ')
        {
            game->board->gameBoard[1][i] = 'm';
        }
        if (game->board->gameBoard[row - 2][i] == ' ')
        {
            game->board->gameBoard[row - 2][i] = 'm';
        }
    }

    // Put the other walls between them
    for (int i = 2; i < row - 2; i++)
    {
        for (int j = 1; j < col - 1; j++)
        {
            if (i % 2 == 0) // Alternate unbreakable walls and mixed-walls between each row (proba a mettre)
            {
                if (j % 2 == 0) // Alternate unbreakable and breakable walls between each column (proba a mettre)
                {
                    game->board->gameBoard[i][j] = 'x';
                }
                else
                {
                    game->board->gameBoard[i][j] = 'm';
                }
            }
            else
            {
                game->board->gameBoard[i][j] = 'm';
            }
        }
    }

    // Put some space around players
    if (game->playerCount >= 1)
    {
        game->board->gameBoard[1][2] = ' ';
        game->board->gameBoard[2][1] = ' ';
    }
    if (game->playerCount >= 2)
    {
        game->board->gameBoard[row - 2][col - 3] = ' ';
        game->board->gameBoard[row - 3][col - 2] = ' ';
    }
    if (game->playerCount >= 3)
    {
        game->board->gameBoard[1][col - 3] = ' ';
        game->board->gameBoard[2][col - 2] = ' ';
    }
    if (game->playerCount >= 4)
    {
        game->board->gameBoard[row - 2][2] = ' ';
        game->board->gameBoard[row - 3][1] = ' ';
    }

    // Print map
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            char currentCell = game->board->gameBoard[i][j];
            printf("%c", currentCell);
            printf("ca passe");
        }
        printf("\n");
    }
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
    Game *game = malloc(sizeof(Game));
    game->players = malloc(sizeof (Player*)*2);
    for (int i = 0; i < playerCount; ++i) {
        game->players[i] = malloc(sizeof (Player));
    }

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
                game->players[i]->position = topLeftPosition;
                break;
            case 1:
                game->players[i]->position = bottomRightPosition;
                break;
            case 2:
                game->players[i]->position = topRightPosition;
                break;
            case 3:
                game->players[i]->position = bottomLeftPosition;
                break;
            default:
                break;
        }
        game->players[i] = player;
    }
    printf("lalala");
    print_board(height,width,game);
}

void loadMenu() {
    int menuChoice = 0;

    printf("########## Casse briques ##########\n\n");

    printf(" - 1 : Lancer le jeu\n");
    printf(" - 2 : Parametres\n");
    printf(" - 3 : Quitter\n\n");

    while(1) {
        scanf("%d", &menuChoice);

        switch (menuChoice) {
            case 1:
                printf("Jeu : OK\n");
                init_game(9, 5, 2, 0);
                break;
            case 2:
                printf("Parametres : OK\n");
                break;
            case 3:
                printf("Merci d'avoir joue !\n");
                exit(1);
                break;
            default:
                printf("Mauvais choix ! Veuiller reessayer :\n");
                break;
        }
    }
}

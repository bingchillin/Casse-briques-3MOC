#include "../header/header.h"
int checkPosChangingConditions(Game *game, int playerChoice){
    int validOrNot = 0;
    for (int i = 0; i < game->playerCount; ++i) {
        if (game->players[i]->turn==1){
            if (playerChoice==1){
                printf("passe par ici");
                if (game->players[i]->position->y <= 1){
                    printf("ici");
                    validOrNot = 0;
                    return validOrNot;
                }
                else{
                    printf("passe par là");
                    validOrNot = 1;
                    return validOrNot;
                }
            }
            if (playerChoice == 2){
                if (game->players[i]->position->x <= 1){
                    validOrNot = 0;
                    return validOrNot;
                }
                else{
                    validOrNot = 1;
                    return validOrNot;
                }
            }
            if(playerChoice == 3){
                if (game->players[i]->position->x >= game->map->width-1){
                    validOrNot = 0;
                    return validOrNot;
                }
                else{
                    validOrNot = 1;
                    return validOrNot;
                }
            }
            if(playerChoice == 4){
                if (game->players[i]->position->y >= game->map->height-1){
                    validOrNot = 0;
                    return validOrNot;
                }
                else{
                    validOrNot = 1;
                    return validOrNot;
                }
            }
        }
    }
}

Game *setChangedPosOnMap(Game *game){
    for (int i = 0; i < game->playerCount; i++)
    {
        Position *playerPosition = game->players[i]->position;
        game->map->gameMap2D[playerPosition->x][playerPosition->y] = 'p';
    }
    print_map(game);
    return game;
}
Game *playersTurn(Game *game){
    int playerChoice = 0;

    printf(MAGENTA "########## TOUR %d ##########\n\n", game->actualTurn);
    for (int i = 0; i < game->playerCount; ++i) {
        if(game->players[i]->turn==1){
            printf(YELLOW "######## Joueur %d ########\n\n", i+1);
        }
    }

    printf(GREEN " - 1 : Se deplacer\n" RESET);
    printf(BLUE " - 2 : Poser une bombe\n" RESET);
    printf(RED " - 3 : Passer son tour \n\n" RESET);
    while(1) {
        scanf("%d", &playerChoice);

        switch (playerChoice) {
            case 1:
                movePlayer(game);
                printf("\n");
                break;
            case 2:
                printf("Paramètres : OK\n");
                break;
            case 3:
                for (int i = 0; i < game->playerCount; ++i) {
                    if (game->players[i]->turn==1){
                        if(i+1 == game->playerCount){
                            game->players[i]->turn=0;
                            game->players[0]->turn=1;
                            game->actualTurn=game->actualTurn+1;
                        }
                        else{
                            game->players[i]->turn=0;
                            game->players[i+1]->turn=1;
                            game->actualTurn=game->actualTurn+1;
                        }
                        break;
                    }
                }
                exit(0);
            default:
                printf("Mauvais choix ! Veuillez réessayer :\n");
                break;
        }
    }
}

Game *createPlayers(Game *game){
    Player **players = malloc(sizeof(Player*) * game->playerCount);
    for (int i = 0; i < game->playerCount; i++) {
        players[i] = malloc(sizeof(Player));
        players[i]->explodingRange = 2;
        players[i]->maxBombs = 3;
        players[i]->maxMoves = 1;
        players[i]->countBombs = 1;
        players[i]->countMoves = 1;
        players[i]->turn=0;
        if (i==0){
            players[i]->turn = 1;
        }
    }
    game->players = players;
    return game;
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

Game *movePlayer(Game *game){
    int playerMove;
    int validMove = 0;
    Player *actualPlayer = malloc(sizeof(Player));
    printf(MAGENTA "##### Deplacement #####\n\n");
    for (int i = 0; i < game->playerCount; ++i) {
        if(game->players[i]->turn==1){
            printf(YELLOW "Deplacements restants : %d \n\n", game->players[i]->countMoves);
            break;
        }
    }
    printf(GREEN " 1 : Vers le haut \n" RESET);
    printf(BLUE " 2 : Vers la gauche \n" RESET);
    printf(RED " 3 : Vers la droite \n" RESET);
    printf(WHITE " 4 : Vers le bas \n" RESET);
    printf(CYAN " 5 : Annuler \n" RESET);

    while(1) {
        scanf("%d", &playerMove);

        switch (playerMove) {
            printf("zeroOOO");
            case 1:
                printf("ONE");
                for (int i = 0; i < game->playerCount; ++i) {
                    if(game->players[i]->turn==1){
                        printf("TWO");
                        validMove = checkPosChangingConditions(game,playerMove);
                        if (validMove == 1) {
                            game->players[i]->position->y = game->players[i]->position->y - 1;
                            game = setChangedPosOnMap(game);
                            return 0;
                        }
                        else{
                            printf("Vous ne pouvez pas vous déplacer vers le haut");
                            movePlayer(game);
                            break;
                        }
                    }
                }
                printf("\n");
                break;
            case 2:
                for (int i = 0; i < game->playerCount; ++i) {
                    if(game->players[i]->turn==1){
                        validMove = checkPosChangingConditions(game,playerMove);
                        if (validMove == 1) {
                            game->players[i]->position->x = game->players[i]->position->x - 1;
                            game = setChangedPosOnMap(game);
                            break;
                        } else{
                            printf("Vous ne pouvez pas vous déplacer vers la gauche");
                            movePlayer(game);
                            return 0;
                        }
                    }
                }
                break;
            case 3:
                for (int i = 0; i < game->playerCount; ++i) {
                    if(game->players[i]->turn==1){
                        game->players[i]->position->x = game->players[i]->position->x+1;
                        setChangedPosOnMap(game);
                        print_map(game);
                        return 0;
                    }
                }
                printf("\n");
                break;
            case 4:
                for (int i = 0; i < game->playerCount; ++i) {
                    if(game->players[i]->turn==1){
                        game->players[i]->position->y = game->players[i]->position->y+1;
                        setChangedPosOnMap(game);
                        print_map(game);
                        return 0;
                    }
                }
                break;
            case 5:
                playersTurn(game);
                break;
            default:
                printf("Mauvais choix ! Veuillez réessayer :\n");
        }
    }
    return game;
}

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
    setChangedPosOnMap(game);

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

Game *init_game(int width, int height, int bomb, int playerCount, int winCount)
{
    Game *game = malloc(sizeof(Game));

    game->playerCount = playerCount;

    game = createPlayers(game);

    Map *map = malloc(sizeof (Map));
    game->map = map;
    map->height = height;
    map->width = width;
    map->defaultNbBomb=bomb;
    game->actualTurn = 1;

    char **gameMap = (char**)malloc(height * sizeof(char*));
    for (int i = 0; i < height; i++){
        gameMap[i] = (char*)malloc(width * sizeof(char));
    }
    map->gameMap2D = gameMap;

    game = create_map1(game);
    return game;
}

Game letsPlay(){
    Game *game = init_game(9,7,1,2,0);
    print_map(game);
    while(1){
        playersTurn(game);
    }
}

void loadMenu() {
    int menuChoice = 0;

    printf(MAGENTA "########## Casse briques ##########\n\n" RESET);

    printf(GREEN " - 1 : Lancer le jeu\n" RESET);
    printf(BLUE " - 2 : Paramètres\n" RESET);
    printf(RED " - 3 : Quitter\n\n" RESET);
    while(1) {
        scanf("%d", &menuChoice);

        switch (menuChoice) {
            case 1:
                printf("Jeu : OK\n");
                letsPlay();
                printf("\n");
                break;
            case 2:
                printf("Paramètres : OK\n");
                break;
            case 3:
                printf("Merci d'avoir joué !\n");
                exit(0);
            default:
                printf("Mauvais choix ! Veuillez réessayer :\n");
                break;
        }
    }
}
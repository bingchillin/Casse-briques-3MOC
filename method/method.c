#include "../header/map.h"

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
    }
    game->players = players;
    return game;
}

Game movePlayer(Game *game){
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
    movePlayer(game);
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
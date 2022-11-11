#include "../header/map.h"

Game *init_game(int width, int height, int playerCount, int winCount)
{
    Game *game = malloc(sizeof(Game));

    game->playerCount = playerCount;

    Player **players = malloc(sizeof(Player*) * playerCount);
    for (int i = 0; i < playerCount; i++) {
        players[i] = malloc(sizeof(Player));
    }
    game->players = players;

    Map *map = malloc(sizeof (Map));
    game->map = map;
    map->height = height;
    map->width = width;

    char **gameMap = (char**)malloc(height * sizeof(char*));
    for (int i = 0; i < height; i++){
        gameMap[i] = (char*)malloc(width * sizeof(char));
    }
    map->gameMap2D = gameMap;

    create_map2(width, height, game);
}


void loadMenu() {
    int menuChoice = 0;

    printf(MAGENTA "########## Casse briques ##########\n\n" RESET);

    while(1) {
        printf(GREEN " - 1 : Lancer le jeu\n" RESET);
        printf(BLUE " - 2 : Paramètres\n" RESET);
        printf(RED " - 3 : Quitter\n\n" RESET);
        scanf("%d", &menuChoice);

        switch (menuChoice) {
            case 1:
                printf("Jeu : OK\n");
                init_game(15, 13, 4, 0);
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
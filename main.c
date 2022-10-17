#include <stdio.h>
#include <stdlib.h>

void loadMenu();

int main(int argc , char** argv) {
    loadMenu();
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

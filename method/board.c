#include <stdio.h>
#include "../header/board.h"
#include "../header/header.h"

void print_board(int rows, int columns, Game *game){
    int col = columns;
    int row = rows;

    printf("\n");

    // Map
    for(int i = 0; i < row; i++){
        for (int j = 0; j < col; ++j) {
            if (i == 0 || i == row - 1 || j == 0 || j == col - 1)
            {
                game.board->gameBoard[i][j] = ' ';
            }
            else
            {
                game.board->gameBoard[i][j] = ' ';
            }
        }
    }

    // Players

    if (game.playerCount >= 1)
    {
        game.board->gameBoard[1][2] = ' ';
        game.board->gameBoard[2][1] = ' ';
    }
    if (game.playerCount>= 2)
    {
        game.board->gameBoard[row - 2][col - 3] = ' ';
        game.board->gameBoard[row - 3][col - 2] = ' ';
    }
    if (game.playerCount >= 3)
    {
        game.board->gameBoard[1][col - 3] = ' ';
        game.board->gameBoard[2][col - 2] = ' ';
    }
    if (game.playerCount >= 4)
    {
        game.board->gameBoard[row - 2][2] = ' ';
        game.board->gameBoard[row - 3][1] = ' ';
    }

    // Put first and last row of walls
    for (int i = 1; i < col - 1; i++)
    {
        if (game.board->gameBoard[1][i] == ' ')
        {
            game.board->gameBoard[1][i] = 'm';
        }
        if (game.board->gameBoard[row - 2][i] == ' ')
        {
            game.board->gameBoard[row - 2][i] = 'm';
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
                    game.board->gameBoard[i][j] = 'x';
                }
                else
                {
                    game.board->gameBoard[i][j] = 'm';
                }
            }
            else
            {
                game.board->gameBoard[i][j] = 'm';
            }
        }
    }

    // Put some space around players
    if (game.playerCount >= 1)
    {
        game.board->gameBoard[1][2] = ' ';
        game.board->gameBoard[2][1] = ' ';
    }
    if (game.playerCount >= 2)
    {
        game.board->gameBoard[row - 2][col - 3] = ' ';
        game.board->gameBoard[row - 3][col - 2] = ' ';
    }
    if (game.playerCount >= 3)
    {
        game.board->gameBoard[1][col - 3] = ' ';
        game.board->gameBoard[2][col - 2] = ' ';
    }
    if (game.playerCount >= 4)
    {
        game.board->gameBoard[row - 2][2] = ' ';
        game.board->gameBoard[row - 3][1] = ' ';
    }

    // Print map
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            char currentCell = game.board->gameBoard[i][j];
            printf("%c", currentCell);
        }
        printf("\n");
    }
}
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "morpion.h"

void displayLine(morpion grid, int line)
{
  printf("|");
  for (int i = 0; i < 3; i++)
  {
    printf(" %c ", grid.grid[3 * line + i]);
  }
  printf("|");
}

void displayMeta(morpion meta[9])
{
  for (int i = 0; i < 9; i += 3)
  { // Print row of morpion
    for (int i2 = 0; i2 < 3; i2++)
    { // Print column of morpion
      printf("%d", i2 * 3);
      for (int j = 0; j < 3; j++)
      { // Print row in morpion
        displayLine(meta[i + j], i2);
      }
      printf("\n");
    }
    printf("\n");
  }
}

int main(int argc, char const *argv[])
{
  morpion meta[9];
  morpion bigMeta;
  int metaBox = 4;
  int count = 0;
  char player = 'o';
  char winner = 'o';

  for (int i = 0; i < 9; i++) // Initialisation du meta
  {
    for (int j = 0; j < 9; j++)
    {
      meta[i].grid[j] = '-';
    }
    bigMeta.grid[i] = '-'; // Initialisation du meta simplifie
  }

  first: printf("Choisir la 1ere case : ");
  fflush(stdin);
  scanf("%d", &metaBox);

  if (metaBox < 0 || metaBox > 8) goto first;

  do {
    int play;

    // Print the summary
    printf("\n");
    printf("Summary: ");
    display(bigMeta);
    printf("\n");

    // Print the game
    displayMeta(meta);
    // Changement de joueur
    if (player == 'o') player = 'x';
    else player = 'o';

    play: printf("Joueur %c dans case %d: ", player, metaBox); // Get player's choice
    fflush(stdin);
    scanf("%d", &play);

    if (meta[metaBox].grid[play] != '-' || play > 8 || play < 0) goto play; // Check if the input is correct

    meta[metaBox].grid[play] = player; // Replace '-' by player symbol
    if (isWin(meta[metaBox], player)) bigMeta.grid[metaBox] = player; // Check if player win the box
    while (isFinished(meta[play])) play++; // Increase while the current box is full
    metaBox = play; // Save coords of next box to play

    count++;
    system("clear");


  } while (!isWin(bigMeta, player) && !isFinished(bigMeta) && count < 9 * 9); // Game continue while no player win or the meta is not full

  if (isWin(bigMeta, 'x')) winner = 'x';

  printf("Winner: %c", winner);

  return 0;
}

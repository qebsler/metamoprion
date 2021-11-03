#include <stdbool.h>
#include <stdio.h>
#include "morpion.h"


void display(morpion grid)
{
  for (int i = 0; i < 9; i++)
  {
    if (i % 3 == 0) printf("\n");
    printf(" %c ", grid.grid[i]);
  }
  printf("\n");
}

bool isWin(morpion grid, char player)
{
  for (int i = 0; i < 3; i++)
  {
    if (grid.grid[i] == player && grid.grid[i + 3] == player && grid.grid[i + 6] == player) return true; // Test horizontal
  }

  for (int i = 0; i < 9; i += 3)
  {
    if (grid.grid[i] == player && grid.grid[i + 1] == player && grid.grid[i + 2] == player) return true; // Test vertical
  }

  if (grid.grid[4] == player && ((grid.grid[0] == player && grid.grid[8] == player) || (grid.grid[2] == player && grid.grid[6] == player))) return true; // Test diagonales
  return false;
}

bool isFinished(morpion grid)
{
  for (int i = 0; i < 9; i++)
  {
    if (grid.grid[i] != 'o' && grid.grid[i] != 'x') return false;
  }
  return true;
}

#include <stdbool.h>

typedef struct Morpion
{
  char grid[9];
} morpion;

bool isWin(morpion grid, char player);
bool isFinished(morpion grid);
void display(morpion grid);
// void init(int *grid);

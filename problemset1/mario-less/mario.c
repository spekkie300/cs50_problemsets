#include <cs50.h>
#include <stdio.h>

const int MIN_HEIGHT = 1;
const int MAX_HEIGHT = 8;

int main(void) {
  int height;

  // Prompt user, retry if input is not correct
  do {
    height = get_int("Height: ");
  } while (height < MIN_HEIGHT || height > MAX_HEIGHT);

  // Amount of spaces on first row is always height minus one, since there is
  // always one hash on the first row.
  int spaces = height - 1;
  int hashes = 1;

  // Outer loop for every row
  for (int i = 0; i < height; i++) {
    // Loop that prints right amount of spaces
    for (int j = 0; j < spaces; j++) {
      printf(" ");
    }
    // Loop for hashes
    for (int k = 0; k < hashes; k++) {
      printf("#");
    }
    // Every row the amount of spaces decrease and the Hashes increase
    spaces--;
    hashes++;

    printf("\n");
  }
  return 0;
}

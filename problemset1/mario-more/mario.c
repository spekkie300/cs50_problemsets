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
  // always one hash on the first row
  int spaces = height - 1;
  int hashes = 1;

  // Outer loop for every row
  for (int i = 0; i < height; i++) {
    // Loop that prints right amount of spaces on left side
    for (int x = 0; x < spaces; x++) {
      printf(" ");
    }
    // Loop that prints left side hashes
    for (int y = 0; y < hashes; y++) {
      printf("#");
    }
    // Always print double spaces in the center
    printf("  ");

    // Loop that prints right side hashes
    for (int r = 0; r < hashes; r++) {
      printf("#");
    }
    spaces--;
    hashes++;
    printf("\n");
  }
  return 0;
}

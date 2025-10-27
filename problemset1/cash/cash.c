#include <cs50.h>
#include <stdio.h>

const int QUARTER = 25;
const int DIME = 10;
const int NICKEL = 5;
const int PENNY = 1;

int main(void) {
  int change = 0;
  int total_cash = 0;

  int quarters = 0;
  int dimes = 0;
  int nickels = 0;
  int pennies = 0;

  // Ask user for change until number is correct
  do {
    change = get_int("Change owed: ");
  } while (change < 0);

  while (change) {
    // Divide change by quarters, since C rounds down on integer division
    // quarter now becomes amount of quarters that fit in change.
    // After dividing,lessen the change by the amount of quarters times 25.
    quarters = change / QUARTER;
    change -= quarters * QUARTER;

    // Same thing as above but with dimes
    dimes = change / DIME;
    change -= +dimes * DIME;

    // Same thing as above but with nickels
    nickels = change / NICKEL;
    change -= nickels * NICKEL;

    // Same thing as above but with pennies, since pennies are 1 we don't need
    // to do: pennies * PENNY
    pennies = change / PENNY;
    change -= pennies;
  }

  total_cash = quarters + dimes + nickels + pennies;

  printf("%i\n", total_cash);

  return 0;
}

#include <cs50.h>
#include <stdbool.h>
#include <stdio.h>

// Card Validation constants
const int CARD_DIGIT_MIN = 13;
const int CARD_DIGIT_MAX = 16;
const int VISA_DIGITS1 = 13;
const int VISA_DIGITS2 = 16;
const int AMEX_DIGITS = 15;

// Card prefixes
const int MASTER_MIN = 51;
const int MASTER_MAX = 55;
const int VISA_START = 4;
const int AMEX_START1 = 34;
const int AMEX_START2 = 37;

// Function prototypes
long get_cc(void);
int count_digits(long cc_num);
void invalid_card(void);
bool is_valid_checksum(long cc_num);
void print_brand(long cc_num, int digits);

int main(void) {
  long cc_num = get_cc();
  int cc_digits = count_digits(cc_num);

  // Validate length
  if (cc_digits < CARD_DIGIT_MIN || cc_digits > CARD_DIGIT_MAX) {
    invalid_card();
    return 0;
  }

  // Validate checksum(via Luhn's algorithm)
  if (!is_valid_checksum(cc_num)) {
    invalid_card();
    return 0;
  }

  print_brand(cc_num, cc_digits);
  return 0;
}

long get_cc(void) {
  long cc_num = 0;
  do {
    cc_num = get_long("Number: ");
  } while (cc_num < 0);
  return cc_num;
}

int count_digits(long cc_num) {
  int digits = 0;

  while (cc_num > 0) {
    digits++;
    cc_num /= 10;
  }
  return digits;
}

bool is_valid_checksum(long cc_num) {
  int finalsum = 0;

  finalsum = cc_num % 10;
  cc_num /= 10;

  while (cc_num) {
    int temp = cc_num % 10 * 2;

    if (temp > 9) {
      finalsum += temp % 10;
      temp /= 10;
      finalsum += temp;
    } else {
      finalsum += temp;
    }
    cc_num /= 10;
    finalsum += cc_num % 10;
    cc_num /= 10;
  }
  if (finalsum % 10 == 0) {
    return true;
  }
  return false;
}

void print_brand(long cc_num, int digits) {
  while (cc_num > 100) {
    cc_num /= 10;
  }
  if (digits == AMEX_DIGITS &&
      (cc_num == AMEX_START1 || cc_num == AMEX_START2)) {
    printf("AMEX\n");
    return;
  } else if (cc_num >= MASTER_MIN && cc_num <= MASTER_MAX) {
    printf("MASTERCARD\n");
    return;
  } else if (cc_num / 10 == VISA_START &&
             (digits == VISA_DIGITS1 || digits == VISA_DIGITS2)) {
    printf("VISA\n");
    return;
  } else {
    invalid_card();
  }
}

void invalid_card(void) { printf("INVALID\n"); }

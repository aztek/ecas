#include <stdio.h>
#include <stdint.h>

#define ALIVE '#'
#define DEAD  ' '

#define SIZE 64U
#define GET_BIT(n, i) (((n) >> (i)) & 1U)

int main(int argc, char* argv[]) {
  uint8_t rule = 110;
  uint64_t gens = 50;
  uint64_t tape = 9223372036854775808U;
  uint8_t first = GET_BIT(tape, 0U);
  uint8_t left = GET_BIT(tape, SIZE - 1U);
  for (uint64_t gen = 0; gen < gens; gen++) {
    for (uint8_t i = 0; i < SIZE; i++) {
      uint8_t middle = GET_BIT(tape, i);
      putc(middle ? ALIVE : DEAD, stdout);
      uint8_t right = (i + 1 < SIZE) ? GET_BIT(tape, i + 1U) : first;
      uint8_t next = GET_BIT(rule, left << 2U | middle << 1U | right);
      left = middle;
      if (next) {
        tape |= (1ULL << i);
      } else {
        tape &= ~(1ULL << i);
      }
      if (i == 0) {
        first = next;
      }
    }
    printf("\n");
  }
  return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <getopt.h>

#define ALIVE '*'
#define DEAD  ' '

#define GET_BIT(n, i) (((n) >> (i)) & 1U)

int main(int argc, char* argv[]) {
  uint8_t  width = 64;
  uint8_t  rule  = 90;
  uint64_t gens  = 32;
  uint64_t tape  = 2147483648;

  int c;
  while ((c = getopt(argc, argv, "w:r:g:t:")) != -1) {
    switch (c) {
      case 'w':
        width = strtoul(optarg, NULL, 10);
        if (width < 1 || width > 64) {
          fprintf(stderr, "Incorrect value of width %s\n", optarg);
          return 1;
        }
        break;

      case 'r':
        rule = strtoul(optarg, NULL, 10);
        break;

      case 'g':
        gens = strtoull(optarg, NULL, 10);
        break;

      case 't':
        tape = strtoull(optarg, NULL, 10);
        break;

      default:
        fprintf(stderr, "Unknown argument\n");
        return 1;
    }
  }
  
  uint8_t first = GET_BIT(tape, 0U);
  uint8_t left = GET_BIT(tape, width - 1U);
  for (uint64_t gen = 0; gen < gens; gen++) {
    for (uint8_t i = 0; i < width; i++) {
      uint8_t middle = GET_BIT(tape, i);
      putc(middle ? ALIVE : DEAD, stdout);
      uint8_t right = (i + 1 < width) ? GET_BIT(tape, i + 1U) : first;
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
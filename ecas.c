#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <getopt.h>

#define GET_BIT(n, i) (((n) >> (i)) & 1U)

int main(int argc, char* argv[]) {
  uint8_t  width = 64;
  uint8_t  rule  = 90;
  uint64_t gens  = 32;
  uint64_t tape  = 2147483648;
  char*    alive = "\u2588"; // Full block
  char*    dead  = " ";

  int c;
  while ((c = getopt(argc, argv, "w:r:g:t:a:d:")) != -1) {
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
        
      case 'a':
        alive = optarg;
        break;

      case 'd':
        dead = optarg;
        break;

      default:
        fprintf(stderr, "Unknown argument\n");
        return 1;
    }
  }

  do {
    uint64_t next = 0;
    for (uint8_t i = 0; i < width; i++) {
      printf("%s", GET_BIT(tape, i) ? alive : dead);
      uint8_t left   = GET_BIT(tape, i > 0 ? i - 1U : width - 1U);
      uint8_t middle = GET_BIT(tape, i);
      uint8_t right  = GET_BIT(tape, i + 1 < width ? i + 1U : 0U);
      uint8_t conf   = left << 2U | middle << 1U | right;
      if (GET_BIT(rule, conf)) {
        next |= 1ULL << i;
      }
    }
    printf("\n");
    tape = next;
  } while (--gens);

  return 0;
}
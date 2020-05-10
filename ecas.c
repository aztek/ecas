#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <getopt.h>

#define GET_BIT(n, i) (((n) >> (i)) & 1U)
#define GET_CELL(tape, i) GET_BIT(tape, (i) % width)
#define SET_CELL(tape, i) ((tape) |= 1ULL << (i))

int main(int argc, char* argv[]) {
  uint8_t  width = 64;
  uint8_t  rule  = 110;
  uint64_t gens  = 0;
  uint64_t tape  = 1ULL;
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

  for (uint64_t gen = 0; gens == 0 || gen < gens; gen++) {
    uint64_t next = 0;
    for (uint8_t i = 0; i < width; i++) {
      uint8_t left   = GET_CELL(tape, i - 1U);
      uint8_t middle = GET_CELL(tape, i);
      uint8_t right  = GET_CELL(tape, i + 1U);
      uint8_t config = left << 2U | middle << 1U | right;
      if (GET_BIT(rule, config)) {
        SET_CELL(next, i);
      }
      printf("%s", middle ? alive : dead);
    }
    printf("\n");
    if (tape == next) {
      break;
    }
    tape = next;
  }

  return 0;
}
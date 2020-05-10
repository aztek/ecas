#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <getopt.h>

typedef uint64_t block_t;
#define BLOCK_WIDTH (8 * sizeof(block_t))

#define GET_BIT(n, i) (((n) >> (i)) & 1U)
#define GET_CELL(tape, i) GET_BIT(tape[((i) % width) / BLOCK_WIDTH], ((i) % width) % BLOCK_WIDTH)
#define SET_CELL(tape, i) (tape[((i) % width) / BLOCK_WIDTH] |= 1ULL << (((i) % width) % BLOCK_WIDTH))

int main(int argc, char* argv[]) {
  uint64_t width = 64;
  uint8_t  rule  = 90;
  uint64_t gens  = 32;
  char* init  = "31";
  char* alive = "\u2588"; // Full block
  char* dead  = " ";

  int c;
  while (-1 != (c = getopt(argc, argv, "w:r:g:t:a:d:"))) {
    switch (c) {
      case 'w':
        width = strtoull(optarg, NULL, 10);
        break;

      case 'r':
        rule = strtoul(optarg, NULL, 10);
        break;

      case 'g':
        gens = strtoull(optarg, NULL, 10);
        break;

      case 't':
        init = optarg;
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

  block_t blocks = (width + (BLOCK_WIDTH - 1)) / BLOCK_WIDTH;
  size_t tape_width = sizeof(block_t) * blocks;

  block_t* tape = malloc(tape_width);
  memset(tape, 0, tape_width);
  char* p = strtok(init, ",");
  while (p != NULL) {
    uint64_t i, j;
    switch (sscanf(p, "%llu-%llu", &i, &j)) {
      case 1:
        j = i;

      case 2:
        if (i >= width) i = width - 1;
        if (j >= width) j = width - 1;
        for (uint64_t k = i; k <= j; k++) {
          SET_CELL(tape, k);
        }
        break;

      default:
        fprintf(stderr, "Incorrect value of -t\n");
        return 1;
    }
    p = strtok(NULL, ",");
  }

  block_t* next = malloc(tape_width);
  for (uint64_t gen = 0; 0 == gens || gen < gens; gen++) {
    memset(next, 0, tape_width);
    for (uint64_t i = 0; i < width; i++) {
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
    if (0 == memcmp(tape, next, tape_width)) {
      break;
    }
    memcpy(tape, next, tape_width);
  }

  free(next);
  free(tape);

  return 0;
}
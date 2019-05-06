#include <stdio.h>
#include <assert.h>

#include "common.h"
#include "chunk.h"
#include "debug.h"

#include "line.h"

int main(int argc, char const *argv[])
{
  /*Chunk chunk;
  initChunk(&chunk);

  int constant = addConstant(&chunk, 1.2);
  writeChunk(&chunk, OP_CONSTANT, 123);
  writeChunk(&chunk, constant, 123);

  writeChunk(&chunk, OP_RETURN, 123);

  disassembleChunk(&chunk, "test chunk");
  freeChunk(&chunk);
  */

  LineArray lines;
  initLineArray(&lines);
  writeLineArray(&lines, 1, 0);
  writeLineArray(&lines, 1, 1);
  writeLineArray(&lines, 2, 2);
  writeLineArray(&lines, 2, 3);
  writeLineArray(&lines, 3, 4);
  writeLineArray(&lines, 3, 5);
  writeLineArray(&lines, 4, 6);
  writeLineArray(&lines, 4, 7);
  writeLineArray(&lines, 5, 8);
  writeLineArray(&lines, 5, 9);
  writeLineArray(&lines, 6, 10);
  writeLineArray(&lines, 6, 11);
  writeLineArray(&lines, 6, 12);
  writeLineArray(&lines, 6, 13);
  writeLineArray(&lines, 6, 14);
  writeLineArray(&lines, 6, 15);
  writeLineArray(&lines, 7, 16);
  writeLineArray(&lines, 8, 28);
  writeLineArray(&lines, 9, 43);
  writeLineArray(&lines, 10, 72);
  
  assert(getLineArray(&lines, 9) == 5);
  assert(getLineArray(&lines, 8) == 5);
  assert(getLineArray(&lines, 0) == 1);
  assert(getLineArray(&lines, 30) == 8);

  displayLineArray(&lines);

  freeLineArray(&lines);

  return 0;
}

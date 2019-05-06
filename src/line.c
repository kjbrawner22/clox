#include <stdlib.h>
#include <stdio.h>

#include "line.h"
#include "memory.h"

void initLineArray(LineArray *lines)
{
  lines->count = 0;
  lines->capacity = 0;
  lines->array = NULL;
}

void freeLineArray(LineArray *lines)
{
  FREE_ARRAY(int, lines->array, lines->count);
  initLineArray(lines);
}

void writeLineArray(LineArray *lines, int line, 
  int instructionIndex)
{
  if (lines->count != 0 && 
      line == lines->count) {
    return;
  }

  if (lines->capacity < lines->count + 1) {
    int oldCapacity = lines->capacity;
    lines->capacity = GROW_CAPACITY(lines->capacity);
    lines->array = GROW_ARRAY(lines->array, int, 
      oldCapacity, lines->capacity);
  }

  lines->array[lines->count] = instructionIndex;
  lines->count++;
}

/**
 * @brief Return int i, such that array[i] <= number
 *        and array[i + 1] > number
 * 
 * @param array - array of integers representing the
 *                index of the first instruction on
 *                each line
 * @param size - size of the array
 * @param number - number to search for
 * @return int
 */
static int binaryRangeSearch(int *array, int size, int number)
{
  if (number < 0) {
    return -1;
  } else if (number >= array[size - 1]) {
    return size - 1;
  }

  int low = 0, high = size, mid = 0;
  while (low < high - 1) {
    mid = (low + high) / 2;
    if (number < array[mid]) {
      high = mid;
    } else {
      low = mid;
    }
  }

  return low;
}

int getLineArray(LineArray *lines, int instructionIndex)
{
  return binaryRangeSearch(lines->array, lines->count, 
    instructionIndex) + 1;
}

void displayLineArray(LineArray *lines)
{
  printf("line number : starting instruction index\n");
  printf("{\n");
  for (int i = 0; i < lines->count; i++) {

    printf("    %d : %d\n", i + 1, lines->array[i]);
  }

  printf("}\n");
}
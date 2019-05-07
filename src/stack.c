#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "memory.h"
#include "stack.h"
#include "value.h"

/**
 * @brief Initialize the stack 
 * 
 * @param stack - struct holding stack state
 */
void initStack(Stack *stack)
{
  stack->capacity = 0;
  stack->values = NULL;
  stack->top = NULL;
}

void freeStack(Stack *stack)
{
  FREE_ARRAY(Value, stack->values, stack->capacity);
  initStack(stack);
}

#define STACK_USED(stack) ((int)(stack->top - stack->values))

/**
 * @brief push a new Value [value] onto the stack, and resize the array if necessary
 * 
 * @param stack 
 * @param value 
 * 
 * @note: Since stack->values is reallocated to a new contiguous block of memory
 * when growing the array, we must reset stack->top to be where it was, but at the new 
 * memory address. This is done by this line:
 *  stack->top = stack->values + oldCapacity;
 */
void push(Stack *stack, Value value)
{
  if (stack->capacity < STACK_USED(stack) + 1) {
    int oldCapacity = stack->capacity;
    stack->capacity = GROW_CAPACITY(stack->capacity);
    stack->values = GROW_ARRAY(stack->values, Value, oldCapacity, stack->capacity);
    stack->top = stack->values + oldCapacity;
  }

  *stack->top = value;
  stack->top++;
}

Value pop(Stack *stack)
{
  stack->top--;
  Value value = *stack->top;

  if (stack->capacity > 8 && stack->capacity >= STACK_USED(stack) * 4) {
    int size = STACK_USED(stack);
    int oldCapacity = stack->capacity;
    stack->capacity = SHRINK_CAPACITY(stack->capacity);
    stack->values = GROW_ARRAY(stack->values, Value, oldCapacity, stack->capacity);
    stack->top = stack->values + size;
  }

  return value;
}

#undef STACK_USED

void displayStack(Stack *stack)
{
  printf("[ ");
  for (Value *value = stack->values; value < stack->top; value++) {
    printf("{ ");
    printValue(*value);
    printf(" } ");
  }
  printf("]\n");
}
#ifndef clox_stack_h
#define clox_stack_h

#include "common.h"
#include "value.h"

typedef struct {
  Value *values;
  Value *top;
  int capacity;
} Stack;

void initStack(Stack *stack);
void freeStack(Stack *stack);
void push(Stack *stack, Value value);
Value pop(Stack *stack);
void displayStack(Stack *stack);

#endif
#include <stdio.h>
#include <assert.h>

#include "common.h"
#include "chunk.h"
#include "debug.h"
#include "stack.h"
#include "vm.h"

int main(int argc, char const *argv[])
{
  initVM();

  Chunk chunk;
  initChunk(&chunk);

  int constant = addConstant(&chunk, 1.2);
  writeChunk(&chunk, OP_CONSTANT, 123);
  writeChunk(&chunk, constant, 123);

  constant = addConstant(&chunk, 3.4);    
  writeChunk(&chunk, OP_CONSTANT, 123);   
  writeChunk(&chunk, constant, 123);

  writeChunk(&chunk, OP_ADD, 123);        

  constant = addConstant(&chunk, 5.6);    
  writeChunk(&chunk, OP_CONSTANT, 123);   
  writeChunk(&chunk, constant, 123);      

  writeChunk(&chunk, OP_DIVIDE, 123);  

  writeChunk(&chunk, OP_NEGATE, 123);

  writeChunk(&chunk, OP_RETURN, 123);

  disassembleChunk(&chunk, "test chunk");
  interpret(&chunk);
  freeVM();
  freeChunk(&chunk);

  printf("---------- Testing Stack ----------\n\n");

  Stack stack;
  initStack(&stack);

  Value v1 = 1.0;
  Value v2 = 2.0;
  Value v3 = 3.0;
  Value v4 = 4.0;
  Value v5 = 5.0;
  Value v6 = 6.0;
  Value v7 = 7.0;
  Value v8 = 8.0;
  Value v9 = 9.0;
  Value v10 = 10.0;
  Value v11 = 11.0;
  Value v12 = 12.0;
  Value v13 = 13.0;
  Value v14 = 14.0;
  Value v15 = 15.0;
  Value v16 = 16.0;
  Value v17 = 17.0;

  push(&stack, v1);
  push(&stack, v2);
  push(&stack, v3);
  push(&stack, v4);
  push(&stack, v5);
  push(&stack, v6);
  push(&stack, v7);
  push(&stack, v8);
  push(&stack, v9);
  push(&stack, v10);
  push(&stack, v11);
  push(&stack, v12);
  push(&stack, v13);
  push(&stack, v14);
  push(&stack, v15);
  push(&stack, v16);
  push(&stack, v17);

  displayStack(&stack);

  assert(pop(&stack) == v17);
  pop(&stack);
  pop(&stack);
  pop(&stack);
  pop(&stack);
  pop(&stack);
  pop(&stack);
  assert(pop(&stack) == v10);
  assert(pop(&stack) == v9);

  displayStack(&stack);

  return 0;
}

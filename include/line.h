#ifndef clox_line_h
#define clox_line_h

typedef struct {
  int count;
  int capacity;
  int *array;
} LineArray;

void initLineArray(LineArray *lines);
void freeLineArray(LineArray *lines);
void writeLineArray(LineArray *lines, int line, 
  int instructionIndex);
int getLineArray(LineArray *lines, int instructionIndex);
void displayLineArray(LineArray *lines);

#endif
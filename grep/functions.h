#ifndef SRC_GREP_FUNCTIONS_H_
#define SRC_GREP_FUNCTIONS_H_
#include <stdbool.h>

typedef struct flags {
  bool e;
  int i;
  bool v;
  bool c;
  bool l;
  bool n;
  bool h;
  bool s;
  bool f;
} Flag;

void cleanPointers(char *ptrns[], int pCntr, bool fFlag);
void parser(int argc, char *argv[], int *optind, int *ptrnCntr, int *flsCntr,
            char *patterns[], char *files[], Flag *flags, int *free);
void processor(char *patterns[], int ptrnsCntr, char *files[], int filesCntr,
               Flag flags);

#endif  // SRC_GREP_FUNCTIONS_H_

#ifndef SRC_CAT_FUNCTIONS_H_
#define SRC_CAT_FUNCTIONS_H_
#include <stdio.h>

typedef struct options {
  int b;
  int e;
  int n;
  int s;
  int t;
  int v;
} opt;

void parser(int argc, char *argv[], opt *flags);
void reader(int argc, char *argv[], opt flags);
void getOptions(int gopt, opt *flags);
void out(opt options, FILE *fp);

#endif  // SRC_CAT_FUNCTIONS_H_

#ifndef SRC_CAT_HELPER_H_
#define SRC_CAT_HELPER_H_
#include <stdio.h>

#include "functions.h"

int checkFilePointer(FILE *pointer, char *argv[], int curFile);
void getOptions(int gopt, opt *flags);
void out(opt flags, FILE *fp);

#endif  // SRC_CAT_HELPER_H_

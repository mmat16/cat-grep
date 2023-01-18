#ifndef SRC_GREP_HELPER_H_
#define SRC_GREP_HELPER_H_

#include <stdbool.h>
#include <stdio.h>

#include "functions.h"

void parseOpts(char *opt, Flag *flags);
bool checkFilePointer(FILE *f, char *fileName, bool sFlag);
void out(FILE *file, char *patterns[], int pCntr, int fCntr, Flag flags,
         char *fName);
bool doArgs(Flag flags, int ptrnCounter, char *buf, char *patterns[],
            bool *printFileName, int *cCounter, int fCounter, char *fName,
            int lnCounter);

#endif  // SRC_GREP_HELPER_H_

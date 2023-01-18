#include "functions.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "helper.h"

void parser(int argc, char *argv[], int *optind, int *ptrnCntr, int *flsCntr,
            char *patterns[], char *files[], Flag *flags, int *free) {
  bool hasPattern = false;
  while (*optind < argc) {
    if (argv[*optind][0] == '-') {
      parseOpts(argv[*optind], flags);
      //      hasOpt = *optind;
      if (flags->e) {
        *optind += 1;
        patterns[*ptrnCntr] = argv[*optind];
        *ptrnCntr += 1;
        flags->e = false;
      }
      if (flags->f) {
        *optind += 1;
        FILE *p = fopen(argv[*optind], "rb");
        if (checkFilePointer(p, argv[*optind], flags->s)) {
          char buf[256];
          while (fgets(buf, 256, p)) {
            patterns[*ptrnCntr] = (char *)malloc(256 * sizeof(char));
            snprintf(patterns[*ptrnCntr], strlen(buf), "%s", buf);
            *ptrnCntr += 1;
          }
        }
        flags->f = false;
        *free = 1;
      }
    } else {
      if (!checkFilePointer(fopen(argv[*optind], "r"), argv[*optind], true) &&
          !hasPattern) {
        patterns[*ptrnCntr] = argv[*optind];
        *ptrnCntr += 1;
        hasPattern = true;
      } else {
        files[*flsCntr] = argv[*optind];
        *flsCntr += 1;
      }
    }
    *optind += 1;
  }
}

void cleanPointers(char *ptrns[], int pCntr, bool fFlag) {
  if (fFlag) {
    for (int i = 0; i < pCntr; i++) {
      free(ptrns[i]);
    }
  }
}

void processor(char *patterns[], int ptrnsCntr, char *files[], int filesCntr,
               Flag flags) {
  int filesInd = 0;
  while (filesInd < filesCntr) {
    FILE *fp = fopen(files[filesInd], "rb");
    char fileName[256];
    strcpy(fileName, files[filesInd]);
    if (checkFilePointer(fp, files[filesInd], flags.s))
      out(fp, patterns, ptrnsCntr, filesCntr, flags, fileName);
    filesInd++;
    fclose(fp);
  }
}

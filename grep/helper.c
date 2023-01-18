#include "helper.h"

#include <regex.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool createRegex(regex_t *reg, char *string, int rFlag) {
  bool success;
  int value = regcomp(reg, string, rFlag);
  if (value) {
    fprintf(stderr, "failed to compile regular expression\nquit\n");
    success = false;
  } else {
    success = true;
  }
  return success;
}

bool doArgs(Flag flags, int ptrnCounter, char *buf, char *patterns[],
            bool *printFileName, int *cCounter, int fCounter, char *fName,
            int lnCounter) {
  bool hasPtrn = false;
  bool stop = false;
  int value;
  for (int i = 0; i < ptrnCounter && !hasPtrn; i++) {
    regex_t regex;
    if (createRegex(&regex, patterns[i], flags.i)) {
      value = regexec(&regex, buf, 0, NULL, flags.i);
      hasPtrn = (!value);
    } else {
      exit(1);
    }
    if ((hasPtrn && !flags.v) || (!hasPtrn && flags.v)) {
      *printFileName = true;
      if (flags.c || flags.l) {
        *cCounter += 1;
        regfree(&regex);
        continue;
      }
      if (flags.v && i != ptrnCounter - 1) {
        hasPtrn = false;
        regfree(&regex);
        continue;
      }
      if (fCounter > 1 && !flags.h) printf("%s:", fName);
      if (flags.n) printf("%d:", lnCounter);
      printf("%s", buf);
    }
    regfree(&regex);
  }
  if (flags.l && *printFileName) {
    printf("%s\n", fName);
    stop = true;
  }
  return stop;
}

void out(FILE *file, char *patterns[], int pCntr, int fCntr, Flag flags,
         char *fName) {
  char *buffer = (char *)malloc(4096 * sizeof(char));
  bool stop = false;
  bool printFileName = false;
  if (buffer == NULL) {
    fprintf(stderr, "required memory were not allocated\n");
    fclose(file);
    exit(1);
  }
  int lineCounter = 0;
  int containsCounter = 0;
  while ((fgets(buffer, 4096, file) != NULL) && !stop) {
    int len = strlen(buffer);
    if (buffer[len - 1] != '\n') strcat(buffer, "\n");
    lineCounter++;
    stop = doArgs(flags, pCntr, buffer, patterns, &printFileName,
                  &containsCounter, fCntr, fName, lineCounter);
  }
  if (flags.c) {
    if (fCntr > 1 && !flags.h) printf("%s:", fName);
    printf("%d\n", containsCounter);
  }
  free(buffer);
}

bool checkFilePointer(FILE *f, char *fileName, bool sFlag) {
  bool flag = true;
  if (f == NULL) {
    flag = false;
    if (!sFlag) fprintf(stderr, "no such file or directory %s\n", fileName);
  }
  return flag;
}

void parseOpts(char *opt, Flag *flags) {
  int len = strlen(opt);
  for (int i = 1; i < len; i++) {
    switch (opt[i]) {
      case 'e':
        flags->e = true;
        break;
      case 'i':
        flags->i = REG_ICASE;
        break;
      case 'v':
        flags->v = true;
        break;
      case 'c':
        flags->c = true;
        break;
      case 'l':
        flags->l = true;
        break;
      case 'n':
        flags->n = true;
        break;
      case 'h':
        flags->h = true;
        break;
      case 's':
        flags->s = true;
        break;
      case 'f':
        flags->f = true;
        break;
      default:
        fprintf(stderr,
                "illegal option \"%s\"\nusage: ./s21_grep [-eivclnhsf] [FILE "
                "...]\n",
                opt);
        exit(1);
    }
  }
}

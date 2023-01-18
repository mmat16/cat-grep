#include "functions.h"

int main(int argc, char *argv[]) {
  Flag options = {0};
  int optind = 1;
  int ptrnCntr = 0;
  int filesCntr = 0;
  char *patterns[256];
  char *files[256];
  int fFlag = 0;
  parser(argc, argv, &optind, &ptrnCntr, &filesCntr, patterns, files, &options,
         &fFlag);
  processor(patterns, ptrnCntr, files, filesCntr, options);
  cleanPointers(patterns, ptrnCntr, fFlag);
  return 0;
}

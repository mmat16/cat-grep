#include "functions.h"

#include <getopt.h>
#include <stdio.h>
#include <string.h>

#include "helper.h"

void parser(int argc, char *argv[], opt *flags) {
  int opt = 0;
  int optionIndex = 0;
  static struct option longOptions[] = {{"number", 0, 0, 'n'},
                                        {"squeeze-blank", 0, 0, 's'},
                                        {"number-nonblank", 0, 0, 'b'},
                                        {0, 0, 0, 0}};
  while ((opt = getopt_long(argc, argv, "+benstvTE", longOptions,
                            &optionIndex)) != -1) {
    getOptions(opt, flags);
  }
}

void reader(int argc, char *argv[], opt flags) {
  int currentFile = optind;
  FILE *fp = NULL;
  int status = 0;
  while (currentFile <= argc) {
    if (currentFile != argc) {
      fp = fopen(argv[currentFile], "rb");
      status = checkFilePointer(fp, argv, currentFile);
    }
    if (!status) {
      currentFile++;
      continue;
    }
    out(flags, fp);
    currentFile++;
  }
  fclose(fp);
}

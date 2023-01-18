#include "helper.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"

void createTable(const char *table[static 256]) {
  const char *preTable[] = {
      "\00",  "\01",  "\02",  "\03",  "\04",  "\05",  "\06",  "\a",   "\b",
      "\t",   "\n",   "\v",   "\014", "\r",   "\016", "\017", "\020", "\021",
      "\022", "\023", "\024", "\025", "\026", "\027", "\030", "\031", "\032",
      "\033", "\034", "\035", "\036", "\037", " ",    "!",    "\"",   "#",
      "$",    "%",    "&",    "'",    "(",    ")",    "*",    "+",    ",",
      "-",    ".",    "/",    "0",    "1",    "2",    "3",    "4",    "5",
      "6",    "7",    "8",    "9",    ":",    ";",    "<",    "=",    ">",
      "?",    "@",    "A",    "B",    "C",    "D",    "E",    "F",    "G",
      "H",    "I",    "J",    "K",    "L",    "M",    "N",    "O",    "P",
      "Q",    "R",    "S",    "T",    "U",    "V",    "W",    "X",    "Y",
      "Z",    "[",    "\\",   "]",    "^",    "_",    "`",    "a",    "b",
      "c",    "d",    "e",    "f",    "g",    "h",    "i",    "j",    "k",
      "l",    "m",    "n",    "o",    "p",    "q",    "r",    "s",    "t",
      "u",    "v",    "w",    "x",    "y",    "z",    "{",    "|",    "}",
      "~",    "\x7f", "\x80", "\x81", "\x82", "\x83", "\x84", "\x85", "\x86",
      "\x87", "\x88", "\x89", "\x8a", "\x8b", "\x8c", "\x8d", "\x8e", "\x8f",
      "\x90", "\x91", "\x92", "\x93", "\x94", "\x95", "\x96", "\x97", "\x98",
      "\x99", "\x9a", "\x9b", "\x9c", "\x9d", "\x9e", "\x9f", "\xa0", "\xa1",
      "\xa2", "\xa3", "\xa4", "\xa5", "\xa6", "\xa7", "\xa8", "\xa9", "\xaa",
      "\xab", "\xac", "\xad", "\xae", "\xaf", "\xb0", "\xb1", "\xb2", "\xb3",
      "\xb4", "\xb5", "\xb6", "\xb7", "\xb8", "\xb9", "\xba", "\xbb", "\xbc",
      "\xbd", "\xbe", "\xbf", "\xc0", "\xc1", "\xc2", "\xc3", "\xc4", "\xc5",
      "\xc6", "\xc7", "\xc8", "\xc9", "\xca", "\xcb", "\xcc", "\xcd", "\xce",
      "\xcf", "\xd0", "\xd1", "\xd2", "\xd3", "\xd4", "\xd5", "\xd6", "\xd7",
      "\xd8", "\xd9", "\xda", "\xdb", "\xdc", "\xdd", "\xde", "\xdf", "\xe0",
      "\xe1", "\xe2", "\xe3", "\xe4", "\xe5", "\xe6", "\xe7", "\xe8", "\xe9",
      "\xea", "\xeb", "\xec", "\xed", "\xee", "\xef", "\xf0", "\xf1", "\xf2",
      "\xf3", "\xf4", "\xf5", "\xf6", "\xf7", "\xf8", "\xf9", "\xfa", "\xfb",
      "\xfc", "\xfd", "\xfe", "\xff"};
  memcpy(table, preTable, sizeof(preTable));
}

void setEndl(const char *table[static 256]) { table['\n'] = "$\n"; }

void setTab(const char *table[static 256]) { table['\t'] = "^I"; }

void setNonPrnt(const char *table[static 256]) {
  const char *first[] = {"^@", "^A", "^B", "^C", "^D", "^E", "^F", "^G", "^H"};
  const char *second[] = {"^K", "^L", "^M", "^N",  "^O", "^P", "^Q",
                          "^R", "^S", "^T", "^U",  "^V", "^W", "^X",
                          "^Y", "^Z", "^[", "^\\", "^]", "^^", "^_"};
  const char *third[] = {
      "^?",   "M-^@", "M-^A",  "M-^B", "M-^C", "M-^D", "M-^E", "M-^F", "M-^G",
      "M-^H", "M-^I", "M-^J",  "M-^K", "M-^L", "M-^M", "M-^N", "M-^O", "M-^P",
      "M-^Q", "M-^R", "M-^S",  "M-^T", "M-^U", "M-^V", "M-^W", "M-^X", "M-^Y",
      "M-^Z", "M-^[", "M-^\\", "M-^]", "M-^^", "M-^_", "M- ",  "M-!",  "M-\"",
      "M-#",  "M-$",  "M-%",   "M-&",  "M-'",  "M-(",  "M-)",  "M-*",  "M-+",
      "M-,",  "M--",  "M-.",   "M-/",  "M-0",  "M-1",  "M-2",  "M-3",  "M-4",
      "M-5",  "M-6",  "M-7",   "M-8",  "M-9",  "M-:",  "M-;",  "M-<",  "M-=",
      "M->",  "M-?",  "M-@",   "M-A",  "M-B",  "M-C",  "M-D",  "M-E",  "M-F",
      "M-G",  "M-H",  "M-I",   "M-J",  "M-K",  "M-L",  "M-M",  "M-N",  "M-O",
      "M-P",  "M-Q",  "M-R",   "M-S",  "M-T",  "M-U",  "M-V",  "M-W",  "M-X",
      "M-Y",  "M-Z",  "M-[",   "M-\\", "M-]",  "M-^",  "M-_",  "M-`",  "M-a",
      "M-b",  "M-c",  "M-d",   "M-e",  "M-f",  "M-g",  "M-h",  "M-i",  "M-j",
      "M-k",  "M-l",  "M-m",   "M-n",  "M-o",  "M-p",  "M-q",  "M-r",  "M-s",
      "M-t",  "M-u",  "M-v",   "M-w",  "M-x",  "M-y",  "M-z",  "M-{",  "M-|",
      "M-}",  "M-~",  "M-^?"};

  memcpy(table, first, sizeof(first));
  memcpy(&table[9 + 2], second, sizeof(second));
  memcpy(&table['~' + 1], third, sizeof(third));
}

int checkFilePointer(FILE *pointer, char *argv[], int curFile) {
  int flag = 1;
  if (pointer == NULL) {
    fprintf(stderr, "%s: %s: No such file or directory\n", argv[0],
            argv[curFile]);
    flag = 0;
  }
  return flag;
}

void getOptions(int gopt, opt *flags) {
  switch (gopt) {
    case 'b':
      flags->b = 1;
      break;
    case 'e':
      flags->e = 1;
      flags->v = 1;
      break;
    case 'n':
      flags->n = 1;
      break;
    case 's':
      flags->s = 1;
      break;
    case 't':
      flags->t = 1;
      flags->v = 1;
      break;
    case 'v':
      flags->v = 1;
      break;
    case 'T':
      flags->t = 1;
      flags->v = 0;
      break;
    case 'E':
      flags->e = 1;
      flags->v = 0;
      break;
    default:
      fprintf(stderr, "usage ./s21-cat [-benstvTE] [file ...]");
      exit(1);
  }
}

void out(opt flags, FILE *fp) {
  const char *table[256];
  createTable(table);
  if (flags.e) {
    setEndl(table);
  }
  if (flags.t) {
    setTab(table);
  }
  if (flags.v) {
    setNonPrnt(table);
  }
  int c = 0;
  int last = '\n';
  int sqz = 0;
  int lnNum = 1;
  while (fread(&c, 1, 1, fp) > 0) {
    if (last == '\n') {
      if (flags.s && c == '\n') {
        if (sqz) continue;
        sqz = 1;
      } else {
        sqz = 0;
      }
      if (flags.b) {
        if (c != '\n') {
          printf("%*d\t", 6, lnNum++);
        }
      } else if (flags.n) {
        printf("%*d\t", 6, lnNum++);
      }
    }
    if (!*table[c]) {
      printf("%c", '\0');
    } else {
      printf("%s", table[c]);
    }
    last = c;
  }
}

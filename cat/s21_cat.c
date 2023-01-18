#include "functions.h"

int main(int argc, char *argv[]) {
  opt flags = {0, 0, 0, 0, 0, 0};
  parser(argc, argv, &flags);
  reader(argc, argv, flags);
  return 0;
}

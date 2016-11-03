#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char const *argv[]) {
  int i, file, patternSize;
  char const *pattern;
  int const BUFFOR_SIZE = 256;
  char buffor[BUFFOR_SIZE];

  // Check how many arguments program has
  if (argc != 3) {
    printf("Wrong number of arguments!\n");
    return(1);
  }

  // Take pattern
  pattern = argv[1];
  patternSize = 0; // TODO Finding pattern size

  // Open file
  if (file = open(argv[2], O_RDONLY) == -1) {
    printf("File error!\n");
    return(3);
  }
  // TODO Reading file and looking for the pattern

  return(0);
}

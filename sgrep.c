#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  int i, file, patternLength, lineLength;
  char const *pattern;
  int const BUFFOR_SIZE = 256;
  char buffor[BUFFOR_SIZE];

  // Check how many arguments program has
  if (argc != 3) {
    printf("Wrong number of arguments!\n");
    return(1);
  }

  // Take a pattern and lenght of the pattern
  pattern = argv[1];
  patternLength = strlen(pattern);

  // Open file
  if (file = open(argv[2], O_RDONLY) == -1) {
    printf("File error!\n");
    return(3);
  }

  // Take every line from file
  while ((lineLength = read(file, buffor, BUFFOR_SIZE)) > 0) {
    // If pattern exists in the line, print this line
    if (strstr(buffor, pattern) != NULL)
      printf("%s\n", buffor);
  }
  return(0);
}

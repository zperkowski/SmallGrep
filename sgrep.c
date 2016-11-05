#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  FILE *file;
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
  
  // Open file
  if ((file = fopen(argv[2], "r")) == NULL) {
    printf("File error!\n");
    return(3);
  }

  // Take every line from file
  while (fgets(buffor, BUFFOR_SIZE, file)) {
    // If pattern exists in the line, print this line
    if (strstr(buffor, pattern) != NULL)
      printf("%s", buffor);
  }
  fclose(file);
  return(0);
}

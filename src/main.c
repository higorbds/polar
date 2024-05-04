#include <stdio.h>
#include <string.h>

/*
 * A Simple Hello World code
 */
int main(int argc, char **argv) {
  printf("Hello, Command Line! %d\n", argc);
  
  if(argc > 2) {
    if(strcmp(argv[1], "new") == 0) {
      char *name_file;
      sprintf(name_file, "%s.txt", argv[2]);
      FILE *file = fopen(name_file, "w");
      fprintf(file, "Hello, %s!\n", argv[2]);

      fclose(file);
    }

  }
  
  return 0;
}

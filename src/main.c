#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "polar.h"

static inline bool skip_prefix(const char *str, const char *prefix,
                               const char **out) {
  do {
    if (!*prefix) {
      *out = str;
      return true;
    }
  } while (*str++ == *prefix++);
  return false;
}

bool command(char *arg, char *command) {
  if (strcmp(arg, command) == 0)
    return true;
  return false;
}

/*
 * A Simple Hello World code
 */
int main(int argc, char **argv) {
  if (argc <= 1) {
    fprintf(stderr, "No command avaliable, see commands in 'polar help'\n");
    exit(-1);
  }

  // 'help' command
  if (command(argv[1], "help")) {
    fprintf(stdout, "Avaliable commands:\n");
    fprintf(stdout, "\thelp: prints this help text.\n");
    fprintf(stdout, "\tnew <project_name> <options>: create a new project project-name with options\n");
    fprintf(stdout, "\t\t--git: initialize git on their project\n");
    fprintf(stdout, "\t\t--lang=<lang>: copy a <lang> template to your project\n");
  }

  // 'new' command
  if (command(argv[1], "new")) {
    if (argc >= 3) {

      bool as_git = false;
      const char *lang;
      char project_name[PATH_SIZE];
      strcpy(project_name, argv[2]);

      for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--git") == 0)
          as_git = true;
        skip_prefix(argv[i], "--lang=", &lang);
      }

      create_project(project_name, lang, as_git);

    } else {
      fprintf(stderr, "'polar new' command requires an project name.\nType "
                      "'polar new (project_name)'.\n");
      exit(-1);
    }
  }

  return 0;
}

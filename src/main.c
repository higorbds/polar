#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>

#define PJ_NAME_SIZE 20
#define PATH_SIZE 30
#define PROJECTS_PATH "/home/higor/Projects" // ALTERATE THIS TO YOUR PERSONAL PROJECT PATH

void put_log(char *msg) {
  fprintf(stdout, "%s", msg);
}

int create_project(const char *name, const char *lang, const bool git) {
  char project_path[PATH_SIZE];
  sprintf(project_path, "%s/%s", PROJECTS_PATH, name);

  struct stat st = {0};
  if(stat(project_path, &st) != -1) {
    fprintf(stderr, "Project: '%s' Already exists!\n", name);
    exit(-1);
  }

  mkdir(project_path, 0777);
  put_log("[INFO]: Creating path.\n");

  return 0;
}

/*
 * A Simple Hello World code
 */
int main(int argc, char **argv) {
  if(argc > 1) {

    // 'new' command
    if(strcmp(argv[1], "new") == 0) {
      if(argc >= 3) {

        char project_name[PJ_NAME_SIZE];
        strcpy(project_name, argv[2]);
        create_project(project_name, NULL, false);

      } else {
        fprintf(stderr, "'polar new' command requires an project name.\nType 'polar new (project_name)'.\n");
        exit(-1);
      }

    }

  }
  
  return 0;
}

#include <stdbool.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>

#include "polar.h"

int create_project(const char *name, const char *lang, const bool git) {
  char project_path[PATH_SIZE];
  sprintf(project_path, "%s/%s", PROJECTS_PATH, name);

  struct stat st = {0};
  if(stat(project_path, &st) != -1) {
    fprintf(stderr, "Project: '%s' Already exists!\n", name);
    exit(-1);
  }

  mkdir(project_path, 0777);
  LOG("[INFO]: Creating path.");

  if(git) {
    char tmp[PJ_NAME_SIZE+8];
    sprintf(tmp, "git init %s", project_path);
    system(tmp);
    LOG("[INFO] Initializing Git");
  }

  return 0;
}

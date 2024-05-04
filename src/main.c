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
  fprintf(stdout, "%s\n", msg);
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
  put_log("[INFO]: Creating path.");

  if(git) {
    char tmp[PJ_NAME_SIZE+8];
    sprintf(tmp, "git init %s", project_path);
    system(tmp);
    put_log("[INFO] Initializing Git");
  }

  return 0;
}

static inline bool skip_prefix(const char *str, const char *prefix,
			       const char **out)
{
	do {
		if (!*prefix) {
			*out = str;
			return true;
		}
	} while (*str++ == *prefix++);
	return false;
}

/*
 * A Simple Hello World code
 */
int main(int argc, char **argv) {
  if(argc > 1) {

    // 'new' command
    if(strcmp(argv[1], "new") == 0) {
      if(argc >= 3) {
        
        bool as_git = false;
        const char *lang; 
        char project_name[PATH_SIZE];
        strcpy(project_name, argv[2]);

        for(int i=1; i < argc; i++) {
          if(strcmp(argv[i], "--git") == 0)
            as_git = true;
          if(skip_prefix(argv[i], "--lang=", &lang))
            printf("LANG_PARAM=%s\n", lang);
        }

        create_project(project_name, lang, as_git);

      } else {
        fprintf(stderr, "'polar new' command requires an project name.\nType 'polar new (project_name)'.\n");
        exit(-1);
      }

    }

  }
  
  return 0;
}

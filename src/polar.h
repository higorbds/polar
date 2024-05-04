#ifndef POLAR_H
#define POLAR_H

#define PJ_NAME_SIZE 20
#define PATH_SIZE 30
#define PROJECTS_PATH "/home/higor/Projects" // ALTERATE THIS TO YOUR PERSONAL PROJECT PATH

#define LOG(msg) \
do { \
    fprintf(stdout, "%s\n", msg); \
} while(0);

int create_project(const char *name, const char *lang, const bool git);
static inline bool skip_prefix(const char *str, const char *prefix, const char **out);

#endif

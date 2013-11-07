#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#include <cstdio>

int main(int argc, char *argv[]) {
  fprintf(stdout, "%s v%s (Copyright %s)\n", PACKAGE_NAME, PACKAGE_VERSION, COPYRIGHT);
  fprintf(stdout, "Build %s\n", BUILD_DATE);
  return 0;
}


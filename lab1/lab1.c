#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char *line = NULL;
  size_t size = 0;
  ssize_t length;

  while (1) {
    printf("Enter some text:");
    length = getline(&line, &size, stdin);
    if (length == -1) {
      break;
    }

    if (line[length - 1] == '\n') {
      line[length - 1] = '\0';
    }
    printf("Tokens:\n");

    char *saveptr;
    char *token = strtok_r(line, " ", &saveptr);

    while (token != NULL) {
      printf(" %s\n", token);
      token = strtok_r(NULL, " ", &saveptr);
    }
  }

  free(line);
  return 0;
}

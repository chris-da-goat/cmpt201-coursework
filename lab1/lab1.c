#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  char *buffer, *token;
  char *saveptr;
  size_t bufsize = 50;
  ssize_t input;
  int j = 1;

  buffer = (char *)malloc(bufsize * sizeof(char));

  while (j == 1) {
    printf("Please enter some text: ");
    while ((input = getline(&buffer, &bufsize, stdin)) != -1) {

      printf("Tokens: ");
      token = strtok_r(buffer, " ", &saveptr);

      while (token != NULL) {
        printf("\n");
        printf("%s", token);
        token = strtok_r(NULL, " ", &saveptr);
      }
      printf("Please enter some text: ");
    }
  }
  return 0;
}

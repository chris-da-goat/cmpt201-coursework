#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 5

void removeLines(int *counter, char **lines);
void addToLines(char **lines, int *counter, char *input);
char *takeInput();

int main() {

  char *input = NULL;
  int counter = 0;
  char *lines[MAX_LINES];

  while (1) {
    printf("Enter input: ");
    input = takeInput();

    if (strcmp(input, "print") == 0) {
      for (int i = 0; i < counter; i++) {
        printf("%s \n", lines[i]);
        lines[i] = NULL;
      }
    } else {
      addToLines(lines, &counter, input);
    }
  }

  free(input);
  return 0;
}

char *takeInput() {
  char *buffer = NULL;
  size_t buffsize = 0;
  ssize_t len = getline(&buffer, &buffsize, stdin);
  if (len == -1) {
    exit(1);
  }
  buffer[len - 1] = '\0';
  return buffer;
}

void addToLines(char **lines, int *counter, char *input) {
  if (*counter >= MAX_LINES) {
    removeLines(counter, lines);
  }
  lines[*counter] = input;
  (*counter)++;
}

void removeLines(int *counter, char **lines) {
  if (counter > 0) {
    free(lines[0]);
    for (int i = 1; i < *counter; i++) {
      lines[i - 1] = lines[i];
    }
    (*counter)--;
  }
}

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  int i = 1;
  char *input = NULL;
  size_t cap = 0;

  while (i == 1) {
    printf("Enter programs to run. \n");

    ssize_t len = getline(&input, &cap, stdin);
    if (len > 0 && input[len - 1] == '\n') {
      input[len - 1] = '\0';
    }

    pid_t pid = fork();
    if (pid == 0) {
      execlp(input, input, (char *)NULL);
    }

    if (waitpid(pid, NULL, 0) == -1) {
      perror("waitpid");
      break;
    }
  }

  free(input);
  return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <string.h>

char sigintmsg[128] = "Program exited due to SIGINT\n";

void sighandler(int signo) {
  if (signo == SIGINT) {
    int f = open("temp.txt", O_RDWR | O_APPEND | O_CREAT, 0644);
    write(f, sigintmsg, strlen(sigintmsg));
    close(f);
    exit(0);
  } else if (signo = SIGUSR1) {
    printf("Parents: %d\n", getppid());
  }
}

int main(int argc, char *argv[]) {
  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);

  while(1) {
    printf("Process PID: %d\n", getpid());
    sleep(1);
  }
  return 0;
}

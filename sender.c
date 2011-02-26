#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "message.h"

int main(int argc, const char **argv) {

  int out = open("out1", O_WRONLY),
    in = open("in", O_RDONLY | O_NONBLOCK);

  message *m;
  char sent, received, *text = (char*)malloc(32 * sizeof(char));
  int i, n = atoi(argv[1]);

  write(out, &n, sizeof(int));

  for (i = 0; i < n; ++ i) {
    sprintf(text, "Hello World %d!\n", i);
    sent = i % 2;
    m = new_message(text, sent);
    int j = 0;
    do {
      write_message(out, *m);
      printf("sending: %d\n", i);

      int t = 0;
      do {
        read(in, &received, sizeof(char));
        if (errno != EAGAIN)
          break;
        sleep(1);
        t += 100;
      } while (t < 1000);

      printf("%d\n", j++);
    } while (sent != received);
    printf("confirmed %d\n", i);

    free(m->contents);
    free(m);
  }

  free(text);
  close(out);
  close(in);
  return 0;
}

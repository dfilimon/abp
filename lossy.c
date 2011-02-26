#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "message.h"

int main(int argc, const char **argv) {
  int out1 = open("out1", O_RDONLY),
    out2  = open("out2", O_WRONLY);

  int n;
  read(out1, &n, sizeof(int));
  write(out2, &n, sizeof(int));

  message *m;
  srand(time(NULL));
  while (1) {
    read_message(out1, &m);

    printf("read %d\n", m->bit);
    if (rand() % 5 == 0)
      continue;

    write_message(out2, m);
    printf("forwarded %d\n", m->bit);

  }

  return 0;
}

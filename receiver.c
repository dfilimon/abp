#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "message.h"

int main(int argc, const char **argv) {

  int out = open("out2", O_RDONLY),
    in = open("in", O_WRONLY);

  message *m;
  int i, n;
  read(out, &n, sizeof(int));
  char prevBit = -1;
  for (i = 0; ; ++ i) {

    read_message(out, &m);
    if (prevBit == -1 || prevBit != m->bit) {
      puts(m->contents);
      prevBit = m->bit;
    }
    write(in, &(m->bit), sizeof(char));

    free(m->contents);
    free(m);
  }

  close(out);
  close(in);

  return 0;
}

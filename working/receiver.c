#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "message.h"

int main(int argc, const char **argv) {

  int out = open("out", O_RDONLY),
    in = open("in", O_WRONLY);

  message *m;
  int i, n;
  read(out, &n, sizeof(int));
  
  for (i = 0; i < n; ++ i) {
    read_message(out, &m);
    
    puts(m->contents);
    write(in, &(m->bit), sizeof(char));
    
    free(m->contents);
    free(m);
  }

  close(out);
  close(in);
  
  return 0;
}

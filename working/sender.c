#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "message.h"

int main(int argc, const char **argv) {

  int out = open("out", O_WRONLY),
    in = open("in", O_RDONLY);
  
  message *m;  
  char status, *text = (char*)malloc(32 * sizeof(char));
  int i, n = atoi(argv[1]);

  write(out, &n, sizeof(int));
  
  for (i = 0; i < n; ++ i) {
    sprintf(text, "Hello World %d!", i);
    m = new_message(text, i % 2);
    
    write_message(out, *m);
    rec = read(in, &status, sizeof(char));
    do {
    } while (rec != i % 2);
    printf("%d\n", status);

    free(m->contents);
    free(m);
  }

  free(text);
  close(out);
  close(in);
  return 0;
}

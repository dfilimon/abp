#include "message.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline int error(int ret) {
  if (ret < 0)
    perror("Something Bad happened");
  return ret;
}

int read_message(int fd, message **m) {
  *m = (message*)malloc(sizeof(message));
  
  int total_read = 0, read_ret;
  read_ret = read(fd, &((*m)->bit), sizeof(char));
  total_read += error(read_ret);

  //printf("%d\n", total_read);
  
  read(fd, &((*m)->length), sizeof(int));
  total_read += error(read_ret);

  //printf("%d\n", total_read);


  (*m)->contents = (char*)malloc((*m)->length * sizeof(char));
  read(fd, (*m)->contents, (*m)->length * sizeof(char));
  total_read += error(read_ret);

  //printf("%d\n", total_read);

  
  return total_read;
}

int write_message(int fd, message m) {
  int total_written = 0, write_ret;
  write_ret = write(fd, &m.bit, sizeof(char));
  total_written += error(write_ret);

  write_ret = write(fd, &m.length, sizeof(int));
  total_written += error(write_ret);

  write_ret = write(fd, m.contents, m.length * sizeof(char));
  total_written += error(write_ret);
  
  return total_written;
}

message* new_message(char *str, char bit) {
  message *m = (message*)malloc(sizeof(message));
  m->bit = bit;
  m->length = strlen(str) + 1;
  m->contents = strdup(str);
  return m;
}

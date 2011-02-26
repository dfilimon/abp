#ifndef __MESSAGE_H__
#define __MESSAGE_H__

typedef struct {
  char bit;
  int length;
  char *contents;
} message;

int read_message(int fd, message **m);
int write_message(int fd, message *m);
message* new_message(char *str, char bit);

#endif

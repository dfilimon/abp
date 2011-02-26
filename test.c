#include <stdio.h>

int main() {
  void *p;
  printf("%d %d %d\n", p, p + 1, sizeof p);
  return 0;
}

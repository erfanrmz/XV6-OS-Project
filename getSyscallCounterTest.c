#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
  char *a = argv[1];
  int n = atoi(a);
  getSyscallCounter(n);
  getSyscallCounter(n);
  getSyscallCounter(n);
  getSyscallCounter(n);
  getSyscallCounter(n);
  getSyscallCounter(n);
  printf(1,"Counter of systemCall %d: %d \n",n,getSyscallCounter(n));
  while(wait() != -1) { }
    sleep(1);
    exit();

    return 0;
}
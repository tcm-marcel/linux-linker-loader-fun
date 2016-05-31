#define _GNU_SOURCE

#include <unistd.h>
#include <stdio.h>
//#include <sys/ptrace.h>

//long ptrace(enum __ptrace_request request, pid_t pid, void *addr, void *data)

// full signature is not even necessary, because we do not need the parameters on the stack
long ptrace()
{
  printf("ptrace hooked!\n");
  return 1;
}

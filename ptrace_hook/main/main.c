#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/ptrace.h>

int main()
{
  if (ptrace(PTRACE_TRACEME, 0, 0, 0) == -1)
  {
    printf("Debugger recognised\n");
    exit(1);
  }
  else
  {
    printf("Everything looks fine, seems there is no debugger\n");
  }

  return 0;
}

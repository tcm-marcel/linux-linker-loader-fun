ptrace hook
===========

Example of hooking ptrace with LD_PRELOAD to escape the anti-debugging trick for GDB. 

## GDB anti-debugging trick

This article describes the trick of checking the return of ptrace during execution to determine, whether the program is currently getting debugged by GDB. Malware may use this to hide parts of its code during analysis. 

'''
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
'''

https://xorl.wordpress.com/2009/01/01/quick-anti-debugging-trick-for-gdb/

## Hooking ptrace

The trick can be easily be fooled by writing a simple ptrace hook returning always 1 and compiling it into a shared library. When starting GDB the linker/loader can be told to use the the ptrace hook instead of the orginal functino by using the LD_PRELOAD environment variable. 

'''
// full signature is not even necessary, because we do not need the parameters on the stack
long ptrace()
{
  printf("ptrace hooked!\n");
  return 1;
}
'''

Luckily hooking ptrace with LD_PRELOAD doesn't affect GDB, which avoids further differentation in the hook function. 

## Usage

1. Debugging without ptrace hook
'''gdb ./main/main''' will start the debugger and with '''r''' the program starts running. The output should be '''Debugger recognised'''. 

2. Debugging with ptrace hook
'''LD_PRELOAD="$(pwd)/lib/libfoo.so" gdb ./main/main''' sets the environment variable for the temporary shell before starting gdb. When running the program, the output now should be '''Everything looks fine, seems there is no debugger'''.

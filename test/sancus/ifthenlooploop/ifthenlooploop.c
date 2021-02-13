#include "ifthenlooploop.h"

static int v;

__attribute__((noinline)) static void foo(int n, int m)
{
  n < m ? v++ : v--;
}

int ifthenlooploop_enter(__attribute__((secret)) int a, int b)
{
  int result = 3;

  if (a < b)
  {
    int i;

    for (i=0; i<3; i++)
    {
      int j;

      for (j=0; j<4; j++)
      {
        foo(i, j);
      }
    }
  }

  return result;
}

// The following functions should be generated by SLLVM but this feature
// is not supported yet.
#if 1
__attribute__((noinline, used)) static void _nds_foo(int i) 
{ 
  asm("\tmov #1, r14\n"
      "\tcmp r13, r12\n"
      "\tjl .LOC1\n"
      "\tmov #-1, r14\n"
      "\tbr #.LOC2\n"
      ".LOC1:\n"
      "\tnop\n"
      "\tbr #.LOC2\n"
      ".LOC2:\n"
      "\tadd r14, &v\n"
      "\tret\n");
}

__attribute__((noinline, used)) static void _ndd_foo(int i) 
{ 
  asm("\tnop\n"
      "\tnop\n"
      "\tmov #42, r3\n"
      "\tnop\n"
      "\tmov #42, r3\n"
      "\tnop\n"
      "\tmov #42, r3\n"
      "\tbis #0xFFFF, 0(r4)\n"
      "\tret\n");
}
#endif

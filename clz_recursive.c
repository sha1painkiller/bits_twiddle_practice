#include <stdio.h>

int main(int argc, char* argv[])
{
  int ret = 0;
  int input = 0;

  if (argc != 2) {
    printf("invalid command. use \"clz <number>\"\n");
    return 0;
  }

  input = atoi(argv[1]);
  ret = clz_recursive(input, 32, 0);
  printf("input[0x%08x]. leading zeros[%d]\n", input, ret);
  return 0;
}


// using recursive skill to count leading zeros in logn time?
int clz_recursive(int value, int bits, int zeros)
{
  if (bits > 1) {
    int mask = 1 << (bits/2);
    int i;
    for (i = 0; i < bits/2 - 1; i++)
      mask |= (mask << 1);

    if (mask & value)
      clz_recursive(value >>= bits/2, bits/2, 0 + zeros);
    else
      clz_recursive(value, bits/2, bits/2 + zeros);
  } else {
    return zeros;
  }
}


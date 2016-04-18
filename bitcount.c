#include <stdio.h>

int main(int argc, char* argv[])
{
  int ret = 0;
  int input = 0;

  if (argc != 2) {
    printf("invalid command. use \"bitcount <number>\"\n");
    return 0;
  }

  input = atoi(argv[1]);
  ret = bitcount_SWAR(input);
  //ret = bitcount_decomp(input);
  printf("input[0x%08x]. bits count[%d]\n", input, ret);
  return 0;
}

// check step-by-step explanation from
// http://stackoverflow.com/questions/22081738/how-variable-precision-swar-algorithm-works
int bitcount_SWAR(int i)
{
   i = i - ((i >> 1) & 0x55555555);
   i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
   return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

int bitcount_decomp(int x)
{
  x = (x & 0x55555555) + ((x >> 1) & 0x55555555);
  x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
  x = (x & 0x0f0f0f0f) + ((x >> 4) & 0x0f0f0f0f);
  x = (x & 0x00ff00ff) + ((x >> 8) & 0x00ff00ff);
  x = (x & 0x0000ffff) + ((x >> 16) &0x0000ffff);
  return x;
}

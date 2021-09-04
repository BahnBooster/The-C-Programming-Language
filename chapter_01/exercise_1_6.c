#include <stdio.h>

void main()
{
	int c;

  c = getchar();

  while (c != EOF)
  {
    printf("\nValue %d\n", (c != EOF));
    c = getchar();
  }

  printf("\nValue %d\n", (c != EOF));
}

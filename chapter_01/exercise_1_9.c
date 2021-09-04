#include <stdio.h>

void main()
{
	double c;

  while ((c = getchar()) != EOF)
  {
    putchar(c);

    //blank
    if (c == ' ')
    {
      while (c == ' ')
      {
        c = getchar();
      }
      putchar(c);
    }
  }
}

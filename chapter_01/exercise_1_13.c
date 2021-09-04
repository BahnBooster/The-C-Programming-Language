#include <stdio.h>


/**
 *
 * Print a horizontal histogram of words in the input.
 *
 **/

void main()
{
	int c, first, nw;

  first = 1;
  nw = 1;

  while((c = getchar()) != EOF)
  {
    if (c != ' ' && c != '\n' && c != '\t')
    {
      if (first == 1)
      {
        printf("%d", nw);
        first = 0;
        putchar('*');
      }
      else
      {
        putchar('*');
      }
    }
    else
    {
      nw++;
      putchar('\n');
      first = 1;
    }
  }
}

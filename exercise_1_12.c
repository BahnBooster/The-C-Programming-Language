#include <stdio.h>

#define IN 1 //inside a word
#define OUT 0 //outside a word


void main()
{
	int c, state;

  state = OUT;


  while((c = getchar()) != EOF)
  {

    if (c != ' ' && c != '\n' && c != '\t')
      state = IN;
    else if (state == IN)
    {
      state = OUT;
    }

    if (state == IN)
      putchar(c);
    else
      putchar('\n');
  }
}

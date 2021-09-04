#include <stdio.h>
#define ESC '\\'
void main()
{
	double c;

  while ((c = getchar()) != EOF)
  {
    if (c == '\t' || c == '\b' || c == ESC )
    {
      //tab
      if (c == '\t')
        putchar('t');
      //backspace
      if (c == '\b')
        putchar('b');
      //putchar(BACKSLASH_ESC);
      if (c = ESC)
      {
        putchar(ESC);
        putchar(ESC);
      }
    } else
    {
      putchar(c);
    }
  }
}

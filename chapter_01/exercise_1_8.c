#include <stdio.h>

void main()
{
  double c, cb, ct, cn;

  cb = 0; //blanks
  ct = 0; //newlines
  cn = 0; //tabs


  /* Character Constant
   newline NL (LF) -> \n
   horizontal tab -> \t
   */

  while ((c = getchar()) != EOF)
  {
    //tabs
    if (c == '\t')
    {
      ct++;
    }
    //NL
    if (c == '\n')
    {
      cn++;
    }
    //blank
    if (c == ' ')
    {
       cb++;
    }
  }
  printf("\nYou have just written %.0f blanks, %.0f newlines, and %.0f tabs!\n", cb, cn, ct);
}

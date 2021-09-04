#include <stdio.h>

#define IN 1 //inside a word
#define OUT 0 //outside a word


//count lines, words, and characters in input
void main()
{
	int c, nl, nw, nc, state;

  state = OUT;
  nl = nw = nc = 0;

  //test---------
  printf("You can use multi-character characters to test the program: like ");
  int ua, ub;
  ua = 0303;
  ub = 0274;

  printf("%c%c and ",ua,ub);
  printf("%s\n", "\303\244");
  //-----------

  while((c = getchar()) != EOF)
  {
   if (c != ' ' && c != '\n' && c != '\t')
   nc++;
   if (c == '\n')
     nl++;
    if (c == ' ' || c == '\n' || c == '\t')
      state = OUT;
    else if (state == OUT)
    {
      state = IN;
      nw++;
    }
  }
  printf("%d %d %d\n", nl, nw, nc);
}

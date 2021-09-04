#include <stdio.h>

void main()
{
  printf("hello, world\c");
}

/*warning: unknown escape sequence: '\c'
   printf("hello, world\c");

/a.out
hello, worldc
*/

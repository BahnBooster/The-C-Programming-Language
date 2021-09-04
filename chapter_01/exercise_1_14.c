/**
 *
 *  program to print a histogram of the frequencies of different characters in its input
 *
 **/

#include<stdio.h>

#define MAXNO 128 /* Maximum No of characters (ASCII Table) */

void main()
{
  int c, maxfc, i, j;  
  int chars[MAXNO];
  
  maxfc = 0;  
  
  for (i = 0; i <= MAXNO; i++)
  {
    chars[i] = 0;
  }
  
  while ((c = getchar()) != EOF)
  {
    if (c != ' ' && c != '\n' && c != '\t')
    { 
      chars[c] = chars[c] + 1;
    }     
  }
  
  for (i = 0; i <= MAXNO; i++)
  {
    if (maxfc < chars[i])
    {
      maxfc = chars[i];
    }
  }
  
  for (i = maxfc; i >= 1; --i)
  {
    printf("%3d |", i);
    
    for (j = 0; j <= MAXNO; ++j)
    {
      if (chars[j] > 0)
      {
        if (i <= chars[j])
        {
          putchar('*');  
          putchar(' ');           
        }
        else
        {
          putchar(' ');  
          putchar(' ');              
        }
      } 
    }
    putchar('\n');
  }
  
  printf("----|");
  
  for (j = 0; j <= MAXNO; ++j)
  {
    if (chars[j] > 0)
    {
      printf("%c ", j);
    }
  }
  printf("\n");  
} 


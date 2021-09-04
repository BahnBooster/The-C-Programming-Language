#include <stdio.h>
#define MAXLINE 1000 /*maximum input line size*/

int getl(char s[], int lim);
void copy (char to[], char from[]);

/*print longest input line*/
int main(void)
{
  int len; //current line lenght
  int max; //maximum lenght seen so far
  char line[MAXLINE]; //current input line
  char longest[MAXLINE]; //longest line saved here

  max = 0;
  #ifdef DEBUG
  printf("before while in main: %d\n",len);
  #endif

  while ((len = getl(line, MAXLINE)) > 0 )
  {
     if (len > 80)
       printf("lenght:%d text: %s\n",len, line);

    if (len > max)
    {
      max = len;
      copy(longest, line);
    }
  }

  #ifdef DEBUG
  printf("after while in main %d\n", len);
  #endif

  if (max > 0) //there was a line
  {
    printf("max:%d line:%s\n" ,max, longest);
  }

  return 0;
}

/* getline: read a line into s, return lenght */
int getl(char s[], int lim)
{
  int c, i;

  for (i = 0; i < lim - 1 &&(c = getchar()) != EOF && c != '\n'; ++i)
  {
    s[i] = c;
  }

  if (c == '\n')
  {
    s[i] = c;
    i++;
  }
  s[i] = '\0';
  #ifdef DEBUG
  printf("getl:  %d\n", i);
  #endif
  return i;
}

/* copy: copy 'from' into 'to'´; assume to is big enough */
void copy(char to[], char from[])
{
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0')
    i++;
  #ifdef DEBUG
  printf("copy:  %d\n" , i);
  #endif
}

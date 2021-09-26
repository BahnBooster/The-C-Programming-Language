#include <stdio.h>
#define MAXLINE 1000

void getl(char s[]);
void reverse(char to[], char from[]);


int main(void)
{
  char line[MAXLINE];
  char linerev [MAXLINE];

  getl(line);
  reverse(linerev, line);
  printf("Reverse line:%s\n", linerev);

  return 0;
}

void getl(char s[])
{
  int c, i;
  for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF; i++)
  {
    s[i] = c;
  }
  //i++;
  s[i] = '\0';
}

void reverse (char to[], char from[])
{
  int t,f;
  t = 0;
  f = 0;

  while (from[f] != '\0')
    f++;

  while (f > 0)
  {

    to[t] = from[f-1];
    t++;
    f--;
  }
}

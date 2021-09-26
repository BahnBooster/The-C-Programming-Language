#include <stdio.h>

#define MAXLINE 1000 /*maximum input*/
#define TAB_TO_SPACE 8 /*number of blanks to space to the next tap stop*/

int get_line (char s[]);
int space_to_tab(char from[], char to[]);
int get_number_of_spaces_to_next_char(char s[], int start);

int main (void)
{
  char line[MAXLINE];
  char entab[MAXLINE];
  int in, out;

  in = 0;
  out = 0;

  in = get_line(line);
  out = space_to_tab(line, entab);

  printf("Number of chars IN: %d\n", in);
  printf("Number of chars OUT: %d\n\n", out);
  printf("Data IN :%s\n", line);
  printf("Data OUT:%s\n", entab);

  return 0;
}


int get_line (char s[])
{
  int c, i;

  for (i=0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; i++)
  {
    s[i] = c;
  }
  if (c == '\n')
  {
    s[i] = c;
    i++;
  }
  s[i] = '\0';
  return i;
}

int space_to_tab(char from[], char to[])
{
  int f, t, i, nc, tabs, spaces, before;

  f = 0;
  t = 0;
  tabs = 0;
  spaces = 0;
  before = 1;

  while (from[f] != '\0')
  {
    if (from[f] != ' ')
    {
      to[t] = from[f];
      t++;
      f++;
      if (to[t-1] == '\303')
        before = before - 1;
      before++;
    }
    else
    {
      nc = get_number_of_spaces_to_next_char(from, f);
      tabs = (nc - (nc % TAB_TO_SPACE)) / TAB_TO_SPACE;

      if (tabs > 0)
      {
         spaces = (nc % TAB_TO_SPACE) + (before % TAB_TO_SPACE);
      }
      else
      {
        spaces = nc;
      }

      for (i = 0; i < tabs; i++)
      {
        to[t] = '\t';
        before = 0;
        t++;

      }
      for (i = 0; i < spaces; i++)
      {
        to[t] = ' ';
        before++;
        t++;
      }
      f = f + nc;
      tabs = 0;
      spaces = 0;
    }
  }
  to[t] = from[f];
  return t;
}

int get_number_of_spaces_to_next_char(char s[], int start)
{
  int i;
  i = 0;
  while (s[start] == ' ')
  {
   i++;
   start++;
  }
  return i;
}

#include <stdio.h>

#define MAXLINE 1000 /*maximum input*/
#define TAB_FIX 5 /*fix tab stops for every n columns*/
#define TAB_TO_SPACE 8 /*number of blanks to space to the next tap stop*/

void get_line (char s[]);
void tab_to_space(char from[], char to[]);
int get_number_of_chars_to_previous_tab(char s[], int start);

int main (void)
{
  char line[MAXLINE];
  char detab[MAXLINE];

  get_line(line);
  tab_to_space(line, detab);

  printf("%s\n", detab);

  return 0;
}


void get_line (char s[])
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
}

void tab_to_space(char from[], char to[])
{
  int space, f, t, i, nc;

  f = 0;
  t = 0;

  while (from[f] != '\0')
  {
    if (from[f] != '\t')
    {
      to[t] = from[f];
      t++;
    }
    else
    {
      nc = get_number_of_chars_to_previous_tab(from, f) % TAB_TO_SPACE;
      for (i = 0; i < TAB_TO_SPACE - nc; i++)
      {
        #ifdef DEBUG
          to[t] = '-';
        #else
          to[t] = ' ';
        #endif
        t++;
      }
    }
    f++;
  }
  to[t] = from[f];
}

int get_number_of_chars_to_previous_tab(char s[], int start)
{
  int i;
  i = 0;
  start = start - 1;
  while (start >= 0)
  {
   if (s[start] == '\t')
     break;
   start = start - 1;
   i++;
  }
  return i;
}

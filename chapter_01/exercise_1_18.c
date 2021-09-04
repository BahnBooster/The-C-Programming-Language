#include <stdio.h>
#define MAX 1000 /*maximum input size*/

int getinput(char s[], int lim);
int cleanl (char to[], char from[]);

/*print clean output*/
int main(void)
{
  int in, out, i;
  char input[MAX]; //current input
  char output[MAX]; //clean output

  in = out = 0;

  if ((in = getinput(input, MAX)) > 0)
  {
    out = cleanl(output, input);

    printf("\n");
    printf("---------------------------------\n");
    printf("Raw intput: * -> blank | # -> tab\n");
    printf("---------------------------------\n");

    for (i = 0; i<= in; i++)
    {
      if (input[i] == ' ')
      {
        printf("*");
      }
      else if (input[i] == '\t')
      {
        printf("####");
      }
      else
      {
        printf("%c", input[i]);
      }
    }

    printf("---------------------------------\n");
    printf("Clean output:\n");
    printf("---------------------------------\n");

    for (i = 0; i<= out; i++)
    {
      if (output[i] == ' ')
      {
        printf("*");
      }
      else if (output[i] == '\t')
      {
        printf("####");
      }
      else
      {
        printf("%c", output[i]);
      }
    }
    printf("-------------------------\n");
  }
  else
  {
    printf("No input!\n");
  }

  return 0;
}

/* getinput: read input  into s, return lenght */
int getinput(char s[], int lim)
{
  int c, i;

  for (i = 0; i < lim - 1 &&(c = getchar()) != EOF; ++i)
  {
    s[i] = c;
  }

  i++;
  s[i] = '\0';

  return i;
}

/* cleanl: copy 'from' into 'to' and remove trailing blangs and tabs */
int cleanl(char to[], char from[])
{
  int i, j, k, nl, before, bc, del, cp, icp;
  char raw[MAX];
  int pos[MAX];

  /* explanation with example
  line(k):   |                   0                    |                   1                     |nl = 2
  ARRAY:     |---0---|---1---|---2---|---3---|---\n---|---5---|---6---|---7---|---\n---|---\0---|...
  pos[k]:    |                                 pos[0] |                         pos[1]          |
  before:    |   1x     2x      3x       4x   before=4|   1x      2x      3x    before=3        |
             |                                        |                                         |
  to delete  |   a       b      ' '     ' '     \n    |   c       d      ' '      \n       \0   |
  del value  |                       2                |                   1                     |
  cp(to copy)|       2                                |       2
  */

  i = j = k = nl = before = bc = del = cp = icp = 0;

  //copy raw output
  while ((raw[i] = from[i]) != '\0')
    i++;

  //counting newlines
  while (k <= i)
  {
    if (raw[k] == '\n')
    {
      //saving position of newline
      pos[nl] = k;
      nl++;
    }
    k++;
  }

  k = 0;
  //loop for each (new)line
  while (k < nl)
  {
    if (k > 0)
    {
      //caracters before line (not first one)
      before = pos[k] - pos[k-1];
      before = before -1;
      bc = 1;
      del = 0;
      //to delete (not to copy)
      while (bc <= before)
      {
        if (raw[pos[k]-bc] == ' ' || raw[pos[k]-bc] == '\t')
          del++;
      bc++;
      }
      //to copy (clean output)
      cp = before - del;
      icp = 1;
      while ((cp > 0) && (raw[pos[k-1] + icp] != '\n') && (raw[pos[k-1] + icp] != '\0'))
      {
        to[j] = raw[pos[k-1] + icp];
        icp++;
        j++;
        cp = cp - 1;
      }
      if (raw[pos[k-1] + icp + del] == '\n')
      {
        to[j] = '\n';
        j++;
      }
    }
    else
    {
      //caracters before line (first one)
      before = pos[k];
      bc = 1;
      del = 0;
      //to delete (not to copy)
      while (bc <= before)
      {
        if (raw[pos[k]-bc] == ' ' || raw[pos[k]-bc] == '\t')
          del++;
      bc++;
      }
      //to copy (clean output)
      cp = before - del;
      icp = 0;
      while ((cp > 0) && (raw[icp] != '\n') && (raw[icp] != '\0'))
      {
        to[j] = raw[icp];
        icp++;
        j++;
        cp = cp - 1;
      }
      if (raw[icp + del] == '\n')
      {
        to[j] = '\n';
        j++;
      }
    }
    k++;
  }

  to[j] = '\0';

  return j;
}

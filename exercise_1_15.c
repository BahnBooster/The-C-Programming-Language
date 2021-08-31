#include <stdio.h>

/*print Fahrenheit-Celsius table
   for fahr = 0, 20, ..., 300; floating-pint version */

float convert_to_C(float fahr);

int main()
{
  float fahr;
  int lower, upper, step;

  lower = 0; /* lower limit of temperatur table */
  upper = 300; /* upper limit */
  step = 20; /* step size */

  fahr = lower;

  printf("--------------------\n");
  printf("|Fahrenheit-Celsius|\n");
  printf("--------------------\n");
  printf("|%9s %9s|\n", "F", "C");
  printf("--------------------\n");

  while (fahr <= upper)
  {
    printf("|%9.0f %9.1f|\n", fahr, convert_to_C(fahr));
    fahr = fahr + step;
  }
  printf("--------------------\n");

  return 0;
}

float convert_to_C(float fahr)
{
  return ((fahr - 32.0) * 5/9);     
}

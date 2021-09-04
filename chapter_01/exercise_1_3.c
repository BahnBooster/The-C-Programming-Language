#include <stdio.h>

/*print Fahrenheit-Celsius table
   for fahr = 0, 20, ..., 300; floating-pint version */

void main()
{
  float fahr, celsius;
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

  while (fahr <= upper) {
    //celsius = (fahr - 32.0) * (5.0/9.0);
    celsius = (fahr - 32.0) * 5/9;
    printf("|%9.0f %9.1f|\n", fahr, celsius);
    fahr = fahr + step;
  }
  printf("--------------------\n");
}


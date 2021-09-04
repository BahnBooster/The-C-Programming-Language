#include <stdio.h>

/*print Celsius-Fahrenheit table
   for fahr = 0, 20, ..., 300; floating-point version */

void main()
{
  float fahr, celsius;
  int lower, upper, step;

  lower = 0; /* lower limit of temperatur table */
  upper = 300; /* upper limit */
  step = 20; /* step size */

  celsius = lower;

  printf("--------------------\n");
  printf("|Celsius-Fahrenheit|\n");
  printf("--------------------\n");
  printf("|%9s %9s|\n", "C", "F");
  printf("--------------------\n");

  while (celsius <= upper) {

    fahr = (celsius * (9.0/5.0)) + 32 ;
    printf("|%9.0f %9.1f|\n", celsius, fahr);
    celsius = celsius + step;
  }
  printf("--------------------\n");
}


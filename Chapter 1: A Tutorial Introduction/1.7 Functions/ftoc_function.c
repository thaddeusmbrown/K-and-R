#include <stdio.h>
#define LOWER 0     /* lower limit of table */
#define UPPER 300   /* upper limit */
#define STEP 20     /* step size */

/* Rewrite th temperature conversion program of Section 1.2 to use a
function for conversion */

/* Fahrenheit to Celsius converter*/
float ftoc(float fahr) {
  return (5.0/9.0) * (fahr-32.0);  
}

int main(int argc, char *argv[]) {
  float fahr, celsius;

  printf("degC  degF\n");
  fahr = LOWER;
  while (fahr <= UPPER) {
    celsius = ftoc(fahr);
    printf("%4.0f %6.1f\n", fahr, celsius);
    fahr = fahr + STEP;
  }
}

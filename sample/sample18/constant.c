// A demonstration of a preprocessor macro for a named constant.
// Nothing fancy.

#include <stdio.h>

// Define a macro, to replace PI with 3.1415926
#define PI 3.1415926

int main(void)
{
   double d;
   printf("Enter the diameter: ");
   scanf("%lf", &d);

   // Here, the identifier PI will get replaced
   double x = PI * d;

   printf("Circumference: %.2f\n", x);
   return 0;
}

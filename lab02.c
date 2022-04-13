#include <stdio.h>
#include <math.h>

int main()
{
  double x, y, z;
  printf("Введите x\n");
  scanf("%lf", &x);
  if (0.144 <= x && x <= 1.0)
  {
    y = sqrt(sin(2*x)) + sqrt(sin(3*x));
    z = pow(log(tan(y-M_PI/8)), 0.25);
    printf ("y(x) = %lf\nz(y) = %lf\n", y, z);
  }
  else
        printf("Введённый x неверен!\n");
  return 0;
}

#include <stdio.h>
#include <math.h>

int main()
{
  double x, y, z, temp1, temp2;
  printf("Введите x\n");
  scanf("%lf", &x);
  temp1 = sin(2*x);
  temp2 = sin(3*x);
  if (temp1 >= 0 && temp2 >= 0)
  {
    y = sqrt(sin(2*x)) + sqrt(sin(3*x));
    temp1 = tan(y-M_PI/8);
    if (temp1 > 0)
    {
      z = pow(log(tan(y-M_PI/8)), 0.25);
      printf("y(x) = %lf\nz(y) = %lf\n", y, z);
    }
      else
      printf("Введённый x неверен!\n");

    }
  else
  printf("Введённый x неверен!\n");
  return 0;
}

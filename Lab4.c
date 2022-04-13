#include <stdio.h>
#include <math.h>

double f(int n)
{
  double I = 0.0;
  double h = M_PI / n;
  for (double x = M_PI/2 / n; x <= M_PI; x += h)
  {
    double y;
    if (x <= M_PI / 2)
      y = pow(2, x) - 2 + pow(x, 2);
    else
      y = sqrt(x) * exp(-pow(x, 2));
    I += y;
  }
  I *= h;
  return I;
}

int main()
{
  double e;
  printf("Введите точность -> ");
  scanf("%lf", &e);

  int n = 1;
  double In = 0;
  double I2n = 1;

  while ((fabs(I2n - In) / 3) >= e)
  {
    n = n * 2;
    In = I2n;
    I2n = f(2 * n);
  }
  printf("%lf\n", I2n);

  return 0;
}

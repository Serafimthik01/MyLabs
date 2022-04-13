
#include <stdio.h>
#include <math.h>
int main()
{
  double h;
  printf ("Введите шаг аргумента");
  scanf ("%lf", &h);
  printf ("%-20sf(x)\n", "x");
  printf ("---------------------------\n");

  int count_h = (int)(2 / h);
  double y;

  int i = 0;
  while (i <= count_h)
  {
    double x = i * h;
    if (x <= 1.5)
      y = (pow(2, x)) - 2 + (pow(x, 2));
    else
      y = sqrt(x)*exp(-pow((x), 2));

    printf("%-20lf% lf\n", x, y);
    i++;
  }
  return 0;
}

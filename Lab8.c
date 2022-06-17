#include <ctype.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

int mygetch() {
  struct termios oldt, newt;
  int c;
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  c = getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  return c;
}

int is_functional() {
  int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);
  char c;
  int nofchars = 0;
  // read all pending func-key's codes not to handle them in main loop
  do {
    c = getchar();
    nofchars++;
  } while (c != EOF);

  fcntl(STDIN_FILENO, F_SETFL, flags);
  return nofchars != 1;
}

int main() {
  int k = 0, d = 0;
  char c = 0;
  while (1) {
    c = mygetch();
    if (c != 27) {
      // if(!is_functional())
      //     break;
      // continue;
      printf("%c", c);
      if (c == 46)
        d += 1;
      if (isalpha(c) || isspace(c)) {
        k += 1;
      }
    } else {
      if (k > 0 || d > 1)
        printf("\nЧисло не является верной записью вещественного числа\n");
      else
        printf("\nЧисло является верной записью вещественного чиcла\n");
      return 0;
    }
  }
}

#include <unistd.h>

void ft_write(char a) {
  write(1, & a, 1);
}

int main() {
  int test_x = 10;
  int test_y = 10;
  int initial_x = test_x;
  int initial_y = test_y;
  int start_line = 1;

  while (start_line <= initial_y) {
    if (start_line == 1 && test_x == initial_x) //first line, first column
    {
      ft_write('/');
      test_x--;
      if (test_x == 0) {
        ft_write('\n');
        test_x++;
        start_line++;
      }
    }

    while (start_line == 1 && test_x > 0) //first line input
    {
      if (test_x == 1) //last column of first line
      {
        ft_write('\\');
        ft_write('\n');
        start_line++;
        test_x = initial_x;
      } else {
        ft_write('*');
        test_x--;
      }
    }

    while (start_line < initial_y) {

      if (test_x == 1) //end of each row
      {
        ft_write('*');
        ft_write('\n');
        start_line++;
        test_x = initial_x;
      }
      if (test_x == initial_x && start_line != initial_y) //start of each row, but not the last row
      {
        ft_write('*');
        test_x--;
        if (test_x == 0) {
          ft_write('\n');
          start_line++;
          test_x = initial_x;
        }
      }

      if (test_x > 1 && start_line != initial_y) //middle of each row
      {
        ft_write(' ');
        test_x--;
      }

    }

    while (start_line == initial_y) //last line input
    {
      if (test_x == initial_x) //first  column of last line
      {
        ft_write('\\');
        test_x--;
      }
      if (test_x == 1) //last column, last line
      {
        ft_write('/');
        start_line++;
      } else {
        if (test_x == 0) {
          start_line++;
        } else {
          ft_write('*');
          test_x--;
        }
      }
    }

  }

}
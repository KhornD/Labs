#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void fill(int m, int n, int array[][n])
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            array[i][j] = rand() % 101 - 50;
}

void out(int m, int n, int arr[][n], int *i_max, int *i_min, int *max_row, int *min_row, int *j_max, int *j_min, int *max_col, int *min_col)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%10d", arr[i][j]);
        if (i == *i_max) printf(" max:%d", *max_row);
        if (i == *i_min) printf(" min:%d", *min_row);
        printf("\n");
    }
    for (int j = 0; j < n; j++)
    {
      if (j == *j_min) printf("   min:%d", *min_col);
      else if (j == *j_max) printf("   max:%d", *max_col);
      else {
        printf("%10c", ' ');
      }
    }
    printf("\n");
}

void findSumInRows(int m, int n, int array[][n], int *i_max, int *i_min, int *max_row, int *min_row)
{
  int sum = 0;
  for (int i = 0; i < m; i++)
  {
      sum = 0;
      for (int j = 0; j < n; j++)
          sum += array[i][j];
      if (sum > *max_row)
      {
          *max_row = sum;
          *i_max = i;
      }
      if (sum < *min_row)
      {
          *min_row = sum;
          *i_min = i;
      }
  }
}

void findSumInColumns(int m, int n, int array[][n], int *j_max, int *j_min, int *max_col, int *min_col)
{
  int sum = 0;
  for (int j = 0; j < n; j++)
  {
      sum = 0;
      for (int i = 0; i < m; i++)
          sum += array[i][j];
      if (sum > *max_col)
      {
          *max_col = sum;
          *j_max = j;
      }
      if (sum < *min_col)
      {
          *min_col = sum;
          *j_min = j;
      }
  }
}

int main() {
    srand(time(NULL));
    int n, m;
    int i_max = -1, i_min = -1, j_max = -1, j_min = -1;
    int max_col = -1E9, min_col = 1E9, max_row = -1E9, min_row = 1E9;
    printf("Введите количество строк: ");
    scanf("%d", &m);
    printf("Введите количество колонок: ");
    scanf("%d", &n);
    int array[m][n];
    fill(m, n, array);
    findSumInRows(m, n, array, &i_max, &i_min, &max_row, &min_row);
    findSumInColumns(m, n, array, &j_max, &j_min, &max_col, &min_col);
    out(m, n, array, &i_max, &i_min, &max_row, &min_row, &j_max, &j_min, &max_col, &min_col);
    return 0;
}

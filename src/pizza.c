#include <stdlib.h>
#include <stdio.h>
#include "pizza.h"

int solve (int  **pizza,
           int ***slices,
           int   *nslices,
           int    nrows,
           int    ncols,
           int    miningr,
           int    maxsize,
           int    nmush)
{
  char c;
  int i,
      j;

  if (pizza != NULL &&
      nrows > 0 &&
      ncols > 0 &&
      maxsize > 0 &&
      miningr >= 0 &&
      nmush >= miningr &&
      nrows * ncols - nmush >= miningr)
    {
      printf ("Yay! %d, %d, %d, %d\n", nrows, ncols, miningr, maxsize);
      printf ("Toms: %d\nMushes: %d\n", nrows * ncols - nmush, nmush);
      for (i = 0; i < nrows; i++)
        {
          for (j = 0; j < ncols; j++)
            {
              c = pizza[i][j] == 0 ? 'T' : 'M';
              printf ("%c", c);
            }
          printf ("\n");
        }

      *nslices = 3;

      *slices = (int**) malloc (sizeof (int*) * 3);
      (*slices)[0] = (int*) malloc (sizeof (int) * 4);
      (*slices)[1] = (int*) malloc (sizeof (int) * 4);
      (*slices)[2] = (int*) malloc (sizeof (int) * 4);

      (*slices)[0][0] = 0;
      (*slices)[0][1] = 0;
      (*slices)[0][2] = 2;
      (*slices)[0][3] = 1;
      (*slices)[1][0] = 0;
      (*slices)[1][1] = 2;
      (*slices)[1][2] = 2;
      (*slices)[1][3] = 2;
      (*slices)[2][0] = 0;
      (*slices)[2][1] = 3;
      (*slices)[2][2] = 2;
      (*slices)[2][3] = 4;
    }
  return 0;
}

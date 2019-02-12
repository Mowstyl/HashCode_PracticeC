#include <stdlib.h>
#include <stdio.h>
#include "pizza.h"

int** solve (int **pizza,
             int  *nslices,
             int  *returnsize,
             int   nrows,
             int   ncols,
             int   miningr,
             int   maxsize,
             int   nmush)
{
  int **slices,
      **used,
        i,
        j,
        ntoms,
        total;

  total = nrows * ncols;
  ntoms = total - nmush;
  if (pizza != NULL &&
      nrows > 0 &&
      ncols > 0 &&
      maxsize > 0 &&
      miningr >= 0 &&
      total > nmush &&
      total > ntoms &&
      nmush >= miningr &&
      ntoms >= miningr)
    {
      used = (int**) malloc (nrows * sizeof (int*));
      for (i = 0; i < nrows; i++)
        used[i] = (int*) calloc (ncols, sizeof (int));

      if (nmush < ntoms)
        *returnsize = nmush / miningr;
      else
        *returnsize = ntoms / miningr;

      slices = (int**) malloc (sizeof (int*) * (*returnsize));

      // TO-DO
      printf ("Yay! %d, %d, %d, %d\n", nrows, ncols, miningr, maxsize);
      printf ("Toms: %d\nMushes: %d\n", ntoms, nmush);

      for (i = 0; i < nrows; i++)
        {
          for (j = 0; j < ncols; j++)
            printf ("%c", pizza[i][j] == 0 ? 'T' : 'M');
          printf ("\n");
        }

      for (i = 0; i < nrows; i++)
        {
          for (j = 0; j < ncols; j++)
            used[i][j] = 1;
        }

      *nslices = 3;

      slices[0] = (int*) malloc (sizeof (int) * 4);
      slices[1] = (int*) malloc (sizeof (int) * 4);
      slices[2] = (int*) malloc (sizeof (int) * 4);

      slices[0][0] = 0;
      slices[0][1] = 0;
      slices[0][2] = 2;
      slices[0][3] = 1;
      slices[1][0] = 0;
      slices[1][1] = 2;
      slices[1][2] = 2;
      slices[1][3] = 2;
      slices[2][0] = 0;
      slices[2][1] = 3;
      slices[2][2] = 2;
      slices[2][3] = 4;

      // END TO-DO

      printf ("Score: %d\n", getScore (used, nrows, ncols));
      for (i = 0; i < nrows; i++)
        free (used[i]);
      free (used);
    }
  return slices;
}

int
getScore (int **usedCells,
          int   nrows,
          int   ncols)
{
  int i,
      j,
      score;

  score = 0;
  for (i = 0; i < nrows; i++)
    {
      for (j = 0; j < ncols; j++)
        score += usedCells[i][j];
    }

  return score;
}

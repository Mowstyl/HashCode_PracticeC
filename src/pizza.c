#include <stdlib.h>
#include <stdio.h>
#include "pizza.h"

int**
solve (int **pizza,
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

      // TO-DO

      slices = _splizza (pizza, nslices, returnsize, nrows, ncols, miningr, maxsize, nmush, ntoms);

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

int** // Devuelve el array de slices
_splizza (int **pizza, // Matriz pizza
          int  *nslices, // Numero de slices que se han hecho
          int  *returnsize, // Tamaño del array devuelto
          int   nrows,  //numero de filas
          int   ncols,  //numero de columnas
          int   miningr,  //numero minimo de cada ingrediente por slice
          int   maxsize,  //tamaño maximo de cada slice
          int   nmush,  //numero de champiñones
          int   ntoms)  //numero de tomeitoes
{
  int   maxmin, // El maximo numero de celdas con el ingrediente mas escaso que pueden haber en una porcion
      **slices,
        maxslices;

  maxslices = _upperBound (nmush, ntoms, miningr);


  slices = (int**) malloc (sizeof (int*) * (*returnsize));

  maxmin = nmush > ntoms ? 0 : 0;

  return slices;
}

int
_upperBound (int nmush,
             int ntoms,
             int miningr)
{
  int maxslices;

  if (nmush > ntoms)
    maxslices = ntoms / miningr;
  else
    maxslices = nmush / miningr;

  return maxslices
}

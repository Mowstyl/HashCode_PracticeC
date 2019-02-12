#define _POSIX_C_SOURCE 200809L
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <complex.h>
#include <time.h>
#include "files.h"
#include "pizza.h"

int main(int argc, char *argv[]) {
  char *input,
       *output;
  int i,
      j,
      k,
      code = 0;

  if (argc <= 1)
    {
      code = 1;
    }
  else if (argc == 2)
    {
      input = argv[1];

      i = 0;
      k = 0;
      while (argv[1][i] != '\0')
        {
          if (argv[1][i] == '.')
            k = i;
          i++;
        }
      if (k == 0)
        k = i;
      output = (char*) malloc (sizeof (char) * (k + 5));
      for (j = 0; j < k; j++)
        output[j] = argv[1][j];
      output[k] = '.';
      output[k + 1] = 'o';
      output[k + 2] = 'u';
      output[k + 3] = 't';
      output[k + 4] = '\0';
    }
  else
    {
      input = argv[1];
      output = argv[2];
    }

  int **pizza = NULL,
      **slices = NULL;
  int nrows,
      ncols,
      miningr,
      maxsize,
      nmush,
      nslices = 0,
      slicesize = 0;

  if (code == 0)
    pizza = readFile (input, &nrows, &ncols, &miningr, &maxsize, &nmush);

  if (pizza != NULL && code == 0)
    {
      int cronometer = time (NULL);
      slices = solve (pizza, &nslices, &slicesize, nrows, ncols, miningr, maxsize, nmush);
      cronometer = time (NULL) - cronometer;
      printf ("%d seconds!\n", cronometer);
    }

  if (pizza != NULL && slices != NULL && code == 0)
    code = saveFile (output, slices, nslices);

  switch (code)
    {
      case 1:
        printf ("No input file given!\n");
        break;
      case 2:
        printf ("Error parsing file!\n");
        break;
      case 3:
        printf ("Error writing results!\n");
        break;
    }

  if (pizza != NULL)
    {

      for (i = 0; i < nrows; i++)
        free (pizza[i]);

      free (pizza);
    }

  if (slices != NULL)
    {
      for (i = 0; i < slicesize; i++)
        free (slices[i]);

      free (slices);
    }

  free (output);

  return code;
}

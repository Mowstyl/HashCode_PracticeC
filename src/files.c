#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int
readFile (const char   *fileName,
          int        ***pizza,
          int          *rows,
          int          *cols,
          int          *min,
          int          *max,
          int          *nmush)
{
  FILE *fp;
  char  string[20],
       *token,
        c;
  int code = 1,
      i,
      j,
      lastline;

  printf ("Input file: %s\n", fileName);
  fp = fopen (fileName, "r");

  if (fp != NULL && fgets (string, 20, fp) != NULL)
    {
      token = strtok(string, " ");
      if (token != NULL)
        {
          *rows = atoi(token);
          token = strtok(NULL, " ");
          if (token != NULL)
            {
              *cols = atoi(token);
              token = strtok(NULL, " ");
              if (token != NULL)
                {
                  *min = atoi(token);
                  token = strtok(NULL, " ");
                  if (token != NULL)
                    {
                      *max = atoi(token);
                      if (*rows > 0 && *cols > 0 && *min > 0 && *max > 0)
                        code = 0;
                    }
                }
            }
        }
    }
  else
    {
      if (fp == NULL)
        printf ("File not found!\n");
      else
        printf ("Empty file!\n");
    }

  if (code == 0)
    {
      *pizza = (int**) malloc (sizeof (int*) * (*rows));
      *nmush = 0;
      for (i = 0; i < *rows; i++)
        {
          (*pizza)[i] = (int*) malloc (sizeof (int) * (*cols));
          lastline = i;
          for (j = 0; j < *cols; j++)
            {
              c = getc (fp);

              if (c == 'T')
                {
                  (*pizza)[i][j] = 0;
                }
              else if (c == 'M')
                {
                  (*pizza)[i][j] = 1;
                  *nmush = *nmush + 1;
                }
              else
                {
                  printf ("Unknown character in file!\n");
                  code = 2;
                  break;
                }
            }
          c = getc (fp);
          if (c == '\r')
            c = getc (fp);
          if (code != 0 || c != '\n')
            {
              if (code == 0)
                printf ("Expected new line!\n");
              code = 2;
              break;
            }
        }
    }

  if (code >= 2)
    {
      for (i = 0; i <= lastline; i++)
        free ((*pizza)[i]);
      free (*pizza);
      *pizza = NULL;
      code = 2;
      printf ("Cleaned pizza!\n");
    }

  fclose(fp);

  printf ("Read code %d\n", code);

  return code;
}

/*
* This function reads the specified file and returns the pizza and its size
*
* fileName -> The name of the file the results will be stored. Input.
* slices   -> A list of slices, containing the solution. Input.
*/
int
saveFile (const char  *fileName,
          int        **slices,
          int          nslices)
{
  int i;
  FILE *fp;

  printf ("Output file: %s\n", fileName);
  fp = fopen (fileName, "w");
  fprintf (fp, "%d\n", nslices);

  if (slices != NULL)
    {
      for (i = 0; i < nslices; i++)
        {
          fprintf (fp, "%d %d %d %d\n", slices[i][0], slices[i][1], slices[i][2], slices[i][3]);
        }
    }

  fclose (fp);

  return 0;
}

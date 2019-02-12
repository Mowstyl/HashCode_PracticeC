#ifndef __PIZZA_H
#define __PIZZA_H

int** solve    (int **pizza,
                int  *nslices,
                int  *returnsize,
                int   nrows,
                int   ncols,
                int   miningr,
                int   maxsize,
                int   nmush);

int   getScore (int **usedCells,
                int   nrows,
                int   ncols);

#endif

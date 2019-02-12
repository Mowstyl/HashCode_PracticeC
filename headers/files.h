#ifndef __FILES_H
#define __FILES_H

/*
 * This function reads the specified file and returns the pizza and its size
 *
 * fileName -> The name of the file. Input.
 * rows     -> A pointer to the number of rows. Output.
 * cols     -> A pointer to the number of columns. Output.
 *
 * returns  -> A matrix of ints representing the pizza. Output.
 *             0 means Tomato, 1 means Mushroom.
 */
int** readFile (const char   *fileName,
                int          *rows,
                int          *cols,
                int          *min,
                int          *max,
                int          *nmush);

/*
 * This function reads the specified file and returns the pizza and its size
 *
 * fileName -> The name of the file the results will be stored. Input.
 * slices   -> A list of slices, containing the solution. Input.
 */
int   saveFile (const char  *fileName,
                int        **slices,
                int          nslices);

#endif

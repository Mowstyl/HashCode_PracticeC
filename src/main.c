#define _POSIX_C_SOURCE 200809L
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <complex.h>
#include <time.h>
#include "precision.h"
#include "funmatrix.h"
#include "qgates.h"
#include "qregistry.h"

#if UINTPTR_MAX == 0xffffffff
#define ARC 86
#elif UINTPTR_MAX == 0xffffffffffffffff
#define ARC 64
#else
#define ARC 0
#endif

int main(int argc, char *argv[]) {
  QRegistry *r;
  int *result,
      *qlist,
       bal,
       nqubits,
       i;
  unsigned long ti,
                tf;

  if (argc == 0) {
    srand(time(0));
  }
  else {
    srand(atoi(argv[0]));
  }

  if (ARC == 86) {
    printf("Running with x%d architecture. Consider upgrading to x64.\n", ARC);
  }
  else if (ARC == 64) {
    printf("Running with x%d architecture. Noice!\n", ARC);
  }
  else {
    printf("Running with unknown architecture! We hope this doesn't explode...\n");
  }

  nqubits = 14;

  qlist = (int*) malloc (sizeof (int) * (nqubits - 1));
  result = (int*) malloc (sizeof (int) * (nqubits - 1));

  for (i = 0; i < nqubits - 1; i++)
    {
      *(qlist + i) = i;
    }

  ti = (unsigned long)time(NULL);

  r = new_QRegistry(nqubits);

  if (applyGate (r, kron (Identity (nqubits - 1), X ())))
    {
      printf ("Applied X gate to last QuBit!\n");
      if (applyGate (r, H (nqubits)))
        {
          printf ("Applied Hadamard to all Qubits!\n");
          if (applyGate (r, kron (H (nqubits - 1), Identity (1))))
            {
              printf ("Finished D-J Algorithm!\n");

              if (measure (r, qlist, nqubits - 1, result))
                {
                  bal = 0;
                  for (i = 0; i < nqubits - 1; i++)
                    {
                      bal = bal || *(result + i);
                    }

                  tf = (unsigned long)time(NULL);
                  printf ("Finished in %lu s\n", tf - ti);
                  if (bal)
                    printf ("Balanced!\n");
                  else
                    printf ("Constant!\n");
                }
            }
        }
    }

  free (r);

  return 0;
}

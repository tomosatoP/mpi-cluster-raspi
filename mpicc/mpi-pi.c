/*
  MPI pi code.

  This numerical intergration calculates
  pi using MPI. It converges very slowly,
  requiring 5 milllion iteration for
  48 decima place accuracy.

  Author; Carlos R. Morrison

  Date: 1/14/2017
*/

#include <stdio.h>
#include <math.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int total_iter;
    int n, rank, length, numprocs, i;
    double mypi, pi, width, sum, x, rank_integral;
    char hostname[MPI_MAX_PROCESSOR_NAME];

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Get_processor_name(hostname, &length);

    if (rank == 0)
    {
        printf("\n");
        printf("############################");
        printf("\n\n");
        printf("Master node name: %s\n", hostname);
        printf("\n");
        printf("Enter number of segments:\n");
        printf("\n");
        scanf("%d", &n);
        printf("\n");
    }

    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);

    for (total_iter = 1; total_iter < n; total_iter++)
    {
        sum = 0.0;
        width = 1.0 / (double)total_iter;

        for (i = rank + 1; i <= total_iter; i += numprocs)
        {
            x = width * ((double)i - 0.5);
            sum += 4.0 / (1.0 + x * x);
        }

        rank_integral = width * sum;

        MPI_Reduce(&rank_integral, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    }

    if (rank == 0)
    {
        printf("\n\n");
        printf("*** Number of processes: %d\n", numprocs);
        printf("\n\n");
        printf("     Calculated pi = %.50f\n", pi);
        printf("              M_PI = %.50f\n", M_PI);
        printf("    Relative Error = %.50f\n", fabs(pi - M_PI));
        printf("\n");
    }

    MPI_Finalize();
    return 0;
}

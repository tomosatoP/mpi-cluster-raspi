#!/usr/bin/python3

from mpi4py import MPI
import math, timeit


def f(x):
    return 4.0 / (1 + x**2)


def Rsum(a, b, n, start=0, step=1):
    area = 0.0
    for i in range(start, n, step):
        area = area + (b - a) / n * f(a + (b - a) / n * (i + 1))
    return area


"""
def compute_pi(n, start=0, step=1):
    h=1.0/n
    s=0.0
    for i in range(start, n, step):
        x=h*(i+0.5)
        s+=4.0/(1.0+x**2)
    return s*h
"""
comm = MPI.COMM_WORLD
nprocs = comm.Get_size()
myrank = comm.Get_rank()

if myrank == 0:
    n = 1000000
    start_time = timeit.default_timer()
else:
    n = None

n = comm.bcast(n, root=0)
# mypi=compute_pi(n,myrank,nprocs)
mypi = Rsum(0.0, 1.0, n, myrank, nprocs)
pi = comm.reduce(mypi, op=MPI.SUM, root=0)

if myrank == 0:
    rel_error = pi - math.pi
    abs_error = abs(rel_error)
    print("pi   = " + str(math.pi))
    print("area = " + str(pi))
    print("relative error = " + str(rel_error))
    end_time = timeit.default_timer()
    print("start time = " + str(start_time))
    print("end time   = " + str(end_time))
    print("cpu time   = " + str(end_time - start_time) + " seconds")

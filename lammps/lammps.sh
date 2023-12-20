#!/bin/bash

#SBATCH -p debug
#SBATCH -N 3
#SBATCH -n 12
#SBATCH -c 1
#SBATCH -J LAMMPS
#SBATCH -o stdout_%J.txt
#SBATCH -e stderr_%J.txt

export OMP_NUM_THREADS=1
# valid values: hash, ds12, ds21
export PMIX_MCA_gds=hash
# valid values: cma, emulated, none
export OMPI_MCA_btl_vader_single_copy_mechanism=none

sbcast -pf ~/sif/lammps.sif lammps.sif
sbcast -pf ~/data/in.melt in.melt
srun apptainer exec lammps.sif lmp -in in.melt
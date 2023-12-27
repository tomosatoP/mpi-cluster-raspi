# mpicc

[mpi-pi.c](mpi-pi.c)<br>
[call-proc.c](call-procs.c)<br>
[mpicc.def](mpicc.def)

## 使い方
SIF 作成
~~~sh
cp hpc/mpicc/* /mpi/mpicc
cd /mpi/mpicc

apptainer build mpicc.sif mpicc.def
~~~
SIF 確認
~~~sh
cd /mpi/mpicc

apptainer run mpicc.sif
~~~
slurm
~~~sh
cd /mpi/mpicc

sbatch mpi-cc.sh
sbatch call-procs.sh
~~~

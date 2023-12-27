# mpicc

[円周率計算用 C ソース mpi-pi.c](mpi-pi.c)<br>
[円周率計算 mpi-pi.sh](mpi-pi.sh)<br>
[ノード表示用 C ソース call-procs.c](call-procs.c)<br>
[ノード表示 call-procs.sh](call-procs.sh)<br>
[Apptainer 用定義ファイル mpicc.def](mpicc.def)

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

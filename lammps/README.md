# LAMMPS

[Apptainer 用定義ファイル lammps.def](lammps.def)<br>
[Slurm 用シェルスクリプト lammps.sh](lammps.sh)<br>
[入力ファイル in.melt](in.melt)<br>

## 使い方
SIF 作成
~~~sh
cp hpc/lammps/* /mpi/lammps
cd /mpi/lammps

apptainer build lammps.sif lammps.def
~~~
SIF 確認
~~~sh
cd /mpi/lammps

apptainer run lammps.sif
~~~
Slurm
~~~sh
cd /mpi/lammps

sbatch lammps.sh
~~~
---

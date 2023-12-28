# mpi4py

[Apptainer 用定義ファイル mpi4py.def](mpi4py.def)<br>
[テスト1 mpi-test1.sh](mpi-test1.sh)<br>
[テスト1 用 python ソース mpi-test1.py](mpi-test1.py)<br>
[テスト2 mpi-test2.sh](mpi-test2.sh)<br>
[テスト2 用 python ソース mpi-test2.py](mpi-test2.py)<br>

## 使い方
SIF 作成
~~~sh
cp -r hpc/mpi4py /mpi/mpi4py
cd /mpi/mpi4py

apptainer build mpi4py.sif mpi4py.def
~~~
SIF 確認
~~~sh
cd /mpi/mpi4py

apptainer run mpi4py.sif
~~~
slurm
~~~sh
cd /mpi/mpi4py

sbatch mpi-test1.sh
sbatch mpi-test2.sh
~~~
> 事前に、各計算ノードの状態が `idle` であることを確認
---
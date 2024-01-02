# Slurm workload manager [version: 22.05.8]
## [概観](https://slurm.schedmd.com/archive/slurm-22.05.8/overview.html)
## [コマンド](https://slurm.schedmd.com/archive/slurm-22.05.8/man_index.html)
### [scontrol](https://slurm.schedmd.com/archive/slurm-22.05.8/scontrol.html)
~~~sh
# "down" から復帰
scontrol update nodename=mpi[0-2] state=idle
~~~
~~~sh
# "configless" モードで、 
# "slurm.conf", "cgroup.conf" などの変更を計算ノード群へ反映
scontrol reconfigure
~~~
### [squeue](https://slurm.schedmd.com/archive/slurm-22.05.8/squeue.html)
### [sinfo](https://slurm.schedmd.com/archive/slurm-22.05.8/sinfo.html)
### [sbatch](https://slurm.schedmd.com/archive/slurm-22.05.8/sbatch.html)
### [sbcast](https://slurm.schedmd.com/archive/slurm-22.05.8/sbcast.html)
### [scancel](https://slurm.schedmd.com/archive/slurm-22.05.8/scancel.html)
### [srun](https://slurm.schedmd.com/archive/slurm-22.05.8/srun.html)

---
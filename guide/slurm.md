# Slurm workload manager [version: 22.05.8]

## [概観](https://slurm.schedmd.com/archive/slurm-22.05.8/overview.html)

## [設定ファイル](https://slurm.schedmd.com/archive/slurm-22.05.8/overview.html)

### [slurm.conf](https://slurm.schedmd.com/archive/slurm-22.05.8/slurm.conf.html)

### [cgroup.conf](https://slurm.schedmd.com/archive/slurm-22.05.8/cgroup.conf.html)

### [mpi.conf](https://slurm.schedmd.com/archive/slurm-22.05.8/mpi.conf.html)

### [slurmdbd.conf](https://slurm.schedmd.com/archive/slurm-22.05.8/slurmdbd.conf.html)

## [クライアント コマンド](https://slurm.schedmd.com/archive/slurm-22.05.8/man_index.html)

### [scontrol](https://slurm.schedmd.com/archive/slurm-22.05.8/scontrol.html)

~~~sh
# 設定値[slurm.conf, cgroup.conf, mpi.conf]の確認
scontrol show config
~~~

~~~sh
# "down" から復帰
scontrol update nodename=mpi[0-2] state=idle
~~~

~~~sh
# "configless" モードで、 
# "slurm.conf", "cgroup.conf", "mpi.conf" の変更を計算ノード群へ反映
scontrol reconfigure
~~~

### [sacct](https://slurm.schedmd.com/archive/slurm-22.05.8/sacct.html)

~~~sh
# n 番目のジョブの情報を表示
sacct -j n
~~~

### [sacctmgr](https://slurm.schedmd.com/archive/slurm-22.05.8/sacctmgr.html)

~~~sh
# 設定値[slurm.conf, slurmdbd.conf]の確認
sacctmgr show config
~~~

~~~sh
# "configless" モードで、 
# "slurmdbd.conf" の変更を計算ノード群へ反映
sacctmgr reconfigure
~~~

### [squeue](https://slurm.schedmd.com/archive/slurm-22.05.8/squeue.html)

### [sinfo](https://slurm.schedmd.com/archive/slurm-22.05.8/sinfo.html)

### [sbatch](https://slurm.schedmd.com/archive/slurm-22.05.8/sbatch.html)

### [sbcast](https://slurm.schedmd.com/archive/slurm-22.05.8/sbcast.html)

### [scancel](https://slurm.schedmd.com/archive/slurm-22.05.8/scancel.html)

### [srun](https://slurm.schedmd.com/archive/slurm-22.05.8/srun.html)

---
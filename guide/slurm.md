# Slurm workload manager
https://slurm.schedmd.com/overview.html
## コマンド
https://slurm.schedmd.com/man_index.html
### scontrol
https://slurm.schedmd.com/scontrol.html
~~~sh
# "down" から復帰
scontrol update nodename=mpi[0-2] state=idle
~~~
~~~sh
# "configless" モードで、 
# "slurm.conf", "cgroup.conf" などの変更を計算ノード群へ反映
scontrol reconfigure
~~~
### squeue
https://slurm.schedmd.com/squeue.html
### sinfo
https://slurm.schedmd.com/sinfo.html
### sbatch
https://slurm.schedmd.com/sbatch.html
### sbcast
https://slurm.schedmd.com/sbcast.html
### scancel
https://slurm.schedmd.com/scancel.html
### srun
https://slurm.schedmd.com/srun.html

## REST API
https://slurm.schedmd.com/rest.html

---

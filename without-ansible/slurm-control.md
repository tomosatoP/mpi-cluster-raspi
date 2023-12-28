# Slurm - 制御ノード
`mpi0`
> 計算ノードを兼ねる<br>
> Configless slurm を導入 https://slurm.schedmd.com/configless_slurm.html

https://slurm.schedmd.com/

* `Slurm packages` をインストール
* slurm.conf, cgroup.conf を作成
* slurmd.service を編集

## `Slurm packages` をインストール
~~~sh
sudo apt install slurm-wlm
# 確認
sudo slurmctld -V

# 所有者変更 (slurm -> mpi)
sudo chown mpi:mpi -R /var/log/slurm
sudo chown mpi:mpi -R /var/lib/slurm
~~~
## slurm.conf, cgroup.conf を作成
~~~sh
# 初期設定の slurm.conf は、下記で作成
start /usr/share/doc/slurmctld/slurm-wlm-configrator.html
~~~
[/etc/slurm/slurm.conf](conf/slurm.conf)
|項目|default|設定値
|---|---|---|
|SlurmctldHost=|linux0|mpi0|
|NodeName=|linux[1-32] CPUs=1 State=UNKNOWN|mpi[0-2] CPUs=4 State=UNKNOWN|
|SlurmUser=|slurm|mpi|
||||
|MpiDefault=|none|pmix|
||||
|TaskPlugin=|task/affinity|task/cgroup,task/affinity|
|ProctrackType=|proctrack/cgroup|proctrack/cgroup|
|JobAcctGatherType=|jobacct_gather/none|jobacct_gather/cgroup|
|PrologFlags=|(comment out)|Contain|
||||
|SlurmctldParameters=||enable_configless|
> `CPUs=` の値は、`slurmd -C` コマンドの出力を転記

[/etc/slurm/cgroup.conf](conf/cgroup.conf)
|項目|default|設定値
|---|---|---|
|CgroupPlugin=|autodetect|autodetect|
|ConstrainCores=|no|yes|
|ConstrainDevices=|no|yes|
|ConstrainRAMSpace=|no|no|
|ConstrainSwapSpace=|no|no|

## slurmd.service を編集
~~~sh
sudo nano /lib/systemd/system/slurmd.service
~~~
~~~diff
- ConditionPathExists=/etc/slurm/slurm.conf
+ #ConditionPathExists=/etc/slurm/slurm.conf
- ExecStart=/usr/sbin/slurmd -D -s $SLURMD_OPTIONS
+ ExecStart=/usr/sbin/slurmd --conf-server mpi0 -D -s $SLURMD_OPTIONS
~~~
~~~sh
sudo systemctl daemon-reload
sudo systemctl restart slurmctld
sudo systemctl restart slurmd
scontrol reconfigure
~~~
確認
~~~sh
sudo systemctl status munge | grep Activate
sudo systemctl status slurmctld | grep Activate
sudo systemctl status slurmd | grep Activate
~~~

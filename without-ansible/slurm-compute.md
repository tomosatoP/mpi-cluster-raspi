# Slurm - 計算ノード
`mpi1, mpi2`

> Configless slurm を導入 https://slurm.schedmd.com/configless_slurm.html

https://slurm.schedmd.com/

* `Slurm packages` をインストール
* slurmd.service を編集
* 確認

## `Slurm packages` をインストール
~~~sh
sudo apt install slurmd

# 所有者変更 (slurm -> mpi)
sudo chown mpi:mpi -R /var/log/slurm
sudo chown mpi:mpi -R /var/lib/slurm
~~~
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
sudo systemctl restart slurmd
~~~
確認
~~~sh
sudo systemctl status munge | grep Activate
sudo systemctl status slurmd | grep Activate
~~~

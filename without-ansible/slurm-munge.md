# Slurm -  MUNGE 認証サービス
`pi0, pi1, pi2 共通`

https://slurm.schedmd.com/

* MUNGE 認証サービス 導入
* 認証鍵の配布
## MUNGE 認証サービス 導入
~~~sh
sudo apt install munge
# 確認
sudo systemctl status munge | grep Active
~~~
## 認証鍵の配布
pi0 の 認証鍵 `/etc/munge/munge.key` を　pi1, pi2 に配布
~~~sh
# pi0 にて
sudo rsync -a /etc/munge/munge.key ~
sudo chown mpi:mpi munge.key
sudo rsync -a munge.key mpi@pi1:~
sudo rsync -a munge.key mpi@pi2:~
sudo rm munge.key
~~~
~~~sh
# pi1, pi2 にて
sudo rsync -a munge.key /etc/munge
sudo chown munge:munge /etc/munge/munge.key
sudo rm munge.key
~~~
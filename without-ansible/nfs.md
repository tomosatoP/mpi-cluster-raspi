# NFS 共有フォルダ 作成
共有フォルダ `/mpi` を作成

* NFS サーバーを立てる
* 共有フォルダの利用

## NFS サーバーを立てる
`mpi0`

~~~sh
sudo apt update
sudo apt install -y nfs-kernel-server

sudo mkdir /mpi
sudo chown mpi:mpi /mpi
sudo chmod 0777 /mpi
sudo nano /etc/exports
~~~
~~~diff
+ /mpi 192.168.68.0/24(rw,sync,no_subtree_check)
~~~
~~~sh
sudo exportfs -a
~~~
~~~sh
sudo systemctl daemon-reload
sudo systemctl restart nfs-server.service
~~~

共有フォルダに `OpenMPI` 用の `host` ファイルを作成
~~~sh
cd /mpi
nano host
~~~
~~~diff
+ mpi0 slots=4
+ mpi1 slots=4
+ mpi2 slots=4
~~~
## 共有フォルダをマウント
`mpi1, mpi2`

共有フォルダのマウント先を作成
~~~sh
sudo apt update
sudo apt intall -y nfs-common

sudo mkdir /mpi
sudo chown mpi:mpi /mpi
sudo chmod 0777 /mpi
~~~
共有フォルダへの自動マウント設定
~~~sh
sudo nano /etc/systemd/system/mpi.mount
~~~
~~~diff
+ [Unit]
+ Description=mount mpi
+ 
+ [Mount]
+ What=mpi0:/mpi
+ Where=/mpi
+ Type=nfs
~~~
~~~sh
sudo nano /etc/systemd/system/mpi.automount
~~~
~~~diff
+ [Unit]
+ Description=automount mpi
+ 
+ [Automount]
+ Where=/mpi
+ 
+ [Install]
+ WantedBy=multi-user.target
~~~
~~~sh
sudo systemctl daemon-reload
sudo systemctl enable mpi.automount
sudo systemctl restart mpi.automount
~~~
---

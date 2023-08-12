# Ansible で lammps 用 ラズパイ mpi クラスタ環境を構築

構成管理ツール `Ansible` とは？<br>
SSH接続を介して、システムの構成、ソフトウェアの展開、継続的な展開やダウンタイムなしのローリング更新など行う。

- [Ansible実践ガイド 第4版［基礎編］](https://book.impress.co.jp/books/1122101189)
- [Ansibleクックブック](https://book.impress.co.jp/books/1120101163)
- https://docs.ansible.com/ansible/latest/index.html

> この主題に対しては、牛刀な感じですけどね。

## Todo
- ansible 自体を docker コンテナ化
  - もしくは、 `git clone & pip install -e .` で簡略化する。
- mpi クラスタ環境を docker コンテナ化 & docker swarm / Apptainer(Singularity) で運用


## 構成
### ハードウェア
- Raspberry Pi 4B 8GB x 3
- microSD Card 64GB x 3
- [PoE HAT](https://www.waveshare.com/poe-hat-e.htm) x 3
- [PoE HUB](https://www.iodata.jp/lib/product/e/6368.htm)
- [イーサネットケーブル](https://www.edion.com/detail.html?p_cd=00043376414) x 3
### ソフトウェア
- Raspberry Pi OS 64bit Lite
- ansible, OpenMPI, mpi4py, lammps, ...

## Raspberry Pi Imager で OS を microSD Card に書き込み
- ☒ ホスト名 \<hostname>
- ☒ SSHを有効化する - パスワード認証を使う
- ☒ ユーザー名とパスワードを設定する
  - ユーザー名 \<username>
  - パスワード \<password>
- ☐ WiFiを設定する
- ☒ ロケール設定をする
  - タイムゾーン Asia/Tokyo
  - キーボードレイアウト JP

|MPI Rank|username|hostname|ip address<br>(後で設定)|ansible|
|---|---|---|---|---|
|0|mpi|host0|xxx.xxx.xxx.150|制御ノード|
|1|mpi|host1|xxx.xxx.xxx.151|管理対象ノード|
|2|mpi|host2|xxx.xxx.xxx.152|管理対象ノード|

> MPI 実行時に全ホストで同じユーザー名が必要になるので、最初から同じにしておく（別にユーザーを追加するのが正しいやり方だけど）<br>
> ansible での記述が楽になるので、hostname, ip address を連番にしておく。

## 制御ノード (host0) に `Ansible` を導入

### 仮想環境 (venv) にインストール
~~~sh
mpi@host0:~ $ sudo apt update
mpi@host0:~ $ sudo apt install python3-pip python3-venv sshpass
mpi@host0:~ $ sudo -H python3 -m pip install -U pip setuptools wheel build

mpi@host0:~ $ git clone https://github.com/tomosatoP/mpi-cluster_raspberrypi.git mcr
mpi@host0:~/mcr/ansible $ python3 -m venv venv --upgrade-deps
mpi@host0:~/mcr/ansible $ . venv/bin/activate

(venv) mpi@host0:~/mcr/ansible $ pip install -U ansible paramiko
(venv) mpi@host0:~/mcr/ansible $ ansible --version
~~~
> `paramiko` は、SSH公開鍵認証で必須

### Ansible 設定ファイルを作成
~~~sh
(venv) mpi@host0:~/mcr/ansible $ ansible-config init --disabled -t all > ansible.cfg
(venv) mpi@host0:~/mcr/ansible $ sed -i.disabled -f ansible.cfg.scritp ansible.cfg
~~~

### インベントリーの修正と確認
ファイル [inventory.yaml](ansible/inventory.yaml) を適宜に修正してから、以下を実行。
~~~sh
(venv) mpi@host0:~/mcr/ansible $ ansible-inventory --list # output: ノードのリスト
(venv) mpi@host0:~/mcr/ansible $ ansible all -m ping -k   # input: ssh password, output: pingモジュールの結果
~~~

### adhoc test (再起動、シャットダウン)
~~~sh
(venv) mpi@host0:~/mcr/ansible $ ansible all -a "/usr/sbin/reboot" -b
(venv) mpi@host0:~/mcr/ansible $ ansible all -a "/usr/sbin/shutdown now" -b
~~~

## `Ansible` で環境構築

~~~sh
(venv) mpi@host0:~/mcr/ansible $ ansible-playbook ssh.yaml
(venv) mpi@host0:~/mcr/ansible $ ansible-playbook package.yaml
(venv) mpi@host0:~/mcr/ansible $ ansible-playbook locale.yaml
(venv) mpi@host0:~/mcr/ansible $ ansible-playbook bluetooth.yaml
(venv) mpi@host0:~/mcr/ansible $ ansible-playbook swap.yaml
...
~~~

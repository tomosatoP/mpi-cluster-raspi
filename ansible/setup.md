# Ansible による HPC クラスタ構築
狙い：Ansible を使って ラズパイ HPC クラスタ [Slurm, Apptainer, OpenMPI] を構築を自動化<br>
Ansible とは: [Ansible Documentation](https://docs.ansible.com/ansible/latest/index.html)

* Ansible 導入
* Ansible の利用

## Ansible 導入
`mpi0`
### Python 仮想環境 (venv) を作成
~~~sh
sudo apt update
sudo apt install git python3-pip python3-venv sshpass

git clone --depth 1 -b release https://github.com/tomosatoP/mpi-cluster-raspi.git hpc

python3 -m venv hpc/ansible/venv --upgrade-deps
~~~
使い方
~~~sh
# Python 仮想環境 (venv) を開始
cd hpc/ansible/
. venv/bin/activate

# Python 仮想環境 (venv) を終了
deactivate
~~~
### Python 仮想環境 (venv) に `Ansible` と関連パッケージをインストール
~~~sh
# Python 仮想環境 (venv) を開始
cd hpc/ansible/
. venv/bin/activate

pip install -U pip ansible paramiko

# 確認
ansible --version

# Python 仮想環境 (venv) を終了
deactivate
~~~
### Ansible 設定ファイルを作成
`ansible.cfg.script`
~~~sh
# Python 仮想環境 (venv) を開始
cd hpc/ansible/
. venv/bin/activate

ansible-config init --disabled -t all > ansible.cfg
sed -i.disabled -f ansible.cfg.script ansible.cfg
~~~
### Ansible インベントリーファイルを作成
実際のクラスタ構成に合わせて、ファイル構成を修正する
~~~
hpc/ansible/─┬─inventory.yaml       # グループとホストの構成を記載
     │       └─inventory.avahi.yaml # SSH 認証鍵共有時、一時的に使用
     ├─group_vars/─┬─all.yaml       # 共通のインベントリ変数を記載
     │             ├─control.yaml   # control グループのインベントリ変数を記載
     │             └─managed.yaml   # managed グループのインベントリ変数を記載
     └─host_vars/──┬─mpi0.yaml      # mpi0 のインベントリ変数を記載
                   ├─mpi1.yaml      # mpi1 のインベントリ変数を記載
                   └─mpi2.yaml      # mpi2 のインベントリ変数を記載
~~~
確認
~~~sh
# Python 仮想環境 (venv) を開始
cd hpc/ansible/
. venv/bin/activate

ansible-inventory --list
 > ノードのリスト

ansible -i inventory.avahi.yaml all -m ping -k
 > SSH password: [SSH 接続のパスワードを入力]
 > pingモジュールの結果
~~~
> ssh 認証鍵の配布後は、ssh 接続にパスワード不要。
## Ansible の利用
### adhoc(コマンドの呼び出し) の場合
~~~sh
# Python 仮想環境 (venv) を開始
cd hpc/ansible/
. venv/bin/activate

# managed グループの再起動 
ansible -i inventory.avahi.yaml managed -a "/usr/sbin/reboot" -b
# managed グループのシャットダウン
ansible -i inventory.avahi.yaml managed -a "/usr/sbin/shutdown now" -b
~~~
### module を使った場合
~~~sh
# Python 仮想環境 (venv) を開始
cd hpc/ansible/
. venv/bin/activate

# managed グループの再起動 
ansible -i inventory.avahi.yaml managed -m ansible.builtin.reboot -b
# managed グループのシャットダウン
ansible -i inventory.avahi.yaml managed -m community.general.shutdown -b
~~~
---

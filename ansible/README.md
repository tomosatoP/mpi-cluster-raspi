# マルチノード並列処理の環境構築 - ansible 編
ansible-playbook コマンドで自動構築

前提：`ansible 用の Python 仮想環境` を使う為、 [Ansible 環境](setup.md) を構築済み

以下はすべて、`ansible 用の Python 仮想環境 (venv)` で行う
---
## SSH 認証鍵
ansible では SSH 接続が必要なことがある為、認証を自動化
> 後でインストールする `slurm` では、`munge` が代わって認証を行う
~~~sh
# この時点では認証にパスワードを使用
ansible-playbook site.yaml -i inventory.avahi.yaml --tags ssh -k

ansible-playbook site.yaml --tags ssh
~~~
|ノード|内容|補足|
|---|---|---|
|mpi0|認証鍵ペア作成|-|
|mpi1, mpi2|mpi0 の SSH 公開認証鍵を登録|-|
|mpi0|SSH 設定ファイルに mpi1, mpi2 の設定値を追加|~/.ssh/config|

## 固定IPアドレス、 DNS サービス
クラスタを構成する為、クラスタ内のDNSサービスとIPアドレスの固定化
~~~sh
ansible-playbook site.yanml --tags dns
~~~
|ノード|内容|補足|
|---|---|---|
|mpi0|DNSサービスをインストール & 設定|dnsmasq|
|all|`wired` 接続を設定|NetworkManager|

> 再起動

## system 設定
システム設定を更新
~~~sh
ansible-playbook site.yanml --tags system
~~~
|ノード|内容|補足|
|---|---|---|
|all|タイムゾーン、ロケール設定|Asia/Tokyo, en_GB.UTF-8|
|all|/boot/cmdline.txt 編集|cgroup v2 の有効化|
|all|/boot/config.txt 編集|Wi-Fi 無効化, Bluetooth 無効化, 電源LEDの設定変更|

## インストール済みパッケージの更新
~~~sh
ansible-playbook site.yanml --tags package
~~~

> 再起動

## OpenMPI
マルチノード並列処理に必要な `OpenMPI` 関連のパッケージをインストール
~~~sh
ansible-playbook site.yanml --tags openmpi
~~~
|ノード|内容|補足|
|---|---|---|
|all|OpenMPI 関連のパッケージをインストール|-|

## Apptainer
Apptainer (高速計算処理に適したコンテナを生成するツール) をインストール
~~~sh
ansible-playbook site.yanml --tags apptainer
~~~
|ノード|内容|補足|
|---|---|---|
|all|Apptainer 関連のパッケージをインストール|-|
|all|Apptainer インストーラーを実行|-|

## Slurm workload manager
Slurm workload manager (マルチノード並列処理を管理するツール) をインストール
> Configless slurm モードを適用して、導入後の管理をさらに楽に

~~~sh
ansible-playbook site.yanml --tags slurm
~~~
|ノード|内容|補足|
|---|---|---|
|all|munge をインストール & 設定|-|
|mpi0|slurm-wlm をインストール & 設定|slurm control & client |
|all|slurmd をインストール & 設定|slurm compute|

## NFS 共有フォルダ
マルチノード並列処理では、NFS 共有フォルダがだいたい必要
~~~sh
ansible-playbook site.yanml --tags sharedfolder
~~~
|ノード|内容|補足|
|---|---|---|
|mpi0|nfs-server|localhost|
|mpi1, mpi2|自動マウント設定|-|
--- 

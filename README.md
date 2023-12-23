# ラズパイクラスタで `LAMMPS` を稼働
ラズパイのマルチノード並列処理の環境構築と `LAMMPS` の導入
* Ansible: パッケージマネージャーを使った導入
  * クラスタ構築
  * OpenMPI(with PMIx): パッケージマネージャーを使った導入
  * Slurm: パッケージマネージャーを使った導入
  * Apptainer: インストーラーを使った導入
* LAMMPS: SIF (Apptainer コンテナ) で構築
> Apptainer の制限：コンテナ内外で、同じ OpenMPI を使う

## 環境
### ハードウェア
- Raspberry Pi 4B 8GB x 3
- microSD Card 64GB x 3
- [PoE HAT](https://www.waveshare.com/poe-hat-e.htm) x 3
- [PoE HUB](https://www.iodata.jp/product/lan/hub/etg-poe04/index.htm)
- [イーサネットケーブル](https://www.edion.com/detail.html?p_cd=00043376414) x 3

### ソフトウェア (OS)
- Raspberry Pi OS Lite (64-bit) [Debian Bookworm]

### 各ノードの役割
|項目|1台目|2台目|3台目|
|---|---|---|---|
|ネットワーク|DNS サーバー|-|-|
|Ansible|制御ノード<br>管理対象ノード|<br>管理対象ノード|<br>同左|
|Slurm workload manager|クライアントノード<br>制御ノード<br>計算ノード|<br><br>計算ノード|<br><br>同左|

### 各ノードの OS インストールの設定値
|項目|適用|小項目|1台目|2台目|3台目|
|---|---|---|---|---|---|
|ホスト名|yes||mpi0|mpi1|mpi2|
|ユーザー名とパスワードを設定する|yes|username<br>password|mpi<br>****|同左|同左|
|WiFiを設定する|no|||||
|ローケール設定をする|yes|timezone<br>keyboard layout|Asia/Tokyo<br>JP|同左|同左|
|||||||
|SSHを有効化する|yes||パスワード認証を使う|同左|同左|

### 各ノードの設定値
|項目||1台目|2台目|3台目|
|---|---|---|---|---|
|ユーザー名@ホスト名||mpi@mpi0|mpi@mpi1|mpi@mpi2|
|ip address|192.168.68.xxx/24|150|151|152|

## マルチノード並列処理のクラスタ構築
[ansible を使う場合](ansible/README.md)<br>
[ansible を使わない場合](without-ansible/README.md)<br>

## LAMMPS
`mpi0`
### SIF 作成
~~~sh
cp hpc/lammps/* /mpi
cd /mpi
apptainer build lammps.sif lammps.def
~~~
確認
~~~sh
apptainer run lammps.sif
~~~
### 実行
~~~sh
cd /mpi
sbatch lammps.sh
~~~
> 事前に、各計算ノードの状態が `idle` であることを確認
---

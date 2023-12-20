# Apptainer 導入
`pi0, pi1, pi2 共通`

https://apptainer.org/docs/admin/latest/installation.html

* 関連パッケージの導入
* インストーラーをダウンロード & 実行
## 関連パッケージの導入
~~~sh
sudo apt update
sudo apt install -y curl rpm2cpio cpio uidmap
~~~
## インストーラーをダウンロード & 実行
ユーザー名前空間へ、ファイル群の配置
~~~sh
curl -s https://raw.githubusercontent.com/apptainer/apptainer/main/tools/install-unprivileged.sh | bash -s - apptainer

sudo ln -s /home/mpi/apptainer/bin/apptainer /usr/local/bin/
~~~
確認
~~~sh
apptainer buildcfg
~~~

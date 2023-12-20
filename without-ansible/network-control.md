# クラスタ構築 - 制御ノード
`mpi0`

* 固定 IP アドレスの設定
* DNS サービスを設置
* DNS サービス設定変更
## 固定 IP アドレス設定
~~~sh
sudo nmcli connection add type ethernet ifname eth0 \
    con-name wired \
    autoconnect yes \
    ipv4.method manual \
    ipv4.addresses "192.168.68.150/24" \
    ipv4.gateway "192.168.68.1" \
    ipv4.dns "192.168.68.1"

sudo nmcli connection reload
sudo nmcli connection up wired

# 改めて SSH 接続して、確認
nmcli connection show wired
sudo reboot
~~~
## dns サービス導入
~~~sh
sudo apt install dnsmasq
sudo systemctl status dnsmasq | grep Active
~~~
## dns サービス設定変更
~~~sh
sudo nano /etc/dnsmasq.conf
~~~
~~~diff
- #domain-needed
+ domain-needed
- #bogus-priv
+ bogus-priv
~~~
~~~sh
sudo nano /etc/hosts
~~~
~~~diff
- 127.0.1.1    mpi0
+ 192.168.68.150    mpi0
+ 192.168.68.151    mpi1
+ 192.168.68.152    mpi2
~~~

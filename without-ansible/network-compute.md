# クラスタ構築 - 計算ノード
`pi1, pi2`

* 固定 IP アドレス設定
## 固定 IP アドレス設定
~~~sh
# 下記のように変更して入力
# pi1: xxx -> 151
# pi2: xxx -> 152
sudo nmcli connection add type ethernet ifname eth0 \
    con-name wired \
    autoconnect yes \
    ipv4.method manual \
    ipv4.addresses "192.168.68.xxx/24" \
    ipv4.gateway "192.168.68.1" \
    ipv4.dns "192.168.68.150"

sudo nmcli connection reload
sudo nmcli connection up wired

# 改めて SSH 接続して、確認
nmcli connection show wired
sudo reboot
~~~

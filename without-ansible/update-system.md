# 各ノードの OS システムなどを更新
`mpi0, mpi1, mpi2 共通`

* OS 更新
* WiFi 無効、Bluetooth 無効、電源 LED 設定変更
* cgroup v2 で memory 制御を許可
* 参考情報

## OS 更新
~~~sh
sudo apt update
sudo apt full-upgrade -y
sudo apt autoremove -y
~~~
> `python3`, `python3-venv` とかインストールした方が良いかも

## WiFi 無効、Bluetooth 無効、電源 LED 設定変更
~~~sh
sudo nano /boot/config.txt
~~~
~~~diff
+ dtoverlay=disable-bt
+ dtoverlay=disable-wifi
+ dtparam=pwr_led_trigger=heartbeat
~~~
## cgroup v2 で memory 制御を許可
~~~sh
sudo nano /boot/cmdline.txt
~~~
> 以下の3つの項目を行末に追記 (間はスペース、改行無し)
~~~
cgroup_enable=cpuset
cgroup_enable=memory
cgroup_memory=1
swapaccount=1
~~~
## 参考情報
セキュリティ向上のために導入が推奨されているサービス
> firewall: ufw (docker を使う場合は、iptables)<br>
> fail2ban

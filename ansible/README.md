# playbook(yaml) の説明

[ssh.yaml](ssh.yaml), [roles/ssh/tasks/main.yaml](roles/ssh/tasks/main.yaml)
- SSH認証鍵を設定し、公開鍵を配布する。

[package.yaml](package.yaml)
- インストール済みのパッケージを更新する。

[locale.yaml](locale.yaml)
- ロケールを設定する。

[swap.yaml](swap.yaml)
- swapfile を8 GByte に拡張する。

[bluetooth.yaml](bluetooth.yaml)
- Bluetooth サービスを無効にする

[networkmanager.yaml](networkmanager.yaml)
- dhcpcd, wpa_sapplicant サービスを停止し、NetworkManager サービスを有効にする。

[ethernet.yaml](ethernet.yaml)

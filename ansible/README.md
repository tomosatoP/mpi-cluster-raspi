# playbook(yaml) の説明

[ssh.yaml](ssh.yaml), [roles/ssh/tasks/main.yaml](roles/ssh/tasks/main.yaml)
- SSH認証鍵を設定し、公開鍵を配布する。

[package.yaml](package.yaml), [roles/package/tasks/main.yaml](roles/package/tasks/main.yaml)
- インストール済みのパッケージを更新する。

[locale.yaml](locale.yaml), [roles/](roles/)
- ロケールを設定する。

[swap.yaml](swap.yaml), [roles/](roles/)
- swapfile を8 GByte に拡張する。

[bluetooth.yaml](bluetooth.yaml), [roles/](roles/)
- Bluetooth サービスを無効にする

[networkmanager.yaml](networkmanager.yaml), [roles/](roles/)
- dhcpcd, wpa_sapplicant サービスを停止し、NetworkManager サービスを有効にする。

[ethernet.yaml](ethernet.yaml), [roles/](roles/)
- 固定IPアドレスを設定する。
- 途中で停止ししてしまう問題が未解決のまま。
---

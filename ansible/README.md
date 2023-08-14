# playbook(yaml) の説明

[ssh.yaml](ssh.yaml), [roles/ssh/tasks/main.yaml](roles/ssh/tasks/main.yaml)
- SSH認証鍵を設定し、公開鍵を配布する。mpi クラスタでは必須。

[package.yaml](package.yaml), [roles/package/tasks/main.yaml](roles/package/tasks/main.yaml)
- インストール済みのパッケージを更新する。

[locale.yaml](locale.yaml), [roles/locale/defaults/main.yaml](roles/locale/defaults/main.yaml), [roles/locale/tasks/main.yaml](roles/locale/tasks/main.yaml)
- ロケールを設定する。

[swap.yaml](swap.yaml), [roles/swap/tasks/main.yaml](roles/swap/tasks/main.yaml)
- swapfile を8 GByte に拡張する。メインメモリ不足になるのを回避するため。

[bluetooth.yaml](bluetooth.yaml), [roles/bluetooth/tasks/main.yaml](roles/bluetooth/tasks/main.yaml)
- 必要のない Bluetooth サービスを無効にする

[networkmanager.yaml](networkmanager.yaml), [roles/networkmanager/tasks/main.yaml](roles/networkmanager/tasks/main.yaml)
- dhcpcd, wpa_sapplicant サービスを停止し、NetworkManager サービスを有効にする。

[ethernet.yaml](ethernet.yaml), [roles/ethernet/defaults/main.yaml](roles/ethernet/defaults/main.yaml), [roles/ethernet/tasks/main.yaml](roles/ethernet/tasks/main.yaml)
- 固定IPアドレスを設定する。mpi クラスタでは必須。
- 制御ノードの再起動ができないので、失敗する（playbook は実行を継続）。
- 途中で停止ししてしまう問題が未解決のまま。

[sharedfolder.yaml](sharedfolder.yaml), [roles/sharedfolder/defaults/main.yaml](roles/sharedfolder/defaults/main.yaml), [roles/sharedfolder/handlers/main.yaml](roles/sharedfolder/handlers/main.yaml), [roles/sharedfolder/tasks/main.yaml](roles/sharedfolder/tasks/main.yaml), [roles/sharedfolder/templates/exports.j2](roles/sharedfolder/templates/exports.j2)
- NFS 共有フォルダを設定する。mpi クラスタでは必須。
- /etc/exports ファイル編集を作成中。
---

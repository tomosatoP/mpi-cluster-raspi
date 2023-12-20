# SSH 認証鍵方式の導入
`pi0`

* SSH 接続 [`pi0` -> `pi1, pi2`] の認証を、パスワード入力から認証鍵方式に変更
  > 目的: SSH 接続の認証を自動化、およびセキュリティ向上

## SSH 鍵ペア作成

~~~sh
# デフォルトで RSA方式 2048Bits
ssh-keygen
# > Enter file in which to save the key(~/.ssh/id_rsa): 
# > Enter passphrase (empty for no passphrase):
# > Enter same passphrase again:
~~~
|||
|---|---|
|秘密鍵|~/.ssh/id_rsa|
|公開鍵|~/.ssh/id_rsa.pub|

## SSH 公開鍵の共有

~~~sh
ssh-copy-id -i ~/.ssh/id_rsa.pub mpi@pi1
# > mpi@pi1's password: ********
ssh-copy-id -i ~/.ssh/id_rsa.pub mpi@pi2
# > mpi@pi2's password: ********
~~~
> `パスワード入力` を求められるが、SSH 鍵ペア作成時の `パスフレーズ` ではない。

## SSH 設定ファイル

SSH 接続時のオプションを登録して、コマンドを簡略化
~~~sh
nano ~/.ssh/config
~~~
~~~text
Host pi2
    hostname pi2
    user mpi
    identityfile /home/mpi/.ssh/id_rsa
Host pi1
    hostname pi1
    user mpi
    identityfile /home/mpi/.ssh/id_rsa
~~~
### 確認
~~~sh
ssh pi1
~~~
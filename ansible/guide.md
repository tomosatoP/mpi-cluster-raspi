# Ansible の使い方
## 定義済み変数の参照方法
### ローカルの変数
ターゲットノードからローカル(コントロール)ノードの `環境変数` を参照
* lookup('ansible.builtin.env', 'HOME') => /home/mpi
* lookup('ansible.builtin.env', 'LANG') => en_GB.UTF-8
* lookup('ansible.builtin.env', 'USER') => mpi

### ターゲットノードの変数
ターゲットノード自身の `環境変数` を参照
> `become: false` の場合
* ansible_facts.env.HOME => /home/mpi
* ansible_facts.env.LANG => en_GB.UTF-8
* ansible_facts.env.USER => mpi

> `become: true` の場合
* ansible_facts.env.HOME => /root
* ansible_facts.env.LANG => en_GB.UTF-8
* ansible_facts.env.USER => root

ターゲットノード自身のインベントリ変数を参照
* ansible_facts.default_ipv4.address => 192.168.68.150

ターゲットノード自身のインベントリ変数を参照
* inventory_hostname => pi0
* inventory_dir => /home/mpi/hpc/ansible
* hostvars[inventory_hostname] => マップ形式のファクト変数一覧

### 各ターゲットノードの変数
他のターゲットノードの変数を参照
* ansible_play_hosts => ["pi0", "pi1", "pi2"]
* hostvars['pi0']['ansible_all_ipv4_address'] => 192.168.68.150
---
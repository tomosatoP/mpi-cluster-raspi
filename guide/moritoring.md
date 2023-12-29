# クラウド監視

* Node Exporter
  > メトリクス(監視データ: OS などのシステム情報)を収集
* Prometheus
  > 各ノードのNode Exporter からメトリクスを集積
* Grafana
  > Prometheus の集積したメトリクスを可視化する Web UI

## Node Exporter のインストール
~~~sh
sudo apt update
sudo apt install prometheus-node-exporter
~~~
確認
~~~sh
sudo systemctl status prometheus-node-exporter.service
curl -Ss http://localhost:9100/metrics
~~~

## Prometheus のインストール
~~~sh
sudo apt update
sudo apt install prometheus
~~~
確認
~~~sh
sudo systemctl status prometheus.service
~~~
設定変更
~~~sh
sudo nano /etc/prometheus/prometheus.yml
~~~
~~~diff
~~~

## Grafana のインストール
https://grafana.com/tutorials/install-grafana-on-raspberry-pi/
~~~sh
wget -q -O - https://packages.grafana.com/gpg.key | sudo apt-key add -
echo "deb https://packages.grafana.com/oss/deb stable main" | sudo tee -a /etc/apt/sources.list.d/grafana.list

sudo apt update
sudo apt install grafana

sudo systemctl daemon-reload
sudo systemctl enable grafana-server
sudo systemctl restart grafana-server
~~~
確認
~~~sh
sudo systemctl status grafana-server
~~~
---
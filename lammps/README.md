# LAMMPS

[Apptainer 用定義ファイル lammps.def](lammps.def)<br>
[Slurm 用シェルスクリプト lammps.sh](lammps.sh)<br>
[入力ファイル in.melt](in.melt)<br>

---
ベンチマーク
> n=1 なので、参考までに

|N nodes|n tasks|ntasks-per-node||mpi0|mpi1|mpi2|time(s)|rate(%)|
|--:|--:|--:|--:|--:|--:|--:|--:|--:|
|1|1|1||1|-|-|2496|100|
|1|2|2||2|-|-|1533|61|
|1|3|3||3|-|-|1410|56|
|1|4|4||4|-|-|1618|65|
|2|2|1||1|1|-|1527|61|
|2|4|2||2|2|-|1061|42|
|2|6|3||3|3|-|||
|2|8|4||4|4|-|||
|3|3|1||1|1|1|1138|46|
|3|6|2||2|2|2|||
|3|9|3||3|3|3|804|32|
|3|12|4||4|4|4|915|37|

Raspberry Pi 4 の `slumd-C` 出力
|項目|値|
|---|---|
|CPUs|4|
|Boards|1|
|SocketsPerBoard|1|
|CoresPerSocket|4|
|ThreadsPerCore|1|
|RealMemory|7811|
---

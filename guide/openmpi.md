# OpenMPI(PMIx)
https://www.open-mpi.org/<br>
https://docs.open-mpi.org/en/v5.0.x/<br>
https://docs.open-mpi.org/en/v4.1.x/
## コマンド
### ompi_info
~~~sh
ompi_info --param btl vader --level 3 | grep values
 > Valid values: 1:"cma", 4:"emulated", 3:"none"
~~~
### pmix_info
~~~sh
pmix_info --param mca gds | grep gds
~~~
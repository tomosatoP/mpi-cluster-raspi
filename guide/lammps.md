# Lammps

## コマンド

## lammps の構築に使える compiler のリスト
|Compiler|cmake<br>(cmake/presets/)|packages<br>build|packages<br>run|
|---|---|---|---|
|-|-|gfortran<br>clang-format||
|GCC|gcc.cmake|gfortran<br>clang-format<br>libgsl-dev|gsl-bin<br>libgomp1|
|Clang/LLVM|clang.cmake|gfortran<br>clang-format<br>clang<br>clang-tidy<br>libomp-dev|libomp5|
## lammps 構築 & 実行 関連のパッケージ
|name|build|run|
|---|---|---|
|PNG|libpng-dev|libpng-tools|
|JPEG|libjpeg62-turbo-dev|libjpeg62-turbo|
|FFMPEG|ffmpeg|ffmpeg|
|FFT|libfftw3-dev|libfftw3-bin|
|HDF5|libhdf5-serial-dev|hdf5-tools|
|OpenMPI (with PMIx)|libopenmpi-dev|mpi-default-bin<br>libpmix-bin|
|OpenMP (GCC compiler)|(libgomp1)|libgomp1|
|OpenMP (LLVM compiler)|libomp-dev|libomp5|
|GNU Scientific Library|libgsl-dev|gsl-bin|
|BLAS|liblas-dev<br>liblapack-dev|labblas3<br>liblapack3|
# 机器视觉实验代码

用`cmake -B build`编译，如果找不到OpenCV可以自行定义`-DOpenCV_ROOT=/path/to/opencv`或环境变量`OpenCV_DIR`。如果OpenCV的DLL不在PATH中，可以定义`-DCOPY_DLL=ON`复制DLL到运行目录。

```shell
cmake -B build -DOpenCV_ROOT=/path/to/opencv -DCOPY_DLL=ON -DEigen_INCLUDE_DIR=/path/to/eigen
cmake --build build
cmake --build build -t run-transparency
```


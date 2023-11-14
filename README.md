# gcc-and-cmake-tasks
## gcc Subtask 1:
In this task create a dynamic library and compile the given files using the following g++ commands in terminal:
```
g++ -shared -o lib_mymath.so mymath.cpp -fpic
g++ -o dynamic_main main.cpp -L . lib_mymath.so
```
## gcc Subtask 2:
In this task create a static library and compile the given files using the following g++ commands in terminal:
```
g++ -c mymath.cpp -o mymath.o
ar rcs lib_mymath.a mymath.o
g++ -o static_main main.cpp -l . lib_mymath.a 
```

## gcc Subtask 3:
In this task compile the given files in Release mode using the following g++ commands in terminal:
```
g++ -o main_release main.cpp mymath.cpp -O2
```
In this task compile the given files in Debug mode using the following g++ commands in terminal:
```
g++ -o main_debug main.cpp mymath.cpp -g
```
## CMake-task1:
In this task, the above cmake task has been implemeneted using cmake. Follow the following task to run the cmake:
1. Make a folder called 'build' and navigate inside the folder:
```
mkdir build
cd build
```
2. Now in this folder run the following commands to create the makefile and executable by passsing either of the build options:
```
cmake -DCMAKE_BUILD_TYPE=Debug .. OR 
cmake -DCMAKE_BUILD_TYPE=Release .. OR 
make
```
3. Now run the executable.
```
./static_exec OR
./dynamic_exec
```

## CMake-task2:
In this task we are using a third party library and downloading and isntalling it using cmake. In our CMakeLists.txt we are adding boost as an external project and downloading it from gihub.
Use the following steps to run the cmake file and then run the executable:
```
mkdir build
cd build
cmake ..
make
./validate_time
```
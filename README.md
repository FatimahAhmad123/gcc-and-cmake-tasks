## gcc-and-cmake-tasks
# gcc Subtask 1:
In this task create a dynamic library and compile the given files using the following g++ commands in terminal:
```
g++ -shared -o lib_mymath.so mymath.cpp -fpic
g++ -o dynamic_main main.cpp -L . lib_mymath.so
```
# gcc Subtask 2:
In this task create a static library and compile the given files using the following g++ commands in terminal:
```
g++ -c mymath.cpp -o mymath.o
ar rcs lib_mymath.a mymath.o
g++ -o static_main main.cpp -l . lib_mymath.a 
```

# gcc Subtask 3:
In this task compile the given files in Release mode using the following g++ commands in terminal:
```
g++ -o main_release main.cpp mymath.cpp -O2
```
In this task compile the given files in Debug mode using the following g++ commands in terminal:
```
g++ -o main_debug main.cpp mymath.cpp -g
```

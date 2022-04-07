## How to run

```
$ g++-11 -I/usr/local/Cellar/boost/1.78.0_1/include/ -c keccak.cpp
$ g++-11 -I/usr/local/Cellar/boost/1.78.0_1/include/ -c app.cpp
$ g++-11 -o app keccak.o app.o
```

## Prerequisites

```
$ brew install boost
$ cd i_love_mining
$ git clone https://github.com/stbrumme/hash-library.git
$ vim hash-library/keccak.cpp
```

Replace the code in line 11 with the following:

```
#include <machine/endian.h>
```

## How to run

```
$ g++ -I/usr/local/Cellar/boost/1.78.0_1/include/ -c keccak.cpp
$ g++ -I/usr/local/Cellar/boost/1.78.0_1/include/ -c app.cpp
$ g++ -o app keccak.o app.o
```

or

```
$ make
```

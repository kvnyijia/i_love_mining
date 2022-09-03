APP=app
CPPFLAGS=-I/usr/local/Cellar/boost/1.79.0_1/include

all: clean app.o hash-library/keccak.o
	${CXX} -o ${APP} app.o hash-library/keccak.o

%.o: %.c
	${CXX} ${CPPFLAGS} -c $<

clean:
	rm -f *.o ${APP}

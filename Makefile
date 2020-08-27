# bt
all: bt

bt: bittest.o
	g++ bittest.o -o bt

bittest.o: bittest.cpp
	g++ -c bittest.cpp

clean:
	rm -rf *.o bt

all: sorter

sorter: sorter.o
	g++ sorter.cpp helper.cpp algorithm.cpp -o sorter

sorter.o: sorter.cpp helper.h algorithm.h
	g++ -c sorter.cpp

clean:
	rm -rf *o sorter

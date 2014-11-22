all: sorter

sorter: sorter.o
	g++ sorter.cpp helper.cpp -o sorter

sorter.o: sorter.cpp helper.h
	g++ -c sorter.cpp

clean:
	rm -rf *o sorter

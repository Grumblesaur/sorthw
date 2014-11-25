sorter: sorter.o
	g++ sorter.cpp helper.cpp algorithm.cpp -o sorter

sorter.o: sorter.cpp helper.h algorithm.h helper.cpp algorithm.cpp
	g++ -c sorter.cpp helper.cpp algorithm.cpp

clean:
	rm -rf *o sorter

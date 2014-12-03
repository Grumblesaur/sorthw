sorter: main.o algorithm.o helper.o
	g++ main.o helper.o algorithm.o -o sorter

helper.o: helper.cpp helper.h
	g++ -c helper.cpp

algorithm.o: algorithm.cpp helper.h helper.cpp algorithm.h
	g++ -c helper.cpp algorithm.cpp

main.o: main.cpp helper.h algorithm.h
	g++ -c main.cpp

clean:
	rm -rf *o sorter

main: main.o textquery.o
	g++ -o main main.o textquery.o

main.o: main.cpp
	g++ -o main.o -c main.cpp

textquery.o: TextQuery.cpp
	g++ -o textquery.o -c TextQuery.cpp

clean:
	rm -rf *.o main

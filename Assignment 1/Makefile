hw1: main.o sort.o timer.o random_generator.o
	g++ -Wall -std=c++11 main.o sort.o timer.o random_generator.o -o hw1

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

sort.o: sort.cpp sort.h
	g++ -c -std=c++11 sort.cpp

timer.o: timer.cpp timer.h
	g++ -c -std=c++11 timer.cpp

random_generator.o: random_generator.cpp random_generator.h
	g++ -c -std=c++11 random_generator.cpp

clean:
	rm *.o hw1

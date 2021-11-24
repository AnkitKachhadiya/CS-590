hw4: main.o dynprog.o timer.o random_generator.o
	g++ -Wall -std=c++11 main.o dynprog.o timer.o random_generator.o -o hw4

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

dynprog.o: dynprog.cpp dynprog.h
	g++ -c -std=c++11 dynprog.cpp

timer.o: timer.cpp timer.h
	g++ -c -std=c++11 timer.cpp

random_generator.o: random_generator.cpp random_generator.h
	g++ -c -std=c++11 random_generator.cpp

clean:
	rm *.o hw4

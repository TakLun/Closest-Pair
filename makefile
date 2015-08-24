all: submission

submission: assignment2.o
	g++ -g assignment2.o -o submission
	
assignment2.o: assignment2.cpp
	g++ -g -c assignment2.cpp
	
clean:
	rm -f *.o submission

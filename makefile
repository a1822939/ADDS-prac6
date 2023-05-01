all: testall 
	
testall: main.out
	./main.out

main.out: mainA-1.cpp LinkedList.h LinkedList.cpp Node.h Node.cpp  
	g++ -std=c++11 -o main.out -O2 -Wall mainA-1.cpp  Node.cpp LinkedList.cpp

clean:
	rm -f *.out
	
	# BigNumCalc.cpp
	# BigNumCalc.h BigNumCalc.cpp
	# g++ -std=c++20 -o main.out -O2 -Wall mainA-1.cpp  Node.cpp LinkedList.cpp
	
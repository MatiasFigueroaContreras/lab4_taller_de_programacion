FLAGS = -O2 -g -Wall

all: clean test_FordFulkersonData test_FordFulkersonGraph test_FordFulkersonSolver test_MBPSolver run

main: MBPSolver.o FordFulkersonSolver.o FordFulkersonGraph.o FordFulkersonData.o main.cpp
	g++ $(FLAGS) -o main MBPSolver.o FordFulkersonSolver.o FordFulkersonGraph.o FordFulkersonData.o main.cpp

test_MBPSolver: MBPSolver.o FordFulkersonSolver.o FordFulkersonGraph.o FordFulkersonData.o test_MBPSolver.cpp
	g++ $(FLAGS) -o test_MBPSolver MBPSolver.o FordFulkersonSolver.o FordFulkersonGraph.o FordFulkersonData.o test_MBPSolver.cpp

test_FordFulkersonSolver: FordFulkersonSolver.o FordFulkersonGraph.o FordFulkersonData.o test_FordFulkersonSolver.cpp
	g++ $(FLAGS) -o test_FordFulkersonSolver FordFulkersonSolver.o FordFulkersonGraph.o FordFulkersonData.o test_FordFulkersonSolver.cpp

test_FordFulkersonGraph: FordFulkersonGraph.o FordFulkersonData.o test_FordFulkersonGraph.cpp
	g++ $(FLAGS) -o test_FordFulkersonGraph FordFulkersonGraph.o FordFulkersonData.o test_FordFulkersonGraph.cpp

test_FordFulkersonData: FordFulkersonData.o test_FordFulkersonData.cpp
	g++ $(FLAGS) -o test_FordFulkersonData FordFulkersonData.o test_FordFulkersonData.cpp

MBPSolver.o: MBPSolver.cpp MBPSolver.h
	g++ $(FLAGS) -c MBPSolver.cpp

FordFulkersonSolver.o: FordFulkersonSolver.cpp FordFulkersonSolver.h
	g++ $(FLAGS) -c FordFulkersonSolver.cpp

FordFulkersonGraph.o: FordFulkersonGraph.cpp FordFulkersonGraph.h
	g++ $(FLAGS) -c FordFulkersonGraph.cpp

FordFulkersonData.o: FordFulkersonData.cpp FordFulkersonData.h
	g++ $(FLAGS) -c FordFulkersonData.cpp

clean:
	rm -f test_FordFulkersonData test_FordFulkersonGraph test_FordFulkersonSolver test_MBPSolver main *.o

run:
	./test_FordFulkersonData
	./test_FordFulkersonGraph
	./test_FordFulkersonSolver
	./test_MBPSolver
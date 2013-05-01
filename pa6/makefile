CC=c++ -g -Wall
EXEC=graph

all: $(EXEC)

$(EXEC): Edge.o Graph.o GraphTest.o Vertex.o
	@echo Linking project…
	@$(CC) Edge.o Graph.o GraphTest.o Vertex.o -o $(EXEC)
	@echo Done.
	
Edge.o: Edge.cpp Edge.h
	@echo Compiling $@…
	@$(CC) -c Edge.cpp
Graph.o: Graph.cpp Graph.h Vertex.h Edge.h PriorityQueue.h BinaryHeap.h ComparisonCounter.h
	@echo Compiling $@…
	@$(CC) -c Graph.cpp
GraphTest.o:  GraphTest.cpp Graph.h Vertex.h Edge.h PriorityQueue.h BinaryHeap.h PQComp.h ComparisonCounter.h
	@echo Compiling $@…
	@$(CC) -c GraphTest.cpp
Vertex.o: Vertex.cpp Vertex.h
	@echo Compiling $@…
	@$(CC) -c Vertex.cpp
	
clean:
	@rm -rf *.o $(EXEC) $(EXEC).dSYM core
	@echo Clean complete.
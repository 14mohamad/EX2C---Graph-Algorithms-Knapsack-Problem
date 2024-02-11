CC = gcc
FLAGS = -Wall -g
EXE_MY_GRAPH = my_graph
EXE_MY_KNAPSACK = my_Knapsack
OBJECTS_MY_GRAPH = my_graph.o
OBJECTS_MY_KNAPSACK = my_Knapsack.o

.PHONY: clean all
#target commands

all: $(EXE_MY_GRAPH) $(EXE_MY_KNAPSACK)

$(EXE_MY_GRAPH): $(OBJECTS_MY_GRAPH)
	$(CC) $(OBJECTS_MY_GRAPH) -o $(EXE_MY_GRAPH)

$(EXE_MY_KNAPSACK): $(OBJECTS_MY_KNAPSACK)
	$(CC) $(OBJECTS_MY_KNAPSACK) -o $(EXE_MY_KNAPSACK)

my_graph.o: my_graph.c my_mat.h
	$(CC) $(FLAGS) -c my_graph.c

my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -c my_mat.c

my_Knapsack.o: my_Knapsack.c
	$(CC) $(FLAGS) -c my_Knapsack.c

clean:
	rm -f *.o $(EXE_MY_GRAPH) $(EXE_MY_KNAPSACK)


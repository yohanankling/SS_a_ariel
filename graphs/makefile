maFLAGS= -Wall -g

all: my_graph.a graph 

my_graph.a: my_graph.o
	ar -rcs my_graph.a my_graph.o
graph:main.o my_graph.o
	gcc $(FLAGS) -o graph main.o my_graph.o
main.o:main.c my_graph.h
	gcc $(FLAGS) -c main.c

my_graph.o: my_graph.c my_graph.h
	gcc $(FLAGS) -c my_graph.c

.PHONY: clean all
clean:
	rm -f *.o *.a graph 
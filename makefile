CC=g++
P=submission
H1=GreedyAlg
FLAGS=-g -Wall -Wextra --std=c++14

all: $(P)

run: $(P)
	./$(P) smallInput.txt out.txt 0

memcheck: $(P)
	valgrind ./$(P) smallInput.txt out.txt 0 

$(P): $(H1).o $(P).o
	$(CC) $(FLAGS) -o $(P) $(P).o $(H1).o 

$(P).o: $(P).cpp $(H1).cpp
	$(CC) $(FLAGS) -c $(P).cpp

$(H1).o: $(H1).cpp 
	$(CC) $(FLAGS) -c $(H1).cpp

clean:
	rm -rf $(P) *.o

test: $(P)
	./$(P) smallInput.txt smallOutput.txt 0

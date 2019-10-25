CC=g++
P=submission
H1=GreedyAlg
FLAGS=-g -Wall -Wextra --std=c++14

all: $(P)

run: $(P)
	./$(P) smallInput.txt smallOutputGreedy2.txt 1
	./$(P) smallInput.txt smallOutputBacktracking.txt 2
	./$(P) input.txt outputGreedy2.txt 1
	./$(P) input.txt outputBacktracking.txt 2
	./$(P) mediumInput.txt mediumOutputGreedy2.txt 1
	./$(P) mediumInput.txt mediumBacktracking.txt 2
	./$(P) badGreedyInput.txt outputbadGreedy1.txt 0
	./$(P) badGreedyInput.txt outputbadGreedy2.txt 1
	./$(P) badImprovedGreedyInput.txt outputbadImprovedGreedy2.txt 1

memcheck: $(P)
	valgrind ./$(P) smallInput.txt smallOutput.txt 0 

$(P): $(H1).o $(P).o
	$(CC) $(FLAGS) -o $(P) $(P).o $(H1).o 

$(P).o: $(P).cpp $(H1).cpp
	$(CC) $(FLAGS) -c $(P).cpp

$(H1).o: $(H1).cpp 
	$(CC) $(FLAGS) -c $(H1).cpp

clean:
	rm -rf $(P) *.o smallOutputGreedy2.txt smallOutputBacktracking.txt outputGreedy2.txt mediumOutputGreedy2.txt mediumBacktracking.txt outputbadGreedy1.txt outputbadGreedy2.txt outputbadImprovedGreedy2.txt

test: $(P)
	./$(P) smallInput.txt smallOutput.txt 0

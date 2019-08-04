GXX = g++
GFLAGS = -c -std=c++11 -Wall -Werror
LFLAGS = -std=c++11 -Wall -Werror
SRC = ./src/

maze_solver: $(SRC)main.o $(SRC)Maze.o $(SRC)MazeSolver.o $(SRC)Node.o
	$(GXX) $(LFLAGS) $(SRC)main.o $(SRC)Maze.o $(SRC)MazeSolver.o $(SRC)Node.o -o maze_solver

main.o: $(SRC)main.cpp $(SRC)MazeSolver.h $(SRC)Maze.h
	$(GXX) $(LFLAGS) $(SRC)main.cpp

Node.o: $(SRC)Node.cpp $(SRC)Node.h
	$(GXX) $(GFLAGS) $(SRC)Node.cpp

Maze.o: $(SRC)Maze.cpp $(SRC)Maze.h $(SRC)Node.h
	$(GXX) $(GFLAGS) $(SRC)Maze.cpp

MazeSolver.o: $(SRC)MazeSolver.cpp $(SRC)MazeSolver.h $(SRC)Maze.h
	$(GXX) $(GFLAGS) $(SRC)MazeSolver.cpp

clean:
	rm -rf $(SRC)*.o maze_solver


# MazeSolver
A simple maze solving program that uses the A* pathfinding algorithim to solve a .txt maze.

# Motivation
I was motivated to do this project when I learned about Dijkstra's Pathfinding Algorithim in my Data Structures and Algorithims class, and later became even more interested when I found [Devon Crawford's A* Visualization](https://youtu.be/1-YPj5Vt0oQ)

# How to use?
Making the executable is simple, as I have included a `Makefile`. Simply have both the included `Makefile` and the included `src` folder. Then in your terminal of choice type:

`$ make`

I have included a clean rule to remove `.o` files and the executable. To use the clean rule, type the following into the terminal:

`$ make clean`

Once you have made the executable, the syntax to run the executable is the following:

`$ ./maze_solver [directory_to_input_maze] [maze_solutions_name]`

I have included 5 sample mazes in the `sample_mazes` folder in the GitHub project. Lets do a quick demo of the program using the `4.txt`. First lets look at the maze.

`$ cat 4.txt`

![maze 4](https://i.imgur.com/gO5hRw0.jpg)

Now lets run the maze solver on the maze. 

`$ ./maze_solver 4.txt maze_4_sol`

Now lets take a look at the solution.

`$ cat maze_4_sol`

![maze4sol](https://i.imgur.com/gNIOPN2.jpg)

The `@` represent the shortest path between the start and finish.

# Making your own maze!
If you have run all the sample mazes, and instead want to create your own maze make sure to adhere to the following guidelines:

1. First row of your maze should always be the number of rows.
2. Second row of your maze should always be the number of columns.
3. `+` indicates an impassable wall
4. `.` indicates a spot that can be moved onto
5. `S` is the start
6. `F` is the finish

If no start or finish is provided, or the finish is unreachable, an approriate error message will be provided.

# Contributing/Errors
If you happen to stumble upon this project and want to contribute, please feel free I have much to learn. However, also tell me of any errors/bugs you may find.

*Project by Harjot Singh*


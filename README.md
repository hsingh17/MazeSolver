# MazeSolver
A simple maze solving program that uses the A* pathfinding algorithim to solve a .txt maze.

# Motivation
I was motivated to do this project when I learned about Dijkstra's Pathfinding Algorithim in my Data Structures and Algorithims class, and later became even more interested when I found [Devon Crawford's A* Visualization](https://youtu.be/1-YPj5Vt0oQ)

# How to use?
Making the executable is simple, as I have included a `Makefile`. Simply have both the included `Makefile` and the included `src` folder. Then in your terminal of choice type:

`make`

I have included a clean rule to remove `.o` files and the executable. To use the clean rule, type the following into the terminal:

`make clean`

Once you have made the executable, the syntax to run the executable is the following:

`./maze_solver [directory_to_input_maze] [maze_solutions_name]`

I have included 5 sample mazes in the `sample_mazes` folder in the GitHub project. Lets do a quick demo of the program using the `4.txt`. First lets look at the maze.

`cat 4.txt`

![maze 4](https://imgur.com/a/jdwtPYm.jpg)


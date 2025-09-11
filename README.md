# Conway's Game of Life


It is a cellular automaton devised by John Conway in 1970. Here evolution is determined by the initial state, requiring no input making it a 0 player game. It is turing complete and can simulate a universal constructor or any other turing machine.

*I made this game in C to explore more C libraries and was interested in studying cellular automaton suggested by Stanislav Ulam and Von Neumann. Also their model of fluid flow was too difficult to make due to each cell having 27 different states* 

<div style="text-align:center;">
<img src="https://upload.wikimedia.org/wikipedia/commons/e/e5/Gospers_glider_gun.gif">
</div>


#### Rules Withn The Cells
The universe of the Game of Life is an infinite, two-dimensional orthogonal grid of square cells, each of which is in one of two possible states, _live_ or _dead_ (or _populated_ and _unpopulated_, respectively). Every cell interacts with its eight neighbours, which are the cells that are horizontally, vertically, or diagonally adjacent. At each step in time, the following transitions occur:
1. Any live cell with fewer than two live neighbours dies, as if by underpopulation.
2. Any live cell with two or three live neighbours lives on to the next generation.
3. Any live cell with more than three live neighbours dies, as if by overpopulation.
4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.






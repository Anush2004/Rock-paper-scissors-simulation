# Rock Paper Scissor Simulator

This is a C++ implementation of a Rock-Paper-Scissors tournament simulator. The code reads the input of state transitions of each player's moves and then generates its own moves based on a set of rule. The implementation uses a tuple data structure to represent the state transitions and the results of each game.

## How to Use

1. Compile the code using a C++ compiler (e.g., g++).
2. Run the compiled executable.
3. Input the number of states, followed by their state transitions.
4. The program will output best transition required by the player to win against input transitions and state.

## Implementation Details

The `winner()` function is used to determine the winner of each game. It takes two arguments `a` and `b`, representing the moves of two players. The function returns 1 if the first player wins and 0 if the second player wins or if it is a draw.

The code reads the number of players `n` and their state transitions. It reads different states `c` and their state transitions for the Rock, Paper, and Scissors moves `r`, `p`, and `s`, respectively. The state transitions are stored in a vector of tuples `v_list input_state_transition`.

The code then generates its own moves based on a set of rules. If the opponent's last move was Rock, it chooses Paper for the next move, and if the opponent's last move was Paper, it chooses Scissors, and if the opponent's last move was Scissors, it chooses Rock. The generated moves are stored in another vector of tuples `v_list output`. 

The implementation then matches the moves of each player in a tournament. For each player, the code retrieves their state transitions for the Rock, Paper, and Scissors moves from `input_state_transition`. By iterating and making the player transition better by checking the number of wins and losses , it makes most best possible output state which wins most of the times with the opponent

Note: The implementation uses a `rand()` function to generate random numbers. The output of the program may not be the same each time it is run.

## Example

### Input

```
13
P 13 7 6
P 10 9 6
R 11 9 6
P 10 3 1
P 2 11 8
S 5 10 10
P 4 5 6
S 8 11 6
S 8 5 9
R 2 13 10
S 3 13 7
R 13 1 12
S 2 3 4
```

### Output

```
13
S 10 6 10
S 12 6 5
P 9 2 2
S 13 1 4
S 2 8 8
R 3 4 5
S 1 6 5
R 13 2 8
R 10 11 8
P 13 11 12
R 8 9 3
P 1 4 4
R 4 6 2
```
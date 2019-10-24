# Langton's Ant
A program that simulates the universal Turing machine known as Langton's Ant with each step being printed to the console. Utilized dynamic 2D arrays to build the board, wrapped the board around to solve the edge case, and implemented input validation as well as a reusable menu function.

**Langton’s Ant Rule:**
The ant is placed onto the board that is filled with white spaces, and starts moving forward. For each step forward, the Langton’s ant will follow 2 rules: <br/>
    1. If the ant is on a white space, turn right 90 degrees and change the space to black.
    2. If the ant is on a black space, turn left 90 degrees and change the space to white.
After that the ant moves to the next step and continue moving forward. The ant will follow these rules, and continue moving around
the board, until the number of steps runs out.

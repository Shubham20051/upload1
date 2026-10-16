AAC Programming Assignment Set 2 - 8 questions from the supplied DOCX

Each question is a separate C source file.

Compile an individual program with GCC:
    gcc S2_Q01_Fractional_Knapsack.c -o program
Run on Windows:
    program.exe
Run on Linux/macOS:
    ./program

Input conventions:
- Topological sort: enter directed edges as source destination; vertices are numbered from 1.
- Floyd-Warshall and Dijkstra: enter an adjacency matrix and use -1 to represent no edge. Diagonal values are treated as 0.
- Prim: enter a weighted adjacency matrix and use 0 for no edge.
- Strassen: matrix order must be a power of two from 1 to 64.
- N-Queens: prints all solutions; output can be lengthy for larger N.
- Dijkstra and Prim require non-negative weights.

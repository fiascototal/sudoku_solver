sudoku_solver
==============

A C/C++ code that solve a sudoku game

Usage
------

### 1) pass the grid throw argument to the binary

Let's get an example of a sudoku comming from `https://sudoku.com/fr/evil/`

```shell
$ ./sudoku "8  7      3  98 2 4     5  3   17  4   6   1  7 2       9     2    6     8  31 9 "
|-----------------------------|
| 8       | 7       |         |
|    3    |    9  8 |    2    |
| 4       |         | 5       |
|-----------------------------|
| 3       |    1  7 |       4 |
|         | 6       |    1    |
|    7    | 2       |         |
|-----------------------------|
|       9 |         |       2 |
|         |    6    |         |
|    8    |    3  1 |    9    |
|-----------------------------|
[+] nb tries: 105667
[+] nb found solutions: 1
  [+] solution #1:
|-----------------------------|
| 8  6  2 | 7  5  4 | 1  3  9 |
| 7  3  5 | 1  9  8 | 4  2  6 |
| 4  9  1 | 3  2  6 | 5  7  8 |
|-----------------------------|
| 3  2  8 | 5  1  7 | 9  6  4 |
| 9  5  4 | 6  8  3 | 2  1  7 |
| 1  7  6 | 2  4  9 | 8  5  3 |
|-----------------------------|
| 6  1  9 | 8  7  5 | 3  4  2 |
| 5  4  3 | 9  6  2 | 7  8  1 |
| 2  8  7 | 4  3  1 | 6  9  5 |
|-----------------------------|
```


### 2) edit the main function to hardcode the grid to solve

```C
int main(int argc, char *argv[])
{
    const char *board = "8       4"
                        "   9 27  "
                        " 9     3 "
                        " 4 2 7 5 "
                        "  7   4  "
                        " 2 3 5 7 "
                        " 7  6  1 "
                        "  18 96  "
                        "4       7";
    char       *solutions    = NULL;
    const char *board2solve  = NULL;
...
```

Then compile + run the binary

```shell
$ ./sudoku 
|-----------------------------|
| 8       |         |       4 |
|         | 9     2 | 7       |
|    9    |         |    3    |
|-----------------------------|
|    4    | 2     7 |    5    |
|       7 |         | 4       |
|    2    | 3     5 |    7    |
|-----------------------------|
|    7    |    6    |    1    |
|       1 | 8     9 | 6       |
| 4       |         |       7 |
|-----------------------------|
[+] nb tries: 387368
[+] nb found solutions: 3
  [+] solution #1:
|-----------------------------|
| 8  1  2 | 7  3  6 | 5  9  4 |
| 3  5  4 | 9  1  2 | 7  6  8 |
| 7  9  6 | 4  5  8 | 2  3  1 |
|-----------------------------|
| 6  4  3 | 2  8  7 | 1  5  9 |
| 5  8  7 | 6  9  1 | 4  2  3 |
| 1  2  9 | 3  4  5 | 8  7  6 |
|-----------------------------|
| 9  7  8 | 5  6  4 | 3  1  2 |
| 2  3  1 | 8  7  9 | 6  4  5 |
| 4  6  5 | 1  2  3 | 9  8  7 |
|-----------------------------|

  [+] solution #2:
|-----------------------------|
| 8  3  2 | 7  5  1 | 9  6  4 |
| 1  6  4 | 9  3  2 | 7  8  5 |
| 7  9  5 | 4  8  6 | 2  3  1 |
|-----------------------------|
| 6  4  3 | 2  1  7 | 8  5  9 |
| 5  1  7 | 6  9  8 | 4  2  3 |
| 9  2  8 | 3  4  5 | 1  7  6 |
|-----------------------------|
| 2  7  9 | 5  6  4 | 3  1  8 |
| 3  5  1 | 8  7  9 | 6  4  2 |
| 4  8  6 | 1  2  3 | 5  9  7 |
|-----------------------------|

  [+] solution #3:
|-----------------------------|
| 8  3  2 | 7  5  1 | 9  6  4 |
| 1  6  4 | 9  3  2 | 7  8  5 |
| 7  9  5 | 4  8  6 | 2  3  1 |
|-----------------------------|
| 9  4  3 | 2  1  7 | 8  5  6 |
| 5  1  7 | 6  9  8 | 4  2  3 |
| 6  2  8 | 3  4  5 | 1  7  9 |
|-----------------------------|
| 2  7  9 | 5  6  4 | 3  1  8 |
| 3  5  1 | 8  7  9 | 6  4  2 |
| 4  8  6 | 1  2  3 | 5  9  7 |
|-----------------------------|
```

Compilation
------------

### On Linux ###

```shell
$ make clean all
```

Then run the binary


TODO
-----

* Build a generator or sudoku
* Implement an image parser (OCR) to autofill the grid

(Any kind of contribution is welcome)

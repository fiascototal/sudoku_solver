#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BOARD_SIZE 9*9


static void print_board(const char *board)
{
    int x = 0,
        y = 0;
    for (y = 0; y < 9; y++)
    {
        if (y % 3 ==  0)
            printf("|-----------------------------|\n");
        for (x = 0; x < 9; x++)
        {
            if (x % 3 == 0)
                printf("|");
            printf(" %c ", board[y * 9 + x]);
        }
        printf("|\n");
    }
    printf("|-----------------------------|\n");
}

/*
** Here we implement the main rules of SUDOKU:
** 1) The value must not already be present on the line
** 2) The value must not already be present on the column
** 3) The value must not already be present on the 3x3 square
**
** return 0 is the value is valid at this location
*/
static int is_value_possible(const char *board, int x, int y, char value)
{
    int idx_x = 0,
        idx_y = 0;

    // 1) check the line
    for (idx_x = 0; idx_x < 9; idx_x++)
    {
        if (idx_x != x)
        {
            if (board[9*y+idx_x] == value)
                return (1);
        }
    }

    // 2) check the column
    for (idx_y = 0; idx_y < 9; idx_y++)
    {
        if (idx_y != y)
        {
            if (board[9*idx_y+x] == value)
                return (2);
        }
    }

    // 3) check for the 3x3 square
    for (idx_x = (x / 3)*3; idx_x < ((x / 3)*3 + 3); idx_x++)
        for (idx_y = 9 * ((y / 3) * 3); idx_y < (9 * ((y / 3) * 3 + 3)); idx_y += 9)
        {
            if (idx_x != x && (idx_y % 9) != y)
            {
                if (board[idx_y + idx_x] == value)
                    return (3);
            }
        }
    return (0);
}


/*
** recusive fct
*/
static void solve(const char *board, char **solutions, int *nb_solutions, int *nb_calls)
{
    int   x         = -1,
          y         = -1,
          idx_x     = 0,
          idx_y     = 0,
          value     = 0;
    char *new_board = NULL,
          new_value = 0;
    
    *nb_calls = *nb_calls + 1;
    
    // 1) find next empty cell
    for (idx_y = 0; idx_y < 9; idx_y++)
    {
        for (idx_x = 0; idx_x < 9; idx_x++)
        {
            if (board[9*idx_y + idx_x] == ' ')
            {
                x = idx_x;
                y = idx_y;
                break;
            }
        }
        if (x != -1 || y != -1)
            break;
    }

    // no empty cell ? CONGRATULATION !
    if (x == -1 && y == -1)
    {
        *nb_solutions = *nb_solutions + 1;
        *solutions = (char *)realloc(*solutions, (BOARD_SIZE * *nb_solutions) + 1);
        strncpy(*solutions + (*nb_solutions - 1) * BOARD_SIZE, board, BOARD_SIZE);
        return;
    }
    
    // 2) find a valid new value
    for (value = 1; value <= 9; value++)
    {
        new_value = '0' + value;
        if (is_value_possible(board, x, y, new_value) == 0)
        {
            new_board = strdup(board);
            new_board[9*y+x] = new_value;
            solve(new_board, solutions, nb_solutions, nb_calls);
            free(new_board);
        }
    }
}


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
    int         nb_solutions = 0,
                nb_tries     = 0,
                idx          = 0;

    if (argc == 2)
        board2solve = argv[1];
    else
        board2solve = board;
    if (strlen(board2solve) != BOARD_SIZE)
    {
        fprintf(stderr, "[-] invalid board (must be 9x9)\n");
        return (1);
    }

    print_board(board2solve);
    solve(board2solve, &solutions, &nb_solutions, &nb_tries);
    printf("[+] nb tries: %d\n", nb_tries);
    printf("[+] nb found solutions: %d\n", nb_solutions);

    for (idx = 0; idx < nb_solutions; idx++)
    {
        printf("  [+] solution #%d:\n", idx + 1);
        print_board(solutions + (BOARD_SIZE * idx));
        printf("\n");
    }

    return (0);
}

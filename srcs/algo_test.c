
/** @file algo_test.c
 *  @brief Test a simple idea i had for the algorithm.
 * 
 *  1) Using a 2d matrix using y for lines and x for columns.
 *  2) Find in the x axis (sequecial access) the same values in a row
 *  3) Access (random access) row lenght in y axis and check if the 
 *      same length can be find.
 *  4) If the lenght amount of values in a row are found that means that a
 *      potential square is possible.
 *  5) Then procced to check any column by x rows indexing by y axis.
 *  WARNNING: array[y+1][x] does not use L1 cache but array[y][x+1] probally does.
 *  TODO: LOWER AMOUNT INTER
 *  TODO: NOT ALLIGNED SQUARES
 *  6) Never check for a smaller square that the one found.
 *  7) Store a square using a the middle of the address and in the first bytes
 *      store the size (address start always with the same bytes).
*/

# include <square.h>

uint_size_t find_the_square(uint_op_t* const matrix)
{
    
}


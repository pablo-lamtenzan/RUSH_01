
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


// NO INLINE ATTRIBUTE EXISTS
// THINK ABOUT CALLS IN INLINED FUNC
// IF A FUNCTION IS CALLED ONCE INLINE IS VIABLE TOO
// INLINE FUNCTION MAY INCREASSE THE SIZE OF THE CODE (THAN CAN FUCK UP L1 EXECUTION)
// ASM CODE IS LOADDED IN L1 TOO (IF IT FITS)
// INLINE CAN BE BAD IN THIS CASES:
/*
    if (condition)
        f(); // if is inlined
    // code 
*/
// IF CONDITION IS FALSE, THEIR A CHUNK OF UNSED CODE  (POLLUATES L1)
// CODE IS NOT LINEAR
// THE OFTEN USED LINAR CODE IS PROBALLY LOADED INTO L1
// THE LESS USED CODE (not linear) IS LOADDED SOMEWHERE ELSE TO NOT HURT L1 EFICENCY

// long __builtin_expect(long EXP, long C); CAN BE USED TO PREDICT RESULTS

// PROCESSORS PRIORIZES SOME LOOPS

// ALIGNING EACH INSTRUCTIONS IS OPTIMAL IN:
    // THE BEGIN OF FUNCTIONS CALL
    // THE BEGIN OF A LOOP (see beter that, can fck up the code)
    // THE BEGIN OF CODE AFTER A CONDITIONAL JUMP
    // REASON: INSTRUCTIONS ARE FASTER AT THE BEGIN OF THE L1 CACHE
    // OPTIMIZE: PREFETHING AND DECODING
    // ALIGNING ALL THE CODES NOT MAKES SENSE
    // CAN ONLY BE ACHIEVED IN ASM OR BUY THE COMPILER


// Check atribute section

/*
struct mystruct
{
    char c;
    __packed short s; // recommended
}
*/

// UNROLL LOOPS CAN BE AN OPTIZATION



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

#include <square.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <local_mem.h>


typedef struct  s_pos
{
	uint_size_t   y;
	uint_size_t   x;
}               t_pos;

typedef struct  t_streak
{
	t_pos			pos;
	uint_size_t		size;
	uint_op_t		height;
}               t_streak;


uint_op_t  same_height(t_streak streak)
{
	t_pos pos;
	t_pos end;
   /*  if (streak.size % 2 && pos.x % 2)
	{
		start_x = pos.x / 2;
		size = mat_size / 2;
		streak.size /= 2;
		half_matrix = (uint_fast64_t*)mat;
		mask = (streak.size << 32) + streak.size;
		pos.y = 0;
		while (pos.y < streak.size)
		{
			pos.x = start_x;
			while (pos.x < streak.size && half_matrix[pos.y * size + pos.x] == mask)
				pos.x++;
			if (pos.x < streak.size)
				return (0);
			pos.y++;
		}
		return (1);
	}
	else */
	{
		printf("Checking for size %zu\n", streak.size);
		pos.y = streak.pos.y;
		end.y = streak.pos.y + streak.size;
		end.x = streak.pos.x + streak.size;
		while (pos.y < end.y)
		{
			pos.x = streak.pos.x;
			while (pos.x < end.x && static_matrix[pos.y * (height + 1) + pos.x] == streak.height)
				pos.x++;
			if (pos.x < end.x)
				return (0);
			pos.y++;
		}
		return (1);
	}
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



// UNROLL LOOPS CAN BE AN OPTIZATION

int find_the_square(t_sq *square)
{
	t_pos		pos;
	t_streak	biggest;
	t_streak	streak;

	*square = (t_sq){1, {0, 0}};
	pos = (t_pos){0, 0};
	biggest = (t_streak){{0, 0}, 1, static_matrix[0]};
	streak = (t_streak){{0, 0}, 1, static_matrix[0]};

	while (pos.y != height)
	{
		streak = (t_streak){pos, 1, static_matrix[pos.y * (height + 1) + pos.x]};
		while (pos.x != height
		&& static_matrix[pos.y * (height + 1) + pos.x] == streak.height)
			pos.x++;
		streak.size = pos.x - streak.pos.x;
		if (streak.size > biggest.size && same_height(streak))
			biggest = streak;
		if (pos.x == height)
		{
			pos.x = 0;
			pos.y++;
		}
	}
	printf("streak size: %lu\n", biggest.size);
	if (biggest.size != 1)
	{
		streak.pos.x = biggest.pos.x;
		pos.y = biggest.pos.y;
		biggest.pos.y += biggest.size;
		biggest.pos.x += biggest.size;
		while (pos.y < biggest.pos.y)
		{
			pos.x = streak.pos.x;
			while (pos.x < biggest.pos.x)
			{
				static_matrix[pos.y * (height + 1) + pos.x] = '.';
				pos.x++;
			}
			pos.y++;
		}
	}
	return (1);
}

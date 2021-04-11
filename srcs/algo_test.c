
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


#define MATRIX_SIZE 1024U

static uint_op_t    mat_static[MATRIX_SIZE * (MATRIX_SIZE + 1)];

static uint_op_t*   mat = mat_static;

static uint_size_t  mat_size = 0;

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
	t_pos                   pos;
	t_pos                   end;

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
		pos.y = streak.pos.y;
		end.y = streak.pos.y + streak.size;
		end.x = streak.pos.x + streak.size;
		while (pos.y < end.y)
		{
			pos.x = streak.pos.x;
			while (pos.x < end.x && mat[pos.y * (mat_size + 1) + pos.x] == streak.height)
				pos.x++;
			if (pos.x < end.x)
				return (0);
			pos.y++;
		}
		return (1);
	}
}

void square_find()
{
	t_pos		pos;
	t_streak	biggest;
	t_streak	streak;

	biggest = (t_streak){{0, 0}, 1, mat[0]};
	streak = (t_streak){{0, 0}, 1, mat[0]};

	pos.y = 0;
	while (pos.y != mat_size)
	{
		pos.x = 0;
		if (streak.size > biggest.size && same_height(streak))
			biggest = streak;
		streak = (t_streak){pos, 1, mat[pos.y * (mat_size + 1) + pos.x]};
		while (pos.x != mat_size)
		{
			if (mat[pos.y * (mat_size + 1) + pos.x] == streak.height)
				streak.size++;
			else
			{
				if (streak.size > biggest.size && same_height(streak))
					biggest = streak;
				streak = (t_streak){pos, 1, mat[pos.y * (mat_size + 1) + pos.x]};
			}
			pos.x++;
		}
		pos.y++;
	}
	printf("streak size: %lu\n", streak.size);
	if (streak.size != 0)
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
				mat[pos.y * (mat_size + 1) + pos.x] = '.';
				pos.x++;
			}
			pos.y++;
		}
	}
}

#define TEST_DATA "\
0111222222\n\
0111222222\n\
0111222222\n\
0122232222\n\
0122222222\n\
0122222222\n\
0122222222\n\
0122222222\n\
0122222222\n\
0122222222\n\
0122222222\n\
0122222222\n"

int main()
{
	mat_size = 10;

	memcpy(mat_static, TEST_DATA, sizeof(TEST_DATA) - 1);

	square_find();
	write(1, mat_static, mat_size * (mat_size + 1));
	return (0);
}
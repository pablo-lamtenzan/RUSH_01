#ifndef SQUARE_H
# define SQUARE_H

#include <local_types.h>

typedef struct	s_pos
{
	uint_size_t	y;
	uint_size_t	x;
}				t_pos;

typedef struct	t_streak
{
	t_pos		pos;
	uint_size_t	size;
	uint_op_t	height;
}				t_streak;

int	find_the_square(t_streak *dest);

#endif
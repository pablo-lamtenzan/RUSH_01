#ifndef SQUARE_H
# define SQUARE_H

#include <local_types.h>

typedef struct	s_pos
{
	t_uint_size	y;
	t_uint_size	x;
}				t_pos;

typedef struct	t_streak
{
	t_pos		pos;
	t_uint_size	size;
	t_uint_op	height;
}				t_streak;

int	find_the_square(t_streak *dest);

#endif
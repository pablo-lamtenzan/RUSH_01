#include <square.h>
#include <string.h>
#include <unistd.h>

#include <local_mem.h>

uint_op_t	same_height(t_streak *streak)
{
	t_pos			pos;
	t_pos			end;

	pos.y = streak->pos.y;
	end.y = streak->pos.y + streak->size;
	end.x = streak->pos.x + streak->size;
	while (pos.y < end.y)
	{
		pos.x = streak->pos.x;
		while (pos.x < end.x
			&& matrix[pos.y * (height + 1) + pos.x] == streak->height)
			pos.x++;
		if (pos.x < end.x)
			return (0);
		pos.y++;
	}
	return (1);
}

void		find_streak(t_streak *streak, t_pos *pos, uint_size_t biggest_size)
{
	*streak = (t_streak){*pos, 0, matrix[pos->y * (height + 1) + pos->x]};
	while (pos->x != height
	&& matrix[pos->y * (height + 1) + pos->x] == streak->height)
		(pos->x)++;
	streak->size = pos->x - streak->pos.x;
	if (streak->size > height - pos->y)
		streak->size = height - pos->y;
	while (streak->size > biggest_size && !same_height(streak))
	{
		(streak->pos.x)++;
		streak->size--;
	}
}

int			find_the_square(t_streak *dest)
{
	t_pos		pos;
	t_streak	biggest;
	t_streak	streak;

	pos = (t_pos){0, 0};
	biggest = (t_streak){{0, 0}, 1, matrix[0]};
	while (pos.y != height)
	{
		find_streak(&streak, &pos, biggest.size);
		if (streak.size > biggest.size)
		{
			biggest = streak;
			if (height - pos.y < biggest.size)
				break ;
		}
		if (height - pos.x < biggest.size)
		{
			pos.x = 0;
			pos.y++;
			if (height - pos.y < biggest.size)
				break ;
		}
	}
	*dest = biggest;
	return (1);
}

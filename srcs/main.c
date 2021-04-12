#include <unistd.h>
#include <local_mem.h>
#include <square.h>
#include <stdlib.h>

t_uint_op   *g_matrix = NULL;
t_uint_size g_dynamic_lenght = 0;
t_uint_size g_height = 0;
t_uint_op   g_ascii = 0;

int print_matrix()
{
	return (write(STDOUT_FILENO, g_matrix, g_height * (g_height + 1)) != -1);
}

int mark_the_square(t_streak *biggest)
{
	const t_pos	end =
		{biggest->pos.x + biggest->size, biggest->pos.y + biggest->size};
	t_pos   	pos;

	if (biggest->size != 1)
	{	
		pos.y = biggest->pos.y;
		while (pos.y < end.y)
		{
			pos.x = biggest->pos.x;
			while (pos.x < end.x)
			{
				g_matrix[pos.y * (g_height + 1) + pos.x] = g_ascii;
				pos.x++;
			}
			pos.y++;
		}
	}
	else
		g_matrix[0] = g_ascii;
	return (1);
}

int main()
{
	static t_streak streak;

	const int   err = !(mem_read_stdin()
		&& find_the_square(&streak)
		&& mark_the_square(&streak)
		&& print_matrix());
	free(g_matrix);
	return (err);
} 
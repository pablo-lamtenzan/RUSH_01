#include <unistd.h>
#include <local_mem.h>
#include <square.h>
#include <stdlib.h>

uint_op_t   static_matrix[STATIC_ROOM]; // 8
uint_op_t   *dynamic_matrix = NULL;
uint_op_t   *matrix = static_matrix; // 8
uint_size_t dynamic_lenght = 0; // 8
uint_size_t height = 0; // 8
uint_op_t   ascii = 0; // 4


int print_matrix()
{
	return (write(STDOUT_FILENO, matrix, height * (height + 1)) != -1);
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
				matrix[pos.y * (height + 1) + pos.x] = ascii;
				pos.x++;
			}
			pos.y++;
		}
	}
	else
		matrix[0] = ascii;
	return (1);
}

int main()
{
	static t_streak streak;

	const int   err = !(mem_read_stdin()
		&& find_the_square(&streak)
		&& mark_the_square(&streak)
		&& print_matrix());
	free(dynamic_matrix);
	return (err);
} 
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 00:01:59 by chamada           #+#    #+#             */
/*   Updated: 2021/04/12 21:20:26 by chamada          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <local_mem.h>
#include <square.h>
#include <stdlib.h>

t_uint_op	*g_matrix = NULL;
t_uint_size	g_dynamic_lenght = 0;
t_uint_size	g_height = 0;
t_uint_op	g_ascii = 0;

int	print_matrix(void)
{
	return (write(STDOUT_FILENO, g_matrix, g_height * (g_height + 1)) != -1);
}

int	mark_the_square(t_streak *biggest)
{
	t_pos		pos;
	const t_pos	end = \

	{biggest->pos.y + biggest->size, biggest->pos.x + biggest->size};
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

int	main(void)
{
	static t_streak	streak;
	const int		err =\

	!(mem_read_stdin()
		&& find_the_square(&streak)
		&& mark_the_square(&streak)
		&& print_matrix());
	free(g_matrix);
	return (err);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   local_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 22:54:59 by pablo             #+#    #+#             */
/*   Updated: 2021/04/12 22:56:48 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <local_mem.h>
#include <stdlib.h>

static inline int	is_digit(int ascii)
{
	return ((ascii >= '0') & (ascii <= '9'));
}

static t_uint_size	ft_atoi(const char *s)
{
	t_uint_size number;

	number = 0;
	while (is_digit(*s))
		number = number * 10 + *s++ - '0';
	return (number);
}

static t_uint_size	read_stdin_line_to_integer(bool convert)
{
	t_uint_size	bytes;
	t_uint_op	index;
	t_uint_op	data[32UL];

	bytes = 0;
	index = 0;
	while (((bytes = read(STDIN_FILENO, data + index, 1UL)) == 1)
	& (*(data + index) != '\n'))
		++index;
	if (bytes == 1)
	{
		if (convert)
			return (ft_atoi((char *)data));
		else
			return (*data);
	}
	return (0);
}

bool				read_stdin_into(t_uint_op *matrix, t_uint_size bytes)
{
	t_uint_size	read_bytes;
	t_uint_size	index;

	index = 0;
	while (index < bytes)
	{
		read_bytes = read(STDIN_FILENO, matrix + index, bytes);
		if (read_bytes <= 0)
			break ;
		index += read_bytes;
	}
	return (index == bytes);
}

bool				mem_read_stdin(void)
{
	t_uint_size	bytes;

	g_height = read_stdin_line_to_integer(true);
	if (g_height)
	{
		g_ascii = (t_uint_op)read_stdin_line_to_integer(false);
		if (g_ascii)
		{
			bytes = g_height * (g_height + 1UL);
			if (!(g_matrix = malloc(sizeof(*g_matrix) * bytes)))
				return (false);
			return (read_stdin_into(g_matrix, bytes));
		}
	}
	return (false);
}

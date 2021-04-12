/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chamada <chamada@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 04:03:26 by chamada           #+#    #+#             */
/*   Updated: 2021/04/12 21:20:26 by chamada          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUARE_H
# define SQUARE_H

# include <local_types.h>

typedef struct	s_pos
{
	t_uint_size	y;
	t_uint_size	x;
}				t_pos;

typedef struct	s_streak
{
	t_pos		pos;
	t_uint_size	size;
	t_uint_op	height;
}				t_streak;

int				find_the_square(t_streak *dest);

#endif

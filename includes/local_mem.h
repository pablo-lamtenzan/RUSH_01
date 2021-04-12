/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   local_mem.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 19:31:13 by plamtenz          #+#    #+#             */
/*   Updated: 2021/04/12 22:57:16 by plamtenz         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOCAL_MEM_H
# define LOCAL_MEM_H

# include <stdbool.h>
# include <local_types.h>

extern t_uint_op	*g_matrix;
extern t_uint_size	g_height;
extern t_uint_op	g_ascii;

bool				mem_read_stdin();

#endif

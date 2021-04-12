/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   local_mem.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 22:45:37 by pablo             #+#    #+#             */
/*   Updated: 2021/04/12 22:52:30 by pablo            ###   ########.fr       */
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


# pragma once

# include <stdbool.h>
# include <local_types.h>

# define STATIC_ROOM 1024UL * (1024UL + 1UL)

uint_op_t   static_matrix[STATIC_ROOM];
uint_op_t*  dynamic_matrix = static_matrix;
uint_size_t dynamic_lenght = 0;

bool   mem_read_stdin(uint_size_t mat_height);

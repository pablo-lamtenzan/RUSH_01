
# pragma once

# include <stdbool.h>
# include <local_types.h>

# define HEIGHT 1024UL
# define STATIC_ROOM (HEIGHT * (HEIGHT + 1UL))

uint_op_t   static_matrix[STATIC_ROOM]; // 8
uint_op_t*  dynamic_matrix = (void*)0UL; // 8
uint_size_t dynamic_lenght = 0; // 8
uint_size_t height = 0; // 8
uint_op_t   ascii = 0; // 4

bool   mem_read_stdin();


# pragma once

# include <stdbool.h>
# include <local_types.h>

# define HEIGHT 1024UL
# define STATIC_ROOM (HEIGHT * (HEIGHT + 1UL))

extern uint_op_t   static_matrix[STATIC_ROOM]; // 8
extern uint_op_t*  dynamic_matrix; // 8
extern uint_op_t*  matrix; // 8
extern uint_size_t height; // 8
extern uint_op_t   ascii; // 4

bool   mem_read_stdin();


# pragma once

# include <stdbool.h>
# include <local_types.h>


# define HEIGHT 0//(1UL << 12)
# define STATIC_ROOM (HEIGHT * (HEIGHT + 1UL))

extern uint_op_t*  matrix; // 8
extern uint_size_t height; // 8
extern uint_op_t   ascii; // 4

bool   mem_read_stdin();


# ifndef LOCAL_MEM_H
# define LOCAL_MEM_H

# include <stdbool.h>
# include <local_types.h>

extern uint_op_t        *matrix;
extern uint_size_t      height;
extern uint_op_t        ascii;

bool   mem_read_stdin();

#endif

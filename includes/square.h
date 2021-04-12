/** @file square.h
 * 
 *  A square can be stored in a @p uint_size_t.
 *  - 4 first bytes represent the border size.
 *  - 4 last bytes represent the last 4 bytes of the address of top left corner.
*/

# pragma once

# include <local_types.h>
# include <stdbool.h>

# define MACTH true

/**
 * @brief Represent a square in the matrix.
 * @member: coord, the position in the matrix of the %t_sq.
 * @member: height the of the size.
 *
 */
typedef struct  sq
{
    uint_size_t height;
    struct
    {
        uint_size_t y;
        uint_size_t x;
    };
}               t_sq;

<<<<<<< HEAD
extern uint_size_t mask;

bool        write_the_square(t_sq* const sq)  __attribute__((pure));
bool        find_the_square(t_sq* const sq, uint_size_t* const matrix, uint_size_t matrix_lenght) __attribute__((pure));
=======
/// Prepend ( into @p pointer ) @p size, sizeof(sq_size_t) into @p pointer dereference (sizeof(uint_size_t))
# define INJECT_SIZE(size, pointer) inject_append_4b_data(size, pointer)
/// Represent the size stored in @p pointer .
# define EXTRACT_SIZE(pointer) ((uint_size_t)(pointer >> (sizeof(uint_size_t) / 2UL)))
/// @p pointer takes the value of it original address.
# define EXTRACT_ADDR(pointer, hint) inject_append_4b_data((sq_size_t)(hint >> (sizeof(uint_size_t) / 2UL), pointer))

void        inject_prepend_4b_data(sq_size_t data, uint_size_t*const pointer);
sq_print_t  create_sq_print(uint_size_t sq, const uint_op_t* const min_x, const uint_op_t* const max_x, uint_op_t ascii, sq_size_t hint);
//void        write_sq(sq_print_t* const sq);


// NEW VERSION
bool        insert_square(t_sq* const sq)  __attribute__((pure));
>>>>>>> 87c3f5fee0ccdfd8664bb318a570fd5b2763c2d0

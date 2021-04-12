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

extern uint_size_t mask;

bool    write_the_square(t_sq* const sq)  __attribute__((pure));
int     find_the_square(t_sq *square);
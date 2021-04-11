/** @file square.h
 * 
 *  A square can be stored in a @p uint_size_t.
 *  - 4 first bytes represent the border size.
 *  - 4 last bytes represent the last 4 bytes of the address of top left corner.
*/

# pragma once

# include <local_types.h>
# include <stdbool.h>

/** 
 *  @brief struct used for print a square
 *  @member: sq_left_corner: The address of the top left corner.
 *  @member: sq_height: The height of the square.
 *  @member: ascii: The ascii character used to fill the square.
 *  @member: min_x: The address of start of the line.
 *  @member: max_x: The address of the end of the line.
 *  NOTE: size is 40 bytes.
*/
typedef struct  sq_print
{
    uint_op_t* const        sq_left_corner;
    uint_size_t             sq_height;
    uint_op_t               ascii;
    struct
    {
        uint_op_t* const    min_x;
        uint_op_t* const    max_x;
    };
}               sq_print_t;

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

/// Prepend ( into @p pointer ) @p size, sizeof(sq_size_t) into @p pointer dereference (sizeof(uint_size_t))
# define INJECT_SIZE(size, pointer) inject_append_4b_data(size, pointer)
/// Represent the size stored in @p pointer .
# define EXTRACT_SIZE(pointer) ((uint_size_t)(pointer >> (sizeof(uint_size_t) / 2UL)))
/// @p pointer takes the value of it original address.
# define EXTRACT_ADDR(pointer, hint) inject_append_4b_data((sq_size_t)(hint >> (sizeof(uint_size_t) / 2UL), pointer))

void        inject_prepend_4b_data(sq_size_t data, uint_size_t*const pointer);
sq_print_t  create_sq_print(uint_size_t sq, const uint_op_t* const min_x, const uint_op_t* const max_x, uint_op_t ascii, sq_size_t hint);
void        write_sq(sq_print_t* const sq);


// NEW VERSION
bool        write_the_square(t_sq* const sq)  __attribute__((pure));
/**
 *  @file square.c
 *  @brief square.h definitions.
*/

# include <optimised_lib.h>
# include <local_mem.h>

/**
 *  @brief injects @p size into the first to the midle bits
 *  of @p pointer.
 *  @p pointer must be a reference to a @a uint_size_t .
*/
inline void
inject_prepend_4b_data(sq_size_t data, uint_size_t*const pointer)
{
    sq_size_swap(&data, (sq_size_t*const)pointer);
    *pointer <<= (sizeof(uint_size_t) / 2UL);
    sq_size_swap(&data, (sq_size_t*const)pointer);
}

# include <square.h>

// If this is expensive just literally inline the code.
inline sq_print_t
create_sq_print(uint_size_t sq, const uint_op_t* const restrict min_x, const uint_op_t* const restrict max_x, uint_op_t ascii, sq_size_t hint)
{    
    sq_print_t obj = (sq_print_t){
        .sq_height = EXTRACT_SIZE(sq),
        .ascii = ascii,
        .min_x = min_x,
        .max_x = max_x
    };
    EXTRACT_ADDR((uint_size_t*const)&obj.sq_left_corner, hint);
    return (obj);
}

/**
 *  @brief writes the square @p sq in the matrix.
 *  NOTE: All loops compare to 0 (the less expensive solution).
*/
void
write_sq(sq_print_t* const sq)
{
    uint_size_t distance = (sq->max_x - sq->sq_left_corner) + ((sq->sq_left_corner + sq->sq_height) - sq->max_x);
    uint_op_t* x = sq->sq_left_corner;

    for (uint_size_t y = sq->sq_height ; y-- ;)
    {
        for (uint_size_t amount = sq->sq_height ; amount-- ;)
            *(x + amount) = sq->ascii;
        x += distance;
    }
}


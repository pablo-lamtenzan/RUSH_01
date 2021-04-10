/**
 *  @file square.c
 *  @brief square.h definitions.
*/

# include <optimised_lib.h>

/**
 *  @brief injects @p size into the first to the midle bits
 *  of @p pointer.
 *  @p pointer must be a reference to a @a uint_size_t .
*/
inline void inject_append_4b_data(sq_size_t data, uint_size_t*const pointer)
{
    sq_size_swap(&data, (sq_size_t*const)pointer);
    *pointer <<= (sizeof(uint_size_t) / 2UL);
    sq_size_swap(&data, (sq_size_t*const)pointer);
}


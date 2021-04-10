/** @file square.h
 * 
 *  A square can be stored in a @p uint_size_t.
 *  - 4 first bytes represent the border size.
 *  - 4 last bytes represent the last 4 bytes of the top left corner.
*/

# pragma once

# include <local_types.h>

/// Prepend ( into @p pointer ) @p size, sizeof(sq_size_t) into @p pointer dereference (sizeof(uint_size_t))
# define INJECT_SIZE(size, pointer) inject_append_4b_data(size, pointer)
/// Repres
# define EXTRACT_SIZE(pointer) ((uint_size_t)(pointer >> (sizeof(uint_size_t) / 2UL)))
# define EXTRACT_ADDR(pointer, hint) inject_append_4b_data((sq_size_t)(hint >> (sizeof(uint_size_t) / 2UL), pointer)

void inject_append_4b_data(sq_size_t data, uint_size_t**const pointer);
/** @file optimised_lib.c
 * 
 *  @brief contains an fast lib definition.
*/

# include <local_types.h>

/** @brief swap @p lhs and @p rhs dereferences.
 *  NOTE: @p lhs and @p rhs can not be the same object.
 *  Specilized version swaps objects of @a uint_op_t types.
*/
inline void op_swap(uint_op_t* const restrict lhs, uint_op_t* const restrict rhs)
{
    *lhs += *lhs + *rhs;
    *rhs = *lhs - *rhs;
    *lhs -= *rhs;
}

/** @brief swap @p lhs and @p rhs dereferences.
 *  NOTE: @p lhs and @p rhs can not be the same object.
 *  Specilized version swaps objects of @a uint_size_t types.
*/
inline void u_size_swap(uint_size_t* const restrict lhs, uint_size_t* const restrict rhs)
{
    *lhs += *lhs + *rhs;
    *rhs = *lhs - *rhs;
    *lhs -= *rhs;
}

/** @brief swap @p lhs and @p rhs dereferences.
 *  NOTE: @p lhs and @p rhs can not be the same object.
 *  Specilized version swaps objects of @a int_size_t types.
*/
inline void s_size_swap(int_size_t* const restrict lhs, int_size_t* const restrict rhs)
{
    *lhs += *lhs + *rhs;
    *rhs = *lhs - *rhs;
    *lhs -= *rhs;
}

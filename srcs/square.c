/**
 *  @file square.c
 *  @brief square.h definitions.
*/

# include <square.h>
# include <local_mem.h>
# include <uint_64_masks.h>

/**
 *  @brief Map an address and return a @p t_sq 
 *  @param top_left_corner_addr The top left corner address of the square.
 *  @param height The height of the square.
*/
t_sq store_square(int_size_t* const top_left_corner_addr, int_size_t height)
{
    // TO DO: Possible long allignent makes errors
    t_sq sq = (t_sq){
        .y = (top_left_corner_addr - static_matrix) / height,
        .x = 0UL, // TO DO
        .height = height
    };
    return (sq);
}

/**
 *  @brief Test the current mask with @p target
*/
static inline
bool apply_mask(int_size_t* const target)
{
    return (*target & mask);
}

/**
 *  @brief Check the legitimity of a potential square
 *  @param top_left_corner The top side of the square.
 *      pointer (points to the first element).
 *  @param bot_left_corner The bootom of the sqaure
 *      pointer (points to the first element).
*/
static bool
square_verification(int_size_t* const top_left_corner, int_size_t* const bot_left_corner)
{
    // bot_left_corner is bad called, allignment
    // TO DO: allignment can cause errors
    uint_size_t allignment = (bot_left_corner - top_left_corner) / sizeof(allignment);
    uint_size_t* it =  top_left_corner + allignment;
    
    if (apply_mask(bot_left_corner) == MACTH) 
    {
        while (it - bot_left_corner)
        {
            // TO DO: unrolled version
            if (apply_mask(it) != MACTH)
                return (false);
            it += allignment;
        }
        return (true);
    }
    return (false);
}

/**
 *  @brief Iterates over a familly of masks,
 *  set mask_ptr to the lefther mask possible.
 *  Start iterating from the right.
 *  
 *  @param fam_first The first member of the familly.
 *  @param data The data to be compared.
*/
bool test_familly_masks_left(uint_size_t* const fam_first, uint_size_t* data)
{
    bool matched;

    matched = false;
    mask_ptr = fam_first;
    while (mask_ptr - fam_first + U64_SMASK_FAMILLY_INDEX * FAMILLY_MEMBERS)
    {
        if (/* MASK MATCH */0)
            matched = true;
        if (matched && /* NO MATCH */0)
        {
            mask_ptr -= U64_SMASK_FAMILLY_INDEX;
            break ;
        }
        mask_ptr += U64_SMASK_FAMILLY_INDEX;
    }
} // TO DO, The same but starting from the left

bool test_size_masks_left(uint_size_t* const fam_first, uint_size_t* data)
{
    /*
        iterate over a size (size == alignment)
        e.g. 0xff00 maches size with 0xee00
    */
}

bool find_mask(uint_size_t* const target, uint_size_t height)
{
    // The amount of the previous iteration right bytes match
    static uint_size_t prev_room = 0;

    if (prev_room)
    {
        height -= prev_room;
        // Check using the height - prev_room left matches
        // Uses the previous mask (loadded "in my chache") as hint for use it familly
        // ALLIGN MASKS USING it familly
    }
    else
    {
        // Search a height all the mask with >= sizes
        // ALLIGN MASKS USING it size
    }
}

bool find_the_square(t_sq* const sq, uint_size_t* const matrix, uint_size_t matrix_lenght)
{
    uint_size_t* it;
    uint_size_t curr_height;

    it = matrix;
    curr_height = 2;
    mask_ptr = (void*)0UL;
    while (it - matrix + matrix_lenght)
    {
        // COND JUMP HERE FOR > 8 MASK LOOP
        while (find_mask(it, curr_height) == MACTH)
        {
            if (square_verification(it, it + height * curr_height) == MACTH) // check for the square legitimity)
                *sq = store_square(it, curr_height); // store the square in a abtract representation
            curr_height++; // can do better ?

        }
        // TO DO: it incrementation influenced by curr_height
    }
    return (true);
}

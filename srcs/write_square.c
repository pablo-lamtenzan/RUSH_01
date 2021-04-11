
# include <square.h>
# include <local_mem.h>


static inline void
write_x8(uint_op_t* const it, uint_size_t* const lenght, uint_size_t remember_lenght)
{
    while (*lenght - 8UL)
    {
        it[*lenght - remember_lenght - 7UL] = ascii;
        it[*lenght - remember_lenght - 6UL] = ascii;
        it[*lenght - remember_lenght - 5UL] = ascii;
        it[*lenght - remember_lenght - 4UL] = ascii;
        it[*lenght - remember_lenght - 3UL] = ascii;
        it[*lenght - remember_lenght - 2UL] = ascii;
        it[*lenght - remember_lenght - 1UL] = ascii;
        it[*lenght - remember_lenght] = ascii;
        *lenght -= 8UL;
    }
}

static inline void
write_x4(uint_op_t* const it, uint_size_t* const lenght, uint_size_t remember_lenght)
{
    while (*lenght - 4UL)
    {
        it[*lenght - remember_lenght - 3UL] = ascii;
        it[*lenght - remember_lenght - 2UL] = ascii;
        it[*lenght - remember_lenght - 1UL] = ascii;
        it[*lenght - remember_lenght] = ascii;
        *lenght -= 4UL;
    }
}

static inline void
write_x2(uint_op_t* const it, uint_size_t* const lenght, uint_size_t remember_lenght)
{
    while (*lenght - 2UL)
    {
        it[*lenght - remember_lenght - 1UL] = ascii;
        it[*lenght - remember_lenght] = ascii;
        *lenght -= 2UL;
    }
}

static void write_x_axis(uint_op_t* const it, uint_size_t lenght)
{
    const uint_size_t remember_lenght = lenght;

    // IF THAT IS BETTER CAN INCREAMENT
    // IT THAT IS BETTER CAN BE USED TO WRITE THE MATRIX AT THE END
    if (lenght - 8UL)
        write_x8(it, &lenght, remember_lenght);
    if (lenght - 4UL)
        write_x4(it, &lenght, remember_lenght);
    if (lenght - 2UL)
        write_x2(it, &lenght, remember_lenght);
    if (lenght)
        it[lenght - remember_lenght] = ascii;
}

bool write_the_square(t_sq* const sq) 
{
    uint_op_t* it;
    uint_size_t steps;

    it = &static_matrix[sq->y * height + sq->x];
    steps = height;
    while (steps--)
    {
        write_x_axis(it, height);
        it += height;
    }
    return (true);
}

# include <local_mem.h>
# include <square.h>

int main()
{
    static t_sq sq = {0};
    return (mem_read_stdin()
    && find_the_square(&sq)
    && write_the_square(&sq, static_matrix)
    && print_matrix());
} 
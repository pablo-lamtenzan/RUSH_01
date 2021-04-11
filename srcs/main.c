
# include <local_mem.h>
# include <square.h>

int main()
{
    static t_sq sq = {0};
    return (mem_read_stdin()
    && find_the_square(&sq)
    && insert_square(&sq)
    && print_matrix());
} 
#include <unistd.h>
#include <local_mem.h>
#include <stdlib.h>

uint_op_t   *matrix = NULL;
uint_size_t dynamic_lenght = 0;
uint_size_t height = 0;
uint_op_t   ascii = 0;

int print_matrix()
{
    return (write(STDOUT_FILENO, matrix, height * (height + 1)) != -1);
}

int main()
{
    static t_sq sq = {0};
    const int   err = !(mem_read_stdin()
        && find_the_square(&sq)
    // && write_the_square(&sq, static_matrix)
        && print_matrix());
    free(dynamic_matrix);
    return (err);
} 
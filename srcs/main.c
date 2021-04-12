#include <unistd.h>
#include <local_mem.h>
#include <square.h>

uint_op_t   static_matrix[STATIC_ROOM]; // 8
uint_op_t*  dynamic_matrix = NULL; // 8
uint_size_t dynamic_lenght = 0; // 8
uint_size_t height = 0; // 8
uint_op_t   ascii = 0; // 4

int find_the_square(t_sq *square);

int print_matrix()
{
    return (write(STDOUT_FILENO, static_matrix, height * (height + 1)) != -1);
}

int main()
{
    static t_sq sq = {0};
    return (mem_read_stdin()
    && find_the_square(&sq)
    && write_the_square(&sq, static_matrix)
    && print_matrix());
} 
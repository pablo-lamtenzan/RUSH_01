
# include <unistd.h>
# include <local_mem.h>
# include <stdlib.h>

bool   mem_read_stdin(uint_size_t mat_height)
{
    // It is better to read by chuncks ?

    uint_size_t bytes;

    bytes = mat_height * mat_height;

    bytes -= read(STDIN_FILENO, static_matrix, STATIC_ROOM);
    if (bytes >= mat_height)
        return (false);
    if (bytes)
    {
        dynamic_lenght = bytes;
        if (!(dynamic_matrix = malloc(sizeof(*dynamic_matrix) * dynamic_lenght)))
            return (false);
        bytes -= read(STDIN_FILENO, dynamic_matrix, dynamic_lenght);
    }
    return (bytes == 0);
}
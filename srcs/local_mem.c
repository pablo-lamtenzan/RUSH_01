
# include <unistd.h>
# include <local_mem.h>
# include <stdlib.h>

static inline is_digit(int ascii)
{
    return ((ascii >= '0') & (ascii <= '9'));
}

/**
 *  @brief Specilized atoi, only for possive numbers.
 *  @error: O is returned. 
 *  NOTE: \n used as delimiters.
*/
static uint_size_t ft_atoi(const char*const s)
{
    uint_size_t number;
    uint_size_t index;

    number = 0;
    index = 0;
    while (is_digit(*(s + index)))
        number = number * 10 + *(s + index) - '0';
    return (number);
}

/**
 *  @brief Read a line from stdin a return an integer
 * 
 *  Read data by chunks of 1 bytes until \n.
 *  @p convert Indicates if the read bytes need to be atoi.
 *  @error: 0 is returned.
*/
static uint_op_t read_stdin_line_to_integer(bool convert)
{
    uint_size_t bytes;
    uint_op_t   index;
    uint_op_t   data[32UL];

    bytes = 0;
    index = 0;
    while (((bytes = read(STDIN_FILENO, data + index, 1UL)) > 0L)
    & (*(data + index) != '\n'))
        ++index;
    return (convert ? ft_atoi(data) : *data);
}

/**
 *  @brief Read from stdin and save into memory:
 *  - The matrix height.
 *  - The given ascii.
 *  - The matrix.
 * 
 *  Store into compile time memory the size of @a STATIC_ROOM
 *  data.
 *  The remaining data (if exists) is stored into dynamic memory.
*/
bool        mem_read_stdin()
{
    int_size_t bytes;

    height = read_stdin_line_to_integer(true);
    ascii = read_stdin_line_to_integer(false);
    bytes = height * height;
    if (height & ascii)
    {
        bytes -= read(STDIN_FILENO, static_matrix, STATIC_ROOM);
        if (bytes >= height)
            return (false);
        if (bytes)
        {
            dynamic_lenght = bytes;
            if (!(dynamic_matrix = malloc(sizeof(*dynamic_matrix) * dynamic_lenght)))
                return (false);
            bytes -= read(STDIN_FILENO, dynamic_matrix, dynamic_lenght);
        }
    }
    return (bytes == 0);
}
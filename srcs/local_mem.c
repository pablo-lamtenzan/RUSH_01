
# include <unistd.h>
# include <local_mem.h>
# include <stdlib.h>

static inline int is_digit(int ascii)
{
	return ((ascii >= '0') & (ascii <= '9'));
}

/**
 *  @brief Specilized atoi, only for possive numbers.
 *  @error: O is returned. 
 *  NOTE: \n used as delimiters.
*/
static uint_size_t ft_atoi(const char* s)
{
	uint_size_t number;

	number = 0;
	while (is_digit(*s))
		number = number * 10 + *s++ - '0';
	return (number);
}

/**
 *  @brief Read a line from stdin a return an integer
 * 
 *  Read data by chunks of 1 bytes until \n.
 *  @p convert Indicates if the read bytes need to be atoi.
 *  @error: 0 is returned.
*/
static uint_size_t read_stdin_line_to_integer(bool convert)
{
	uint_size_t bytes;
	uint_op_t   index;
	uint_op_t   data[32UL];

	bytes = 0;
	index = 0;
	while (((bytes = read(STDIN_FILENO, data + index, 1UL)) == 1)
	& (*(data + index) != '\n'))
		++index;
	if (bytes == 1)
	{
		if (convert)
			return ft_atoi(data);
		else
			return *data;
	}
	return (0);
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
#include <stdio.h>

bool		read_stdin_into(uint_op_t *matrix, uint_size_t bytes)
{
	uint_size_t	read_bytes;
	uint_size_t	index;

	index = 0;
	while (index < bytes)
	{
		read_bytes = read(STDIN_FILENO, matrix + index, bytes);
		if (read_bytes <= 0)
			break;
		index += read_bytes;
	}
	return (index == bytes);
}

bool        mem_read_stdin()
{
	uint_size_t	bytes;

	height = read_stdin_line_to_integer(true);
	if (height)
	{
		ascii = (uint_op_t)read_stdin_line_to_integer(false);
		if (ascii)
		{
			bytes = height * (height + 1);
			if (bytes > STATIC_ROOM)
			{
				if (!(matrix = malloc(sizeof(*matrix) * bytes)))
					return (false);
			}
			return (read_stdin_into(matrix, bytes));
		}
	}
	return (false);
}


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
	uint_size_t	bytes_static;
	uint_size_t	bytes_dynamic;

	height = read_stdin_line_to_integer(true);
	if (height)
	{
		ascii = (uint_op_t)read_stdin_line_to_integer(false);
		printf("height: %zu, ascii: '%c'\n", height, ascii);
		if (ascii)
		{
			bytes_static = height * (height + 1);
			printf("Reading %zu bytes...\n", bytes_static);
			if (bytes_static < STATIC_ROOM)
				bytes_dynamic = 0;
			else
			{
				bytes_dynamic = bytes_static - STATIC_ROOM;
				bytes_static = STATIC_ROOM;
			}
			read_stdin_into(static_matrix, bytes_static);
			dynamic_matrix = malloc(sizeof(*dynamic_matrix) * dynamic_lenght);
			if (!dynamic_matrix)
				return (false);
			dynamic_lenght = bytes_dynamic;
			read_stdin_into(dynamic_matrix, bytes_dynamic);
		}
	}
	return (true);
}
/* 
bool        mem_read_stdin()
{
	int_size_t bytes;

	height = read_stdin_line_to_integer(true);
	ascii = read_stdin_line_to_integer(false);
	printf("height: %zu, ascii: '%c'\n", height, ascii);
	bytes = height * height;
	if (height && ascii)
	{
		bytes += height;
		bytes -= read(STDIN_FILENO, static_matrix, STATIC_ROOM);
		printf("Bytes left: %zd\n", bytes);
		if ((uint_size_t)bytes >= height)
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
} */
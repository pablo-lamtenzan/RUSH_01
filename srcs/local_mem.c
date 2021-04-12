
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
#include <stdio.h>

bool        mem_read_stdin()
{
	uint_size_t	bytes_static;
	uint_size_t	bytes_dynamic;
	uint_size_t	index;
	int_size_t	read_bytes;

	height = read_stdin_line_to_integer(true);
	ascii = read_stdin_line_to_integer(false);
	
	index = 0;
	if (height && ascii)
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
		while (bytes_static)
		{
			read_bytes = read(STDIN_FILENO, static_matrix + index, bytes_static);
			if (read_bytes <= 0)
				return (false);
			bytes_static -= read_bytes;
			index += read_bytes;
		}
		index = 0;
		while (bytes_dynamic)
		{
			dynamic_matrix = malloc(sizeof(*dynamic_matrix) * dynamic_lenght);
			if (!dynamic_matrix)
				return (false);
			read_bytes = read(STDIN_FILENO, dynamic_matrix + index, bytes_dynamic);
			if (read_bytes <= 0)
				return (false);
			bytes_dynamic -= read_bytes;
			index += read_bytes;
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

# include <unistd.h>
# include <local_mem.h>
# include <stdlib.h>

static inline int is_digit(int ascii)
{
	return ((ascii >= '0') & (ascii <= '9'));
}

static uint_size_t ft_atoi(const char* s)
{
	uint_size_t number;

	number = 0;
	while (is_digit(*s))
		number = number * 10 + *s++ - '0';
	return (number);
}

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
			if (!(matrix = malloc(sizeof(*matrix) * bytes)))
				return (false);
			return (read_stdin_into(matrix, bytes));
		}
	}
	return (false);
}

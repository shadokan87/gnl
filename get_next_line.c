#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char *stack[4094];
	char buff[BUFFER_SIZE];
	int file;
	char *tmp;

	tmp = NULL;
	if (fd < 0 || line == NULL)
		return (-1);
	while (1)
	{
		if (c_len(stack[fd], ENDL) > -1)
			break ;
		file = read(fd, buff, BUFFER_SIZE);
		if (file == 0)
			break ;
		buff[file] = '\0';
		if (file > 0)
		{
			stack[fd] = ft_realloc(stack[fd], file + (!stack[fd] ? 0 :
					c_len(stack[fd], '\0')) + 1 * sizeof(char));
			ft_memcpy_index((void**)&stack[fd], buff, c_len(stack[fd], '\0'));
		}
	}
	tmp = ft_realloc(tmp, c_len(stack[fd], '\0')) + 1 * sizeof(char);
	ft_memcpy_index((void**)&tmp, stack[fd], 0);
	*line = tmp;
	printf("GNL : %s", *line);
	return (1);
}

int	main(int argc, char **argv)
{
	int fd = open(argv[1], O_RDONLY);
	char *line;
	
	(void)argc;
	get_next_line(fd, &line);
	printf("\nmain : %s", line);
}

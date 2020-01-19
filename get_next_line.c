#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char *stack[4094];
	char buff[BUFFER_SIZE + 1];
	int file;
	char *tmp;
	int len;

	if (fd < 0 || line == NULL)
		return (-1);
	while (1)
	{
	if (stack[fd] && c_len(stack[fd], '\n') > -1)
		break ;
	len = 0;
	len = (stack[fd]) ? c_len(stack[fd], '\0') : len;
	file = read(fd, buff, BUFFER_SIZE);
	if (file == 0)
		break ;
	buff[file] = '\0';
	//if (!stack[fd])
		//stack[fd] = malloc(sizeof(char) * file + 1);
	if (!(stack[fd] = ft_realloc(stack[fd], sizeof(char) * len + file + 1)))
		return (0);
	ft_memcpy_index((void **)&stack[fd], buff, len, -1);
	}
	return (return_value(line, &stack[fd], file));
}

int	main(int argc, char **argv)
{
	int fd = open(argv[1], O_RDONLY);
	char *line;
	int ret;
	
	(void)argc;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
	printf("%s |%d|", line, ret);
	free(line);
	}
}

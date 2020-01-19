#include "get_next_line.h"

int		c_len(char *str, char c)
{
	int i;

	i = 0;
	if (!str)
		return (-1);
	if (c == '\0')
	{
		while (str[i])
			i++;
		return (i);
	}
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}


void	ft_memcpy_index(void **dst, void *src, size_t index, int max)
{
	unsigned char *c_dst = (unsigned char *)*dst;
	unsigned char *c_src = (unsigned char *)src;
	if (max == -1)
	{
		while (*c_src)
	{
		c_dst[index] = *c_src;
		*c_src ++ && index++;
	}
	c_dst[index] = *c_src;
	return ;
	}
	while (max)
	{
		c_dst[index] = *c_src;
		*c_src ++ && index++;
		max--;
	}
	c_dst[index] = 0;
}

//should realloc a pointer to the new size (size) like the original function
//if the pointer is equal to null, the pointer is just malloc'ed'
//if the (size) is less or eaqual to the len of the pointer, then the pointer is returned
//if the two conditions are null, a new void pointer (return_value) is malloc'ed' by the (size)
//ft_memcpy_index is used on the new pointer on index 0 with the pointer as source
//then the pointer is free'd' and the new pointer is returned;

void	*ft_realloc(void *ptr, size_t size)
{
	void	*return_value;

	if (!ptr)
		return (malloc(size));
	else if (size <= c_len((char *)ptr, '\0'))
		return (ptr);
	else
	{
		if (!(return_value = malloc(size)))
			return (0);
		ft_memcpy_index((void **)&return_value, ptr, 0, -1);
		free(ptr);
	}
	return (return_value);
}

int		return_value(char **line, char **stack, int file)
{
	char *tmp;

	if (c_len(*stack, ENDL) > -1)
	{
	*line = malloc(sizeof(char) * c_len(*stack, ENDL) + 1);
	ft_memcpy_index((void **)line, *stack, 0, c_len(*stack, ENDL));
	tmp = malloc(sizeof(char) * c_len(*stack, '\0') - c_len(*line, '\0'));
	ft_memcpy_index((void **)&tmp, &(*stack)[c_len(*stack, ENDL) + 1],0, -1);
	free(*stack);
	*stack = tmp;
	return (1);
	}
	if (*stack)
	{
		*line = malloc(sizeof(char) * c_len(*stack, '\0') + 1);
		ft_memcpy_index((void **)line, *stack, 0, -1);
		free(*stack);
		*stack = NULL;
		return (1);
	}
	return (0);
}

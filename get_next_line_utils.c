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

void	ft_memcpy_index(void **dst, void *src, size_t index)
{
	unsigned long src_index;
	unsigned char *c_dst;
	unsigned char *c_src;

	if (!src || !dst)
		return ;
	src_index = 0;
	c_dst = (unsigned char *)*dst;
	c_src = (unsigned char *)src;
	while (*c_src)
	{
		c_dst[index] = *c_src;
		c_src++ && index++;
	}
	c_dst[index] = *c_src;
}

//should realloc a pointer to the new size (size) like the original function
//if the pointer is equal to null, the pointer is just malloc'ed'
//if the (size) is less or eaqual to the len of the pointer, then the pointer is returned
//if the two conditions are null, a new void pointer (return_value) is malloc'ed' by the (size)
//ft_memcpy_index is used on the new pointer on index 0 with the pointer as source
//then the pointer is free'd' and the new pointer is returned;

void	*ft_realloc(void *ptr, size_t size)
{
	void *return_value;
	unsigned long i;
	unsigned char *c_ptr;

	i = 0;
	if (!ptr)
		return (malloc(size));
	c_ptr = (unsigned char *)ptr;
	while (c_ptr[i])
		i++;
	if (size <= i)
		return (ptr);
	if (!(return_value = malloc(size)))
		return (0);
	ft_memcpy_index(&return_value, ptr, 0);
	free(ptr);
	return (return_value);
}

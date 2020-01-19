#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define ENDL '\n'
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include "Memd/mem.h"

void	*ft_realloc(void *ptr, size_t size);
void	ft_memcpy_index(void **dst, void *src, size_t index);
int		c_len(char *str, char c);
#endif

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
#endif

char *get_next_line(int fd);
char *ft_realloc(char *saved);
char	*ft_strchr(const char *str, int search_str);


#endif


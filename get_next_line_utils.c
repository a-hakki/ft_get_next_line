#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int		i;

	i = 0;
    if (!str)
        return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *str1)
{
	int		i;
	char	*allocated;

	i = 0;
	allocated = malloc(sizeof(char) * ft_strlen(str1) + 1);
	if (!allocated)
		return (NULL);
	while (str1[i])
	{
		allocated[i] = str1[i];
		i++;
	}
	allocated[i] = '\0';
	return (allocated);
}

int ft_strchr(const char *str, int search_str)
{
	int	i;

	i = 0;
    if (!str)
        return (0);
	while (str[i])
	{
		if (str[i] == (char)search_str)
			return (i);
		i++;
	}
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
    if (!src)
        return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char *ft_realloc(char *saved)
{
    size_t size = 16;
    char *temp;

    
    while (size < BUFFER_SIZE + ft_strlen(saved) + 1)
        size *= 2;
    temp = malloc(size);
    if (!temp)
    {
        if (saved)
            free(saved);
        return (NULL);
    }
    ft_strcpy(temp, saved);
    if (saved)
            free(saved);
    return (temp);
}
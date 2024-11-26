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

void fireforce(char *s, char *a, char *d)
{
	free(s);
	free(a);
	free(d);
	s = NULL;
	a = NULL;
	d = NULL;

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
char	*ft_strncat(char *dest, char *src, size_t nb)
{
	size_t	i;
	size_t	n;

	i = ft_strlen(dest);
	n = 0;
	while (n < nb && src[n])
	{
		dest[i] = src[n];
		i++;
		n++;
	}
	dest[i] = '\0';
	return (dest);
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

char *ft_realloc(char *start)
{
    size_t size = 16;
    char *temp;

    while (size < BUFFER_SIZE + ft_strlen(start) + 1)
        size *= 2;
    temp = calloc(size + 1, 1);
    if (!temp)
    {
        if (start)
            free(start);
        return (NULL);
    }
	if (!start)
		return (temp);
    ft_strcpy(temp, start);
    // if (start)
    //         free(start); // ! double free
    return (temp);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*returned;
	size_t	slen;

	i = 0;
	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (len == 0 || start >= slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	returned = (char *)malloc(sizeof(char) * (len + 1));
	if (!returned)
		return (NULL);
	while (i < len)
	{
		returned[i] = s[start + i];
		i++;
	}
	returned[i] = '\0';
	free((char *)s);
	return (returned);
}
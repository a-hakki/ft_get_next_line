
#include "get_next_line.h"




char *get_next_line(int fd)
{
    static char     *saved;
    char            *temp = NULL;
    char        *allocated = NULL;
    int       readen_bites;
    size_t           check;

    allocated = malloc(BUFFER_SIZE + 1);
    if (!allocated)
        return (NULL);
    readen_bites = 1;
    temp = ft_realloc(saved);
    while (readen_bites > 0)
    {
        temp = ft_realloc(temp);
        readen_bites = read(fd, allocated, BUFFER_SIZE);
        allocated[readen_bites] = '\0';
        if (readen_bites <= 0)
        {
            if (readen_bites == 0)
                break;
            else
                return (free(allocated), free(saved) , saved = NULL, free(temp), NULL);
        }
        if (ft_strchr(allocated, '\n') != BUFFER_SIZE)
        {
            check = ft_strchr(allocated, '\n');
            temp = ft_strncat(temp, allocated, check + 1);
            saved = ft_strdup(allocated + check + 1);
            if(!saved)
                return (fireforce(saved, allocated, temp), NULL);
            break;
        }
        else
            temp = ft_strncat(temp, allocated, BUFFER_SIZE);
    }
    free(allocated);
    if (readen_bites == 0)
        return (free(temp), free(saved), saved = NULL, NULL);
    return(temp);

} 
int main()
{
    int fd = open("test.txt", O_RDONLY | O_CREAT, 0644);
    if (fd < 0)
        return (printf("fd failed\n"), 0);
    int i = 0; 
    char *s = get_next_line(fd);
    printf("[%d] : %s", ++i,s);
    free(s);
    s = get_next_line(fd);
    printf("[%d] : %s", ++i,s);
    free(s);
    s = get_next_line(fd);
    printf("[%d] : %s", ++i,s);
    free(s);
    s = get_next_line(fd);
    printf("[%d] : %s", ++i,s);
    free(s);
    s = get_next_line(fd);
    printf("[%d] : %s", ++i,s);
    free(s);
    s = get_next_line(fd);
    printf("[%d] : %s", ++i,s);
    free(s);
    s = get_next_line(fd);
    printf("[%d] : %s", ++i,s);
    free(s);
    
}
    // char *s = malloc(BUFFER_SIZE + 1);
    // if (!s)
    //     return (0);
    //     // ?????????????????????????????
    // int readen = read(fd, s, BUFFER_SIZE);
    // if (strchr(s, '\n'))
    // printf("the readen bites are : %d\nthe readen string is : %s\n\n", readen, s);
    // while (readen > 0)
    // {
    //     readen = read(fd, s, BUFFER_SIZE);
    //     printf("the readen bites are : %d\nthe readen string is : %s\n\n", readen, s);
    // }


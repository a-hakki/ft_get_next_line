
#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char     *saved;
    char            *temp;
    char        *allocated;
    int       readen_bites;
    size_t              check;

    allocated = malloc(BUFFER_SIZE + 1);
    if (!allocated)
        return (NULL);
    while (readen_bites > 0)
    {
        temp = ft_realloc(temp);
        readen_bites = read(fd, allocated, BUFFER_SIZE);
        if (readen_bites <= 0)
        {
            if (readen_bites == 0)
                break;
            else
                return (free(allocated), free(temp), NULL);
        }
        if (ft_strchr(allocated, '\n') == BUFFER_SIZE)
            ft_strncat(temp, allocated, BUFFER_SIZE);
        else
        {
            check = ft_strchr(allocated, '\n');
            ft_strncat(temp, allocated, check);
            saved = ft_strdup(allocated + check + 1);
            break;
        }
    }
    free(allocated);
    return(temp);
} 
// int main()
// {
//     int fd = open("test.txt", O_RDONLY | O_CREAT, 0644);
//     if (fd < 0)
//         return (printf("fd failed\n"), 0);
//     char *s = malloc(BUFFER_SIZE + 1);
//     if (!s)
//         return (0);
//         // ?????????????????????????????
//     int readen = read(fd, s, BUFFER_SIZE);
//     if (strchr(s, '\n'))
//     printf("the readen bites are : %d\nthe readen string is : %s\n\n", readen, s);
//     while (readen > 0)
//     {
//         readen = read(fd, s, BUFFER_SIZE);
//         printf("the readen bites are : %d\nthe readen string is : %s\n\n", readen, s);
//     }
// }
// ! waach akhay\n ssat  (12 + 1) (17 - 12)+ 1 
// !                     pointer   *(pointer + i)
// ********************************************
// ? waach akhay\n ssat  (12 + 1) (17 - 12)+ 1 
// ? 
#include "../inc/so_long.h"

void    xpm_parser(char *file)
{
    int     fd;
    char    *line;
    int    i;
    t_parser    parser;
    
    i = 1;
    fd = open(file, O_RDONLY);
    while (1)
    {
        line = get_next_line(fd);
        if (i > 3 && ft_strlen(line) == )
        {
            while ()
        }
        free(line);
    } 
}

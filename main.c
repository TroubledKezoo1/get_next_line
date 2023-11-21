#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int main(void)
{
    char *line;
    int   fd;

    fd = open("text.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s",line);
        free(line);
    }
    return (0);
}
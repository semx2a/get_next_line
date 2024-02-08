#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	int		fd[argc - 1];
	char	*line;
	int 	i = 0;

	if (argc > 2 && argv[1])
	{
		if (!strcmp(argv[1], "0") && argc == 2)
			fd[0] = 0;
		else
		{
			while (i < argc - 1)
			{
				if (!strcmp(argv[i + 1], "0"))
					fd[i] = 0;
				else
					fd[i] = open(argv[i + 1], O_RDONLY);
				i++;
			}
		}
		i = 0;
		while (i < argc - 1)
		{
			while ((line = get_next_line(fd[i])))
			{
				printf("%s\n", line);
				free(line);
			}
			printf("%s\n", line);
			free(line);
			i++;
		}
		i = 0;
		while (i < argc - 1)
			close(fd[i]);
	}
	return (0);
}

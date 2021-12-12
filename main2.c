#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"
#include <stdlib.h>
#include <string.h>

int	main()
{
	int		fd = 0;
	char	*ret;

//	fd = open("test", O_RDWR);
	while ((ret = get_next_line(fd)))
	{
		printf("%s", ret);
		free(ret);
	}
	free(ret);
	close(fd);
	return (0);
}

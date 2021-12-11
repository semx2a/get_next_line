#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int	taille(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

int	main(void)
{
	char *s;
	int		fd;
//	char *s2 = "bonjour";


	s = 0;
	fd = 0;

	// = open("file", O_RDONLY);

//	printf("fd = %d\n", fd);
//	write(0, "bonjour", 9);
	s = get_next_line(0);
	printf("s = %p\n", s);
	while (s)
	{
		printf("s = (%2d)%s", taille(s), s);
		free(s);

		s = get_next_line(fd);

	}
	return (0);
}


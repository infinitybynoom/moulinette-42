#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void	ft_cat(int fd);

int	main(int argc, char **argv)
{
	int	fd;
	int	i;

	if (argc == 1)
	{
		ft_cat(0);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
			return (1);
		ft_cat(fd);
		close(fd);
		i++;
	}
	return (0);
}

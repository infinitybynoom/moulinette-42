#include <fcntl.h>
#include <unistd.h>

void	ft_hexdump(int fd);

int	main(int argc, char **argv)
{
	int	fd;

	if (argc < 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	ft_hexdump(fd);
	close(fd);
	return (0);
}

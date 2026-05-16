#include <fcntl.h>
#include <unistd.h>

void	ft_tail(int fd, int nb_lines);

int	main(int argc, char **argv)
{
	int	fd;
	int	n;

	if (argc < 3)
		return (1);
	n = 0;
	if (argv[1][0] == '-')
	{
		int i = 1;
		while (argv[1][i] >= '0' && argv[1][i] <= '9')
			n = n * 10 + argv[1][i++] - '0';
	}
	fd = open(argv[2], O_RDONLY);
	if (fd == -1)
		return (1);
	ft_tail(fd, n);
	close(fd);
	return (0);
}

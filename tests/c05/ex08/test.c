#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int	ft_ten_queens_puzzle(void);

int	main(void)
{
	int	saved;
	int	devnull;
	int	count;

	saved = dup(STDOUT_FILENO);
	devnull = open("/dev/null", O_WRONLY);
	dup2(devnull, STDOUT_FILENO);
	close(devnull);
	count = ft_ten_queens_puzzle();
	dup2(saved, STDOUT_FILENO);
	close(saved);
	printf("%d\n", count);
	return (0);
}

#include <string.h>
#include <unistd.h>

void	ft_print_combn(int n);

int	main(void)
{
	int		pipefd[2];
	char	buf[256];
	ssize_t	nb;

	if (pipe(pipefd) == -1)
		return (1);
	int saved = dup(1);
	dup2(pipefd[1], 1);
	ft_print_combn(1);
	fflush(stdout);
	dup2(saved, 1);
	close(pipefd[1]);
	nb = read(pipefd[0], buf, sizeof(buf) - 1);
	close(pipefd[0]);
	buf[nb] = '\0';
	/* For n=1: "0, 1, 2, ..., 9" */
	if (buf[0] == '0' && strstr(buf, "8, 9") != NULL)
		write(1, "N1_OK\n", 6);
	else
		write(1, "N1_FAIL\n", 8);
	return (0);
}

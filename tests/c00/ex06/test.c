#include <string.h>
#include <unistd.h>

void	ft_print_comb2(void);

int	main(void)
{
	int		pipefd[2];
	char	buf[32768];
	ssize_t	n;

	if (pipe(pipefd) == -1)
		return (1);
	int saved = dup(1);
	dup2(pipefd[1], 1);
	ft_print_comb2();
	fflush(stdout);
	dup2(saved, 1);
	close(pipefd[1]);
	n = read(pipefd[0], buf, sizeof(buf) - 1);
	close(pipefd[0]);
	if (n < 0)
		return (1);
	buf[n] = '\0';
	if (strncmp(buf, "00 01", 5) == 0)
		write(1, "START_OK\n", 9);
	else
		write(1, "START_FAIL\n", 11);
	size_t len = strlen(buf);
	while (len > 0 && (buf[len-1] == '\n' || buf[len-1] == '\r'))
		len--;
	if (len >= 5 && strncmp(buf + len - 5, "98 99", 5) == 0)
		write(1, "END_OK\n", 7);
	else
		write(1, "END_FAIL\n", 9);
	if (strstr(buf, "00 01, 00 02") != NULL)
		write(1, "SEP_OK\n", 7);
	else
		write(1, "SEP_FAIL\n", 9);
	return (0);
}

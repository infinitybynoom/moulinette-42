#include <string.h>
#include <stdio.h>
#include <unistd.h>

void	ft_print_comb(void);

/* Capture stdout into buf via pipe, then verify format */
int	main(void)
{
	int		pipefd[2];
	char	buf[4096];
	ssize_t	n;

	if (pipe(pipefd) == -1)
		return (1);
	int saved = dup(1);
	dup2(pipefd[1], 1);
	ft_print_comb();
	fflush(stdout);
	dup2(saved, 1);
	close(pipefd[1]);
	n = read(pipefd[0], buf, sizeof(buf) - 1);
	close(pipefd[0]);
	if (n < 0)
		return (1);
	buf[n] = '\0';
	/* Must start with "012" */
	if (buf[0] == '0' && buf[1] == '1' && buf[2] == '2')
		write(1, "START_OK\n", 9);
	else
		write(1, "START_FAIL\n", 11);
	/* Must end with "789\n" or "789" */
	size_t len = strlen(buf);
	while (len > 0 && (buf[len-1] == '\n' || buf[len-1] == '\r'))
		len--;
	if (len >= 3 && buf[len-3] == '7' && buf[len-2] == '8' && buf[len-1] == '9')
		write(1, "END_OK\n", 7);
	else
		write(1, "END_FAIL\n", 9);
	/* Check separator ", " between combos */
	if (strstr(buf, "012, 013") != NULL)
		write(1, "SEP_OK\n", 7);
	else
		write(1, "SEP_FAIL\n", 9);
	return (0);
}

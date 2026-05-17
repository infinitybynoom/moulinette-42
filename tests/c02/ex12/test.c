#include <string.h>
#include <unistd.h>
#include <stdio.h>

void	*ft_print_memory(void *addr, unsigned int size);

int	main(void)
{
	char	buf[] = "Hello, 42!";
	void	*ret;
	int		pipefd[2];
	char	output[4096];
	ssize_t	n;
	int		saved;
	char	*colon;

	pipe(pipefd);
	saved = dup(1);
	dup2(pipefd[1], 1);
	ret = ft_print_memory(buf, 10);
	fflush(stdout);
	dup2(saved, 1);
	close(saved);
	close(pipefd[1]);
	n = read(pipefd[0], output, sizeof(output) - 1);
	close(pipefd[0]);
	if (n < 0)
		return (1);
	output[n] = '\0';
	colon = strchr(output, ':');
	if (colon && strstr(colon, "4865 6c6c 6f2c 2034 3221"))
		write(1, "HEX_OK\n", 7);
	else
		write(1, "HEX_FAIL\n", 9);
	if (colon && strstr(colon, "Hello, 42!"))
		write(1, "PRINT_OK\n", 9);
	else
		write(1, "PRINT_FAIL\n", 11);
	if (ret == (void *)buf)
		write(1, "RET_OK\n", 7);
	else
		write(1, "RET_FAIL\n", 9);
	return (0);
}

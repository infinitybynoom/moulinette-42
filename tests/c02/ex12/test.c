#include <string.h>
#include <unistd.h>

void	*ft_print_memory(void *addr, unsigned int size);

int	main(void)
{
	char	buf[] = "Hello, 42!";
	void	*ret;

	ret = ft_print_memory(buf, 10);
	if (ret == (void *)buf)
		write(1, "RET_OK\n", 7);
	else
		write(1, "RET_FAIL\n", 9);
	return (0);
}

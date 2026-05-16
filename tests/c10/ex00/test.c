#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void	display_file(char *filename);

int	main(int argc, char **argv)
{
	if (argc == 2)
		display_file(argv[1]);
	else if (argc == 1)
		write(1, "File name missing.\n", 19);
	else
		write(1, "Too many arguments.\n", 20);
	return (0);
}

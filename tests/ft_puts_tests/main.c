#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

#include "../../include/libfts.h"

int main()
{
	printf("What should be printed:\n");
	puts("\tHello, I am testing ft_puts().");
	//puts(NULL);
	puts("\tI hope I won't crash.");
	puts("\tBecause if I crash, I deserve 0 nooooo");
	puts("\t");
	puts("");
	puts("A");
	puts("\n");

	printf("What ft_puts print:\n");
	ft_puts("\tHello, I am testing ft_puts().");
	ft_puts(NULL);
	ft_puts("\tI hope I won't crash.");
	ft_puts("\tBecause if I crash, I deserve 0 nooooo");
	ft_puts("\t");
	ft_puts("");
	ft_puts("A");
	ft_puts("\n");

	return (0);
}

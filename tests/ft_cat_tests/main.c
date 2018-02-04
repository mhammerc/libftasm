#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

#include "../../include/libfts.h"

int main()
{
	printf("The main Makefile (libfts.a) should be printed below.\n");

	int fd = open("../Makefile", O_RDONLY);
	ft_cat(fd);

	printf("\nNow, I will tests wrong values. It should not crash.\n");
	ft_cat(-1);
	ft_cat(-1000);
	ft_cat(10000);
	ft_cat(10000000);

	printf("Congrats, I'm done. It worked!\n");
	return (0);
}

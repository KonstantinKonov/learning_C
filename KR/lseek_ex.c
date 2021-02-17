#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	if(argc != 2)
		exit(0);
	int f_id;
	if( (f_id = open(argv[1], O_RDONLY, 0)) != -1 ) {
		if( lseek(f_id, 100, SEEK_SET) != -1 ) {
			char str[BUFSIZ];
			int n = read(f_id, str, BUFSIZ);
			write(1, str, n);
		}
	}

	return 0;
}

// print information about /etc/fstab
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
	struct stat st;
	if( stat("/etc/fstab", &st) == -1 ) {
		fprintf(stderr, "Can't get stat \n");
		exit(1);
	}

	fprintf(stdout, "Size: %lu\t", (unsigned long) st.st_size); 
	fprintf(stdout, "Mode: %o\n", st.st_mode);
	if( S_ISDIR(st.st_mode) )
		printf("dir");
	else if( S_ISBLK(st.st_mode) )
		printf("chrdev");
	else if( S_ISBLK(st.st_mode) )
		printf("blkdev");
	else if( S_ISREG(st.st_mode) )
		printf("regfile");
	else if( S_ISFIFO(st.st_mode) )
		printf("fifo");
	else if( S_ISLNK(st.st_mode) )
		printf("symlink");
	else if( S_ISSOCK(st.st_mode) )
		printf("socket");
	else
		printf("unknown");

	printf("\n");

	return 0;
}

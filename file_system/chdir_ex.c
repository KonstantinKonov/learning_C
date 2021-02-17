#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

#define	PWD_STR_SIZE	1024
#define	FILE_BUF_SIZE	4096

int main(void)
{
	char *dir_name = getcwd(NULL, 0);
	printf("Current directory: %s\n", dir_name);
	free(dir_name);

	char dir_name_arg[PWD_STR_SIZE];	
	getcwd(dir_name_arg, PWD_STR_SIZE);
	printf("Current directory: %s\n", dir_name_arg);

	// change directory
	if( chdir("/etc") == -1 ) {
		fprintf(stderr, "chdir() error\n");
		return 1;
	}

	dir_name = getcwd(NULL, 0);
	printf("New directory: %s\n", dir_name);
	free(dir_name);

	// read file fstab from new directory
	int fd = open("fstab", O_RDONLY);
	if(fd == -1) {
		fprintf(stderr, "Can't open fstab\n");
		return 1;
	}

	printf("fstab: \n");
	char file_buf[FILE_BUF_SIZE];
	int count = 0;
	while( (count = read(fd, file_buf, FILE_BUF_SIZE)) > 0 )
		write(1, file_buf, count);
	close(fd);

	return 0;
}

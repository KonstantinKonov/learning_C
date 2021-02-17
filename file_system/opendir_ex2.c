// printf root directory 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

//struct dirent {
//	ino_t          d_ino;       /* Inode number */
//	off_t          d_off;       /* Not an offset; see below */
//	unsigned short d_reclen;    /* Length of this record */
//	unsigned char  d_type;      /* Type of file; not supported by all filesystem types */
//	char           d_name[256]; /* Null-terminated filename */
//};

int main()
{
	// open dir
	char *dir_name = "/";
	DIR *dir_p = opendir("/");
	if( dir_p == NULL ) {
		fprintf(stderr, "Can't open directory %s\n", dir_name);
		exit(1);
	}

	// read and print to stdout entries in dir
	struct dirent *d_ent = NULL;
	while( (d_ent = readdir( dir_p )) != NULL )
		fprintf(stdout, "%s\n", d_ent->d_name);

	closedir( dir_p );

	return 0;
}

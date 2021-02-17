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
	DIR *dir_p = opendir(getcwd(NULL, 0));
	if( dir_p == NULL ) {
		fprintf(stderr, "Can't open directory");
		exit(1);
	}

	// read dir
	struct dirent *d_ent; 
	while( (d_ent = readdir( dir_p )) ) {
		write(1, d_ent->d_name, strlen(d_ent->d_name));
		write(1, "\t", 2);
		fprintf(stdout, "%lu\n", (unsigned long) d_ent->d_ino);
	}

	closedir( dir_p );

	return 0;
}

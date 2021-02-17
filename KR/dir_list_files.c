#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
	if(argc != 2)
		exit(0);

	DIR *d;
	if( d = opendir(argv[1]) ) {
		struct dirent *dir;
		while( (dir = readdir(d)) != NULL ) {
			struct stat *st = (struct stat *) malloc( sizeof(struct stat) );
			stat(dir->d_name, st);
			printf("%-10ld\t%-10ld\t%s\n", dir->d_ino, st->st_size, dir->d_name);
		}
		closedir(d);
	}
	else {
		perror("diropen error\n");
		exit(1);
	}

	return 0;
}

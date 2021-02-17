#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/statvfs.h>
#include <mntent.h>

//struct mntent {
//	char *mnt_fsname;   /* name of mounted filesystem */
//	char *mnt_dir;      /* filesystem path prefix */
//	char *mnt_type;     /* mount type (see mntent.h) */
//	char *mnt_opts;     /* mount options (see mntent.h) */
//	int   mnt_freq;     /* dump frequency in days */
//	int   mnt_passno;   /* pass number on parallel fsck */
//};

//struct statvfs {
//	unsigned long  f_bsize;    /* Filesystem block size */
//	unsigned long  f_frsize;   /* Fragment size */
//	fsblkcnt_t     f_blocks;   /* Size of fs in f_frsize units */
//	fsblkcnt_t     f_bfree;    /* Number of free blocks */
//	fsblkcnt_t     f_bavail;   /* Number of free blocks for unprivileged users */
//	fsfilcnt_t     f_files;    /* Number of inodes */
// 	fsfilcnt_t     f_ffree;    /* Number of free inodes */
//	fsfilcnt_t     f_favail;   /* Number of free inodes for unprivileged users */
//	unsigned long  f_fsid;     /* Filesystem ID */
//	unsigned long  f_flag;     /* Mount flags */
//	unsigned long  f_namemax;  /* Maximum filename length */
//};

int main(void)
{
	struct mntent *entry;
	struct statvfs fs;
	FILE *fp;

	fp = setmntent("/proc/mounts", "r");
	if(fp == NULL) {
		perror("Can't open file \n");
		exit(1);
	}

	while( (entry = getmntent(fp)) != NULL ) {
		// passing mount directory to structure fs
		printf("____________________________________\n");
		if( statvfs(entry->mnt_dir, &fs) == -1 ) {
			fprintf(stderr, "statvfs() error trying to open %s\n", entry->mnt_dir);
			exit(1);
		}

		printf("Filesystem: %s\n", entry->mnt_fsname);
		printf("Filesystem Directory: %s\n", entry->mnt_dir);
		printf("Options: %s\n", entry->mnt_opts);
		printf("Blocks: %lu\n", (unsigned long)fs.f_blocks);
		printf("Block size: %lu\n", (unsigned long)fs.f_bsize);
		printf("Inodes: %lu\n", (unsigned long)fs.f_files);
	}

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int main(int argc, char **argv)
{
	FILE *outfile = stdout;
	int i, opt;
	char *filename = NULL;
	char help_str[] = 
		"Usage: getopedemo [OPTIONS] ARGUMENTS ...\n"
		"-h					- Print help and exit\n"
		"-o <outfile>		- Write output to file\n"; 
	char version_str[] = 
		"v0.1 19.12.2020\n";
	// getopt returns -1 if there is no options left
	while( (opt = getopt(argc, argv, "hvo:")) != -1 ) {
		switch(opt) {
			case 'h':
				printf("%s", help_str);
				return 0;
				
			case 'o':
				// arguments are stored in optarg variable
				filename = optarg;
				printf("optarg = %s, optind = %d\n", optarg, optind);
				break;

			case 'v':
				printf("%s", version_str);
				return 0;

			case '?':
				fprintf(stderr, "%s", help_str);
				return 1;

			default:
				fprintf(stderr, "Unknown error\n");
				return 1;
		}
	}

	if(optind >= argc) {
		fprintf(stderr, 
				"No argument(s) found\n%s", help_str);
		return 1;
	}

	if(filename != NULL) {
		outfile = fopen(filename, "w");
		if(outfile == NULL) {
			fprintf(stderr, "Cannot open output file (%s)\n", filename);
			return 1;
		}
		for(i = optind; i < argc; i++)
			fprintf(outfile, "%s\n", argv[i]);
		if(outfile != stdout) fclose(outfile);
	}

	return 0;
}

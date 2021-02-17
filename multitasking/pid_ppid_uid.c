#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

int main()
{
	pid_t pid = getpid();
	pid_t ppid = getppid();
	uid_t uid = getuid();

	struct passwd *pswd = getpwuid(uid);

	printf("pid: %d, ppid: %d, uid: %d\n", pid, ppid, uid);
	printf("username: %s\n", pswd->pw_name);

	return 0;
}

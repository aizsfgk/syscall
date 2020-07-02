#include "base.h"

//  setreuid, setregid - set real and/or effective user or group ID

int main(int argc, char const *argv[])
{
	uid_t uid, euid;
	gid_t gid, egid;
	uid = getuid();
	gid = getgid();
	euid = geteuid();
	egid = getegid();
	fprintf(stdout, "uid: %d, gid: %d, euid: %d, egid: %d\n", 
		(int)uid, 
		(int)gid,
		(int)euid,
		(int)egid);

	int rs = setreuid(40246, 32106);
	int rs1 = setregid(40246, 40246);

	printf("rs:%d, rs1:%d\n", rs, rs1);
	if (rs == 0) {
		fprintf(stdout, "%s\n", "ok");

		uid = getuid();
		gid = getgid();
		euid = geteuid();
		egid = getegid();
		fprintf(stdout, "uid: %d, gid: %d, euid: %d, egid: %d\n", 
		(int)uid, 
		(int)gid,
		(int)euid,
		(int)egid);
	} else {
		perror("setreuid");
		perror("setregid");
		exit(EXIT_FAILURE);
	}
	return 0;
}
///usr/lib/jvm/java-1.7.0-openjdk-1.7.0.201.x86_64/jre
#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>

int main() {
	int pid = getpid();
	long int ret = listProcessInfo(pid);
	
	if (ret == 0) {
		printf("System call executed correctly. Use dmesg to check processInfo\n");
	} else {
		printf("System call didn't execute as expected\n");
	}
	
	return 0;
}

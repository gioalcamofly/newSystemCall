#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/syscalls.h>

#include "processInfo.h"

asmlinkage long sys_listProcessInfo (int pid) {
	struct task_struct *process;

	process = find_task_by_vpid(pid);
	printk(		
		"Process: %s\nPID_Number: %ld\nProcess State: %ld\nPriority: %ld\n", \
		 process->comm, \
		 (long)task_pid_nr(process), \
		 (long)process->state, \
		 (long)process->prio
	);
	
	if(process->parent) {
		printk(
			"Parent process: %s\n, PID_Number: %ld\n", \
			 process->parent->comm, \
			 (long)task_pid_nr(process->parent) \
		);
	}
	printk("\n\n");
	return 0;
}


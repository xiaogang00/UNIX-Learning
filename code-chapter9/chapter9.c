# include <sys/types.h>
# include <unistd.h>

pid_t getpgrp(void);
int setpgid(pid_t pid, pid_t pgid);

pid_t setsid(void);

pid_t tcgetpgrp(int filedes);
int tcsetpgrp(int filedes, pid_t pgrpid);


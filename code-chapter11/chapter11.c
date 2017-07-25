# include <signal.h>
void (*signal (int signo, void (*func)(int))) (int);
//返回：成功则为以前的信号处理配置，若出错则为 SIG_ERR
//*func表示这是一个函数指针
//signal函数的原型说明此函数要求两个参数，返回一个函数指针，


int kill(pid_t pid, int signo);
int raise(int signo);

//不能正常工作的系统 VSIGCLD处理程序
# include <sys/types.h>
# include <signal.h>
# include <stdio.h>
static void sig_cld();
int main(){
    pid_t pid;
    if(signal(SIGCLD, sig_cld) == -1)
        perror("signal error");
    if((pid == fork())<0)
        perror("fork error");
    else if(pid == 0){
        sleep(2);
        _exit(0);
    }
    pause();
    exit(0);
}

static void sig_cld(){
    pid_t pid;
    int status;
    printf("SIGCLD received\n");
    if(signal(SIGCLD, sig_cld) == -1)
       perror("signal error");
    if((pid = wait(&status)) < 0)
       perror("wait error");
    printf("pid = %d\n", pid);
    return;
}

struct termios{
    tcflag_t c_iflag;
    tcflag_t c_oflag;
    tcflag_t c_cflag;
    tcflag_t c_lflag;
    cc_t c_cc[NCCS];
}

//禁止中断字符和更改文件结束字符
# include <termios.h>
# include "ourhdr.h"
int main(void){
    struct termios term;
    long vdisable;
    if(isatty(STDIN_FILENO) == 0)
       err_quit("standard input is not a terminal device");
    if((vdisable = fpathconf(STDIN_FILENO, _PC_VDISABLE)) < 0)
       err_quit("fpathconf error or _POSIX_VDISABLE not in effect");
    if(tcgetattr(STDIN_FILENP, &term) < 0)
       err_sys("tcgetattr error");
    term.c_cc[VINTR] = vdisable;
    term.c_cc[VEOF] = 2;
    if(tcsetattr(STDIN_FILENO, TCSAFLUSH, &term) < 0)
       err_sys("tcsetattr error");
    exit(0);
}

speed_t cfgetispeed(const struct termios * termptr) ;
speed_t cfgetospeed(const struct termios * termptr) ;
//两个函数返回：波特率值
int cfsetispeed(struct termios * termptr, speed_t speed) ;
int cfsetospeed(struct termios * termptr, speed_t speed) ;
//两个函数返回：若成功为0，出错为-1

//行控制函数
int tcdrain(int filedes) ;
int tcflow(int filedes, int action) ;
int tcflush(int filedes, int queue) ;
int tcsendbreak(int filedes, int duration) ;


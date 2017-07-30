#include <stdio.h>
FILE *popen(const char * cmdstring, const char * type) ;
//返回：若成功则为文件指针，若出错则为 N U L L

int pclose(FILE * fp) ;
//返回： cmdstring的终止状态，若出错则为-1

//共享存储的shmid_ds结构
struct shmid_ds{
    struct ipc_perm shm_perm;
    struct anon_map * shm_amp;
    int shm_segsz;
    ushort shm_lkcnt;
    pid_t shm_lpid;
    pid_t shm_cpid;
    ulong shm_nattch;
    ulong shm_cnattch;
    time_t shm_atime;
    time_t shm_dtime;
    time_t shm_ctime;
}

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
int shmget(key_t key, int size, int flag);

int shmctl(int shmid, int cmd, struct shmid_ds * buf);
//返回：若成功则为0，若出错则为 - 1

void *shmat(int shmid, void * addr, int flag) ;
//返回：若成功则为指向共享存储段的指针，若出错则为 - 1


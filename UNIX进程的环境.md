* C程序总是从main函数开始执行的。其函数的原型是：

  ```c
  int main(int argc, char *argv[]);
  ```

  在内核开始调用C程序的时候，在调用main函数之前需要先使用一个起动例程。通过连接编辑产生的程序起始地址为这个起动例程。

#### 进程终止

一般来说有5种方式可以使得进程终止：

* 正常终止
  * 从main返回
  * 调用exit
  * 调用_exit


* 异常终止
  * 调用abort
  * 由一个信号终止

exit()函数是执行一个标准I/O库的清除关闭操作。对于所有打开流调用fclose函数。

一个进程可以登记多至32个函数，这些函数将由exit自动调用。我们将这些函数称为终止处理程序。可以用函数atexit来进行统计。

```c
int atexit(void (*func)(void));
```

#### 环境表

每个程序都接收到一张环境表。环境表也是一个字符指针数组，其中每个
指针包含一个以null结束的字符串的地址。全局变量 environ则包含了该指针数组的地址。

```c
extern char **environ;
```

#### C程序的存储空间布局

* 正文段
* 初始化数据段：通常将此段称为数据段，它包含了程序中需赋初值的变量。
* 非初始化数据段
* 栈：自动变量以及每次函数调用时所需保存的信息都存放在此段中。
* 堆：通常在堆中进行动态存储分配。

size命令可以报告正文段，数据段和bss段的长度。

```
size /bin/cc /bin/sh
```

这是能够列出两个文件的数据的分布。

#### 存储器分配

有是哪个可以用于存储空间动态分配的函数：

malloc，calloc，realloc

realloc函数能够让我们增加或者减少以前分配区域的长度。但是可能会移动存储的区域，所以不应当使用任何指针在该区域中。realloc的最后一个参数是存储区域的newsize（新长度）。

另外为了解决free的问题，在每次调用这三个函数之后，都需要进行free出错的检验。

alloca函数

这个函数是在当前函数的栈帧上分配存储空间，而不是在堆中。当函数返回的时候，会自动释放它所使用的栈帧，也不必再为释放空间而费心。

#### 环境变量

可以用函数getenv来获取环境变量值。此函数返回一个指针，主要指向的是name = value字符串中的value，也就是环境变量的值。

另外还可以进行设置：putenv,setenv,unsetenv。

#### setjmp和longjmp函数

可以执行跳转功能的函数是setjmp和longjmp

获取资源限制的函数:

```c
int getrlimit(int resource, struct rlimit *rlptr);
int setrlimit(int resource, const struct rlimit *rlptr);
```


The codes here show the difference between fork() and vfork()

1. fork_basic
(1) fork() return 0 for parent process.
(2) fork() 不保证父、子进程执行顺序

2. fork_data_copy.c
(1) fork()创建一个子进程，并将父进程的数据 拷贝 到子进程


3. vfork_basic.c
(1) vfork() 保证子进程 先执行，子进程执行完后，调用exec()/exit()后，父进程才能继续执行


4. vfork_data_share.c 
(1) vfork()创建一个子进程，并共享父进程的数据



用gcc编译运行，即可理解fork()与vfork()的区别。
注意，写时拷贝只有fork具备。一般不推荐使用vfork()

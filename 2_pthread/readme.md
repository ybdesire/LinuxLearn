**Pthread：POSIX 多线程程序设计**

http://www.cnblogs.com/mywolrd/archive/2009/02/05/1930707.html
* UNIX系统，IEEE POSIX 1003.1标准定义了一个C语言多线程编程接口
* 三大类函数：线程管理（Thread Managment）、互斥量（Mutex Variables）和条件变量（Condition Variables）
* 进程包含了程序的资源和执行状态信息。如下
   * 进程ID，进程group ID，用户ID和group ID 
   * 程序指令 
   * 寄存器 
   * 栈 
   * 堆 
   * 文件描述符 
   * 信号动作（Signal actions） 
   * 共享库 
   * 进程间通信工具（如：消息队列，管道，信号量或共享内存） 
* 线程维持着自己的： 
   * 堆栈指针 
   * 寄存器 
   * 调度属性（如：策略或优先级） 
   * 待定的和阻塞的信号集合（Set of pending and blocked signals） 
   * 线程专用数据（TSD：Thread Specific Data.） 
* pthread线程管理函数
   * pthread_create (thread_id,attr,start_routine,arg)  
   * pthread_exit (status)  用于显式退出线程
   * pthread_attr_init (attr)  初始化改属性变量 
   * pthread_attr_destroy (attr)  释放属性所占用的库资源
* 结束线程的方法有一下几种： 
   * 线程从主线程（main函数的初始线程）返回
   * 线程调用了pthread_exit函数
   * 其它线程使用 pthread_cancel函数结束线程
   * 调用exec或者exit函数，整个进程结束 
* 连接（Joining）和分离（Detaching）线程
   * pthread_join (threadid,status)阻塞当前线程，直到threadid所指线程结束为止
   * pthread_detach (threadid,status)  父线程调用，将该子线程的状态设置为detached,则该线程运行结束后会自动释放所有资源，父线程不被阻塞
   * pthread_attr_setdetachstate (attr,detachstate)  设置线程是可连接的（joinable）还是分离的（detached）
   * pthread_attr_getdetachstate (attr,detachstate)  
* 互斥量（Mutex）是“mutual exclusion”的缩写。互斥量是实现线程同步，和保护同时写共享数据的主要方法 
   * pthread_mutex_lock()函数去锁定指定的mutex变量，若该mutex已经被另外一个线程锁定了，该调用将会阻塞线程直到mutex被解锁
   * pthread_mutex_trylock()尝试着去锁定一个互斥量，然而，若互斥量已被锁定，程序会立刻返回并返回一个忙错误值。该函数在优先级改变情况下阻止死锁是非常有用的。
   * pthread_mutex_unlock()解锁自己占用的互斥量
* 有多个线程等待同一个锁定的互斥量，当互斥量被解锁后，那个线程会第一个锁定互斥量？
   * 除非线程使用了优先级调度机制，否则，是随机的。
* 条件变量（Condition Variables）   
   * pthread_cond_signal(&cond)
      * 作用是发送一个信号给另外一个正在处于阻塞等待状态的线程,使其脱离阻塞状态,继续执行.如果没有线程处在阻塞等待状态,pthread_cond_signal也会成功返回。应该在互斥量被锁定后调用。
      * 它最多只给一个线程发信号。假如有多个线程正在阻塞等待着这个条件变量的话，那么是根据各等待线程优先级的高低确定哪个线程接收到信号开始继续执行。如果各线程优先级相同，则根据等待时间的长短来确定哪个线程获得信号。但无论如何一个pthread_cond_signal调用最多发信一次。
   * pthread_cond_wait()阻塞调用线程直到指定的条件受信（signaled）。该函数应该在互斥量锁定时调用，当在等待时会自动解锁互斥量
   * pthread_cancel(tid)发送终止信号给thread线程，如果成功则返回0，否则为非0值。发送成功并不意味着thread会终止   

   
**Linux线程管理系统调用**
* exit, abort, return
   * exit在调用时，会做大部分清理工作（执行收工函数），但是决不会销毁局部对象。
   * abort调用时，不进行任何清理工作。直接终止程序。
   * return调用时，先调用局部对象的析构函数，再交由exit执行退出操作。

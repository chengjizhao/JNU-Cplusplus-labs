## 一个程序当中，有且只有一个进程，但可以拥有至少一个的线程。不同进程拥有不同的地址空间，互不相关，而不同线程共同拥有相同进程的地址空间。

**************************

1. std::thread
	主要用于线程的创建、移动、复制、析构等基本操作。使用不同的thread同时直线任务，有可能每次任务的结束顺序都不一样。因为现代操作系统对任务执行的顺序多数是按照时间片的形式执行，同时划分优先级。
2. std::mutex
	互斥量，可以锁定资源不被其他线程使用。当某线程尝试在其任务中上锁时，若该锁已被别处锁定，则本线程将会阻塞才此处直到锁被释放。
3. std::lock_guard
	一种可以自动解锁的互斥锁。在离开当前lock_guard的定义域后便会自动销毁，防止出现忘记解锁造成任务卡死。
4. std::condition_variable
	通过线程间共享的全局变量实现同步。一个线程等待条件变量的条件成立而挂起；另一个线程使条件成立（给出条件成立信号）。为了防止竞争，条件变量的使用总是和一个互斥量结合在一起。

**************************

## 线程池的出现减少了多线程任务中任务申请和释放产生的性能消耗。将要执行的任务队列送入线程池，线程池中提前创建好的线程便会进行任务处理，当任务完成后再进入等待任务状态，而不是被销毁。这提高了多线程任务执行的效率。
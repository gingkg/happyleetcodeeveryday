// multithreading_c++11.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
C++11多线程并发基础入门教程
https://zhuanlan.zhihu.com/p/194198073
*/

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <Windows.h>

using namespace std;

void proc(int a)
{
    cout << "我是子线程,传入参数为" << a << endl;
    cout << "子线程中显示子线程id为" << this_thread::get_id() << endl;
}

mutex m; //实例化m对象，不要理解为定义变量

void proc1(int a)
{
    m.lock();
    cout << "proc1函数正在改写a" << endl;
    cout << "原始a为" << a << endl;
    cout << "现在a为" << a + 2 << endl;
    m.unlock();
}

void proc2(int a)
{
    m.lock();
    cout << "proc2函数正在改写a" << endl;
    cout << "原始a为" << a << endl;
    cout << "现在a为" << a + 1 << endl;
    m.unlock();
}


void proc3(int a)
{
    //用此语句替换了m.lock()；lock_guard传入一个参数时，该参数为互斥量，此时调用了lock_guard的构造函数，申请锁定m
    lock_guard<mutex> g1(m);
    cout << "proc3函数正在改写a" << endl;
    cout << "原始a为" << a << endl;
    cout << "现在a为" << a + 2 << endl;
    //此时不需要写m.unlock(),g1出了作用域被释放，自动调用析构函数，于是m被解锁
}


void proc4(int a)
{
    //通过使用{}来调整作用域范围，可使得m在合适的地方被解锁
    {
        lock_guard<mutex> g2(m);
        cout << "proc4函数正在改写a" << endl;
        cout << "原始a为" << a << endl;
        cout << "现在a为" << a + 1 << endl;
    }

    cout << "作用域外的内容3" << endl;
    cout << "作用域外的内容4" << endl;
    cout << "作用域外的内容5" << endl;
}

void proc5(int a)
{
    m.lock(); //手动锁定
    // std::lock_gurad也可以传入两个参数，第2个参数为adopt_lock标识时，表示构造函数中不再进行互斥量锁定，因此此时需要提前手动锁定。
    lock_guard<mutex> g1(m, adopt_lock);
    cout << "proc5函数正在改写a" << endl;
    cout << "原始a为" << a << endl;
    cout << "现在a为" << a + 2 << endl;
    //自动解锁
}

/*
unique_lock:
std::unique_lock类似于lock_guard,只是std::unique_lock用法更加丰富，同时支持std::lock_guard()的原有功能。 使用std::lock_guard后不能手动lock()与手动unlock();使用std::unique_lock后可以手动lock()与手动unlock(); std::unique_lock的第二个参数，除了可以是adopt_lock,还可以是try_to_lock与defer_lock;

try_to_lock: 尝试去锁定，得保证锁处于unlock的状态,然后尝试现在能不能获得锁；尝试用mutx的lock()去锁定这个mutex，但如果没有锁定成功，会立即返回，不会阻塞在那里，并继续往下执行；

defer_lock: 初始化了一个没有加锁的mutex;
*/
void proc6(int a)
{
    unique_lock<mutex> g1(m, defer_lock); //始化了一个没有加锁的mutex
    cout << "xxxxxxxxxxxx" << endl;
    g1.lock();  //手动加锁，注意，不是m.lock();注意，不是m.lock(),m已经被g1接管了;
    cout << "proc6函数正在改写a" << endl;
    cout << "原始a为" << a << endl;
    cout << "现在a为" << a + 2 << endl;
    g1.unlock();  //临时解锁
    cout << "xxxxxx" << endl;
    g1.lock();
    cout << "xxxxxxxxxxx" << endl;
    //自动解锁
} 

void proc7(int a)
{
    //尝试加锁一次，但如果没有锁定成功，会立即返回，不会阻塞在那里，且不会再次尝试锁操作。
    unique_lock<mutex> g2(m, try_to_lock); 
    if (g2.owns_lock())  //锁成功
    {
        cout << "proc7函数正在改写a" << endl;
        cout << "原始a为" << a << endl;
        cout << "现在a为" << a + 1 << endl;
    }
    else {//锁失败则执行这段语句
        cout << "锁限失败" << endl;
    }
    //自动解锁
}


// condition_variable:不是用来管理互斥量的，它的作用是用来同步线程
// A、B两个人约定notify_one为行动号角，A就等着（调用wait(),阻塞）,只要B一调用notify_one，A就开始行动（不再阻塞）。



// 异步线程
double t1(const double a, const double b)
{
    double c = a + b;
    Sleep(3000);//假设t1函数是个复杂的计算过程，需要消耗3秒
    return c;
}


// shared_future
// std::future与std::shard_future的用途都是为了占位，但是两者有些许差别。std::future的get()成员函数是转移数据所有权; std::shared_future的get()成员函数是复制数据。 因此： future对象的get()只能调用一次；无法实现多个线程等待同一个异步线程，一旦其中一个线程获取了异步线程的返回值，其他线程就无法再次获取。 std::shared_future对象的get()可以调用多次；可以实现多个线程等待同一个异步线程，每个线程都可以获取异步线程的返回值。


// 原子类型atomic<>
// 原子操作指“不可分割的操作”，也就是说这种操作状态要么是完成的，要么是没完成的，不存在“操作完成了一半”这种状况。互斥量的加锁一般是针对一个代码段，而原子操作针对的一般都是一个变量(操作变量时加锁防止他人干扰)。 std::atomic<>是一个模板类，使用该模板类实例化的对象，提供了一些保证原子性的成员函数来实现共享数据的常用操作。

int main()
{
    
    /*
    cout << "我是主线程" << endl;
    int a = 9;
    //第一个参数为函数名，第二个参数为该函数的第一个参数，如果该函数接收多个参数就依次写在后面。此时线程开始执行。
    thread th2(proc, a);
    cout << "主线程中显示子线程id为" << th2.get_id() << endl;
    th2.join(); //此时主线程被阻塞直至子线程执行结束。
    */

    /*
    int a = 0;
    thread proc1(proc1, a);
    thread proc2(proc2, a);

    proc1.join();
    proc2.join();
    */

    /*
    int a = 0;
    thread proc5(proc5, a);
    thread proc3(proc3, a);

    proc5.join();
    proc3.join();
    */

    /*
    int a = 0;
    thread proc6(proc6, a);
    thread proc7(proc7, a);
    proc6.join();
    proc7.join();
    */

    double a = 2.3;
    double b = 6.7;
    //创建异步线程线程，并将线程的执行结果用fu占位；
    future<double> fu = async(t1, a, b);
    cout << "正在进行计算" << endl;
    cout << "计算结果马上就准备好，请您耐心等待" << endl;
    //阻塞主线程，直至异步线程return, future对象的get()方法只能调用一次。
    cout << "计算结果：" << fu.get() << endl;



    return 0;
}


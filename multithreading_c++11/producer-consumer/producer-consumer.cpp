﻿// producer-consumer.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
生产者消费者问题
生产者-消费者模型是经典的多线程并发协作模型。

生产者用于生产数据，生产一个就往共享数据区存一个，如果共享数据区已满的话，生产者就暂停生产，等待消费者的通知后再启动。

消费者用于消费数据，一个一个的从共享数据区取，如果共享数据区为空的话，消费者就暂停取数据，等待生产者的通知后再启动。

生产者与消费者不能直接交互,它们之间所共享的数据使用队列结构来实现;
*/


#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>

using namespace std;

// 缓冲区存储的数据类型 
struct CacheData
{
    int id;      //商品id 
    string data; //商品属性
};


class producerConsumer
{
private:
    queue<CacheData> Q;
    const int MAX_CACHEDATA_LENGTH = 10; //缓冲区最大空间 
    mutex m; //互斥量，生产者之间，消费者之间，生产者和消费者之间，同时都只能一个线程访问缓冲区 
    condition_variable condConsumer;
    condition_variable condProducer;
    int ID = 1; //全局商品id 

public:
    //消费者动作 
    void ConsumerActor()
    {
        unique_lock<mutex> lockerConsumer(m);
        cout << "[" << this_thread::get_id() << "] 获取了锁" << endl;
        while (Q.empty())
        {
            cout << "因为队列为空，所以消费者Sleep" << endl;
            cout << "[" << this_thread::get_id() << "] 不再持有锁" << endl;
            //队列空， 消费者停止，等待生产者唤醒 
            condConsumer.wait(lockerConsumer);
            cout << "[" << this_thread::get_id() << "] Weak, 重新获取了锁" << endl;
        }
        cout << "[" << this_thread::get_id() << "] ";
        CacheData temp = Q.front();
        cout << "- ID:" << temp.id << " Data:" << temp.data << endl;
        Q.pop();
        condProducer.notify_one();
        cout << "[" << this_thread::get_id() << "] 释放了锁" << endl;
    }

    //生产者动作 
    void ProducerActor()
    {
        unique_lock<mutex> lockerProducer(m);
        cout << "[" << this_thread::get_id() << "] 获取了锁" << endl;
        while (Q.size() > MAX_CACHEDATA_LENGTH)
        {
            cout << "因为队列为满，所以生产者Sleep" << endl;
            cout << "[" << this_thread::get_id() << "] 不再持有锁" << endl;
            //对列慢，生产者停止，等待消费者唤醒 
            condProducer.wait(lockerProducer);
            cout << "[" << this_thread::get_id() << "] Weak, 重新获取了锁" << endl;
        }
        cout << "[" << this_thread::get_id() << "] ";
        CacheData temp;
        temp.id = ID++;
        temp.data = "*****";
        cout << "+ ID:" << temp.id << " Data:" << temp.data << endl;
        Q.push(temp);
        condConsumer.notify_one();
        cout << "[" << this_thread::get_id() << "] 释放了锁" << endl;
    }

    // 消费者
    void ConsumerTask()
    {
        while (1) ConsumerActor();
    }

    // 生产者 
    void ProducerTask()
    {
        while (1) ProducerActor();
    }

    // 管理线程的函数 
    void Dispatch(int ConsumerNum, int ProducerNum)
    {
        vector<thread> thsC;
        for (int i = 0; i < ConsumerNum; i++)
        {
            thsC.push_back(thread(&producerConsumer::ConsumerTask, this));
        }

        vector<thread> thsP;
        for (int j = 0; j < ProducerNum; ++j)
        {
            thsP.push_back(thread(&producerConsumer::ProducerTask, this));
        }

        for (int i = 0; i < ConsumerNum; ++i)
        {
            if (thsC[i].joinable())
            {
                thsC[i].join();
            }
        }
        for (int j = 0; j < ProducerNum; ++j)
        {
            if (thsP[j].joinable())
            {
                thsP[j].join();
            }
        }


    }


};





int main()
{
    producerConsumer PC;
    PC.Dispatch(1, 5);
    return 0;
}


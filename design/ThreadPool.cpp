//
// Created by yzjhh on 2019/3/2.
//

/**
 * 头条：设计一个简单的线程池类
 *
 * https://blog.csdn.net/liushengxi_root/article/details/83932654
 * https://www.cnblogs.com/alwayswangzi/p/7138154.html
 * http://chestnutheng.cn/2017/04/07/cpp-threadpool/
 * */
#include <iostream>
#include <thread>
#include <unistd.h>
#include <mutex>
#include <vector>
#include <queue>

using namespace std;

class Task {
private:
    int run_time;
    int idx;
public:
    Task(int n) {
        run_time = n % 10;
        idx = n;
    }

    virtual void run() {
        sleep(run_time);
        cout << "task " << idx << " has been run " << run_time << "s";
    }

    int getIdx() {
        return idx;
    }
};

// 把线程池中的线程封装成一个Thread类，一直处于等待调度的空闲状态，如果有任务进来那么就立刻执行，执行完毕后恢复空闲状态
class Thread {
private:
    thread _thread;
    Task *_task;
    bool _isFree; // 标记当前线程是否空闲
    mutex _locker; // 锁
public:
    Thread() : _isFree(true), _task(nullptr) {
        _thread = thread(&Thread::run, this);
        _thread.detach(); // 分离线程，挂在后台
    }

    bool isFree() {
        return _isFree;
    }

    // 如果空闲则可以添加任务
    void feedTask(Task *task) {
        if (_isFree) {
            _locker.lock();
            _task = task;
            cout << "task " << _task->getIdx() << " is ready!" << endl;
            _isFree = false;
            _locker.unlock();
        }
    }

    // 如果有任务那就运行，否则空旋
    void run() {
        while (1) {
            if (_task != nullptr) {
                _locker.lock();
                _isFree = false;
                _task->run();
                cout << "task " << _task->getIdx() << " finished!" << endl;
                _isFree = true;
                _task = nullptr;
                _locker.unlock();
            }
        }
    }
};


class ThreadPool {
private:
    vector<Thread *> _pool;
    queue<Task *> task_queue;
    mutex _locker;

public:
    // 初始化，向线程池中创建n个线程
    ThreadPool(int n) {
        while (--n >= 0) {
            _pool.push_back(new Thread());
        }
    }

    // 线程池中的任务执行完毕的时候销毁线程
    ~ThreadPool() {
        for (int i = 0; i < _pool.size(); ++i) {
            delete _pool[i];
        }
    }

    // 向任务队列中添加任务
    void addTask(Task *t) {
        _locker.lock();
        task_queue.emplace(t);
        _locker.unlock();
    }

    void run() {
        while (1) {
            _locker.lock();
            if (task_queue.empty()) {
                continue;
            }
            for (int i = 0; i < _pool.size(); ++i) {
                if (_pool[i]->isFree()) {
                    _pool[i]->feedTask(task_queue.front());
                    task_queue.pop();
                    break;
                }
            }
            _locker.unlock();
        }
    }

};

int main() {
    int N = 100;
    ThreadPool tp(4);

    for (int i = 0; i < N; ++i) {
        tp.addTask(new Task(i));
    }

    sleep(N);
    return 0;
}


//#define chestnutheng

#ifdef chestnutheng

#include <queue>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <unistd.h>

using namespace std;

class Task {
private:
    int no;
public:
    Task(int n) {
        no = n;
    }

    //可以继承这个类重写该方法执行任务
    virtual void run() {
        sleep(no); //构造时决定执行几秒，模拟线程运行
        std::cout << no << "T\n";
    }

};

class Thread {
private:
    std::thread _thread;
    bool _isfree;
    Task *_task;
    std::mutex _locker;
public:
    //构造
    Thread() : _isfree(true), _task(nullptr) {
        _thread = std::thread(&Thread::run, this);
        _thread.detach(); //放到后台， join是等待线程结束
    }

    //是否空闲
    bool isfree() {
        return _isfree;
    }

    //添加任务
    void add_task(Task *task) {
        if (_isfree) {
            _locker.lock();
            _task = task;
            _isfree = false;
            _locker.unlock();
        }
    }

    //如果有任务则执行任务，否则自旋
    void run() {
        while (true) {
            if (_task) {
                _locker.lock();
                _isfree = false;
                _task->run();
                _isfree = true;
                _task = nullptr;
                _locker.unlock();
            }
        }
    }

};

class ThreadPool {
private:
    std::queue<Task *> task_queue;
    std::vector<Thread *> _pool;
    std::mutex _locker;

public:
    //构造线程并后台执行，默认数量为10
    ThreadPool(int n = 10) {
        while (n--) {
            Thread *t = new Thread();
            _pool.push_back(t);
        }
        std::thread main_thread(&ThreadPool::run, this);
        main_thread.detach();
    }

    //释放线程池
    ~ThreadPool() {
        for (int i = 0; i < _pool.size(); ++i) {
            delete _pool[i];
            cout << "threadpool destroyed!" << endl;
        }
    }

    //添加任务
    void add_task(Task *task) {
        _locker.lock();
        task_queue.push(task);
        _locker.unlock();
    }

    //轮询
    void run() {
        while (true) {
            _locker.lock();
            if (task_queue.empty()) {
                continue;
            }
            // 寻找空闲线程执行任务
            for (int i = 0; i < _pool.size(); ++i) {
                if (_pool[i]->isfree()) {
                    _pool[i]->add_task(task_queue.front());
                    task_queue.pop();
                    break;
                }
            }
            _locker.unlock();
        }
    }

};

int main() {
    ThreadPool tp(2);

    Task t1(1);
    Task t2(4);
    Task t3(2);

    tp.add_task(&t1);
    tp.add_task(&t2);
    tp.add_task(&t3);

    sleep(5);   //等待调度器结束，不然会崩溃
    return 0;
}

#endif
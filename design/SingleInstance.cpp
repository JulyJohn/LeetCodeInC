//
// Created by yzjhh on 2019/3/2.
//


/**
 *
 * 面试题：设计一个单例模式的类
 * 考察点：
     * 1.如何实现单例
     * 2.如何正确的释放这唯一的实例，侧面考察了堆栈知识
     * 3.考虑线程安全
 *
 * */

#include <iostream>
#include <pthread.h>

using namespace std;

//#define DEMO
//#define CLASSIC
#define HUNGRY
//#define LAZY

#ifdef CLASSIC

// 经典实现 但不是线程安全的
class SingleInstance {
private:
    SingleInstance() {
        cout << "created! " << endl;
    }

    ~SingleInstance() {
        cout << "destroyed! " << endl;
    };

    static SingleInstance *s;

    class GC { // s是静态成员，但其指向的对象就不是了，分配在堆上需要自己手动释放
    public:
        GC() {}

        ~GC() {
            if (s != nullptr) {
                delete s;
                s = nullptr;
                std::cout << "destroyed by myself! " << std::endl;
            }
        }
    };

    static GC gc;
public:
    static SingleInstance *getInstance() {
        return s;
    };
};

SingleInstance *SingleInstance::s = new SingleInstance();
SingleInstance::GC SingleInstance::gc;

#endif

#ifdef HUNGRY

// 饿汉实现 一开始就把对象创建好了 线程安全
class SingleInstance {
private:
    SingleInstance() {
        std::cout << "created! " << std::endl;
    }

    ~SingleInstance() {
        std::cout << "destroyed! " << std::endl;
    }

    static SingleInstance *s;

    class GC {
    public:
        GC() {}

        ~GC() {
            if (s != nullptr) {
                delete s;
                s = nullptr;
                std::cout << "destroyed by myself! " << std::endl;
            }
        }
    };

    static GC gc;

public:
    static SingleInstance *getInstance();
};

SingleInstance *SingleInstance::s = new SingleInstance();
SingleInstance::GC SingleInstance::gc;

SingleInstance *SingleInstance::getInstance() {
    return s;
}

#endif

#ifdef LAZY

// 加锁实现
class SingleInstance {
private:
    SingleInstance() {
        pthread_mutex_init(&mutex, NULL);
        std::cout << "created! " << std::endl;
    };

    ~SingleInstance() {
        std::cout << "destroyed! " << std::endl;
    };

    static pthread_mutex_t mutex;
public:
    static SingleInstance *getInstance() {
        pthread_mutex_lock(&mutex);
        static SingleInstance s; // 最简单的方法，利用静态变量位于栈的特点，自动回收
        pthread_mutex_unlock(&mutex);
        return &s;
    }
};

pthread_mutex_t SingleInstance::mutex;

#endif

#ifdef DEMO

class CSingleton {
private:
    CSingleton() { cout << "单例对象创建！" << endl; };

    ~CSingleton() { cout << "单例对象销毁！" << endl; };

    static CSingleton *myInstance;
public:
    static CSingleton *getInstance() {
        return myInstance;
    }

private:
    // 定义一个内部类
    class CGarbo {
    public:
        CGarbo() {};

        ~CGarbo() {
            if (nullptr != myInstance) {
                delete myInstance;
                myInstance = nullptr;
            }
        }
    };

    // 定义一个内部类的静态对象
    // 当该对象销毁时，顺带就释放myInstance指向的堆区资源
    static CGarbo m_garbo;
};

CSingleton *CSingleton::myInstance = new CSingleton();
CSingleton::CGarbo CSingleton::m_garbo;

#endif

int main() {
#ifdef CLASSIC

#endif

    SingleInstance *s1 = SingleInstance::getInstance();
    SingleInstance *s2 = SingleInstance::getInstance();

//    CSingleton *ct1 = CSingleton::getInstance();
//    CSingleton *ct2 = CSingleton::getInstance();
//    CSingleton *ct3 = CSingleton::getInstance();


    return 0;
}
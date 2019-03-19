//
// Created by yzjhh on 2019/3/10.
//

/**
 *
 * 在工厂中提供生产A和生产B的方法
 *
 * */

#include <iostream>

using namespace std;

class Product{
public:
    virtual ~Product() {};

    virtual void operation() = 0;
};

class Product1 : public Product {
public:
    virtual void operation() = 0;
};

class Product1A : public Product1 {
public:
    void operation() {
        cout << "product 1A created!" << endl;
    }
};

class Product1B : public Product1 {
public:
    void operation() {
        cout << "product 1B created!" << endl;
    }
};

class Product2 : public Product{
public:
    virtual void operation() = 0;
};

class Product2A : public Product2 {
public:
    void operation() {
        cout << "product 2A created!" << endl;
    }
};


class Product2B : public Product2{
public:
    void operation(){
        cout << "product 2B created!" <<endl;
    }
};

class Factory {
public:
    virtual Product *produce1() = 0;

    virtual Product *produce2() = 0;

    virtual ~Factory() {};
};

// Factory1生产两种不同的A
class FactoryA : public Factory {
public:
    Product *produce1() {
        return new Product1A();
    };

    Product *produce2() {
        return new Product2A();
    };
};

// Factory1生产两种不同的B
class FactoryB : public Factory {
public:
    Product *produce1() {
        return new Product1B();
    };

    Product *produce2() {
        return new Product2B();
    };
};

int main() {
    FactoryA *factoryA = new FactoryA();
    FactoryB *factoryB = new FactoryB();
    Product *pa1 = factoryA->produce1();
    Product *pa2 = factoryA->produce2();
    Product *pb1 = factoryB->produce1();
    Product *pb2 = factoryB->produce2();

    cout << "factoryA is running!" << endl;
    pa1->operation();
    pa2->operation();
    cout << "factoryB is running!" << endl;
    pb1->operation();
    pb2->operation();

    delete pa1;
    delete pa2;
    delete pb1;
    delete pb2;
    delete factoryA;
    delete factoryB;

    return 0;
}

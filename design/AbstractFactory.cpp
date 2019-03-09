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

class Product {
public:
    virtual ~Product() {};

    virtual void operation() = 0;
};

class ProductA : public Product {
public:
    void operation() {
        cout << "product A created!" << endl;
    }
};

class ProductB : public Product {
public:
    void operation() {
        cout << "product B created!" << endl;
    }
};

class Factory {
public:
    virtual ProductA *produceA() = 0;

    virtual ProductB *produceB() = 0;

    virtual ~Factory() {};
};

class FactoryA : public Factory {
public:
    ProductA *produceA() {
        return new ProductA();
    };

    ProductB *produceB() {
        return new ProductB();
    };
};

class FactoryB : public Factory {
public:
    ProductA *produceA() {
        return new ProductA();
    };

    ProductB *produceB() {
        return new ProductB();
    };
};

int main() {
    FactoryA *factoryA = new FactoryA();
    FactoryB *factoryB = new FactoryB();
    ProductA *pa1 = factoryA->produceA();
    ProductB *pb1 = factoryA->produceB();
    ProductA *pa2 = factoryB->produceA();
    ProductB *pb2 = factoryB->produceB();

    pa1->operation();
    pa2->operation();
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

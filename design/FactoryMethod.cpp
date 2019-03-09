//
// Created by yzjhh on 2019/3/9.
//

/**
 *
 * 把工厂抽象成一个类，可以派生出不同的工厂，不同的工厂可以根据需求实现生产工厂抽象类中提供的抽象生产方法
 *
 * */

#include <iostream>

using namespace std;

class AbstractProduct {
public:
    virtual ~AbstractProduct() {};

    virtual void operation() = 0;
};

class ConcreteProductA : public AbstractProduct {
public:
    void operation() {
        cout << "product A created!" << endl;
    }
};

class ConcreteProductB : public AbstractProduct {
public:
    void operation() {
        cout << "product B created!" << endl;
    }
};

class Creator {
public:
    virtual AbstractProduct *FactoryMethod() = 0;

    virtual ~Creator() {};
};

class ConcreteCreatorA : public Creator {
public:
    AbstractProduct *FactoryMethod() {
        return new ConcreteProductA();
    }
};

class ConcreteCreatorB : public Creator {
public:
    AbstractProduct *FactoryMethod() {
        return new ConcreteProductB();
    }
};

int main() {
    ConcreteCreatorA *creatorA = new ConcreteCreatorA();
    ConcreteCreatorB *creatorB = new ConcreteCreatorB();
    AbstractProduct *productA = creatorA->FactoryMethod();
    AbstractProduct *productB = creatorB->FactoryMethod();

    productA->operation();
    productB->operation();

    delete creatorA;
    delete creatorB;
    delete productA;
    delete productB;

    return 0;
}


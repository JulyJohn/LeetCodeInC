//
// Created by yzjhh on 2019/3/9.
//

/**
 *
 * 在工厂类中提供一个方法，根据输入参数生产不同的产品
 *
 * */

#include <iostream>

using namespace std;

class AbstractProduct {
public:
    virtual ~AbstractProduct() {};

    virtual void operation() = 0;
};

class ProductA : public AbstractProduct {
public:
    ~ProductA() {
        cout << "A destroyed!" << endl;
    };

    void operation() {
        cout << "productA" << endl;
    }
};

class ProductB : public AbstractProduct {
public:
    ~ProductB() {
        cout << "B destroyed!" << endl;
    };

    void operation() {
        cout << "productB" << endl;
    }
};

class Factory {
public:
    AbstractProduct *createProduct(char product_type) {
        AbstractProduct *product;
        switch (product_type) {
            case 'A':
                product = new ProductA();
                break;
            case 'B':
                product = new ProductB();
                break;
        }
        return product;
    }
};

int main() {
    Factory *factory = new Factory();
    AbstractProduct *productA = factory->createProduct('A');
    AbstractProduct *productB = factory->createProduct('B');

    productA->operation();
    productB->operation();

    delete productA;
    delete productB;
    delete factory;
    return 0;
}
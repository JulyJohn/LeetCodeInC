//
// Created by julyjohn on 2019-04-07.
//

/**
 *
 * c++ String类的实现
 *
 * 相同字符串指向同一块空间，用一个引用计数来统计该字符串被引用的次数，并且增加了写时拷贝
 *
 * https://blog.csdn.net/Warrior_Harlan/article/details/81407141
 *
 * */

#define _CRT_SECURE_NO_WARNINGS
//#define DEMO
#define MYSTRING

#include<iostream>
#include<cassert>
//#include<string>

using namespace std;

#ifdef MYSTRING

class MyString {
    friend ostream &operator<<(ostream &os, const MyString &s);

    friend MyString operator+(const MyString &s1, const MyString &s2);

public:
    MyString(const char *str = "") : _str(new char[strlen(str) + 1]), _p_cnt(new int(1)) { //默认字符串为空字符串
        strcpy(_str, str);
        cout << str << " has been constructed!" << endl;
    }

    ~MyString() {
        this->release();
    }

    MyString(const MyString &myString) : _str(myString._str), _p_cnt(myString._p_cnt) { // 拷贝构造函数，参数默认为const，引用数+1
        ++(*_p_cnt);
    }

    // 传统写法
    MyString &operator=(const MyString &myString) {
        // 1、s1和s2指向同一块空间(不处理)
        // 2、减减s1指向空间的引用计数，若s1是最后一块管理对象，则释放s1
        if (myString._str != _str) {
            this->release();

            _str = myString._str;
            _p_cnt = myString._p_cnt;
            ++(*_p_cnt);
        }
        return *this;
    }

//    // 现代写法
//    MyString &operator=(MyString myString) {  //拷贝s时引用计数已经加
//        swap(_str, myString._str); // 将this中的_str的指针与s中的_str指针交换，由于s是函数的形参，会随着函数的结束而自动销毁，所以相当于是把this中的两个指针给delete掉了
//        swap(_p_cnt, myString._p_cnt);
//        return *this;
//    }

    const char &operator[](const size_t idx) const {
        assert(idx < strlen(_str));
        return _str[idx];
    }

    char &operator[](const size_t idx) {
        copyOnWrite(); // 如果是可以修改的，那么就要先拷贝
        assert(idx < strlen(_str));
        return _str[idx];
    }

    MyString &operator+=(const MyString &myString) {
        this->copyOnWrite();
        char *tmp = new char[myString.length() + this->length() + 1];
        strcpy(tmp, _str);
        strcat(tmp, myString._str);
        delete[] _str;
        _str = tmp;
        return *this;
    }

    inline bool operator==(const MyString &myString) const {
        if (strlen(_str) != strlen(myString._str)) {
            return false;
        } else {
            return strcmp(myString._str, _str) ? false : true;
        }
    }

    char *get_c_char() const {
        return _str;
    }

    int length() const {
        return strlen(_str);
    }

    void release() {
        if (--(*_p_cnt) == 0) {
            cout << "delete " << _str << endl;
            delete[] _str;
            delete _p_cnt;
        }
    }

    void copyOnWrite() {
        if ((*_p_cnt) > 1) { // 如果大于1的话，就要重新复制一份
            char *tmp = new char[strlen(_str) + 1];
            strcpy(tmp, _str);
            --(*_p_cnt);

            _str = tmp;
            _p_cnt = new int(1);
        }
    }

private:
    char *_str;
    int *_p_cnt;
};

ostream &operator<<(ostream &os, const MyString &s) {
    os << s._str;
    return os;
}

MyString operator+(const MyString &s1, const MyString &s2) {
    char *tmp = new char[s1.length() + s2.length() + 1];
    strcpy(tmp, s1.get_c_char());
    strcat(tmp, s2.get_c_char());
    MyString new_str = MyString(tmp);
    return new_str;
}

int main() {
    const MyString str1("111");
    MyString str2 = "222";
    MyString str3;
    str3 = str1;
    str3 = str2;

    cout << str3 << endl;

    MyString str4 = "444";
    MyString str5(str4);
    cout << "str5 " << str5 << endl;

    MyString str6 = str2 + str1;
    str2 += str1;

    cout << "str6 " << str6 << endl;
    cout << (str6 == str2) << endl;

    return 0;
}

#endif

#ifdef DEMO

//相同字符串指向同一块空间，用一个引用计数来统计该字符串被引用的次数，并且增加了写时拷贝
class String {
    friend &ostream operator<<(ostream &os, const String &s);

public:
    String(const char *str = "")     //默认字符串为空字符串
            : _str(new char[strlen(str) + 1]), _refCount(new int(1)) {
        strcpy(_str, str);
        cout << "String(const char *str)" << endl;
    }

    String(const String &s)  //拷贝构造函数
            : _str(s._str), _refCount(s._refCount) {
        ++(*_refCount);
    }

    //传统的写法（s1=s2）
//    String &operator=(const String &s) {
//        //1、s1和s2指向同一块空间(不处理)
//        //2、减减s1指向空间的引用计数，若s1是最后一块管理对象，则释放s1
//        if (_str != s._str) {
//            this->Release();
//
//            this->_str = s._str;
//            this->_refCount = s._refCount;
//            ++(*_refCount);
//        }
//        return *this;
//    }

    //现代的写法
    String &operator=(String s)   //拷贝s时引用计数已经加1
    {
        swap(_str, s._str); // 将this中的_str的指针与s中的_str指针交换，由于s是函数的形参，会随着函数的结束而自动销毁，所以相当于是把this中的两个指针给delete掉了
        swap(_refCount, s._refCount);
        return *this;
    }

    void Release() {
        if (--(*_refCount) == 0) {
            cout << "delete" << endl;
            delete[] _str;
            delete _refCount;
        }
    }

    //String* this
    char &operator[](size_t index) {
        //写时拷贝
        CopyOnWrite();  //缺点：读的时候也会进行拷贝

        assert(index < strlen(_str));
        return _str[index];
    }

    //const String* this
    const char &operator[](size_t index) const   //常成员函数，当访问常成员变量时调用
    {
        assert(index < strlen(_str));
        return _str[index];
    }

    void CopyOnWrite() {
        //引用计数大于1时需要进行拷贝
        if ((*_refCount) > 1) {
            char *tmp = new char[strlen(_str) + 1];
            strcpy(tmp, _str);
            --(*_refCount);

            _refCount = new int(1);
            _str = tmp;
        }
    }

    ~String() {
        Release();
    }

    char *GetStr() {
        return _str;
    }

private:
    char *_str;
    int *_refCount;   //引用计数的指针
};

ostream &operator<<(ostream &os, const String &s)   //重载string的输出符号
{
    os << s._str;
    return os;
}

int main() {
    const String str1("123456");
    String str2 = "123";
    String str3;
    str3 = str1;
    str3 = str2;

    String str4("abcdef");
    String str5(str4);

    cout << str1[3] << endl;
    cout << str2 << endl;
    cout << str3 << endl;

    cout << str4 << endl;
    cout << str5 << endl;
    return 0;
}
#endif

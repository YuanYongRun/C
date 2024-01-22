/*
静态成员:   在成员属性和成员函数加上static，称为静态成员
分为:
    静态成员变量:
                1.所有对象共享同一份数据
                2.在编译阶段进行内存分配
                3.类内声明，类外初始化(必须要有初始值)
    静态成员函数：
                1.所有对象共享同一个函数
                2.静态成员函数只能访问静态成员变量
*/


//静态成员变量
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
        static void func()   //静态成员也是有访问权限的，如果在private下，就无法调用了
        {   m_A = 400;  //静态成员函数是可以访问静态成员变量
            // m_B = 200;  静态成员函数不可以访问非静态成员变量
            cout<<"static void func的调用"<<endl;
        }
        static int m_A;    //类内声明  静态成员变量
        int m_B;           //非静态成员变量
private:  
        static int m_B;   //依旧访问不到

};

int Person::m_A = 100;  //类外初始化       
// 静态成员变量不属于某个对象，所有对象共享一份数据，因此静态成员有2种访问方式

//1.通过对象访问
void test01()
{
    Person p1;
    cout<<"静态成员的数据为"<<p1.m_A<<endl;
}

//2.通过类名进行访问
void test02()
{
    cout<<"静态成员的数据"<<Person::m_A<<endl;
}


//静态成员函数    和静态成员变量类似    静态成员函数只能访问静态成员变量

void test03()
{
    //通过对象进行访问
    Person p ;
    p.func();

    //通过类名去访问
    Person::func();
}




int main()
{
    test01();
    test02();
    test03();
    system("pause");
}


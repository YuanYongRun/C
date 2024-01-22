//对象特性

/*
1 构造函数和析构函数   若我们不提供析构和构造函数，编译器提供的构造函数是空实现
构造函数: 对象的初始化 创建对象时对象的成员属性进行赋值，构造函数由编译器自动调用，无需手动调用
析构函数: 对象的清理  在对象销毁前，系统自动调用，执行清理工作
*/

#include<iostream>
using namespace std;

/*
构造函数语法:
类名(){}
构造函数:
1.没有返回值，也不用写void
2.函数名称与类名相同
3.构造函数可以有参数，因此可以发生重载
4.程序在调用对象时会自动调整构造，无需手动调用，而且只会调动一次

析构函数语法:
~ 类名(){}
1.没有返回值，也不用写void
2.函数名称与类名相同，在前面加上~
3.析构函数不能有参数，因此不可以发生重载
4.程序在销毁时会自动调用析构函数，无需手动调用，而且只会调动一次
*/

class person
{
public:
        person()
        {
            cout<<"person构造函数的调用"<<endl;
        }
        ~ person()
        {
            cout<<"Person析构函数的调用"<<endl;
        }
};

void test01()
{
    person p;
}


/*
构造函数的分类及其调用
两种分类方式:
            按参数分类:有参构造和无参构造
            按类型分类:普通构造和拷贝构造
三种调用方式:
            括号法  显示法  隐式转换法
*/

class person1
{
public:
        //重载构造函数
        person1()
        {
            cout<<"person1()无参构造"<<endl;
        }

        person1(int a)
        {
            age = a;
            cout<<"person1()有参构造"<<endl;
        }

        // 拷贝构造
        person1(const person1 &p)
        {
            cout<<"person1()的拷贝构造"<<endl;
            age = p.age;   // 将传入人的属性拷贝到我自己的属性上
        }

public:
        int age;
};

//括号法调用
void test02()
{
    person1 p1;  //默认构造函数
    person1 p2(10); //有参构造函数
    person1 p3(p2);  //拷贝构造函数
    // 调用默认构造函数，不要加()；如果写为person1 p1(),编译器会认为这是个函数声明，而非创建对象;
}

// 显示法:
void test03()
{
    person1 p1 ; //默认构造函数
    person1 p2 = person1(10);
    person1 p3 =person1(p2);
}

// 注意事项:不要利用拷贝构造函数进行初始化匿名对象   eg：person1(p3)

//隐式转换法
void test04()
{
    person1 p4 = 10;    //等价于 person1 p4 = person1(10);
    person1 p5 = p4;   //拷贝构造
}



/*
拷贝构造函数调用时机
*/

//1.使用一个已经创建完毕的对象来初始化一个对象
void test05()
{
    person1 p1(20);
    person1 p2(p1);
    cout<<"p2的年龄为:"<<p2.age<<endl;
}

//2.值传递的方式给函数参数进行传值
void dowork(person1 p)
{

}

void test06()
{
    person1 p;
    dowork(p);
}

//3.以值方式返回局部对象
person1 dowork2()
{
    person1 p1;
    cout<<(int *)&p1<<endl;
    cout<<"p1的地址为"<<&p1<<endl;
    return p1;
}

void test07()
{
    person1 p = dowork2();
    cout<<(int *)&p<<endl;
    cout<<"p的地址为"<<&p<<endl;
}



int main()
{
    // test01();
    // test02();
    // test03();
    // test04();
    // test05();
    test06();
    test07();
    system("pause");
}
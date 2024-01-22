/*
常量:
1.局部变量:主函数内    不要返回局部变量的地址   存放在栈区
2.全局变量:主函数外     存放在全局区
*/

#include <iostream>
using namespace std;

int * func1()
{
    static int a =10;   
    return &a;
}
//  不要返回局部变量地址，否则会出现警告
int *func2()
{
    int b = 20; 
    return &b;
}

/*
堆区:主要用new进行开辟,开辟的数据放在堆区   delete释放开辟的空间
*/

int *fun3()
{
    // 利用new的关键字 将数据开辟到堆区
    int * p = new int(30);  // 指针本质是局部变量，放在栈区里，但是指针开辟的数据是放在堆区的
    return p;
}

void test01()
{
    int * p =fun3();
    cout<<"数据为:"<<*p<<endl;
    // 释放地址 delete
    delete p;
    p = nullptr;  //进行置空，否则p指针还会有脏数据存在
    cout<<"释放后数据为:"<<endl;
    // cout<<*p<<endl;
}

//  在堆区中进行开辟数组
void test02()
{
    int * arr = new int[10]; //中括号代表数组
    for(int i = 0;i<10;i++)
    {
        arr[i] = i + 100 ;
    }
    // 读取数据
    for(int i = 0;i<10;i++)
    {
        cout<<*(arr+i)<<endl;
    }
    delete [] arr;
    arr = nullptr;  // 如果缺少此句，arr数组里面还会有脏数据存在
}

int main()
{
    int * p1 = func1();
    int * p2 = func2();
    int *p3 = fun3();
    cout<<"p1的数据为:"<<*p1<<endl;     //由于有static，故此变量为全局变量,可以返回地址
    // cout<<*p2<<endl;   由于变量是局部的，函数运行结束后就销毁了,故报错
    cout<<"p3的数据为:"<<*p3<<endl;
    test01();
    test02();
    system("pause");
}